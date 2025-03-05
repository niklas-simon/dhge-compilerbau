#include <stdio.h>
#include "sdlinterf.h"

int main(int argc, char **argv) {
    printf("Hello World!\n");
    sdlInit();
    sdlMilliSleep(10000);
    sdlExit();
    return 0;
}