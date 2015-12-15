%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "Lib/symbol.h"
  #include "Lib/quad.h"
  #include "Lib/matrix.h"
  #include "Lib/mips.h"
  
  extern FILE *yyin;
  int yylex();
  int yyerror(char *);
  //void lex_free();
  void errorManagement(char * str);

  struct symbol* tds = NULL;
  struct quad* code = NULL;
  int nextquad = 0;
  int nb_string = 0;
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
%type <codegen> expr increment affect1 affect2 list_expr print ids_matrix ids_matrix1 ids_matrix2 row1 row2 list_row list_elem matrix_expr affect_matrix

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
 TYPE MAIN '(' ')' '{' list RETURN number ';' '}' { 
                                                    printf("Match\n");
                                                    $$.code = $6.code;
                                                    code = $6.code;
                                                    printf("---TDS---\n");
                                                    symbol_print(tds);
                                                    printf("---CODE---\n");
                                                    quad_print(code);
                                                    //exit(0);
                                                  }
  ;

affect1 :
  TYPE list_expr
          {
            $$.result = $2.result;
            $$.result->type = $1;
            /*struct symbol *temp=$2.result;
            while(temp!=NULL)
            {
              temp->type=$$.result->type;
              temp=temp->next;
            }*/
            $$.code = $2.code;
            symbol_complete(&tds,$1);
          }
  | affect2 {
              $$.result = $1.result;
              $$.code = $1.code;
            }
  ;
  
list_expr :
    ID '=' expr ',' list_expr
                              {
                                struct symbol * affect = symbol_add(&tds, $1);
                                affect->value = $3.result->value;
                                affect->isconstant = false;
                                $$.result = affect;
                                
                                $$.code = quad_gen(&nextquad, "=", $3.result, NULL, affect);
                                quad_add(&$$.code, $3.code);
                                quad_add(&$$.code, $5.code);
                                
                                // $$.code = concatQuad(quad_gen(&nextquad, "=", $3.result, NULL, affect),$5.code);
                                nextquad++;
                              }
  | ID ',' list_expr {
                      struct symbol * affect = symbol_add(&tds, $1);
                      affect->isconstant = false;
                      $$.result = affect;
                      
                      $$.code = quad_gen(&nextquad, "", NULL, NULL, affect);
                      quad_add(&$$.code,$3.code);
                      
                      //$$.code = concatQuad(quad_gen(&nextquad, "", NULL, NULL, affect),$3.code);
                      nextquad++;
                    }
                    
  | ID '=' expr {
                  struct symbol * affect = symbol_add(&tds, $1);
                  affect->value = $3.result->value;
                  affect->isconstant = false;
                  $$.result = affect;
                  
                  $$.code = quad_gen(&nextquad, "=", $3.result, NULL, affect);
                  quad_add(&$$.code,$3.code);
                  nextquad++;
                }
  | ID {
          struct symbol * affect = symbol_add(&tds, $1);
          affect->isconstant = false;
          $$.result = affect;
          
          $$.code = quad_gen(&nextquad, "", NULL, NULL, affect);
          nextquad++;
        }
  | ids_matrix  {
                  $$.result = $1.result;
                  $$.code = $1.code;
                }
  ;
  
ids_matrix:
    ids_matrix1 {
                  $$.result = $1.result;
                  $$.code = $1.code;
                }
  | ids_matrix2 {
                  $$.result = $1.result;
                  $$.code = $1.code;
                }
  ;

