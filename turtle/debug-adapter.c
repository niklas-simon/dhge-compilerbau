#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debug-adapter.h"
#include "turtle-types.h"
#include "turtle.h"

/**
 * Maximale Länge eines Debugger-Befehls
 */
#define MAX_COMMAND_LENGTH 16

/**
 * Maximale Länge eines Arguments für einen Debugger-Befehl
 */
#define MAX_COMMAND_ARG_LENGTH 8

/**
 * Maximale Anzahl an Breakpoints
 */
#define MAX_BREAKPOINTS 1024

/**
 * Maximale Anzahl an Stacktrace-Einträgen
 */
#define MAX_STACKTRACE_SIZE 128

/**
 * Debugger Flag
 * true, wenn der Debugger aktiv ist.
 */
bool debug = false;

/**
 * Debugger Running Flag
 * true, wenn der Debugger das Programm ausführt.
 */
bool running = false;

/**
 * Debugger Stepping Flag
 * true, wenn der Debugger im Stepping-Modus ist.
 */
bool stepping = false;

/**
 * Array für Breakpoints
 * Die Länge des Arrays ist in br_length gespeichert.
 * Jeder Eintrag ist eine Zeilennummer, die einen Breakpoint darstellt.
 */
int breakpoints[MAX_BREAKPOINTS];

/**
 * Aktuelle Länge des Breakpoint-Arrays
 * Zeigt auf den nächsten freien Eintrag in breakpoints.
 */
size_t br_length = 0;

/**
 * Array für Stacktrace-Einträge
 * Die aktuelle Stacktrace-Größe ist in stack_size gespeichert und 
 * der zuletzt hinzugefügte Eintrag ist unter stack_size - 1 zu finden.
 */
stacktrace_t *stacktrace[MAX_STACKTRACE_SIZE];

/**
 * Aktuelle Stacktrace-Größe
 * Zeigt auf den nächsten freien Eintrag in stacktrace.
 */
size_t stack_size = 0;

/**
 * Aktuelle Position im Sourcefile
 */
srcpos_t current_pos;

/**
 * Fügt einen Stacktrace-Eintrag hinzu
 * Der Eintrag wird in einem Array gespeichert und der Stacktrace-Zähler erhöht.
 * Diese Funktion muss bei jedem Funktionsaufruf aufgerufen werden.
 * @param t Zeiger auf den initialisierten Stacktrace-Eintrag
 */
void push_stacktrace(stacktrace_t *t) {
    // Wenn der Stacktrace voll ist, gib einern Fehler aus
    if (stack_size >= MAX_STACKTRACE_SIZE) {
        fprintf(stderr, "Stacktrace buffer is full. Exiting\n");
        fflush(stdout);
        exit(EXIT_FAILURE);
    }

    stacktrace[stack_size++] = t;
}

/**
 * Entfernt den letzten Stacktrace-Eintrag
 * Der Stacktrace-Zähler wird verringert und der Speicher des Eintrags freigegeben.
 * Diese Funktion muss bei jedem Funktionsende aufgerufen werden.
 */
void pop_stacktrace() {
    free(stacktrace[--stack_size]);
}

/**
 * Fügt einen Breakpoint hinzu
 * Überprüft, ob die Zeilennummer bereits existiert und ob der Breakpoint-Puffer voll ist.
 * @param linenr Zeilennummer, an der der Breakpoint gesetzt werden soll
 */
void add_breakpoint(int linenr) {
    // Überprüfen, ob die Zeilennummer bereits existiert
    for (int i = 0; i < br_length; i++) {
        if (breakpoints[i] == linenr) {
            printf("Breakpoint at line %d already exists\n", linenr);
            return;
        }
    }
    
    // Überprüfen, ob der Breakpoint-Puffer voll ist
    if (br_length >= MAX_BREAKPOINTS) {
        printf("Could not create breakpoint: Breakpoint buffer full\n");
        return;
    }

    breakpoints[br_length++] = linenr;
}

/**
 * Entfernt einen Breakpoint
 * Überprüft, ob die ein Breakpoint an linenr existiert und verschiebt alle nachfolgenden 
 * Breakpoints im Array um eine Position nach vorne.
 * @param linenr Zeilennummer, an der der Breakpoint entfernt werden soll
 */
