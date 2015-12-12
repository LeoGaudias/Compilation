#include <stdlib.h>
#include <string.h>
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