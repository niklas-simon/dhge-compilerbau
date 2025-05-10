%{
    #include "turtle-types.h"
    #include "turtle.h"
    #include "turtle.tab.h"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <errno.h>

    treenode_t *root;

    extern FILE *yyin;
    extern FILE *src_file;

    extern int yylineno;
    extern char *yytext;

    extern int yylex();
    int yyerror(char *);

    treenode_t *new_node(type_t type, YYLTYPE loc);
%}

%locations

%union {
    treenode_t *node;
    double number;
    type_t type;
    nameentry_t *var;
    params_t params;
    args_t args;
};

%token <number> TNUMBER
%token <var> TVAR
%token TBEGIN TEND TWALK TJUMP TTURN TBACK THOME TLEFT TRIGHT TDIR TCOLOR TCLEAR TSTOP TFINISH TCOMMA TSTORE TIN TADD TTO TSUB TFROM TMUL TBY TDIV TMARK TEQ TNEQ TLT TLE TGT TGE TOBR TCBR TIF TTHEN TELSE TENDIF TDO TTIMES TDONE TCOUNTER TDOWNTO TSTEP TWHILE TREPEAT TUNTIL TPATH TENDPATH TCALC TRETURNS TENDCALC TABS

%type <node> Statement Statements OStatements Program Expression Condition
%type <type> WMode WUMode TMode CounterMode
%type <params> Params BRParams OParams
%type <args> Args OArgs BRArgs

%left TPLUS TMINUS
%left TSTAR TDASH
%right TPOW

%left TOR
%left TAND
%right TNOT

%start Program

%%
Program:
    Definitions TBEGIN Statements TEND {
        root = $3;
    }
OStatements: /* Optional Statements */
    /* empty */ {
        $$ = NULL;
    }
    |Statements {
        $$ = $1;
    }
Statements:
    Statement Statements {
        $1->next = $2;  /* Link next pointer of first statement to following statements */
        $$ = $1;        /* Return the first statement */
    }
    |Statement {
        $$ = $1;
    }
