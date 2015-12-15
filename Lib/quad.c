#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "quad.h"
#include "symbol.h"

struct quad* quad_gen(int* label, char* op, struct symbol* arg1, struct symbol* arg2, struct symbol* res)
{
    struct quad* new = malloc(sizeof(*new));
    new->label = *label;
    new->op = op;
    new->arg1 = arg1;
    new->arg2 = arg2;
    new->res = res;
    new->nextquad = NULL;
    return new;
}

void quad_add(struct quad** list, struct quad* new)
{
    if (*list == NULL)
    {
      *list = new;
    }
    else
    {
      struct quad* scan = *list;
      while (scan->nextquad != NULL) 
      {
          scan = scan->nextquad;
      }
      scan->nextquad = new;
    }
}

void quad_print(struct quad* list)
{
    while (list != NULL)
    {
      printf("%d ",list->label);
      
      if(list->op != NULL)
        printf("%s ",list->op);
      else
        printf("NULL ");
        
      if(list->arg1 != NULL && list->arg1->id != NULL)
        printf("%s ",list->arg1->id);
      else
        printf("NULL ");
      
      if(list->arg2 != NULL && list->arg2->id != NULL)
        printf("%s ",list->arg2->id);
      else
        printf("NULL ");
      
      if(list->res != NULL && list->res->id != NULL)
        printf("%s ",list->res->id);
      else
        printf("NULL ");
      
      printf("\n");
      
      list = list->nextquad;
    }
}

// struct quad* concatQuad(struct quad * q1, struct quad * q2)
// {
//     q1->nextquad = q2;
//     return q1;
// }

void quad_free(struct quad * q)
{
  struct quad* temp1 = q;
  struct quad* temp2 = q->nextquad;
  while(temp2 != NULL){
      //free(temp1->op);
      // symbol_free(temp1->arg1);
      // symbol_free(temp1->arg2);
      // symbol_free(temp1->res);
      free(temp1);
      temp1 = temp2;
      temp2 = temp2->nextquad;
  }
  free(temp1);
}

struct quad_list* newlist(struct quad *q)
{
  struct quad_list* res = malloc(sizeof(*res));
  res->first_quad = q;
  return res;
}

struct quad_list* concatList(struct quad_list* l1, struct quad_list* l2)
{
  if(l1 != NULL)
  {
    struct quad * temp = l1->first_quad;
    while(temp != NULL)
    {
      temp = temp->nextquad;
    }
    if(l2!=NULL)
    {
      temp = l2->first_quad;
    }
    return l1;
  }
  else if(l2 != NULL)
  {
    return l2;
  }
  else
  {
    return NULL;
  }
}

void complete(struct quad_list* l, struct symbol* tag)
{
  // complète les quads de la liste l avec le label tag (tag est un symbole qui contient le label)
  if(l!=NULL)
  {
    struct quad* temp=l->first_quad;
    while(temp->nextquad!=NULL)
    {
      temp=temp->nextquad;
    }
    temp->res=tag;
  }
  // else rien
}

void quad_list_print(struct quad_list* list)
{
  while (list->first_quad != NULL)
  {
    quad_print(list->first_quad);
    list->first_quad = list->first_quad->nextquad; 
  }
}