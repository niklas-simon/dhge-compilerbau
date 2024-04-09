// Taschenrechner mit rekursivem Abstieg, Luxusversion
// Programmger�st als Angabe
//
// Aufruf: rechner
// (der Input wird vom Terminal gelesen)
// 
// Klaus Kusche, 2010

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

// Setze das globale c auf das n�chste "echte" Zeichen des Inputs
void nextc(void);
// Gib einen Syntaxfehler an der aktuellen Position aus und beende das Programm
void error(void);
// Lies einen Variablennamen (1 Kleinbuchstabe), liefere dessen Index
int getvar(void);
// Lies eine Gleitkomma-Zahl, ohne Vorzeichen
double value(void);
// Lies einen Operand: Zahl, Variable oder Klammerausdruck,
// |...| f�r Betrag und [...] f�r ganzzahliger Anteil,
// Sqrt(...) als Beispiel f�r eine Funktion,
// oder ! f�r letztes Ergebnis, E f�r Euler'sche Zahl, P f�r Pi
// Alles ev. mit - davor
double operand(void);
// Lies einen Faktor eines Produktes: Ein Operand oder eine Potenz
double factor(void);
// Lies einen Term einer Summe:
// Ein Faktor oder Produkt bzw. Quotient von Faktoren
double term(void);
// Lies einen Ausdruck: Ein Summand oder Summe bzw. Differenz von Summanden
double expr(void);
// Lies, berechne und drucke eine Zeile: Leer, Ausdruck oder Zuweisung
double line(void);


// N�chstes zu bearbeitendes Zeichen (int wegen EOF)
// Das ist unser "1 Zeichen LookAhead"
// Muss am Anfang '\n' sein, um das Lesen der ersten Zeile auszul�sen
int c = '\n';
// Zeilen- und Spaltennummer (f�r Fehlermeldungen)
int lineNr = 0, colNr = 0;

// Speicher f�r die Variablen a-z
double var[26];

// Speicher f�r das Ergebnis der letzten Zeile
double lastVal;

// Setze das globale c auf das n�chste "echte" Zeichen des Inputs:
// �berspringe Zwischenr�ume
// Am Ende des Files ist c die Konstante "EOF"
void nextc(void)
{
    if (c == '\n') {
        ++lineNr;
        colNr = 0;
    }
    do {
        c = getchar();
        ++colNr;
    }
    while ((c == ' ') || (c == '\t'));
    //printf("> reading %c\n", c);
}

// Gib einen Syntaxfehler an der aktuellen Position aus und beende das Programm
void error(void)
{
    if (c == EOF) {
        printf("Line %d: Parse error at end of input\n", lineNr);
    } else if (c == '\n') {
        printf("Line %d, col %d: Parse error at end of line\n", lineNr, colNr);
    } else {
        printf("Line %d, col %d: Parse error before %c\n", lineNr, colNr, c);
    }
    exit(EXIT_FAILURE);
}

// Lies einen Variablennamen (1 Kleinbuchstabe), liefere dessen Index
int getvar(void)
{
    int ind;

    if ((c < 'a') || (c > 'z')) {
        error();
    }
    ind = c - 'a';
    nextc();
    return ind;
}

// Lies eine Gleitkomma-Zahl, ohne Vorzeichen
// <value> ::= <digit> { <digit> } [ . { <digit> } ]
//             [ ( e | E ) [ + | - ] <digit> { < digit> } ]
double value(void)
{
    //printf("> in value\n");
    double val = 0;
    double frac = 0.1;
    int expon = 0;
    int esgn = 1;

    if (!isdigit(c)) {
        error();
    }
    do {
        val = val * 10 + (c - '0');
        nextc();
    } while (isdigit(c));
    if (c == '.') {
        nextc();
        while (isdigit(c)) {
            val += frac * (c - '0');
            frac /= 10;
            nextc();
        }
    }
    if ((c == 'e') || (c == 'E')) {
        nextc();
        if (c == '+') {
            nextc();
        } else if (c == '-') {
            esgn = -1;
            nextc();
        }
        if (!isdigit(c)) {
            error();
        }
        do {
            expon = expon * 10 + (c - '0');
            nextc();
        } while (isdigit(c));
        val *= pow(10.0, ((double) (esgn * expon)));
    }
    return val;
}