Statement:
    TWALK WMode Expression {
        $$ = new_node(keyw_walk, @$);
        $$->d.walk = $2;
        $$->son[0] = $3;
    }
    |TWALK WUMode {
        $$ = new_node(keyw_walk, @$);
        $$->d.walk = $2;
    }
    |TJUMP WMode Expression {
        $$ = new_node(keyw_jump, @$);
        $$->d.walk = $2;
        $$->son[0] = $3;
    }
    |TJUMP WUMode {
        $$ = new_node(keyw_jump, @$);
        $$->d.walk = $2;
    }
    |TTURN TMode Expression {
        $$ = new_node($2, @$);
        $$->son[0] = $3;
    }
    |TDIR Expression {
        $$ = new_node(keyw_direction, @$);
        $$->son[0] = $2;
    }
    |TCOLOR Expression TCOMMA Expression TCOMMA Expression {
        $$ = new_node(keyw_color, @$);
        $$->son[0] = $2;
        $$->son[1] = $4;
        $$->son[2] = $6;
    }
    |TCLEAR {
        $$ = new_node(keyw_clear, @$);
    }
    |TSTOP {
        $$ = new_node(keyw_stop, @$);
    }
    |TFINISH {
        $$ = new_node(keyw_finish, @$);
    }
    |TSTORE Expression TIN TVAR {
        $$ = new_node(keyw_store, @$);
        $$->d.p_name = $4;
        $$->son[0] = $2;
    }
    |TADD Expression TTO TVAR {
        $$ = new_node(keyw_add, @$);
        $$->d.p_name = $4;
        $$->son[0] = $2;
    }
    |TSUB Expression TFROM TVAR {
        $$ = new_node(keyw_sub, @$);
        $$->d.p_name = $4;
        $$->son[0] = $2;
    }
    |TMUL TVAR TBY Expression {
        $$ = new_node(keyw_mul, @$);
        $$->d.p_name = $2;
        $$->son[0] = $4;
    }
    |TDIV TVAR TBY Expression {
        $$ = new_node(keyw_div, @$);
        $$->d.p_name = $2;
        $$->son[0] = $4;
    }
    |TMARK {
        $$ = new_node(keyw_mark, @$);
    }
    |TIF Condition TTHEN Statements TENDIF {
        $$ = new_node(keyw_if, @$);
        $$->son[0] = $2;
        $$->son[1] = $4;
        $$->son[2] = NULL;
    }
    |TIF Condition TTHEN Statements TELSE Statements TENDIF {
        $$ = new_node(keyw_if, @$);
        $$->son[0] = $2;
        $$->son[1] = $4;
        $$->son[2] = $6;
    }
    |TDO Expression TTIMES Statements TDONE {
        $$ = new_node(keyw_do, @$);
        $$->son[0] = $2;
        $$->son[1] = $4;
    }
    |TCOUNTER TVAR TFROM Expression CounterMode Expression TDO Statements TDONE {
        $$ = new_node(keyw_counter, @$);
        $$->d.p_name = $2; /* Name of the counter variable */
        $$->son[0] = $4;   /* Start value */
        if ($5 == keyw_countto) { /* Son 1 => value if "to", Son 2 => value if "downto" */
            $$->son[1] = $6;
            $$->son[2] = NULL;
        } else {
            $$->son[1] = NULL;
            $$->son[2] = $6;
        }
        $$->son[3] = NULL; /* Son 3 is reserved for step => in this case no step */
        $$->son[4] = $8;   /* Statements to be executed */
    }
    |TCOUNTER TVAR TFROM Expression CounterMode Expression TSTEP Expression TDO Statements TDONE {
        $$ = new_node(keyw_counter, @$);
        $$->d.p_name = $2; /* Name of the counter variable */
        $$->son[0] = $4;   /* Start value */
        if ($5 == keyw_countto) { /* Son 1 => value if "to", Son 2 => value if "downto" */
            $$->son[1] = $6;
            $$->son[2] = NULL;
        } else {
            $$->son[1] = NULL;
            $$->son[2] = $6;
        }
        $$->son[3] = $8;  /* Step value */
        $$->son[4] = $10; /* Statements to be executed */
    }
    |TWHILE Condition TDO Statements TDONE {
        $$ = new_node(keyw_while, @$);
        $$->son[0] = $2;
        $$->son[1] = $4;
    }
    |TREPEAT Statements TUNTIL Condition {
        $$ = new_node(keyw_repeat, @$);
        $$->son[0] = $4;
        $$->son[1] = $2;
    }
    |TPATH TVAR OArgs {
        $$ = new_node(keyw_path, @$);
        $$->d.p_name = $2; /* Name of the function */
        
        /* If arguments exist, add them as sons */
        if ($3) { 
            for (int i = 0; i < MAX_ARGS; i++) {
                $$->son[i] = $3[i];
            }
        }
    }
OArgs:
    /* empty */ {
        for (int i = 0; i < MAX_ARGS; i++) {
            $$[i] = NULL;
        }
    }
    |BRArgs {
        for (int i = 0; i < MAX_ARGS; i++) {
            $$[i] = $1[i];
        }
    }
BRArgs: /* Bracketed arguments */
    TOBR TCBR { /* empty brackets */
        for (int i = 0; i < MAX_ARGS; i++) {
            $$[i] = NULL;
        }
    }
    |TOBR Args TCBR {
        for (int i = 0; i < MAX_ARGS; i++) {
            $$[i] = $2[i];
        }
    }
Args:
    Args TCOMMA Expression {
        int i;
        for (i = 0; i < MAX_ARGS && $1[i]; i++) {
            $$[i] = $1[i];
        }
        if (i >= MAX_ARGS) {
            yyerror("too many arguments!");
        }
        $$[i] = $3;
    }
    |Expression {
        $$[0] = $1;
        for (int i = 1; i < MAX_ARGS; i++) {
            $$[i] = NULL;
        }
    }
