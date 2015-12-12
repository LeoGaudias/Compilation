%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "Lib/symbol.h"
  #include "Lib/quad.h"
  #include "Lib/mips.h"
  
  extern FILE *yyin;
  int yylex();
  int yyerror(char *);
  //void lex_free();

  struct symbol* tds = NULL;
  struct quad* code = NULL;
  int nextquad = 0;
%}

%union {
  float value;
  char* string;
  struct symbol* label;
  
  struct {
    char* type;
    float value;
  } num;
    
  struct {
      struct symbol *result;
      struct quad* code;
  } codegen;

  struct {
    struct quad *code;
    struct quad_list* truelist;
    struct quad_list* falselist;
  } code_condition;
  
  struct {
    struct quad *code;
    struct quad_list* nextlist;
  } code_statement;
  
  
  struct {
    struct symbol *quad;
    struct quad *code;
    struct quad_list* nextlist;
  } code_goto;
}

%token PLUSPLUS MOINSMOINS MAIN PRINT PRINTF PRINTMAT RETURN
%token<value> INT FLOAT 

// necessaire aux conditions
%token<string> ID NOT OR AND IF ELSE WHILE FOR STRING TYPE DIFF SUPEQ INFEQ EQUAL SUP INF //KEYWORD

//%type <codegen> matrice row liste_elem

%type<string> op
%type <codegen> expr increment affect1 affect2 list_expr print

%type<code_condition> condition
%type<code_statement> statement list axiom
%type<label> tag
%type<code_goto> tagoto
%type<num> number

%right '='
%left '>' '<' ">=" "<=" "==" "!="
%left '+' '-'
%left '*' '/'
%left PLUSPLUS MOINSMOINS UMOINS

%left OR
%left AND
%left NOT

%%
  
axiom : 
 list { 
        printf("Match\n");
        $$.code = $1.code;
        code = $1.code;
        printf("---TDS---\n");
        symbol_print(tds);
        printf("---CODE---\n");
        quad_print(code);
        //exit(0);
      }
  ;

/* se souvenir qu'on doit pouvoir faire matrix A[2]={3,4}, IA[2]={3,4} */
affect1 :
  TYPE list_expr
          {
            $$.result = $2.result;
            $$.result->type = strdup($1);
            $$.code = $2.code;
            symbol_complete(&tds,$1);
          }
  | affect2 {
              $$.result = $1.result;
              $$.code = $1.code;
            }
//| TYPE ID id_matrix '=' matrice
  ;
  
list_expr :
    ID '=' expr ',' list_expr
                              {
                                struct symbol * affect = symbol_add(&tds, $1);
                                affect->value = $3.result->value;
                                affect->isconstant = false;
                                $$.result = affect;
                                
                                $$.code = concatQuad(quad_gen(&nextquad, "=", $3.result, NULL, affect),$5.code);
                                nextquad++;
                              }
  | ID ',' list_expr {
                      struct symbol * affect = symbol_add(&tds, $1);
                      affect->isconstant = false;
                      $$.result = affect;
                      
                      $$.code = concatQuad(quad_gen(&nextquad, "", NULL, NULL, affect),$3.code);
                      nextquad++;
                    }
                    
  | ID '=' expr {
                  struct symbol * affect = symbol_add(&tds, $1);
                  affect->value = $3.result->value;
                  affect->isconstant = false;
                  $$.result = affect;
                  
                  $$.code = quad_gen(&nextquad, "=", $3.result, NULL, affect);
                  nextquad++;
                }
  | ID {
          struct symbol * affect = symbol_add(&tds, $1);
          affect->isconstant = false;
          $$.result = affect;
          
          $$.code = quad_gen(&nextquad, "", NULL, NULL, affect);
          nextquad++;
        }
  ;
  
affect2 :
  ID '=' expr {
                struct symbol * affect = symbol_lookup(tds, $1);
                affect->value = $3.result->value;
                $$.result = affect;
                
                $$.code = quad_gen(&nextquad, "=", $3.result, NULL, affect);
                nextquad++;
              }
  | increment {
                $$.result = $1.result;
                $$.code = $1.code;
              }
//| TYPE ID id_matrix '=' matrice
  ;

