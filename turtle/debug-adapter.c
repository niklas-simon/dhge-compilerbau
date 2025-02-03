#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef __linux__
#define NEWLINE "\n"
#endif

#ifdef _WIN32
#define NEWLINE "\r\n"
#endif

void print_hex(char *str, int len) {
    for (int i = 0; i < len; i++) {
        printf("%2x ", str[i]);
        if (i % 16 == 15) {
            printf("\n");
        }
    }
    printf("\n");
}

void read_request() {
    printf("awaiting request...\n");
    char *line;
    size_t buffer_len = 0u;
    int line_len;
    int request_len = 0;
    // Wait for Header request
    while ((line_len = getline(&line, &buffer_len, stdin)) != -1)
    {
        if (sscanf(line, "Content-Length: %d" NEWLINE, &request_len) != 1) {
            printf("malformatted request\n");
            return;
        }
        if (request_len) {
            break;
        }
    }
    // Next Line should be \r\n
    while ((line_len = getline(&line, &buffer_len, stdin)) != -1)
    {
        if (strcmp(line, NEWLINE) != 0) {
            printf("malformatted request\n");
            return;
        }
        break;
    }
    // Next lines contain request body
    char *body = (char *)malloc((request_len + 1) * sizeof(char));
    int cursor = 0;
    while (cursor < request_len && (line_len = getline(&line, &buffer_len, stdin)) != -1)
    {
        strcpy(body + cursor, line);
        cursor += line_len;
        // length assumes use of \r\n -> add it if not present
        if (body[cursor - 1] != '\r') {
            body[cursor - 1] = '\r';
            body[cursor] = '\n';
            cursor++;
        }
    }

    printf("body:\n%s\n", body);
}

void initialize() {
    read_request();
}

/* void main() {
    initialize();
} */