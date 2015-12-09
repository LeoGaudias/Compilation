%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "matrix.h"
  #include "quad.h"
  #include "symbol.h"

  struct symbol* tds = NULL;
  struct quad* code = NULL;

  int yylex();
  int yyerror(char *);
%}

%union {
  
    int Int;
    float Float;
    char* string;
    
    struct {
      int valueI;
      float valueF;
      char* name;
    } identifier;
    
    struct {
        struct symbol *result;
        struct quad* code;
    } codegen;
}

%token <identifier> ID
%token <Int> INT
%token <Float> FLOAT
%token <string> STRING
%token <string> TYPE
%token <string> KEYWORD

%type <Int> boolean
%type <identifier> affect
%type <codegen> axiom expr

//operation soit int ou float --> donc faire un type spécifique ...s

%right '='
%left '+' '-'
%left '*' '/'
%left "++" "--" UMOINS // est-ce que ++ et -- sont bien placées ?

%%

axiom : 
    expr ';' axiom  { printf("match expr ';' axiom !\n");}
  | '\n'            { printf("match backslash n !\n");}
  | '\n' axiom      { printf("match backslash n axiom !\n");}
  | {/*empty*/}
  ;

expr : 
  | ID '=' operation  {$1 = $3; $$ = $1;}
  | increment         {$$ = $1;}
  | res_keyword       {$$ = $1;}
  ;

operation: 
    operation '+' operation     {$$ = $1 + $3;}
  | operation '-' operation     {$$ = $1 - $3;}
  | operation '*' operation     {$$ = $1 * $3;}
  | operation '/' operation     {$$ = $1 / $3;}
  | '(' operation ')'           {}
  | '-' operation  %prec UMOINS {$$ = -$2;}
  | ID                          {$$ = $1;}
  | INT                         {$$ = $1;}
  | FLOAT                       {$$ = $1;}
  ;

increment : 
    increment "++"  {$$ = $1 + 1;}
  | "++" increment  {$$ = $2 + 1;}
  | increment "--"  {$$ = $1 - 1;}
  | "--" increment  {$$ = $2 - 1;}
  | ID {$$ = $1;}
  ;  
  
res_keyword: 
    KEYWORD '(' STRING ')' {printf($3); $$ = -1;}
  /*| KEYWORD '(' ID ')' {/*printmat(matrix), print}*/
  | KEYWORD '(' INT ')' {printf("%d",$3); $$ = -1;}
  | KEYWORD '(' FLOAT ')' {printf("%f",$3); $$ = -1;}
  | KEYWORD ID {$$ = $2;}
  | KEYWORD INT {$$ = $2;}
  | KEYWORD FLOAT {$$ = $2;}
  | KEYWORD "()" {$$ = -1;}
  /*| KEYWORD '('boolean')' '{' axiom '}' {
                                          if(strcmp($1,"if")){
                                            printf
                                          }
                                          else{
                                          }
                                        }
  | KEYWORD '{' axiom '}' {$$ = $3;}
  | KEYWORD '(' affect ';' boolean ';' increment ')' '{' axiom '}' {for}*/
  ;

/*
 * penser à faire des opé booléennes avec || &&
 * true 1
 * false 0
 */
boolean :
    "!" boolean             {$$ = $2 == 0;}
  | boolean                 {$$ = $1 > 0;}
  | boolean ">" boolean     {$$ = $1 > $3;}
  | boolean "<" boolean     {$$ = $1 < $3;}
  | boolean ">=" boolean    {$$ = $1 >= $3;}
  | boolean "<=" boolean    {$$ = $1 <= $3;}
  | boolean "==" boolean    {$$ = $1 == $3;}
  | boolean "!=" boolean    {$$ = $1 != $3;}
  | ID                      {
                              if(&$1.valueF == NULL){
                                $$ = $1.valueI;
                              }else{
                                $$ = $1.valueF;
                              }
                            }
  | INT                     {$$ = $1;}
  | FLOAT                   {$$ = $1;}
  ;

affect : 
    TYPE ID '=' INT {
                      if(strcmp($1,"int")){
                        $2.valueI = $4;
                        &$2.valueF = NULL;
                        $$ = $2;
                      }else{
                        printf("error type\n");
                        exit(1);
                      }
                    }
  | TYPE ID '=' '-' INT {
                      if(strcmp($1,"int")){
                        $2.valueI = -$4;
                        &$2.valueF = NULL;
                        $$ = $2;
                      }else{
                        printf("error type\n");
                        exit(1);
                      }
                    }
  | TYPE ID '=' FLOAT {
                      if(strcmp($1,"int")){
                        $2.valueF = $4;
                        &$2.valueI = NULL;
                        $$ = $2;
                      }else{
                        printf("error type\n");
                        exit(1);
                      }
                    }
  | TYPE ID '=' '-' FLOAT {
                      if(strcmp($1,"int")){
                        $2.valueF = -$4;
                        &$2.valueI = NULL;
                        $$ = $2;
                      }else{
                        printf("error type\n");
                        exit(1);
                      }
                    }
  /*| TYPE ID id_matrix '=' matrice*/
  ;

/*
matrice : '{' row '}' {}
      ;

row	: '{' '}' 
			| '{' liste_elem '}'
			| '{' liste_elem '}' ',' row
			;

liste_elem : INT ',' liste_elem
      | FLOAT ',' liste_elem
      ;

id_matrix : '['INT']'
      | '['INT']' id_matrix
      ;
*/
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