Expression:
    TNUMBER {
        $$ = new_node(oper_const, @$);
        $$->d.val = $1;
    }
    |TVAR { /* Variable */
        $$ = new_node(name_any, @$);
        $$->d.p_name = $1;
    }
    |TVAR BRArgs { /* Function call */
        $$ = new_node(oper_lpar, @$);
        $$->d.p_name = $1;
        for (int i = 0; i < MAX_ARGS; i++) {
            $$->son[i] = $2[i];
        }
    }
    |Expression TPLUS Expression {
        $$ = new_node(oper_add, @$);
        $$->son[0] = $1;
        $$->son[1] = $3;
    }
    |Expression TMINUS Expression {
        $$ = new_node(oper_sub, @$);
        $$->son[0] = $1;
        $$->son[1] = $3;
    }
    |Expression TSTAR Expression {
        $$ = new_node(oper_mul, @$);
        $$->son[0] = $1;
        $$->son[1] = $3;
    }
    |Expression TDASH Expression {
        $$ = new_node(oper_div, @$);
        $$->son[0] = $1;
        $$->son[1] = $3;
    }
    |Expression TPOW Expression {
        $$ = new_node(oper_pow, @$);
        $$->son[0] = $1;
        $$->son[1] = $3;
    }
    |TMINUS Expression {
        $$ = new_node(oper_neg, @$);
        $$->son[0] = $2;
    }
    |TOBR Expression TCBR {
        $$ = $2;
    }
    |TABS Expression TABS {
        $$ = new_node(oper_abs, @$);
        $$->son[0] = $2;
    }
WMode: /* Walk Mode (With following expression)*/
    /* empty */ {
        $$ = keyw_walk;
    }
    |TBACK {
        $$ = keyw_back;
    }
WUMode: /* Walk Mode (Without following expression, e.g. "home" and "mark")*/ 
    THOME {
        $$ = keyw_home;
    }
    |TMARK {
        $$ = keyw_mark;
    }
TMode: /* Turn Mode */
    /* empty */ {
        $$ = keyw_right;
    }
    |TLEFT {
        $$ = keyw_left;
    }
    |TRIGHT {
        $$ = keyw_right;
    }
Condition:
    TNOT Condition {
        $$ = new_node(keyw_not, @$);
        $$->son[0] = $2;
    }
    |Condition TAND Condition {
        $$ = new_node(keyw_and, @$);
        $$->son[0] = $1;
        $$->son[1] = $3;
    }
    |Condition TOR Condition {
        $$ = new_node(keyw_or, @$);
        $$->son[0] = $1;
        $$->son[1] = $3;
    }
    |Expression TEQ Expression {
        $$ = new_node(oper_equ, @$);
        $$->son[0] = $1;
        $$->son[1] = $3;
    }
    |Expression TNEQ Expression {
        $$ = new_node(oper_nequ, @$);
        $$->son[0] = $1;
        $$->son[1] = $3;
    }
    |Expression TLT Expression {
        $$ = new_node(oper_less, @$);
        $$->son[0] = $1;
        $$->son[1] = $3;
    }
    |Expression TLE Expression {
        $$ = new_node(oper_lequ, @$);
        $$->son[0] = $1;
        $$->son[1] = $3;
    }
    |Expression TGT Expression {
        $$ = new_node(oper_grtr, @$);
        $$->son[0] = $1;
        $$->son[1] = $3;
    }
    |Expression TGE Expression {
        $$ = new_node(oper_gequ, @$);
        $$->son[0] = $1;
        $$->son[1] = $3;
    }
    |TOBR Condition TCBR {
        $$ = $2;
    }
CounterMode:
    TTO {
        $$ = keyw_countto;
    }
    |TDOWNTO {
        $$ = keyw_downto;
    }
Definitions:
    /* empty */
    |Definition Definitions
