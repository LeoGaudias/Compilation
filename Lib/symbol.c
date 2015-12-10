#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "symbol.h"

int nb_symbol = 0;

struct symbol* symbol_alloc()
{
    struct symbol* new = malloc(sizeof(*new));
    new->id = NULL;
    new->isconstant = false;
    new->value = 0;
    new->next = NULL;
}

struct symbol* symbol_newtemp(struct symbol** tds)
{
    // static int nb_symbol = 0;
    char temp_name[SYMBOL_MAX_NAME];
    snprintf(temp_name, SYMBOL_MAX_NAME, "temp_%d", nb_symbol);
    nb_symbol++;
    return symbol_add(tds, temp_name);
}

struct symbol* symbol_lookup(struct symbol* tds,char* id)
{
    struct symbol* temp=tds;
    bool found=false;
    while(temp != NULL && found == false)
    {
        if(strcmp(temp->id,id))
        {
            found = true;
            break;
        }
        temp = temp->next;
    }
    return temp;
}

struct symbol* symbol_add(struct symbol** tds, char* id)
{
    if (*tds == NULL)
    {
        *tds = symbol_alloc();
        (*tds)->id = strdup(id);
        return *tds;
    } 
    else {
        struct symbol* scan = *tds;
        while (scan->next != NULL) 
        {
            scan = scan->next;
        }
        scan->next = symbol_alloc();
        scan->next->id = strdup(id);
        scan->next->isconstant=false;
        return scan->next;
    }
}

//adresse constante --> ce n'est pas une variable constante
struct symbol* symbol_newlabel(struct symbol** tds, int nextquad)
{
  char temp_name[SYMBOL_MAX_NAME];
  snprintf(temp_name, SYMBOL_MAX_NAME, "label_%d", nextquad);
  if (*tds == NULL)
  {
    *tds = symbol_alloc();
    (*tds)->id = strdup(temp_name);
    (*tds)->value = nextquad;
    (*tds)->type="int";
    
    return *tds;
  } 
  else
  {
    struct symbol* scan = *tds;
    while (scan->next != NULL)
    {
      scan = scan->next;
    }
    
    struct symbol * temp = symbol_alloc();
    temp->isconstant=true;
    temp->id = strdup(temp_name);
    temp->value = nextquad;
    temp->type="int";
    scan->next = temp;
    
    return scan->next;
  }
}

void symbol_print(struct symbol* tds)
{
    while (tds != NULL)
    {
        if(tds->type!=NULL && strcmp(tds->type,"int") == 0)
        {
            // printf("hello ");
            printf("--> %s:%d\n", tds->id,(int) tds->value);
        }
        else
        {
            printf("--> %s:%f\n", tds->id, tds->value);
        }
        tds = tds->next;
    }
}
