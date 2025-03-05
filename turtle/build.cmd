bison -d turtle.y
flex turtle.l

gcc lex.yy.c turtle.tab.c turtle-eval.c turtle-nametab.c turtle-main.c sdlinterf.c debug-adapter.c -L.\SDL2\lib -I.\SDL2\include -static -lmingw32 -lSDL2main -lSDL2 -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid -static-libgcc -lhid -lsetupapi -o turtle -g