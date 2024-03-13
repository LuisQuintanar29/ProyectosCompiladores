%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUM
%token ADD SUB MUL DIV
%token EOL

%left ADD SUB
%left MUL DIV

%%

calc: /* empty */
    | calc expr EOL { printf("Result: %d\n", $2); }
    ;

expr: NUM            { $$ = $1; }
    | expr ADD expr  { $$ = $1 + $3; }
    | expr SUB expr  { $$ = $1 - $3; }
    | expr MUL expr  { $$ = $1 * $3; }
    | expr DIV expr  { $$ = $1 / $3; }
    ;

%%

int main() {
    yyparse();
    return 0;
}

int yyerror(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    return 1;
}