//pas fini 
ids_matrix1:
    ID '[' INT ']' '=' row1 ',' ids_matrix  {
                                              struct symbol * affect = symbol_add(&tds, $1);
                                              affect->matrix=malloc(sizeof(struct matrix_float*));
                                              affect->matrix=malloc(sizeof(float*));
                                              affect->matrix->row = 1;
                                              affect->matrix->column = (int)$3;
                                              affect->matrix->tab=malloc(sizeof(float*));
                                              affect->matrix->tab[0]=malloc($3*sizeof(float));
                                              affect->type="matrix";
                                              affect->isconstant = false;
                                              $$.result = affect;
                                              
                                              //$$.code = concatQuad($6.code,$8.code);
                                              $$.code=$6.code;
                                              quad_add(&$$.code,$8.code);
                                            }
  | ID '[' INT ']' ',' ids_matrix {
                                    struct symbol * affect = symbol_add(&tds, $1);
                                    affect->matrix=malloc(sizeof(struct matrix_float*));
                                    affect->matrix->row = 1;
                                    affect->matrix->column = (int)$3;
                                    affect->matrix->tab=malloc(sizeof(float*));
                                    affect->matrix->tab[0]=malloc($3*sizeof(float));
                                    affect->type="matrix";
                                    affect->isconstant = false;
                                    $$.result = affect;
                                    
                                    //$$.code = concatQuad(quad_gen(&nextquad, "", NULL, NULL, affect),$6.code);
                                    $$.code=quad_gen(&nextquad, "", NULL, NULL, affect);
                                    quad_add(&$$.code,$6.code);
                                    nextquad++;
                                  }
  | ID '[' INT ']' '=' row1 {
                              struct symbol * affect = symbol_add(&tds, $1);
                              affect->matrix=malloc(sizeof(struct matrix_float*));
                              affect->matrix->row = 1;
                              affect->matrix->column = (int)$3;
                              affect->matrix->tab=malloc(sizeof(float*));
                              affect->matrix->tab[0]=malloc($3*sizeof(float));
                              affect->type="matrix";
                              affect->isconstant = false;
                              $$.result = affect;
                              
                              $$.code = $6.code;
                            }
  | ID '[' INT ']'  {
                      struct symbol * affect = symbol_add(&tds, $1);
                      affect->matrix=malloc(sizeof(struct matrix_float*));
                      affect->matrix->row = 1;
                      affect->matrix->column = (int)$3;
                      affect->matrix->tab=malloc(sizeof(float*));
                      affect->matrix->tab[0]=malloc($3*sizeof(float));
                      affect->type="matrix";
                      affect->isconstant = false;
                      $$.result = affect;
                      
                      $$.code = quad_gen(&nextquad, "", NULL, NULL, affect);
                    }
  ;
//pas fini
ids_matrix2:
    ID '[' INT ']' '[' INT ']' '=' row2 ',' ids_matrix  {
                                                          struct symbol * affect = symbol_add(&tds, $1);
                                                          affect->matrix=malloc(sizeof(struct matrix_float*));
                                                          affect->matrix->row = (int)$3;
                                                          affect->matrix->column = (int)$6;
                                                          affect->matrix->tab=malloc($3*sizeof(float*));
                                                          int i;
                                                          for(i=0;i<$3;i++)
                                                          {
                                                            affect->matrix->tab[i]=malloc($6*sizeof(float));
                                                          }
                                                          affect->type="matrix";
                                                          affect->isconstant = false;
                                                          $$.result = affect;
                                                          
                                                          $$.code=$9.code;
                                                          quad_add(&$$.code,$11.code);
                                                          
                                                          //$$.code = concatQuad($9.code,$11.code);
                                                        }
  | ID '[' INT ']' '[' INT ']' ',' ids_matrix {
                                                struct symbol * affect = symbol_add(&tds, $1);
                                                affect->matrix=malloc(sizeof(struct matrix_float*));
                                                affect->matrix->row = (int)$3;
                                                affect->matrix->column = (int)$6;
                                                affect->matrix->tab=malloc($3*sizeof(float*));
                                                int i;
                                                for(i=0;i<$3;i++)
                                                {
                                                  affect->matrix->tab[i]=malloc($6*sizeof(float));
                                                }
                                                affect->type="matrix";
                                                affect->isconstant = false;
                                                $$.result = affect;
                                                
                                                // $$.code = concatQuad(quad_gen(&nextquad, "", NULL, NULL, affect),$9.code);
                                                
                                                $$.code = quad_gen(&nextquad, "", NULL, NULL, affect);
                                                quad_add(&$$.code,$9.code);
                                                nextquad++;
                                              }
  | ID '[' INT ']' '[' INT ']' '=' row2 {
                                          struct symbol * affect = symbol_add(&tds, $1);
                                          affect->matrix=malloc(sizeof(struct matrix_float*));
                                          affect->matrix->row = (int)$3;
                                          affect->matrix->column = (int)$6;
                                          affect->matrix->tab=malloc($3*sizeof(float*));
                                          int i;
                                          for(i=0;i<$3;i++)
                                          {
                                            affect->matrix->tab[i]=malloc($6*sizeof(float));
                                          }
                                          affect->type="matrix";
                                          affect->isconstant = false;
                                          $$.result = affect;
                                          
                                          $$.code = $9.code;
                                        }
  | ID '[' INT ']' '[' INT ']'  {
                                  struct symbol * affect = symbol_add(&tds, $1);
                                  affect->matrix=malloc(sizeof(struct matrix_float*));
                                  affect->matrix->row = (int)$3;
                                  affect->matrix->column = (int)$6;
                                  affect->matrix->tab=malloc($3*sizeof(float*));
                                  int i;
                                  for(i=0;i<$3;i++)
                                  {
                                    affect->matrix->tab[i]=malloc($6*sizeof(float));
                                  }
                                  affect->type="matrix";
                                  affect->isconstant = false;
                                  $$.result = affect;
                                  
                                  $$.code = quad_gen(&nextquad, "", NULL, NULL, affect);
                                }
  ;
  
