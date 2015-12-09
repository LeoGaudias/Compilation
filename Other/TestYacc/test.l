%option nounput
%option noyywrap
%{
  #include <stdio.h>
  #include <string.h>
  #include "y.tab.h"
  //type (int|float|matrix)
%}

type        (int|float)
keyword     (print|printf|printmat|main|return|if|else|while|for)
int         [1-9]?[0-9]+
float       [1-9]?[0-9]+\.[0-9]*f? | \.[0-9]+f?
comment     "/*"[*]*[^/*]*"*/"
string      \".*\"
id          [a-zA-Z_]+[0-9a-zA-Z_]*

%%

{int}          { yylval = atoi(yytext); return INT; }
{float}        { yylval = atoi(yytext); return FLOAT; }
{string}       { yylval = strdup(yytext); return STRING; }
{keyword}      { yylval = strdup(yytext); return KEYWORD; }
{type}         { yylval = strdup(yytext); return TYPE;}
{comment}      { return yytext[0]; }
[-,{}()+*/;~=] { return yytext[0]; }
\[             { return yytext[0]; }
\]             { return yytext[0]; }
[\n]           { return yytext[0]; }
[ ]            { return yytext[0]; }
{id}           { yylval.name = strdup(yytext); return ID; }

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