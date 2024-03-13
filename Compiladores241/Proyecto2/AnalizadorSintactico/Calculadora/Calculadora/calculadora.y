%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%

calc: expr { printf("%d\n", $1); }
    ;

expr: expr '+' expr  { $$ = $1 + $3; }
    | expr '-' expr  { $$ = $1 - $3; }
    | expr '*' expr  { $$ = $1 * $3; }
    | expr '/' expr  { $$ = $1 / $3; }
    | '(' expr ')'   { $$ = $2; }
    | NUM            { $$ = $1; }
    ;

%%

int main() {
    yyparse();
    return 0;
}