// Lies einen Operand: Zahl, Variable oder Klammerausdruck,
// |...| f�r Betrag und [...] f�r ganzzahliger Anteil,
// Sqrt(...) als Beispiel f�r eine Funktion,
// oder ! f�r letztes Ergebnis, E f�r Euler'sche Zahl, P f�r Pi
// Alles ev. mit - davor
// <operand> ::= [ - ] ( ! | E | P | Sqrt "(" <expr> ")" |
//                       "(" <expr> ")" | "|" <expr> "|" | "[" <expr> "]" |
//                       <value> | <var> )
double operand(void)
{
    //printf("> in operand\n");
    double res = 1;
    // [ - ]
    if (c == '-') {
        res *= -1;
        nextc();
    }
    switch (c)
    {
    case '!':
        res *= lastVal;
        nextc();
        break;
    case '(':
        nextc();
        res *= expr();
        if (c != ')') {
            error();
        }
        nextc();
        break;
    case '|':
        nextc();
        res *= abs(expr());
        if (c != '|') {
            error();
        }
        nextc();
        break;
    case '[':
        nextc();
        res *= trunc(expr());
        if (c != ']') {
            error();
        }
        nextc();
        break;
    case '0'...'9':
        res *= value();
        break;
    case 'a'...'z':
        res *= var[getvar()];
        break;
    case 'A'...'Z':
        char buf[9];
        int buf_len = 0;
        while ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            buf[buf_len] = c;
            nextc();
            buf_len++;
            if (buf_len >= 8) {
                break;
            }
        }
        buf[buf_len] = '\0';
        if (c != '(') {
            error();
        }
        nextc();
        // function declarations start here
        if (strcmp(buf, "E") == 0) {
            res *= M_E;
        } else if (strcmp(buf, "P") == 0) {
            res *= M_PI;
        } else if (strcmp(buf, "Sqrt") == 0) {
            res *= sqrt(expr());
        } else {
            error();
        }
        // function declarations end here
        if (c != ')') {
            error();
        }
        nextc();
        break;
    default:
        error();
        break;
    }
    return res;
}

// Lies einen Faktor eines Produktes: Ein Operand oder eine Potenz
// Achtung: ^ bindet von rechts nach links, darum Rekursion, nicht Schleife!
// <factor> ::= <operand> [ ^ <factor> ]
double factor(void)
{
    //printf("> in factor\n");
    double res = operand();
    if (c == '^') {
        nextc();
        res = pow(res, factor());
    }
    return res;
}

// Lies einen Term einer Summe:
// Ein Faktor oder Produkt bzw. Quotient von Faktoren
// <term> ::= <factor> { ( * | / ) <factor> }
double term(void)
{
    //printf("> in term\n");
    double res = factor();
    switch (c)
    {
    case '*':
        nextc();
        res *= factor();
        break;
    case '/':
        nextc();
        double f = factor();
        if (f == 0.0) {
            error();
            break;
        }
        res /= f;
    default:
        break;
    }
    return res;
}

// Lies einen Ausdruck: Ein Summand oder Summe bzw. Differenz von Summanden
// <expr> ::= <term> { ( - | + ) <term> }
double expr(void)
{
    //printf("> in expr\n");
    double res = term();
    switch (c)
    {
    case '-':
        nextc();
        res -= term();
        break;
    case '+':
        nextc();
        res += term();
        break;
    default:
        break;
    }
    return res;
}

// Lies, berechne und drucke eine Zeile: Leer, Ausdruck oder Zuweisung
// <line> ::= [ <expr> [ = <var> ] ]
double line(void)
{
    //printf("> in line\n");
    double res = expr();
    printf("> ");
    if (c == '=') {
        nextc();
        char v = c;
        var[getvar()] = res;
        printf("%c = ", v);
    }
    printf("%f\n", res);
    return res;
}

// Hauptprogramm: Berechne und drucke einen Ausdruck pro Zeile
// ev. mit Zuweisung
// <input> ::= { <line> \n } EOF
int main(void)
{
    while (c != EOF) {
        while (c == '\n') {
            printf("# ");
            nextc();
        }
        if (c == EOF) {
            printf("\n");
            return 0;
        }
        line();
    }
}
