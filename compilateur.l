%option nounput
%option noyywrap
%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include "y.tab.h"
  
  //string      \".*\"
%}

int         [1-9]?[0-9]+
float       [0-9]+"."[0-9]+(E[+-][0-9]+)?
comment     "/*"[*]*[^/*]*"*/"
string      \"(\\.|[^\\"])*\"
id          [a-zA-Z_]+[0-9a-zA-Z_]*

%%

{int}          { yylval.value = atoi(yytext); return INT; }
{float}        { yylval.value = atof(yytext); return FLOAT; }
{string}       { yylval.string = strdup(yytext); return STRING; }
"++"           { return PLUSPLUS; }
"--"           { return MOINSMOINS; }
">"            { yylval.string = yytext; return SUP; }
"<"            { yylval.string = yytext; return INF; }
"!="           { yylval.string = yytext; return DIFF; }
">="           { yylval.string = yytext; return SUPEQ; }
"<="           { yylval.string = yytext; return INFEQ; }
"=="           { yylval.string = yytext; return EQUAL; }
"||"           { return OR; }
&&             { return AND; }
!              { return NOT; }
if             { return IF; }
else           { return ELSE; }
while          { return WHILE; }
for            { return FOR; }
"int"          { yylval.string = strdup(yytext); return TYPE;}
"float"        { yylval.string = strdup(yytext); return TYPE;}
"matrix"       { yylval.string = strdup(yytext); return TYPE;}
"main"         { return MAIN; }
"print"        { return PRINT; }
"printf"       { return PRINTF; }
"printmat"     { return PRINTMAT; }
"return"       { return RETURN; }
{comment}      {}
[-,{}()+*/;~=] { return yytext[0]; }
\[             { return yytext[0]; }
\]             { return yytext[0]; }
[\n]           {}
[ ]            {}
{id}           { yylval.string = strdup(yytext); return ID; }

%%

//Free the memory fox Lex when we are done
// void lex_free(){
//   yy_delete_buffer(YY_CURRENT_BUFFER);
//   free(yy_buffer_stack);
// }