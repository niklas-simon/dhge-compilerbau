[a-zA-Z_][a-zA-Z0-9_]*{
    yylval.stringVal = strdup(yytext);
    return L_ID; 
}
-?[0-9]+{
    yylval.numVal = atoi(yytext);
    return L_NUM;
}