%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "Lib/symbol.h"
  #include "Lib/quad.h"
  
  extern FILE *yyin;
  int yylex();
  int yyerror(char *);

  struct symbol* tds = NULL;
  struct symbol** sauv_tds = &tds;
  struct quad* code = NULL;
  int nextquad = 0;
%}

%union {
  float value;
  char* string;
  struct symbol* label;
    
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

%token PLUSPLUS MOINSMOINS
%token<value> NUMBER

// necessaire aux conditions
%token<string> ID NOT OR AND IF ELSE WHILE FOR STRING TYPE DIFF SUPEQ INFEQ EQUAL SUP INF //KEYWORD

//%type <codegen> matrice row liste_elem

%type<string> op
%type <codegen> expr increment affect

%type<code_condition> condition axiom //relop 
%type<code_statement> statement list //axiom
%type<label> tag
%type<code_goto> tagoto

%right '='
%left '>' '<' ">=" "<=" "==" "!="
%left '+' '-'
%left '*' '/'
%left PLUSPLUS MOINSMOINS UMOINS

%left OR
%left AND
%left NOT

%%

/*axiom : affect ';' axiom { printf("return le code mips"); $$.code = $1.code;}
  | '\n' {}
  | '\n' axiom {}
  | {empty}
  ;*/
  
axiom : 
// list { printf("return le code mips"); $$.code = $1.code;}
// expr '\n'{ printf("Match\n"); $$.code = $1.code;}
// affect {printf("Match\n"); $$.code = $1.code;}
// statement {printf("Match\n"); $$.code = $1.code;}
// relop {printf("Match\n"); $$.code = $1.code;}
condition {printf("Match\n"); $$.code = $1.code;}
  ;

/* se souvenir qu'on doit pouvoir faire matrix A[2]={3,4}, IA[2]={3,4} */
affect : 
  TYPE ID '=' expr {
                        struct symbol * affect = symbol_add(&tds, $2);
                        affect->type = strdup($1);
                        affect->value = $4.result->value;
                        affect->isconstant = false;
                        $$.result = affect;
                        
                        $$.code = quad_gen(&nextquad, "=", $4.result, NULL, affect);
                        nextquad++;
                      }
  | ID '=' expr {
                  struct symbol * affect = symbol_lookup(tds, $1);
                  affect->value = $3.result->value;
                  $$.result = affect;
                  
                  $$.code = quad_gen(&nextquad, "=", $3.result, NULL, affect);
                  nextquad++;
                  
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
  | '-' NUMBER      {
                        $$.result = symbol_newtemp(&tds);
                        $$.result->value = - $2;
                        $$.code = NULL;
                    }
  | NUMBER          {   
                        $$.result = symbol_newtemp(&tds);
                        $$.result->value = $1;
                        $$.code = NULL;
                    }
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
  | PLUSPLUS ID         {
                      struct symbol* temp = symbol_lookup(tds,$2);
                      temp->value += 1;
                      $$.result = temp;
                      $$.code = quad_gen(&nextquad,"++", NULL, temp, $$.result);
                      nextquad++;
                    }
  | ID MOINSMOINS         {
                      struct symbol* temp = symbol_lookup(tds,$1);
                      temp->value -= 1;
                      $$.result = temp;
                      $$.code = quad_gen(&nextquad,"--", temp, NULL , $$.result);
                      nextquad++;
                    }
  | MOINSMOINS ID         {
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
  "int" "main" '(' ')' '{' list '}' {/* temporaire pour qu'il passe la lecture du main, les fonctions ça sera pour plus tard*/}
  |list ';' tag statement {
                              complete($1.nextlist,$3);
                              $$.nextlist = $4.nextlist;
                              $$.code = concatQuad($1.code, $4.code); 
                            }
  | affect ';' list {
                      /* si on a pas de tag on fait pas de complete ou bien ? ... */
                      $$.nextlist = newlist($1.code);
                      $$.code = concatQuad($3.code, $1.code);
                    }
  | statement {
                $$.code = $1.code;
                $$.nextlist = NULL;
              }
  | affect  {
              $$.code = $1.code;
              $$.nextlist = NULL;
            }
  | {}
  ;
  
statement : 
  IF '(' condition ')' '{' tag list '}' { complete($3.truelist,$6);
                                          $$.nextlist=concatList($7.nextlist,$3.falselist);
                                          $$.code=concatQuad($3.code,$7.code);
                                        }
  | IF '(' condition ')' '{' tag list '}' ELSE '{' tagoto list '}'  { complete($3.truelist,$6);
                                                                      complete($3.falselist,$11.quad);
                                                                      $$.nextlist=concatList(concatList($7.nextlist,$12.nextlist),$11.nextlist);
                                                                      $$.code=concatQuad(concatQuad(concatQuad($3.code,$7.code),$11.code),$12.code);
                                                                    }
  | WHILE tag '(' condition ')' '{' tag list '}'  { complete($4.truelist,$7);
                                                    complete($8.nextlist,$2);
                                                    $$.nextlist=$4.falselist;
                                                    $$.code=concatQuad(concatQuad($4.code,$8.code),quad_gen(&nextquad,"goto",NULL,NULL,$2));
                                                    nextquad++;
                                                  }
  | FOR '(' affect ';' tag condition ';' expr ')' '{' tag list '}'  { complete($6.truelist,$11);
                                                                      complete($12.nextlist,$5);
                                                                      $$.nextlist=$6.falselist;
                                                                      $$.code=concatQuad(concatQuad($6.code,$12.code),quad_gen(&nextquad,"goto",NULL,NULL,$5));
                                                                      nextquad++;
                                                                    }
                                                                  
   /*IF '(' condition ')' tag statement { complete($3.truelist,$5);
                                        $$.nextlist=concatList($6.nextlist,$3.falselist);
                                        $$.code=concatQuad($3.code,$6.code);
                                      }
  | IF '(' condition ')' tag statement ELSE tagoto statement  { complete($3.truelist,$5);
                                                                complete($3.falselist,$8.quad);
                                                                $$.nextlist=concatList(concatList($6.nextlist,$9.nextlist),$8.nextlist);
                                                                $$.code=concatQuad(concatQuad(concatQuad($3.code,$6.code),$8.code),$9.code);
                                                              }
  | WHILE tag '(' condition ')' tag statement  { complete($4.truelist,$6);
                                            complete($7.nextlist,$2);
                                            $$.nextlist=$4.falselist;
                                            $$.code=concatQuad(concatQuad($4.code,$7.code),gen(goto $6));
                                          }
  | FOR '(' affect ';' tag condition ';' expr ')' tag statement { complete($6.truelist,$10);
                                                                    complete($11.nextlist,$5);
                                                                    $$.nextlist=$6.falselist;
                                                                    $$.code=concatQuad(concatQuad($6.code,$11.code),gen(goto $10));
                                                                  }
  */
  ;
  
condition : 
    condition OR tag condition       { 
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
                                      
                                      quad_print($$.code);
                                      
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
list_id : {/* empty }
  | TYPE ID, list_id{}
  | TYPE ID {}
  ;
  
function : TYPE ID '(' list_id ')' '{' tag list '}'
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
  // symbol_free(tds);
  return 0;
}