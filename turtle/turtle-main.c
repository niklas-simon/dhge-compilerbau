
// Turtle-Graphics-Compiler:
// Hauptprogramm und programmweite Hilfsfunktionen
//
// Klaus Kusche 2021, 2022

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>

#include "turtle.h"
#include "debug-adapter.h"

// Global: Der Sourcefile & der Programmname & der Sourcefile-Name
FILE *src_file;
const char *prog_name;
const char *file_name;

// Prüfe ob malloc/calloc/realloc erfolgreich war:
// Fehlermeldung und Programmende wenn p gleich NULL ist
// what ... was wurde gerade angelegt?
// pos ... für welche Stelle im Source?
void mem_check(const void *p, const char *what, const srcpos_t *pos)
{
    if (p == NULL)
    {
        fprintf(stderr, "%s: Fehler beim Anlegen von Speicher für %s "
                        "(Zeile %d, Spalte %d): %s\n",
                prog_name, what, pos->line, pos->col, strerror(errno));
        exit(EXIT_FAILURE);
    }
}

// Ausgabe eines Fehlers im Turtle-Programm an Stelle pos & Programmende
// (mit variabel vielen Parametern wie printf)
void code_error(const srcpos_t *pos, const char *format, ...)
{
    va_list arg_p;

    //  fprintf(stderr, "Fehler in Zeile %d, Spalte %d: ", pos->line, pos->col);
    fprintf(stderr, "%s:%d:%d: ", file_name, pos->line, pos->col);
    va_start(arg_p, format);
    vfprintf(stderr, format, arg_p);
    va_end(arg_p);
    putchar('\n');
    exit(EXIT_FAILURE);
}

int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Aufruf: %s Programm-Datei [-d] [Zahlen ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parsen der Argumente - Kopieren der Zahlen in args und prüfen auf -d
    bool debug = false;
    const char **args = (const char **)malloc((argc - 2) * sizeof(const char *));
    int args_len = 0;
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0) {
            debug = true;
        } else {
            args[args_len++] = argv[i];
        }
    }

    if (argc > 11 + debug)
    {
        fprintf(stderr, "Aufruf: %s Programm-Datei [-d] [Zahlen ...]\n"
                        "Höchstens 9 Zahlen!\n",
                argv[0]);
        exit(EXIT_FAILURE);
    }

    src_file = fopen(argv[1], "r");
    if (src_file == NULL)
    {
        fprintf(stderr, "%s: Fehler beim Öffnen von %s zum Lesen: %s\n",
                argv[0], argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    prog_name = argv[0];
    file_name = argv[1];

    // Parsen des Turtle-Programms und Erzeugen des Syntaxbaums
    treenode_t *main_tree = parse();

    // Prüfen ob ein Syntaxbaum erzeugt wurde
    if (main_tree == NULL) {
        exit(EXIT_FAILURE);
    }

    // Initialisieren des Debug Adapters
    debug_init(debug);

    // Interpretieren des Syntaxbaums
    evaluate(main_tree, args_len, args, debug);

    exit(EXIT_SUCCESS);
}