affect2 :
  ID '=' expr {
                struct symbol * affect = symbol_lookup(tds, $1);
                
                printf("%s value : %f\n",$3.result->id, $3.result->value);
                /*struct symbol *temp=affect;
                while(temp!=NULL)
                {
                  temp->type=affect->type;
                  temp=temp->next;
                }*/
                if(affect == NULL)
                {
                  errorManagement(strcat(strcat("L'id ",$1),"n'est pas exisant\n"));
                }
                affect->value = $3.result->value;
                
                $$.result = affect;
                
                $$.code = quad_gen(&nextquad, "=", $3.result, NULL, affect);
                quad_add(&$$.code,$3.code);
                nextquad++;
              }
  | affect_matrix {
                    $$.code = $1.code;
                    $1.result = $1.result;
                  }
  | increment {
                $$.result = $1.result;
                $$.code = $1.code;
              }
  ;
  
//pas fini
affect_matrix :
  ID '=' matrix_expr  {
                          struct symbol * affect = symbol_lookup(tds, $1);
                          if(affect == NULL)
                          {
                            errorManagement(strcat(strcat("L'id ",$1),"n'est pas exisant\n"));
                          }
                          //affect->value = $3.result->value;
                          $$.result = affect;
                          
                          $$.code = quad_gen(&nextquad, "=", $3.result, NULL, affect);
                          nextquad++;
                        }
  | ID '[' INT ']' '[' INT ']' '='  {
                                      $$.result=NULL;
                                      $$.code=NULL;
                                    }
  ;

