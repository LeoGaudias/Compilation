#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "symbol.h"
#include "quad.h"
#include "mips.h"

FILE* open(char* add)
{
  FILE * file=fopen(add,"w+");
  
  if(file==NULL)
  {
    fprintf(stderr,"Error while opening file at %s",add);
    exit(-1);
  }
  
  return file;
}

void convert(struct quad* code, struct symbol* tds)
{
    FILE *fp = open("mips.s");

    fprintf(fp, "\t.data\n");
    fprintf(fp, "newline: .asciiz \"\\n\"\n");
    fprintf(fp, ".align 2\n");
    fprintf(fp, "tab: .asciiz \"\\t\"\n");
    fprintf(fp, ".align 2\n");

    while (tds != NULL) 
    {
        if(tds->type!=NULL)
        {
            if (strcmp(tds->type,"string") == 0) 
            {
                fprintf(fp, "string%d: .asciiz %s\n", (int)tds->value, tds->id);
                fprintf(fp, ".align 2\n");
            } 
            else if (tds->id!=NULL) 
            {
                int size = 0;
                if(strcmp(tds->type,"int") == 0)
                {
                    size=4;
                }
                else if(strcmp(tds->type,"float") == 0)
                {
                    size=8;
                }
                else
                {
                    size=0;
                }
                fprintf(fp, "%s: .space %d\n", tds->id, size);
            }
        }
        tds = tds->next;
    }
    fprintf(fp, "\n");

    fprintf(fp, "\t.text\n");
    fprintf(fp, "main:\n");

    int nb = 0;
    while (code != NULL)
    {
        if (code->label > nb) 
        {
            fprintf(fp, "\tL%d:\n", code->label);
        }

        if (strcmp(code->op, "print")==0) 
        {
            if (strcmp(code->arg1->type,"float")==0) 
            {
                fprintf(fp, "\t\tli $v0, 2\n");
                if (code->arg1->id!=NULL)
                {
                    fprintf(fp, "\t\tl.s $f12, %s\n", code->arg1->id);
                }
                else
                {
                    fprintf(fp, "\t\tmov.s $f12, $f2\n");
                }
                fprintf(fp, "\t\tsyscall\n");
            } 
            else 
            {
                fprintf(fp, "\t\tli $v0, 1\n");
                if (code->arg1->id!=NULL)
                {
                    fprintf(fp, "\t\tlw $a0, %s\n", code->arg1->id);
                }
                else
                {
                    fprintf(fp, "\t\tmove $a0, $t2\n");
                }
                fprintf(fp, "\t\tsyscall\n");
            }
            fprintf(fp, "\t\tli $v0, 4\n");
            fprintf(fp, "\t\tla $a0, newline\n");
            fprintf(fp, "\t\tsyscall\n");
        }
        else if (strcmp(code->op, "printf") == 0)
        {
            fprintf(fp, "\t\tli $v0, 4\n");
            fprintf(fp, "\t\tla $a0, string%d\n", (int)code->arg1->value);
            fprintf(fp, "\t\tsyscall\n");
        }
        else if (strcmp(code->op, "printmat") == 0)
        {
            //fprintf(fp, "\t\tli $t0, %d\n", code->res->v.mat_val->dim1*code->res->v.mat_val->dim2*8);
            fprintf(fp, "\t\tla $t1, %s\n", code->arg1->id);
            fprintf(fp, "\t\tli $t2, 0\n");
            /*fprintf(fp, "\t\tli $t3, %d\n", code->res->v.mat_val->dim2);
            fprintf(fp, "\t\tli $t4, %d\n", code->res->v.mat_val->dim2);*/

            fprintf(fp, "\tstptmat%d:\n", code->label);
            fprintf(fp, "\t\tbeq $t2, $t0, endptmat%d\n", code->label);

            fprintf(fp, "\t\tli $v0, 2\n");
            fprintf(fp, "\t\tl.s $f12, ($t1)\n");
            fprintf(fp, "\t\tsyscall\n");

            fprintf(fp, "\t\taddi $t1, $t1, 8\n");
            fprintf(fp, "\t\taddi $t2, $t2, 8\n");
            fprintf(fp, "\t\tsub $t4, $t4, 1\n");
            fprintf(fp, "\t\tbeq $t4, 0, stligne%d\n", code->label);
            fprintf(fp, "\t\tli $v0, 4\n");
            fprintf(fp, "\t\tla $a0, tab\n");
            fprintf(fp, "\t\tsyscall\n");
            fprintf(fp, "\tsuitemat%d:\n", code->label);

            fprintf(fp, "\t\tb stptmat%d\n", code->label);

            fprintf(fp, "\tstligne%d:\n", code->label);
            fprintf(fp, "\t\tli $v0, 4\n");
            fprintf(fp, "\t\tla $a0, newline\n");
            fprintf(fp, "\t\tsyscall\n");
            fprintf(fp, "\t\tmove $t4, $t3\n");
            fprintf(fp, "\t\tb suitemat%d\n", code->label);

            fprintf(fp, "\tendptmat%d:\n", code->label);
            fprintf(fp, "\t\tli $v0, 4\n");
            fprintf(fp, "\t\tla $a0, newline\n");
            fprintf(fp, "\t\tsyscall\n");

        }
        else if (strcmp(code->op, "=") == 0)
        {
            if (code->label > nb)
            {
                if (strcmp(code->res->type,"float") == 0)
                {
                    fprintf(fp, "\t\tli.s $f2, %f\n", code->arg1->value);
                }
                else
                {
                    fprintf(fp, "\t\tli $t2, %d\n", (int)code->arg1->value);
                }
            }
            if (strcmp(code->res->type,"float")==0)
            {
                fprintf(fp, "\t\ts.s $f2, %s\n", code->res->id);
            }
            else
            {
                fprintf(fp, "\t\tsw $t2, %s\n", code->res->id);
            }

        }
        else if (strcmp(code->op, "+")==0 || strcmp(code->op, "-")==0 || strcmp(code->op, "/")==0 || strcmp(code->op, "*")==0)
        {
            if (code->arg1 != NULL)
            {
                if (code->arg1->isconstant)
                {
                    if (strcmp(code->res->type,"float") == 0)
                    {
                        fprintf(fp, "\t\tli.s $f0, %f\n", code->arg1->value);
                    }
                    else if (strcmp(code->res->type,"int") == 0)
                    {
                        fprintf(fp, "\t\tli $t0, %d\n", (int)code->arg1->value);
                    }
                    else 
                    {
                        if (strcmp(code->arg1->type,"int")==0)
                        {
                            fprintf(fp, "\t\tli.s $f0, %f\n", code->arg1->value);
                        }
                        else if (strcmp(code->arg1->type,"float")==0)
                        {
                            fprintf(fp, "\t\tli.s $f0 %f\n", code->arg1->value);
                        }
                    }
                }
                else
                {
                    if (code->arg1->id != NULL)
                    {
                        if (strcmp(code->res->type,"float") == 0)
                        {
                            fprintf(fp, "\t\tl.s $f0, %s\n", code->arg1->id);
                        }
                        else if (strcmp(code->res->type,"int") == 0)
                        {
                            fprintf(fp, "\t\tlw $t0, %s\n", code->arg1->id);
                        }
                        else
                        {
                            fprintf(fp, "\t\tla $t0, %s\n", code->arg1->id);
                        }
                    }
                    else
                        if (strcmp(code->res->type,"float") == 0)
                        {
                            fprintf(fp, "\t\tmov.s $f0, $f2\n");
                        }
                        else
                        {
                            fprintf(fp, "\t\tmove $t0, $t2\n");
                        }
                }
            }

            if (code->arg2 != NULL) {
                if (code->arg2->isconstant)
                {
                    if (strcmp(code->res->type,"float") == 0)
                    {
                        fprintf(fp, "\t\tli.s $f1, %f\n", code->arg2->value);
                    }
                    else  if (strcmp(code->res->type,"int") == 0)
                    {
                        fprintf(fp, "\t\tli $t1, %d\n", (int)code->arg2->value);
                    }
                    else 
                    {
                        if (strcmp(code->arg2->type, "int") == 0)
                        {
                            fprintf(fp, "\t\tli.s $f0, %f\n", code->arg2->value);
                        }
                        else if (strcmp(code->arg2->type, "float"))
                        {
                            fprintf(fp, "\t\tli.s $f0 %f\n", code->arg2->value);
                        }
                    }
                }
                else
                {
                    if (code->arg2->id!=NULL)
                    {
                        if (strcmp(code->res->type,"float")==0)
                        {
                            fprintf(fp, "\t\tl.s $f1, %s\n", code->arg2->id);
                        }
                        else if (strcmp(code->res->type,"int")==0)
                        {
                            
                            fprintf(fp, "\t\tlw $t1, %s\n", code->arg2->id);
                        }
                        else
                        {
                            fprintf(fp, "\t\tla $t1, %s\n", code->arg2->id);
                        }
                    }
                    else
                    {
                        if (strcmp(code->res->type,"float")==0)
                        {
                            fprintf(fp, "\t\tmov.s $f1, $f2\n");
                        }
                        else
                        {
                            fprintf(fp, "\t\tmove $t1, $t2\n");
                        }
                    }
                }
            }

            /*if (code->res->stype == SYMBOL_MATRIX) {
                if (strcmp(code->op, "+")==0 || strcmp(code->op, "-")==0) {

                    fprintf(fp, "\t\tla $t2, %s\n", code->res->id);
                    fprintf(fp, "\t\tli $t3, %d\n", code->res->v.mat_val->dim1*code->res->v.mat_val->dim2*8);
                    fprintf(fp, "\t\tli $t4, 0\n");

                    if (strcmp(code->op, "+")==0) {
                        fprintf(fp, "\tstaddmat%d:\n", code->label);
                        fprintf(fp, "\t\tbeq $t4, $t3, endaddmat%d\n", code->label);
                    } else if (strcmp(code->op, "-")==0) {
                        fprintf(fp, "\tstminmat%d:\n", code->label);
                        fprintf(fp, "\t\tbeq $t4, $t3, endminmat%d\n", code->label);
                    }

                    fprintf(fp, "\t\tl.s $f0, ($t0)\n");
                    fprintf(fp, "\t\tl.s $f1, ($t1)\n");

                    if (strcmp(code->op, "+")==0) {
                        fprintf(fp, "\t\tadd.s $f2, $f0, $f1\n");
                    } else if (strcmp(code->op, "-")==0) {
                        fprintf(fp, "\t\tsub.s $f2, $f0, $f1\n");
                    }

                    fprintf(fp, "\t\ts.s $f2, ($t2)\n");

                    fprintf(fp, "\t\taddi $t0, $t0, 8\n");
                    fprintf(fp, "\t\taddi $t1, $t1, 8\n");
                    fprintf(fp, "\t\taddi $t2, $t2, 8\n");
                    fprintf(fp, "\t\taddi $t4, $t4, 8\n");

                    if (strcmp(code->op, "+")==0) {
                        fprintf(fp, "\t\tb staddmat%d\n", code->label);
                        fprintf(fp, "\tendaddmat%d:\n", code->label);
                    } else if (strcmp(code->op, "-")==0) {
                        fprintf(fp, "\t\tb stminmat%d\n", code->label);
                        fprintf(fp, "\tendminmat%d:\n", code->label);
                    }
                } else if (strcmp(code->op, "*")==0 || strcmp(code->op, "/")==0) {
                    fprintf(fp, "\t\tla $t2, %s\n", code->res->id);
                    fprintf(fp, "\t\tli $t3, %d\n", code->res->v.mat_val->dim1*code->res->v.mat_val->dim2*8);

                    fprintf(fp, "\t\tli $t4, 0\n");

                    if (strcmp(code->op, "*")==0) {
                        fprintf(fp, "\tstmulmat%d:\n", code->label);
                        fprintf(fp, "\t\tbeq $t4, $t3, endmulmat%d\n", code->label);
                    } else if (strcmp(code->op, "/")==0) {
                        fprintf(fp, "\tstdivmat%d:\n", code->label);
                        fprintf(fp, "\t\tbeq $t4, $t3, enddivmat%d\n", code->label);
                    }

                    if (strcmp(code->arg1->type,"matrix")==0)
                        fprintf(fp, "\t\tl.s $f1, ($t0)\n");
                    else if (strcmp(code->arg2->type,"matrix")==0)
                        fprintf(fp, "\t\tl.s $f1, ($t1)\n");

                    if (strcmp(code->op, "*")==0) {
                        fprintf(fp, "\t\tmul.s $f2, $f0, $f1\n");
                    } else if (strcmp(code->op, "/")==0) {
                        if (strcmp(code->arg1->type,"matrix")==0)
                            fprintf(fp, "\t\tdiv.s $f2, $f1, $f0\n");
                        else if (strcmp(code->arg2->type,"matrix")==0)
                            fprintf(fp, "\t\tdiv.s $f2, $f0, $f1\n");
                    }

                    fprintf(fp, "\t\ts.s $f2, ($t2)\n");

                    if (strcmp(code->arg1->type,"matrix")==0)
                        fprintf(fp, "\t\taddi $t0, $t0, 8\n");
                    else if (strcmp(code->arg2->type,"matrix")==0)
                        fprintf(fp, "\t\taddi $t1, $t1, 8\n");

                    fprintf(fp, "\t\taddi $t2, $t2, 8\n");
                    fprintf(fp, "\t\taddi $t4, $t4, 8\n");

                    if (strcmp(code->op, "*")==0) {
                        fprintf(fp, "\t\tb stmulmat%d\n", code->label);
                        fprintf(fp, "\tendmulmat%d:\n", code->label);
                    } else if (strcmp(code->op, "/")==0) {
                        fprintf(fp, "\t\tb stdivmat%d\n", code->label);
                        fprintf(fp, "\tenddivmat%d:\n", code->label);
                    }
                }
            } else {
                if (strcmp(code->op, "+")==0) {
                    if (strcmp(code->res->type,"float")==0)
                        fprintf(fp, "\t\tadd.s $f2, $f0, $f1\n");
                    else
                        fprintf(fp, "\t\tadd $t2, $t0, $t1\n");
                } else if (strcmp(code->op, "-")==0) {
                    if (code->arg2 != NULL) {
                        if (strcmp(code->res->type,"float")==0)
                            fprintf(fp, "\t\tsub.s $f2, $f0, $f1\n");
                        else
                            fprintf(fp, "\t\tsub $t2, $t0, $t1\n");
                    } else {
                        if (strcmp(code->res->type,"float")==0)
                            fprintf(fp, "\t\tneg.s $f2, $f0\n");
                        else
                            fprintf(fp, "\t\tneg $t2, $t0\n");
                    }
                } else if (strcmp(code->op, "*")==0) {
                    if (strcmp(code->res->type,"float")==0)
                        fprintf(fp, "\t\tmul.s $f2, $f0, $f1\n");
                    else
                        fprintf(fp, "\t\tmul $t2, $t0, $t1\n");
                } else if (strcmp(code->op, "/")==0) {
                    if (strcmp(code->res->type,"float")==0)
                        fprintf(fp, "\t\tdiv.s $f2, $f0, $f1\n");
                    else
                        fprintf(fp, "\t\tdiv $t2, $t0, $t1\n");
                }
            }*/

        }
        else if (strcmp(code->op, "[]=") == 0)
        {
            /*fprintf(fp, "\t\tla $t0, %s\n", code->res->id);
            fprintf(fp, "\t\taddi $t0, $t0, %d\n", code->arg1->v.int_val*8);
            fprintf(fp, "\t\tli.s $f0, %f\n", code->arg2->v.float_val);
            fprintf(fp, "\t\ts.s $f0, ($t0)\n");*/
        }

        if (code->label > nb)
        {
            nb++;
        }
        code = code->nextquad;
    }

    fprintf(fp, "\texit:\n");
    fprintf(fp, "\t\tli $v0, 10\n");
    fprintf(fp, "\t\tsyscall\n");

    close(fp);
}

void generateFile(struct quad* quads)
{
  FILE *res=open("mips.s");
  
  struct quad* scan=quads;
  
  while(scan!=NULL)
  {
    fprintf(res,"li $a0, %f\n",scan->arg1->value);
    fprintf(res,"li $a1, %f\n",scan->arg2->value);
    
    if(strcmp(scan->op,"+")==0)
    {
      fprintf(res,"add $a0, $a0, $a1\n");
    }
    else if(strcmp(scan->op,"-")==0)
    {
      fprintf(res,"sub $a0, $a0, $a1\n");
    }
    else if(strcmp(scan->op,"*")==0)
    {
      fprintf(res,"mul $a0, $a0, $a1\n");
    }
    else if(strcmp(scan->op,"/")==0)
    {
      fprintf(res,"div $a0, $a0, $a1\n");
    }
    else
    {
      // ?
    }
    
    scan=scan->nextquad;
  }
}

void close(FILE* file)
{
  fclose(file);
}