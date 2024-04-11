/* Lex-Definitionen für einen einfachen Taschenrechner */
/* */
/* Klaus Kusche, 2002 */

/* Verarbeitung mehrerer Input-Files ausschalten */
%option noyywrap

/* Das wird oben in den erzeugten C-File hineinkopiert */
%{
/* gemeinsamer Header für lex und yacc mit Typdefinitionen */
#include "global.h"
/* von Yacc erzeugter Header-File mit den Definitionen der Tokens */
#include "cal.tab.h"

#include <stdlib.h>
%}

/* Definitionen von Zeichenfolgen: Links Name, rechts Regular Expression */

/* Whitespace: Ein- oder mehrmals Zwischenraum oder Tab */
white     [ \t]+
/* Ein einzelner Kleinbuchstabe (als Variablen-Name) */
lower     [a-z]
/* Eine einzelne Ziffer */
digit     [0-9]
/* Eine ganze Zahl: Eine oder mehrere Ziffern */
integer   {digit}+
/* Der E-Teil einer Gleitkomma-Zahl */
/* e oder E, optional ein + oder -, eine Zahl */
exponent  [eE][+-]?{integer}
/* Eine komplette Gleitkomma-Zahl: Eine ganze Zahl, */
/* optional gefolgt von . und einer ganzen Zahl */
/* optional gefolgt von einer Exponenten-Angabe */
real      {integer}("."{integer})?{exponent}?


/* lex-Regeln: Wenn das Zeichen oder die Zeichenfolge links gefunden wird, */
/* wird der dahinterstehende C-Code ausgeführt */
/* Er soll das Token als Returnwert liefern */
/* Dabei gibt es zwei globale Variablen: */
/* - yytext (ein char *): Enthält die soeben erkannte Zeichenfolge */
/* - yylval (Typ YYSTYPE, bei uns double): Was man in yylval speichert, */
/*     wird als Nutzdaten im soeben erzeugten Token gespeichert */
%%

{white} {
    /* Kein Code: Whitespace wird einfach ignoriert */
  }

{real} {
    /* Eine Gleitkomma-Zahl: Ihren double-Wert als Token-Nutzdaten speichern */
    yylval = atof(yytext);
    return(NUMBER);
  }

{lower} {
    /* Eine Variable: Ihre Variablen-Nummer als Token-Nutzdaten speichern */
    yylval = ((double) (yytext[0]-'a'));
    return (VAR);
  }

"="  { return(ASSIGN); }
"+"  { return(PLUS); }
"-"  { return(MINUS); }
"*"  { return(TIMES); }
"/"  { return(DIVIDE); }
"^"  { return(POWER); }
"("  { return(LEFT_PARENTHESIS); }
")"  { return(RIGHT_PARENTHESIS); }
"|"  { return(ABS); }
"Sqrt"  { return(SQRT); }
"!"  { return(LAST); }

"\n" { return(END); }

%%

/* Hier könnte Code stehen, der hinten in den erzeugten C-File gehört, */
/* aber wir haben keinen */
