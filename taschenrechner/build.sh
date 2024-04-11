#!/bin/bash

# Shellscript zum Kompilieren des lex & yacc Taschenrechners unter Linux
# Klaus Kusche, 2002

bison -d cal.y
flex cal.lex
gcc -o cal lex.yy.c cal.tab.c -lm -lfl
