#include "turtle-types.h"

typedef enum command_t {
    no_command,
    step_over,
    step_in,
    step_out
} command_t;

typedef struct stacktrace_t {
    const char *name;
    srcpos_t pos;
    vstack_elem_t *frame;
} stacktrace_t;

command_t debug_loop(const treenode_t *t);

void debug_init(bool debug);

void push_stacktrace(stacktrace_t *t);

void pop_stacktrace();