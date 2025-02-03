
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

    bool debug = strcmp(argv[2], "-d") == 0;

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

    evaluate(parse(), argc - 2 - debug, &(argv[2 + debug]), debug);

    exit(EXIT_SUCCESS);
}
