// Yacc-Definition eines einfachen Taschenrechners
//
// Klaus Kusche, 2002

// Das wird oben in den erzeugten .c-File hineinkopiert
%{
// gemeinsamer Header für lex und yacc mit Typdefinitionen
#include "global.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// globale Variable zum Speichern des letzten Ergebnisses
double lastval;

// globales Array zum Speichern der 26 Variablen-Werte
double vars[26];
%}

// Das ist die Liste aller Tokens, die lex liefert
%token ASSIGN
%token PLUS MINUS TIMES DIVIDE POWER
%token SQRT
%token LEFT_PARENTHESIS RIGHT_PARENTHESIS ABS
%token NUMBER LAST VAR
%token END

// Das legt die Vorrangregeln fest (von niedrig nach hoch)
// und auch die Ausrechen-Richtung mehrerer gleicher Operatoren nacheinander
%left  PLUS MINUS
%left  TIMES DIVIDE
// mehrere aufeinanderfolgende ^ werden von rechts nach links ausgerechnet!
%right POWER

// Das legt das äußerste Nonterminal (Startsymbol) der Grammatik fest,
// d.h. das Symbol, das den gesamten Inputfile repräsentiert
%start Input

%%

// Hier kommt die Syntax (als Liste von BNF-Regeln, | für Alternativen).
// Wenn eine Alternative erkannt wird, wird der C-Code in { } ausgeführt
// $$ steht für das Ergebnis des erkannten Nonterminals, d.h. für den Wert,
// der im Symbol auf der linken Seite der Regel gespeichert wird
// $1, $2 usw. steht für den Wert des 1, 2, ... Teilausdruckes,
// d.h. für den Wert, den das i-te Symbol der gewählten Alternative enthält
// Ist das i-te Symbol ein Terminal-Symbol (Token), so ist das der Wert,
// den der Lexer beim Einlesen des Tokens dort gespeichert hat.
// Ist das i-te Symbol ein Nonterminal, so ist das der Wert,
// der beim Erkennen dieses Nonterminals durch eine Regel ausgerechnet wurde.

// der Input besteht aus nichts (bzw. nichts mehr)
// oder aus einer Zeile gefolgt vom restlichen Input
// zu tun ist dabei nichts
Input:
   // Leere Alternative
 | Line Input
 ;

// eine Zeile besteht nur aus einem Newline (leere Zeile)
// oder aus einer Rechnung mit Newline am Ende
// oder aus einer Zuweisung mit Newline am Ende
Line:
   END
 | Expression END
    { lastval = $1; printf("Result: %g\n", lastval); }
 | VAR ASSIGN Expression END
    { vars[((int)($1))] = lastval = $3; printf("Result: %g\n", lastval); }
 ;

// eine Rechnung besteht aus einem einzelnen Operanden
// oder aus zwei Teilrechnungen mit einem Rechenzeichen dazwischen
Expression:
   Operand
    { $$ = $1; }
 | Expression PLUS Expression
    { $$ = $1 + $3; }
 | Expression MINUS Expression
    { $$ = $1 - $3; }
 | Expression TIMES Expression
    { $$ = $1 * $3; }
 | Expression DIVIDE Expression
    { $$ = $1 / $3; }
 | Expression POWER Expression
    { $$ = pow($1, $3); }
 ;

// ein Operand kann sein:
// das ! für das letzte Ergebnis, eine Gleitkommazahl, eine Variable
// eine Rechnung in Klammern oder Betrag-Strichen,
// ein Aufruf der Wurzel-Funktion, oder ein beliebiger Operand mit - davor
Operand:
   LAST
    { $$ = lastval; }
 | NUMBER
    { $$ = $1; }
 | VAR
    { $$ = vars[((int)($1))]; }
 | LEFT_PARENTHESIS Expression RIGHT_PARENTHESIS
    { $$ = $2; }
 | ABS Expression ABS
    { $$ = fabs($2); }
 | SQRT LEFT_PARENTHESIS Expression RIGHT_PARENTHESIS
    { $$ = sqrt($3); }
 | MINUS Operand
    { $$ = -$2; }
 ;

%%

// Das folgende wird an's hintere Ende des erzeugten .c-Programms kopiert

// Die Funktion yyerror wird aufgerufen,
// wenn yacc erkennt, das der eingetippte Input fehlerhaft ist
// wir geben einfach die von yacc gelieferte Fehlermeldung aus
int yyerror(char *s)
{
  printf("%s\n", s);
}

// Das Hauptprogramm
// Wir rufen einfach die von yacc generierte Parser-Funktion auf
int main(void)
{
  yyparse();
}