void remove_breakpoint(int linenr) {
    // Überprüfen, ob die Zeilennummer existiert
    int index = -1;
    for (int i = 0; i < br_length; i++) {
        if (breakpoints[i] == linenr) {
            index = i;
            break;
        }
    }

    // Wenn die Zeilennummer nicht gefunden wurde, gib einen Fehler aus
    if (index == -1) {
        printf("breakpoint at line %d not found\n", linenr);
        return;
    }

    // Verschiebe alle nachfolgenden Breakpoints um eine Position nach vorne
    for (int i = index + 1; i < br_length; i++) {
        breakpoints[i - 1] = breakpoints[i];
    }
    
    br_length--;
}

/**
 * Liest ein Argument aus einer Zeile
 * Liest Zeichen aus line in arg bis entweder '\0', ' ' oder '\n' gelesen wird
 * @param line Zeile, die gelesen werden soll
 * @param arg Zeiger auf den Puffer, in den die Zeichen geschrieben werden
 * @param arg_len Länge des Puffers
 * @return Zeiger auf das nächste Zeichen in line, das nicht gelesen wurde
 */
char *get_arg(char *line, char *arg, size_t arg_len) {
    char *line_ptr = line;

    // Zeichen für Zeichen in arg kopieren
    for (int i = 0; i < arg_len - 1; i++) {
        // Wenn Ende der Zeile erreicht ist, oder ein Leerzeichen oder Zeilenumbruch
        // gefunden wird, beende die Schleife und setze das Nullbyte
        if (*line_ptr == '\0' || *line_ptr == ' ' || *line_ptr == '\n') {
            arg[i] = '\0';
            return line_ptr;
        }
        
        // Ansonsten das Zeichen in arg kopieren
        arg[i] = *(line_ptr++);
    }

    // Wenn die Schleife nicht abgebrochen werden sollte, setze das Nullbyte
    arg[arg_len - 1] = '\0';

    return line_ptr;
}

/**
 * Gibt eine Liste der verfügbaren Befehle aus
 */
void print_help() {
    printf("available commands:\n"\
        "break <line> - sets a breakpoint at the specified line\n"\
        "evaluate <frame> <variable> - returns the value of the provided variable in the provided frame\n"\
        "exit - exits the program\n"\
        "help - prints this text\n"\
        "rbreak [line] - clears all breakpoints or the breakpoint at the specified line\n"\
        "run - runs the program\n"\
        "stacktrace - prints the current stacktrace\n"\
        "step [over|in|out] - steps to next instruction\n"\
        "    over: [default] jumps over function calls\n"\
        "    in: jumps inside a function call\n"\
        "    out: jumps over the current function call\n"\
        "variables <frame> - prints the variables in the provided stack frame\n"\
    );
    fflush(stdout);
}

/**
 * Liest einen Debug-Befehl von der Konsole ein und führt ihn aus
 * @return den ausgeführten Befehl
 */
