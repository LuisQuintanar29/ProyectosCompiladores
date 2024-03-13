%{
#include "calculadora.tab.h"
%}

DIGIT   [0-9]
ESPACIO      [ \t\n]

%%
{DIGIT}+    { yylval = atoi(yytext); return NUM; }
{ESPACIO}        ;
[+\-*/()]   { return *yytext; }
.           { fprintf(stderr, "Caracter no válido: %s\n", yytext); }

%%
