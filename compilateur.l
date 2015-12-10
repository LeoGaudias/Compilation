%option nounput
%option noyywrap
%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include "y.tab.h"
%}

/* type        (int|float|matrix)*/
keyword     (print|printf|printmat|main|return)
int         [1-9]?[0-9]+
float       [0-9]+"."[0-9]+(E[+-][0-9]+)?
comment     "/*"[*]*[^/*]*"*/"
string      \".*\"
id          [a-zA-Z_]+[0-9a-zA-Z_]*

%%

{int}          { yylval.value = atoi(yytext); return NUMBER; }
{float}        { yylval.value = atof(yytext); return NUMBER; }
{string}       { yylval.string = strdup(yytext); return STRING; }
"++"           { yylval.string = strdup(yytext); return PLUSPLUS; }
"--"           { yylval.string = strdup(yytext); return MOINSMOINS; }
">"            { yylval.string = strdup(yytext); return SUP; }
"<"            { yylval.string = strdup(yytext); return INF; }
"!="           { yylval.string = strdup(yytext); return DIFF; }
">="           { yylval.string = strdup(yytext); return SUPEQ; }
"<="           { yylval.string = strdup(yytext); return INFEQ; }
"=="           { yylval.string = strdup(yytext); return EQUAL; }
"||"           { yylval.string = strdup(yytext); return OR; }
&&             { yylval.string = strdup(yytext); return AND; }
!              { yylval.string = strdup(yytext); return NOT; }
if             { yylval.string = strdup(yytext); return IF; }
else           { yylval.string = strdup(yytext); return ELSE; }
while          { yylval.string = strdup(yytext); return WHILE; }
for            { yylval.string = strdup(yytext); return FOR; }
"int"          { yylval.string = strdup(yytext); return TYPE;}
"float"        { yylval.string = strdup(yytext); return TYPE;}
"matrix"       { yylval.string = strdup(yytext); return TYPE;}
{keyword}      { return yytext[0]; /*yylval.string = strdup(yytext); return KEYWORD;*/ }
{comment}      { return yytext[0]; }
[-,{}()+*/;~=] { return yytext[0]; }
\[             { return yytext[0]; }
\]             { return yytext[0]; }
[\n]           {}
[ ]            {}
{id}           { yylval.string = strdup(yytext); return ID; }

%%


/*
ANCIENNE VERSION
option nounput
option noyywrap
{
  #include <stdio.h>
  #include <string.h>
  #include "y.tab.h"
}

type        (int|float|matrix)
identifier  [a-zA-Z_]+[0-9a-zA-Z_]*
int         [1-9]?[0-9]+
float       [1-9]?[0-9]+\.[0-9]+
comment     "/*"[^\*]*[\*]+[^/\*]*[^\*]*[\*]+"/"
%%

{identifier}  { yylval.string = strdup(yytext); return ID; }
{int}         { yylval.value = atoi(yytext); return INT; }
{float}       { yylval.value = atoi(yytext); return FLOAT; }
{type}        { yyval.string = strdup(yytext); return TYPE;}
{comment}     { return yytext[0]; }
[{}()+/*-;~=] { return yytext[0]; }
\[            { return yytext[0]; }
\]            { return yytext[0]; }
[\n]          { return yytext[0]; }
printf        { return PRINTF; }
printmat      { return PRINTMAT; }
main          { return MAIN; }
return        { return RETURN; }

*/