expr :
    expr '+' expr   {   
                        $$.result = symbol_newtemp(&tds);
                        $$.result->value = $1.result->value + $3.result->value;
                        if(strcmp($1.result->type,"int")==0 && strcmp($3.result->type,"int")==0)
                        {
                          $$.result->type = $1.result->type;
                        }
                        else
                        {
                          $$.result->type = "float";
                        }
                        $$.code = $1.code;
                        quad_add(&$$.code, $3.code);
                        quad_add(&$$.code, quad_gen(&nextquad,"+", $1.result, $3.result, $$.result));
                        nextquad++;
                    }
  | expr '-' expr   {   
                        $$.result = symbol_newtemp(&tds);
                        $$.result->value = $1.result->value - $3.result->value;
                        if(strcmp($1.result->type,"int") == 0 && strcmp($3.result->type,"int") ==0)
                        {
                          $$.result->type = $1.result->type;
                        }
                        else
                        {
                          $$.result->type = "float";
                        }
                        $$.code = $1.code;
                        quad_add(&$$.code, $3.code);
                        quad_add(&$$.code, quad_gen(&nextquad,"-", $1.result, $3.result, $$.result));
                        nextquad++;
                    }
  | expr '*' expr   {   
                        $$.result = symbol_newtemp(&tds);
                        $$.result->value = $1.result->value * $3.result->value;
                        if(strcmp($1.result->type,"int") == 0 && strcmp($3.result->type,"int") ==0)
                        {
                          $$.result->type = $1.result->type;
                        }
                        else
                        {
                          $$.result->type = "float";
                        }
                        $$.code = $1.code;
                        quad_add(&$$.code, $3.code);
                        quad_add(&$$.code, quad_gen(&nextquad,"*", $1.result, $3.result, $$.result));
                        nextquad++;
                    }
  | expr '/' expr   {   
                        $$.result = symbol_newtemp(&tds);
                       
                        $$.result->value = $1.result->value / $3.result->value;
                        
                        if(strcmp($1.result->type,"int") == 0 && strcmp($3.result->type,"int") ==0)
                        {
                          $$.result->type = $1.result->type;
                        }
                        else
                        {
                          $$.result->type = "float";
                        }
                        $$.code = $1.code;
                        quad_add(&$$.code, $3.code);
                        quad_add(&$$.code, quad_gen(&nextquad,"/", $1.result, $3.result, $$.result));
                        nextquad++;
                    }
  | '(' expr ')'    {   
                        $$.result = $2.result;
                        $$.code = $2.code;
                    }
  | increment       {
                      $$.result = $1.result;
                      $$.code = $1.code;
                    }
  
  | ID              {   
                        struct symbol* temp = symbol_lookup(tds,$1);
                        if(temp == NULL)
                        {
                          errorManagement(strcat(strcat("L'id ",$1),"n'est pas exisant\n"));
                        }
                        $$.result = temp;
                        $$.code = NULL;
                        // $$.result = symbol_add(&tds, $1);
                        // $$.code = NULL;
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

//pas fini  
matrix_expr :
    '~' ID  {
              $$.code = NULL;
              $$.result = NULL;
            }
  | ID '[' INT ']' '[' INT ']'  {
                                  $$.code = NULL;
                                  $$.result = NULL;
                                }
  | ID '[' INT ']'  {
                      $$.code = NULL;
                      $$.result = NULL;
                    }
  ;
  
number : 
    INT { $$.value=$1; $$.type="int";}
  | FLOAT { $$.value=$1; $$.type="float";}
  ;

increment : 
    ID PLUSPLUS     {
                      struct symbol* temp = symbol_lookup(tds,$1);
                      if(temp == NULL)
                      {
                        errorManagement(strcat(strcat("L'id ",$1),"n'est pas exisant\n"));
                      }
                      temp->value += 1;
                      $$.result = temp;
                      $$.code = quad_gen(&nextquad,"++", temp, NULL, $$.result);
                      nextquad++;
                    }
  | PLUSPLUS ID     {
                      struct symbol* temp = symbol_lookup(tds,$2);
                      if(temp == NULL)
                      {
                        errorManagement(strcat(strcat("L'id ",$2),"n'est pas exisant\n"));
                      }
                      temp->value += 1;
                      $$.result = temp;
                      $$.code = quad_gen(&nextquad,"++", NULL, temp, $$.result);
                      nextquad++;
                    }
  | ID MOINSMOINS   {
                      struct symbol* temp = symbol_lookup(tds,$1);
                      if(temp == NULL)
                      {
                        errorManagement(strcat(strcat("L'id ",$1),"n'est pas exisant\n"));
                      }
                      temp->value -= 1;
                      $$.result = temp;
                      $$.code = quad_gen(&nextquad,"--", temp, NULL , $$.result);
                      nextquad++;
                    }
  | MOINSMOINS ID   {
                      struct symbol* temp = symbol_lookup(tds,$2);
                      if(temp == NULL)
                      {
                        errorManagement(strcat(strcat("L'id ",$2),"n'est pas exisant\n"));
                      }
                      temp->value -= 1;
                      $$.result = temp;
                      $$.code = quad_gen(&nextquad,"--", NULL, temp, $$.result);
                      nextquad++;
                    }
  ;

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
    tag statement list {
                          complete($3.nextlist,$1);
                          $$.nextlist = $2.nextlist;
                          $$.code = $2.code;
                          quad_add(&$$.code,$3.code);
                        }
  | affect1 ';' list
                    {
                      $$.nextlist = newlist($1.code);
                      $$.code=$1.code;
                      quad_add(&$$.code,$3.code);
                    }
  | print ';' list {
                      $$.nextlist = newlist($1.code);
                      $$.code = $1.code;
                      quad_add(&$$.code,$3.code);
                   }
  | {$$.code=NULL;/* empty */}
  ;
  
print:
 PRINT '(' ID ')'
    {
      struct symbol * affect = symbol_lookup(tds, $3);
      if(affect == NULL)
      {
        errorManagement(strcat(strcat("L'id ",$3),"n'est pas exisant\n"));
      }
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
      temp->value = nb_string;
      nb_string++;
      $$.code = quad_gen(&nextquad,"printf",temp,NULL,NULL);
      $$.result = temp;
      nextquad++;
   }
 | PRINTMAT '(' ID ')'
   {
      struct symbol * temp = symbol_newtemp(&tds); 
      temp->type = "string";
      temp->id = $3;
      $$.code = quad_gen(&nextquad,"printmat",temp,NULL,NULL);
      $$.result = temp;
      nextquad++;
   }
  ;
  
statement : 
  IF '(' condition ')' '{' tag list '}'
  
      { 
        complete($3.truelist,$6);
        $$.nextlist = concatList($7.nextlist,$3.falselist);
        $$.code = $3.code;
        quad_add(&$$.code,$7.code);
      }
      
  | IF '(' condition ')' '{' tag list '}' ELSE '{' tagoto list '}'
  
      { 
        complete($3.truelist,$6);
        complete($3.falselist,$11.quad);
        $$.nextlist=concatList(concatList($7.nextlist,$12.nextlist),$11.nextlist);
        $$.code=$3.code;
        quad_add(&$$.code,$7.code);
        quad_add(&$$.code,$11.code);
        quad_add(&$$.code,$12.code);
        //$$.code=concatQuad(concatQuad(concatQuad($3.code,$7.code),$11.code),$12.code);
      }
      
  | WHILE tag '(' condition ')' '{' tag list '}'  
  
      { 
        complete($4.truelist,$7);
        complete($8.nextlist,$2);
        $$.nextlist=$4.falselist;
        //$$.code=concatQuad(concatQuad($4.code,$8.code),quad_gen(&nextquad,"goto",NULL,NULL,$2));
        $$.code=$4.code;
        quad_add(&$$.code,$8.code);
        quad_add(&$$.code,quad_gen(&nextquad,"goto",NULL,NULL,$2));
        nextquad++;
      }
  
  | FOR '(' affect1 ';' tag condition ';' affect2 ')' '{' tag list '}'  
      
      { 
        complete($6.truelist,$11);
        complete($12.nextlist,$5);
        $$.nextlist=$6.falselist;
        //$$.code=concatQuad(concatQuad($6.code,$12.code),quad_gen(&nextquad,"goto",NULL,NULL,$5));
        $$.code=$6.code;
        quad_add(&$$.code,$12.code);
        quad_add(&$$.code,quad_gen(&nextquad,"goto",NULL,NULL,$5));
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
 *function : TYPE ID '(' list ')' '{' tag list '}'
 *  ;
 */
  
row1 :
    '{' list_elem  '}'  {
                          $$.code=NULL;
                          $$.result=$2.result;
                          $$.result=NULL;
                        }
  | '{' '}' {
              $$.code=NULL;
              $$.result=NULL;
            }
  ;

row2	:
  '{' list_row '}'  {
                      $$.code=NULL;
                      $$.result=$2.result;
                      $$.result=NULL;
                    }
  ;

list_row :
    row1  {
            $$.code=NULL;
            $$.result=$1.result;
            $$.result=NULL;
          }
  | row1 ',' list_row {
                        $$.code=NULL;
                        $$.result=$1.result;
                        struct symbol* temp=$1.result;
                        while(temp->next!=NULL)
                        {
                          temp->next=$3.result;
                        }
                        $$.result=NULL;
                      }
  ;

list_elem :
    number ',' list_elem {
                          $$.code=NULL;
                          $$.result = symbol_newtemp(&tds);
                          $$.result->type = $1.type;
                          $$.result->value = $1.value;
                          $$.result->next=$3.result;
                          $$.result=NULL;
                        }
  | number {
            $$.code=NULL;
            $$.result = symbol_newtemp(&tds);
            $$.result->type = $1.type;
            $$.result->value = $1.value;
            //$$.result=NULL;
          }
  ;
%%

void errorManagement(char * str)
{
  fputs(str, stderr);
  //fprintf(stderr, str);
  symbol_free(tds);
  quad_free(code);
  exit(-1);
}

int main(int argc, char *argv[]) {
  if (argc > 1) {
      yyin = fopen(argv[1], "r");
  }
  yyparse();
  if (argc > 1) {
      fclose(yyin);
  }
  convert(code,tds);
  // symbol_print(tds);
  symbol_free(tds);
  quad_free(code);
  //generateFile(code);
  //lex_free();
  return 0;
}