command_t user_eval() {
    // Einlesen der Zeile
    char *line = NULL;
    size_t n = 0;
    int size = getline(&line, &n, stdin);

    // Wenn getline fehlschlägt oder EOF liest, gib einen Fehler aus
    if (size <= 0) {
        printf("invalid option. Type help for more information\n");
        fflush(stdout);

        free(line);
        return no_command;
    }
    
    // Parsen des Befehls
    char command[MAX_COMMAND_LENGTH];
    char *line_ptr = line;
    line_ptr = get_arg(line_ptr, command, sizeof(command)) + 1;

    // Setzen eines Breakpoints
    if (strcmp(command, "break") == 0 || strcmp(command, "b") == 0) {
        // Prüfe, ob kein weiteres Argument vorhanden ist
        if (line_ptr >= line + size) {
            printf("invalid option. Type help for more information\n");
            fflush(stdout);
            return no_command;
        }

        // Einlesen der Zeilennummer
        char arg[MAX_COMMAND_ARG_LENGTH];
        line_ptr = get_arg(line_ptr, arg, sizeof(arg));
        char *endptr;
        int linenr = strtol(arg, &endptr, 10);

        // Wenn die Zeilennummer nicht gelesen werden konnte oder ungültig ist, 
        // gib einen Fehler aus
        if (*endptr != '\0' || linenr <= 0) {
            printf("invalid option. Type help for more information\n");
            fflush(stdout);
            return no_command;
        }
        
        add_breakpoint(linenr);
        printf("new breakpoint at line %d\n", linenr);
        fflush(stdout);
        return no_command;
    } 

    // Entfernen eines Breakpoints
    if (strcmp(command, "rbreak") == 0 || strcmp(command, "rb") == 0) {
        // Prüfe, ob kein weiteres Argument vorhanden ist
        if (line_ptr >= line + size) {
            br_length = 0;
            printf("removed all breakpoints\n");
            fflush(stdout);
            return no_command;
        }

        // Einlesen der Zeilennummer
        char arg[MAX_COMMAND_ARG_LENGTH];
        line_ptr = get_arg(line_ptr, arg, sizeof(arg));
        char *endptr;
        int linenr = strtol(arg, &endptr, 10);

        // Wenn die Zeilennummer nicht gelesen werden konnte oder ungültig ist, 
        // gib einen Fehler aus
        if (*endptr != '\0' || linenr <= 0) {
            printf("invalid option. Type help for more information\n");
            fflush(stdout);
            return no_command;
        }
        
        remove_breakpoint(linenr);
        printf("removed breakpoint at line %d\n", linenr);
        fflush(stdout);
        return no_command;
    } 

    // Ausgeben einer Variablen
    if (strcmp(command, "evaluate") == 0 || strcmp(command, "ev") == 0) {
        // Prüfe, ob kein weiteres Argument vorhanden ist
        if (line_ptr >= line + size) {
            printf("invalid option. Type help for more information\n");
            fflush(stdout);
            return no_command;
        }

        // Einlesen des Frame-Index
        char arg[MAX_COMMAND_ARG_LENGTH];
        line_ptr = get_arg(line_ptr, arg, sizeof(arg)) + 1;
        char *endptr;
        int frame_index = strtol(arg, &endptr, 10);

        // Wenn der Frame-Index nicht gelesen werden konnte oder ungültig ist, 
        // gib einen Fehler aus
        if (*endptr != '\0' || frame_index >= stack_size) {
            printf("unknown frameId (%d)\n", frame_index);
            fflush(stdout);
            return no_command;
        }

        vstack_elem_t *frame = stacktrace[frame_index]->frame;
        vstack_elem_t *stack_top = get_stack_top();
        frame++;

        // Prüfe, ob kein weiteres Argument vorhanden ist
        if (line_ptr >= line + size) {
            printf("invalid option. Type help for more information\n");
            fflush(stdout);
            return no_command;
        }

        // Einlesen des Variablennamens
        char name[32];
        line_ptr = get_arg(line_ptr, name, 32);

        // Überprüfen, ob globale Variable
        if (name[0] == '@') {
            // Finden der globalen Variable in der Namens-Tabelle
            for (int i = 0; i < MAX_NAMES && name_tab[i].name; i++) {
                if (strcmp(name_tab[i].name, name) == 0) {
                    // Wenn die Variable gefunden wurde, gib den Wert aus
                    double val;

                    // Überprüfen, ob es sich um eine benutzerdefinierte globale Variable handelt
                    if (name_tab[i].type == name_glob) {
                        val = name_tab[i].d.val;
                    } else {
                        val = *(name_tab[i].d.p_val);
                    }
                    printf("%lf\n", val);
                    fflush(stdout);
                    return no_command;
                }
            }
        }
        
        // Suchen der Variablen im Stack
        for (; frame <= stack_top && frame->name != NULL && frame->name->name != NULL; frame++) {
            if (strcmp(frame->name->name, name) == 0) {
                printf("%lf\n", frame->val);
                fflush(stdout);
                return no_command;
            }
        }

        printf("variable not found\n");
        fflush(stdout);
        return no_command;
    }

    // Beenden des Programms
    if (strcmp(command, "exit") == 0 || strcmp(command, "e") == 0) {
        printf("exited\n");
        exit(EXIT_SUCCESS);
    }

    // Hilfe ausgeben
    if (strcmp(command, "help") == 0 || strcmp(command, "h") == 0) {
        print_help();
        return no_command;
    }

    // Ausführen des Programms
    if (strcmp(command, "run") == 0 || strcmp(command, "r") == 0) {
        if (running) {
            // Wenn der Debugger bereits läuft, setze den Stepping-Modus zurück
            stepping = false;
        } else {
            // Wenn nicht, starte den Debugger
            running = true;
        }
        return no_command;
    }

    // Stacktrace ausgeben
    if (strcmp(command, "stacktrace") == 0 || strcmp(command, "st") == 0) {
        for (int i = stack_size - 1; i >= 0; i--) {
            // Wenn der Eintrag der erste ist, gebe die aktuelle Position im Quelltext aus
            // Ansonsten gebe die Position des vorherigen Eintrags aus
            srcpos_t pos = (i == stack_size - 1) ? current_pos : stacktrace[i + 1]->pos;

            // Ausgabe des Stacktrace-Eintrags
            printf("%d %s %d:%d\n", i, stacktrace[i]->name, pos.line, pos.col);
            fflush(stdout);
        }
        return no_command;
    }

    // Schrittweise Ausführung
    if (strcmp(command, "step") == 0 || strcmp(command, "s") == 0) {
        if (!running) {
            running = true;
            stepping = true;
        }

        // Wenn kein weiteres Argument vorhanden ist, fallback zu step_over
        if (line_ptr >= line + size) {
            return step_over;
        }

        // Einlesen des Stepping-Modus
        char arg[MAX_COMMAND_ARG_LENGTH];
        line_ptr = get_arg(line_ptr, arg, sizeof(arg));
        if (strcmp(arg, "over") == 0) {
            return step_over;
        }
        if (strcmp(arg, "in") == 0) {
            return step_in;
        }
        if (strcmp(arg, "out") == 0) {
            return step_out;
        }
        printf("invalid option: %s. Type help for more information\n", arg);
        fflush(stdout);
        return no_command;
    }

    // Variablen ausgeben
    if (strcmp(command, "variables") == 0 || strcmp(command, "v") == 0) {
        // Prüfe, ob kein weiteres Argument vorhanden ist
        if (line_ptr >= line + size) {
            printf("invalid option. Type help for more information\n");
            fflush(stdout);
            return no_command;
        }

        // Einlesen des Frame-Index
        char arg[MAX_COMMAND_ARG_LENGTH];
        line_ptr = get_arg(line_ptr, arg, sizeof(arg));
        char *endptr;
        int frame_index = strtol(arg, &endptr, 10);

        // Wenn der Frame-Index nicht gelesen werden konnte oder ungültig ist, 
        // gib einen Fehler aus
        if (*endptr != '\0' || frame_index >= stack_size) {
            printf("unknown frameId (%d)\n", frame_index);
            fflush(stdout);
            return no_command;
        }

        // Ausgabe der Variablen im Stackframe
        vstack_elem_t *frame = stacktrace[frame_index]->frame;
        vstack_elem_t *stack_top = get_stack_top();
        frame++;
        
        for (; frame <= stack_top && frame->name != NULL && frame->name->name != NULL; frame++) {
            printf("%s %lf\n", frame->name->name, frame->val);
        }

        fflush(stdout);

        return no_command;
    }

    printf("unknown command (%s). Type help for a list of commands\n", command);
    fflush(stdout);
    return no_command;
}

