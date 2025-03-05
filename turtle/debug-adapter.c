#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debug-adapter.h"
#include "turtle-types.h"
#include "turtle.h"

bool debug = false;
bool running = false;
bool stepping = false;

int breakpoints[1024];
size_t br_length = 0;

stacktrace_t *stacktrace[128];
size_t stack_size = 0;

srcpos_t current_pos;

void push_stacktrace(stacktrace_t *t) {
    stacktrace[stack_size++] = t;
}

void pop_stacktrace() {
    free(stacktrace[--stack_size]);
}

/**
 * Reads characters from line into arg until reading either '\0', ' ' or '\n'
 * Returns pointer to separator
 */
char *get_arg(char *line, char *arg, size_t arg_len) {
    char *line_ptr = line;
    for (int i = 0; i < arg_len - 1; i++) {
        if (*line_ptr == '\0' || *line_ptr == ' ' || *line_ptr == '\n') {
            arg[i] = '\0';
            return line_ptr;
        }
        arg[i] = *(line_ptr++);
    }

    arg[arg_len - 1] = '\0';

    return line_ptr;
}

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

command_t user_eval() {
    char *line = NULL;
    int n = 0;
    int size = getline(&line, &n, stdin);

    char command[16];
    char *line_ptr = line;
    line_ptr = get_arg(line_ptr, command, 16) + 1;

    if (strcmp(command, "break") == 0 || strcmp(command, "b") == 0) {
        if (line_ptr >= line + size) {
            printf("invalid option. Type help for more information\n");
            fflush(stdout);
            return no_command;
        }
        char arg[8];
        line_ptr = get_arg(line_ptr, arg, 8);
        int linenr = atoi(arg);
        if (linenr <= 0) {
            printf("invalid option. Type help for more information\n");
            fflush(stdout);
            return no_command;
        }
        breakpoints[br_length++] = linenr;
        printf("new breakpoint at line %d\n", linenr);
        fflush(stdout);
        return no_command;
    } 
    if (strcmp(command, "rbreak") == 0 || strcmp(command, "rb") == 0) {
        if (line_ptr >= line + size) {
            br_length = 0;
            printf("removed all breakpoints\n");
            fflush(stdout);
            return no_command;
        }
        char arg[8];
        line_ptr = get_arg(line_ptr, arg, 8);
        int linenr = atoi(arg);
        if (linenr <= 0) {
            printf("invalid option. Type help for more information\n");
            fflush(stdout);
            return no_command;
        }
        int index = 0;
        for (; index < br_length; index++) {
            if (breakpoints[index] == linenr) {
                break;
            }
        }
        if (index >= br_length) {
            printf("breakpoint at line %d not found\n", linenr);
            fflush(stdout);
            return no_command;
        }
        for (int i = index + 1; i < br_length; i++) {
            breakpoints[i - 1] = breakpoints[i];
        }
        br_length--;
        printf("removed breakpoint at line %d\n", linenr);
        fflush(stdout);
        return no_command;
    } 
    if (strcmp(command, "evaluate") == 0 || strcmp(command, "ev") == 0) {
        if (line_ptr >= line + size) {
            printf("invalid option. Type help for more information\n");
            fflush(stdout);
            return no_command;
        }
        char arg[8];
        line_ptr = get_arg(line_ptr, arg, 8) + 1;
        int frame_index = atoi(arg);

        if (frame_index >= stack_size) {
            printf("unknown frameId (%d)\n", frame_index);
            fflush(stdout);
            return no_command;
        }

        vstack_elem_t *frame = stacktrace[frame_index]->frame;
        vstack_elem_t *stack_top = get_stack_top();
        frame++;

        if (line_ptr >= line + size) {
            printf("invalid option. Type help for more information\n");
            fflush(stdout);
            return no_command;
        }

        char name[32];
        line_ptr = get_arg(line_ptr, name, 32);

        if (name[0] == '@') {
            for (int i = 0; i < MAX_NAMES && name_tab[i].name; i++) {
                if (strcmp(name_tab[i].name, name) == 0) {
                    double val;
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
    if (strcmp(command, "exit") == 0 || strcmp(command, "e") == 0) {
        printf("exited\n");
        exit(EXIT_SUCCESS);
    }
    if (strcmp(command, "help") == 0 || strcmp(command, "h") == 0) {
        print_help();
        return no_command;
    }
    if (strcmp(command, "run") == 0 || strcmp(command, "r") == 0) {
        if (running) {
            stepping = false;
        } else {
            running = true;
        }
        return no_command;
    }
    if (strcmp(command, "stacktrace") == 0 || strcmp(command, "st") == 0) {
        for (int i = stack_size - 1; i >= 0; i--) {
            srcpos_t pos = i == stack_size - 1 ? current_pos : stacktrace[i + 1]->pos;
            printf("%d %s %d:%d\n", i, stacktrace[i]->name, pos.line, pos.col);
            fflush(stdout);
        }
        return no_command;
    }
    if (strcmp(command, "step") == 0 || strcmp(command, "s") == 0) {
        if (!running) {
            running = true;
            stepping = true;
        }
        if (line_ptr >= line + size) {
            return step_over;
        }
        char arg[8];
        line_ptr = get_arg(line_ptr, arg, 8);
        if (strcmp(arg, "over") == 0) {
            return step_over;
        }
        if (strcmp(arg, "in") == 0) {
            return step_in;
        }
        if (strcmp(arg, "out") == 0) {
            return step_out;
        }
        printf("invalid option. Type help for more information\n", arg);
        fflush(stdout);
        return no_command;
    }
    if (strcmp(command, "variables") == 0 || strcmp(command, "v") == 0) {
        if (line_ptr >= line + size) {
            printf("invalid option. Type help for more information\n");
            fflush(stdout);
            return no_command;
        }
        char arg[8];
        line_ptr = get_arg(line_ptr, arg, 8);
        int frame_index = atoi(arg);

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

void debug_init(bool _debug) {
    debug = _debug;
    if (!debug) {
        return;
    }

    printf("debugger active. type help for a list of commands\n");
    fflush(stdout);

    while (!running) {
        user_eval();
    }
}

command_t debug_loop(const treenode_t *t) {
    if (!debug) {
        return no_command;
    }

    if (current_pos.line == t->pos.line) {
        return no_command;
    }

    current_pos = t->pos;

    int current_breakpoint = -1;
    for (int i = 0; i < br_length; i++) {
        if (breakpoints[i] == t->pos.line) {
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

    command_t command = no_command;
    
    while (command == no_command && stepping) {
        command = user_eval();
    }

    return command;
}