expr :
    expr '+' expr   {   
                        $$.result = symbol_newtemp(&tds);
                        $$.code = $1.code;
                        quad_add(&$$.code, $3.code);
                        quad_add(&$$.code, quad_gen(&nextquad,"+", $1.result, $3.result, $$.result));
                        nextquad++;
                    }
  | expr '-' expr   {   
                        $$.result = symbol_newtemp(&tds);
                        $$.code = $1.code;
                        quad_add(&$$.code, $3.code);
                        quad_add(&$$.code, quad_gen(&nextquad,"-", $1.result, $3.result, $$.result));
                        nextquad++;
                    }
  | expr '*' expr   {   
                        $$.result = symbol_newtemp(&tds);
                        $$.code = $1.code;
                        quad_add(&$$.code, $3.code);
                        quad_add(&$$.code, quad_gen(&nextquad,"*", $1.result, $3.result, $$.result));
                        nextquad++;
                    }
  | expr '/' expr   {   
                        $$.result = symbol_newtemp(&tds);
                        $$.code = $1.code;
                        quad_add(&$$.code, $3.code);
                        quad_add(&$$.code, quad_gen(&nextquad,"/", $1.result, $3.result, $$.result));
                        nextquad++;
                    }
  | '(' expr ')'    {   
                        $$.result = $2.result;
                        $$.code = $2.code;
                    }
  | increment       {$$ = $1;}
  
  | ID              {   
                        $$.result = symbol_add(&tds, $1);
                        $$.code = NULL;
                    }
  | '-' number      {
                        $$.result = symbol_newtemp(&tds);
                        $$.result->type = $2.type;
                        $$.result->value = - $2.value;
                        $$.code = NULL;
                    }
  | number          {   
                        $$.result = symbol_newtemp(&tds);
                        $$.result->type = $1.type;
                        $$.result->value = $1.value;
                        $$.code = NULL;
                    }
  ;
  
number : 
    INT { $$.value=$1; $$.type="int";}
  | FLOAT { $$.value=$1; $$.type="float";}
  ;
// seg fault quand ya id non présent !
increment : 
    ID PLUSPLUS     {
                      struct symbol* temp = symbol_lookup(tds,$1);
                      temp->value += 1;
                      $$.result = temp;
                      $$.code = quad_gen(&nextquad,"++", temp, NULL, $$.result);
                      nextquad++;
                    }
  | PLUSPLUS ID     {
                      struct symbol* temp = symbol_lookup(tds,$2);
                      temp->value += 1;
                      $$.result = temp;
                      $$.code = quad_gen(&nextquad,"++", NULL, temp, $$.result);
                      nextquad++;
                    }
  | ID MOINSMOINS   {
                      struct symbol* temp = symbol_lookup(tds,$1);
                      temp->value -= 1;
                      $$.result = temp;
                      $$.code = quad_gen(&nextquad,"--", temp, NULL , $$.result);
                      nextquad++;
                    }
  | MOINSMOINS ID   {
                      struct symbol* temp = symbol_lookup(tds,$2);
                      temp->value -= 1;
                      $$.result = temp;
                      $$.code = quad_gen(&nextquad,"--", NULL, temp, $$.result);
                      nextquad++;
                    }
  ;
  
  
/*  IA = ~A
  IA = IA[1;0][1;0];
  IA[0][1] = -IA[0][1];
  IA[1][0] = -IA[1][0];*/

// res_keyword: 
//     KEYWORD '(' STRING ')' {/*printf*/}
//   | KEYWORD '(' ID ')' {/*printmat(matrix), print*/}
//   | KEYWORD '(' INT ')' {/*print*/}
//   | KEYWORD '(' FLOAT ')' {/*print*/}
//   | KEYWORD ID {/*return id*/}
//   | KEYWORD INT {/*return int*/}
//   | KEYWORD FLOAT {/*return float*/}
//   | KEYWORD "()" {/*main*/}
//   ;

tag : {
        $$ = symbol_newlabel(&tds, nextquad);
        nextquad++;
      }
  ;
  
tagoto :  {
            $$.code = quad_gen(&nextquad,"goto", NULL, NULL, NULL);
            nextquad++;
            $$.quad = symbol_newlabel(&tds, nextquad);
            nextquad++;
            $$.nextlist = newlist($$.code);
          }
  ;

list : 
  TYPE MAIN '(' ')' '{' list RETURN number ';' '}'  {
                                                      $$.code = $6.code;
                                                      $$.nextlist = $6.nextlist;
                                                    }
  
  | tag statement list {
                          complete($3.nextlist,$1);
                          $$.nextlist = $2.nextlist;
                          $$.code = concatQuad($2.code, $3.code); 
                        }
  | affect1 ';' list
                    {
                      $$.nextlist = newlist($1.code);
                      $$.code = concatQuad($1.code, $3.code);
                    }
  | print ';' list {
                      $$.nextlist = newlist($1.code);
                      // printf("print -- $3.code --");
                      // quad_print($3.code);
                      // printf("endPrint -- $3.code -- \n");
                      $$.code = concatQuad($1.code, $3.code);
                   }
  | {$$.code=NULL;/* empty */}
  ;
  
