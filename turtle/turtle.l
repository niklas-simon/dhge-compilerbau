%option noyywrap
%option yylineno

%{
#include "turtle-types.h"
#include "turtle.h"
/* von Yacc erzeugter Header-File mit den Definitionen der Tokens */
#include "turtle.tab.h"

#include <stdlib.h>
#include <string.h>

%}

%%

[ \t\n]+ {}
"\"".* {}

"begin" return TBEGIN;
"end" return TEND;
"walk" return TWALK;
"jump" return TJUMP;
"turn" return TTURN;
"back" return TBACK;
"home" return THOME;
"left" return TLEFT;
"right" return TRIGHT;
"direction" return TDIR;
"color" return TCOLOR;
"clear" return TCLEAR;
"stop" return TSTOP;
"finish" return TFINISH;
"," return TCOMMA;
"store" return TSTORE;
"in" return TIN;
"add" return TADD;
"to" return TTO;
"sub" return TSUB;
"from" return TFROM;
"mul" return TMUL;
"by" return TBY;
"div" return TDIV;
"mark" return TMARK;
"if" return TIF;
"then" return TTHEN;
"else" return TELSE;
"endif" return TENDIF;
"=" return TEQ;
"<>" return TNEQ;
"<" return TLT;
"<=" return TLE;
">" return TGT;
">=" return TGE;
"not" return TNOT;
"or" return TOR;
"and" return TAND;
"(" return TOBR;
")" return TCBR;
"do" return TDO;
"times" return TTIMES;
"done" return TDONE;
"counter" return TCOUNTER;
"downto" return TDOWNTO;
"step" return TSTEP;
"while" return TWHILE;
"repeat" return TREPEAT;
"until" return TUNTIL;
"path" return TPATH;
"endpath" return TENDPATH;
"calculation" return TCALC;
"returns" return TRETURNS;
"endcalc" return TENDCALC;
"-" return TMINUS;
"+" return TPLUS;
"*" return TSTAR;
"/" return TDASH;
"^" return TPOW;
"|" return TABS;

[0-9]+|[0-9]*\.[0-9]+ {
    yylval.number = (double)atof(yytext);
    return TNUMBER;
}

[@a-zA-Z_][@a-zA-Z0-9_]* {
    type_t type;
    nameentry_t *entry;
    for (int i = 0; i < MAX_NAMES; i++) {
        if (!name_tab[i].name) {
            name_tab[i].name = strdup(yytext);
            name_tab[i].type = yytext[0] == '@' ? name_glob : name_var;
            entry = name_tab + i;
            break;
        }
        if (strcmp(name_tab[i].name, yytext) == 0) {
            entry = name_tab + i;
            break;
        }
    }
    if (!entry) {
        yyerror("too many variables!");
    }
    yylval.var = entry;
    return TVAR;
}
%%