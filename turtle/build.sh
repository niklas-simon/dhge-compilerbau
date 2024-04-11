#!/bin/bash

# Shellscript zum Kompilieren des lex & yacc Taschenrechners unter Linux
# Klaus Kusche, 2002

bison -d turtle.y -Wcounterexamples &&
flex turtle.l &&
gcc -o turtle $(sdl2-config --cflags) sdlinterf.c lex.yy.c turtle.tab.c turtle-eval.c turtle-nametab.c turtle-main.c -lm $(sdl2-config --libs)