print:
 PRINT '(' ID ')'
    {
      struct symbol * affect = symbol_lookup(tds, $3);
      $$.code = quad_gen(&nextquad,"print",affect,NULL,NULL);
      $$.result = affect;
      nextquad++;
    }
 |PRINT '(' number ')'
    {
      struct symbol * temp = symbol_newtemp(&tds); 
      temp->type = $3.type;
      temp->value = $3.value;
      $$.code = quad_gen(&nextquad,"print",temp,NULL,NULL);
      $$.result = temp;
      nextquad++;
    }
 | PRINTF '(' STRING ')'
   {
      struct symbol * temp = symbol_newtemp(&tds); 
      temp->type = "string";
      temp->id = strdup($3);
      $$.code = quad_gen(&nextquad,"printf",temp,NULL,NULL);
      $$.result = temp;
      nextquad++;
   }
// |PRINTMAT '('  ')'
  ;
  
statement : 
  IF '(' condition ')' '{' tag list '}'
  
      { 
        complete($3.truelist,$6);
        $$.nextlist=concatList($7.nextlist,$3.falselist);
        $$.code=concatQuad($3.code,$7.code);
      }
      
  | IF '(' condition ')' '{' tag list '}' ELSE '{' tagoto list '}'
  
      { 
        complete($3.truelist,$6);
        complete($3.falselist,$11.quad);
        $$.nextlist=concatList(concatList($7.nextlist,$12.nextlist),$11.nextlist);
        $$.code=concatQuad(concatQuad(concatQuad($3.code,$7.code),$11.code),$12.code);
      }
      
  | WHILE tag '(' condition ')' '{' tag list '}'  
  
      { 
        complete($4.truelist,$7);
        complete($8.nextlist,$2);
        $$.nextlist=$4.falselist;
        $$.code=concatQuad(concatQuad($4.code,$8.code),quad_gen(&nextquad,"goto",NULL,NULL,$2));
        nextquad++;
      }
  
  | FOR '(' affect1 ';' tag condition ';' affect2 ')' '{' tag list '}'  
      
      { 
        complete($6.truelist,$11);
        complete($12.nextlist,$5);
        $$.nextlist=$6.falselist;
        $$.code=concatQuad(concatQuad($6.code,$12.code),quad_gen(&nextquad,"goto",NULL,NULL,$5));
        nextquad++;
      }
  ;
  
condition : 
    condition OR tag condition       { 
                                        symbol_print(tds);
                                        complete($1.falselist,$3);
                                        
                                        $$.code = $1.code;
                                        
                                        quad_add(&$$.code, $4.code);
                                        
                                        $$.falselist = $4.falselist;
                                        $$.truelist = $1.truelist;
                                        
                                        concatList($$.truelist,$4.truelist);
                                     }
  | condition AND tag condition      {
                                        complete($1.truelist,$3);
                                        $$.code = $1.code;
                                        quad_add(&$$.code, $4.code);
                                        $$.falselist = $4.falselist;
                                        $$.truelist = $1.truelist;
                                        concatList($$.falselist,$4.truelist);
                                        
                                     }
  | NOT condition                    {
                                        $$.code = $2.code;
                                        $$.truelist = $2.falselist;
                                        $$.falselist = $2.truelist;
                                     }
  | '(' condition ')'               {
                                        $$.code = $2.code;
                                        $$.truelist = $2.truelist;
                                        $$.falselist = $2.falselist;
                                    }
  | expr op expr                    {
                                      $$.code = NULL;
                                      
                                      struct quad* goto_true = quad_gen(&nextquad, $2, $1.result, $3.result, NULL);
                                      nextquad++;
                                      struct quad* goto_false = quad_gen(&nextquad, $2, $1.result, $3.result, NULL);
                                      nextquad++;
                                      
                                      quad_add(&$$.code, goto_true);
                                      quad_add(&$$.code, goto_false);
                                      
                                      // quad_print($$.code);
                                      
                                      $$.truelist = newlist(goto_true);
                                      $$.falselist = newlist(goto_false);
                                   }
  ;
  
op : SUP  { $$=$1; }
  | INF   { $$=$1; }
  | DIFF  { $$=$1; }
  | SUPEQ { $$=$1; }
  | INFEQ { $$=$1; }
  | EQUAL { $$=$1; }
  ;
  
/*
  
function : TYPE ID '(' list ')' '{' tag list '}'
  ;

matrice : '{' row '}' {}
  | {/* une dimension }
  ;

row	: '{' '}' {}
	| '{' liste_elem '}' {}
	| '{' liste_elem '}' ',' row {}
;	

liste_elem : NUMBER ',' liste_elem {}
  ;

id_matrix : '['INT']' {}
  | '['INT']' '[' INT ']' {}
  ;*/
%%
int main(int argc, char *argv[]) {
  if (argc > 1) {
      yyin = fopen(argv[1], "r");
  }
  yyparse();
  if (argc > 1) {
      fclose(yyin);
  }
  // symbol_print(tds);
  symbol_free(tds);
  quad_free(code);
  //generateFile(code);
  //lex_free();
  return 0;
}