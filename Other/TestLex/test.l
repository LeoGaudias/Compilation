%option nounput
%option noyywrap
%{
  #include <stdio.h>
  #include <string.h>
%}

type        (int|float|matrix)
keyword     (printf|printmat|main|return)
int         [1-9]?[0-9]+
float       [1-9]?[0-9]+\.[0-9]+ // je pense que c'est plutôt [1-9]?[0-9]+\.[0-9]*f? | \.[0-9]+f? mais y a le problème qu'on a pas les float qui commence avec 0 (ce qui est possible : octal) ...
comment     "/*"[*]*[^/*]*"*/"
string      \".*\"
id          [a-zA-Z_]+[0-9a-zA-Z_]*
%%
{int}          { printf("\nmatch : %s\n",yytext); }
{float}        { printf("\nmatch : %s\n",yytext); }
{string}       { printf("\nmatch : %s\n",yytext); }
{keyword}      { printf("\nmatch : %s\n",yytext); }
{type}         { printf("\nmatch : %s\n",yytext);}
{comment}      { printf("\nmatch : %s\n",yytext); }
[-,{}()+*/;~=] { printf("\nmatch : %s\n",yytext); }
\[             { printf("\nmatch : %s\n",yytext); }
\]             { printf("\nmatch : %s\n",yytext); }
[\n]           {}
[ ]            {}
{id}           { printf("\nmatch : %s\n",yytext); }
%%
int main( int argc, char **argv ){
  ++argv;
  --argc;  /* skip over program name */
  if ( argc > 0 )
  {
    yyin = fopen( argv[0], "r" );
  }
  else
  {
    yyin = stdin;
  }
  yylex();
}