/**
 * Initialisiert den Debugger
 * Diese Funktion muss aufgerufen werden, bevor der Debugger verwendet werden kann.
 * @param _debug true, wenn der Debugger aktiviert werden soll
 */
void debug_init(bool _debug) {
    debug = _debug;
    if (!debug) {
        return;
    }

    printf("Debugger active. Type help for a list of commands\n");
    fflush(stdout);

    // Warte, bis der Debugger gestartet wird
    while (!running) {
        user_eval();
    }
}

/**
 * Führt den Debugger aus
 * Diese Funktion muss bei jedem Schritt des Interpreters aufgerufen werden.
 * @param t Zeiger auf den aktuellen Tree-Node
 * @return den ausgeführten Befehl
 */
command_t debug_loop(const treenode_t *t) {
    // Prüfe, ob der Debugger aktiviert ist
    if (!debug) {
        return no_command;
    }

    // Prüfe, ob der Debugger bereits für diese Zeile aufgerufen wurde
    // Mehrere Interpretationsschritte in einer Zeile können in dieser Version
    // nicht vom Debugger verarbeitet werden
    if (current_pos.line == t->pos.line) {
        return no_command;
    }

    // Setze die aktuelle Position auf die des aktuellen Knoten im Syntaxbaum
    current_pos = t->pos;

    // Prüfe, ob für die aktuelle Zeile ein Breakpoint gesetzt ist
    int current_breakpoint = -1;
    for (int i = 0; i < br_length; i++) {
        if (breakpoints[i] == current_pos.line) {
            stepping = true;
            current_breakpoint = i;
            break;
        }
    }

    if (!stepping) {
        return no_command;
    }

    if (current_breakpoint != -1) {
        printf("currently at %d:%d [breakpoint: %d]\n", t->pos.line, t->pos.col, current_breakpoint);
    } else {
        printf("currently at %d:%d\n", t->pos.line, t->pos.col);
    }
    fflush(stdout);

    // Wenn der Debugger im Stepping-Modus ist, warte auf einen Befehl
    command_t command = no_command;
    
    while (command == no_command && stepping) {
        command = user_eval();
    }

    return command;
}