Definition:
    // not a statement -> will not get into actual tree -> save in name_tab
    TPATH TVAR OParams Statements TENDPATH {
        funcdef_t *func = (funcdef_t *)malloc(sizeof(funcdef_t));
        func->body = $4;
        func->ret = NULL; // Path functions have no return value
        if ($3) {
            for (int i = 0; i < MAX_ARGS; i++) {
                func->params[i] = $3[i];
            }
        }
        $2->d.func = func;
        $2->type = name_path;
    }
    |TCALC TVAR BRParams OStatements TRETURNS Expression TENDCALC {
        funcdef_t *func = (funcdef_t *)malloc(sizeof(funcdef_t));
        func->body = $4;
        func->ret = $6;
        if ($3) {
            for (int i = 0; i < MAX_ARGS; i++) {
                func->params[i] = $3[i];
            }
        }
        $2->d.func = func;
        $2->type = name_calc;
    }
OParams:
    /* empty */ {
        for (int i = 0; i < MAX_ARGS; i++) {
            $$[i] = NULL;
        }
    }
    |BRParams {
        for (int i = 0; i < MAX_ARGS; i++) {
            $$[i] = $1[i];
        }
    }
BRParams: /* Bracketed parameters */
    TOBR TCBR { /* empty brackets */
        for (int i = 0; i < MAX_ARGS; i++) {
            $$[i] = NULL;
        }
    }
    |TOBR Params TCBR {
        for (int i = 0; i < MAX_ARGS; i++) {
            $$[i] = $2[i];
        }
    }
Params:
    Params TCOMMA TVAR {
        int i;
        for (i = 0; i < MAX_ARGS && $1[i]; i++) {
            if ($1[i] && strcmp($1[i]->name, $3->name) == 0) {
                yyerror("Duplicate params!");
            }

            $$[i] = $1[i];
        }
        if (i >= MAX_ARGS) {
            yyerror("too many params!");
        }
        $$[i] = $3;
    }
    |TVAR {
        $$[0] = $1;
        for (int i = 1; i < MAX_ARGS; i++) {
            $$[i] = NULL;
        }
    }
%%

void update_location() {
    yylloc.first_line = yylloc.last_line;
    yylloc.first_column = yylloc.last_column;
    for(int i = 0; yytext[i] != '\0'; i++) {
        if(yytext[i] == '\n') {
            yylloc.last_line++;
            yylloc.last_column = 0;
        }
        else {
            yylloc.last_column++;
        }
    }
}

/**
 * Erstellt einen neuen Knoten und initialisiert ihn auf den übergebenen Typ.
 * Der Knoten hat zunächst keine Kinder und ist nicht mit einem anderen Knoten verbunden.
 * Zusätzlich wird die Position des Knotens im Quelltext gesetzt.
 *
 * @param type Der Typ des Knotens.
 * @param loc  Die Position des Knotens im Quelltext.
 * @return Ein Pointer auf den neu erstellten Knoten.
 */
treenode_t *new_node(type_t type, YYLTYPE loc) {
    treenode_t *node = (treenode_t *)malloc(sizeof(treenode_t));

    if (node == NULL) {
        fprintf(stderr, "Error allocating memory for a new node: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    
    node->type = type;
    node->pos = (srcpos_t) {
        .line = loc.first_line,
        .col = loc.first_column
    };
    node->next = NULL;

    for (int i = 0; i < MAX_ARGS; i++) {
        node->son[i] = NULL;
    }

    node->d.val = 0;

    return node;
}

// Die Funktion yyerror wird aufgerufen,
// wenn yacc erkennt, das der eingetippte Input fehlerhaft ist
// wir geben einfach die von yacc gelieferte Fehlermeldung aus
int yyerror(char *s) {
    printf("line %d: %s\n", yylineno, s);
    exit(EXIT_FAILURE);
}

// Das Hauptprogramm
// Wir rufen einfach die von yacc generierte Parser-Funktion auf
treenode_t *parse(void) {
    yyin = src_file;

    yyparse();

    return root;
}
