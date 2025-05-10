#include "turtle-types.h"

/**
 * Der Typ eines Debugger-Befehls
 * Er wird nach jeder Aktion des Debuggers zurückgegeben.
 */
typedef enum command_t {
    no_command, ///< kein Befehl
    step_over,  ///< Über die Funktion hinweg
    step_in,    ///< In die Funktion hinein
    step_out    ///< Aus der Funktion heraus
} command_t;

/**
 * Typ eines Stackframe-Eintrags
 */
typedef struct stacktrace_t {
    const char *name;       ///< Name der Funktion
    srcpos_t pos;           ///< Position im Sourcefile
    vstack_elem_t *frame;   ///< Pointer auf den Stackframe
} stacktrace_t;

command_t debug_loop(const treenode_t *t);

void debug_init(bool debug);

void push_stacktrace(stacktrace_t *t);

void pop_stacktrace();