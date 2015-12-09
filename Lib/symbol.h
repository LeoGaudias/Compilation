#include <stdbool.h>
#define SYMBOL_MAX_NAME 64

struct symbol {
    char* id;
    char* type;
    float value;
    bool isconstant;
    struct symbol* next;
};

struct symbol* symbol_alloc();
struct symbol* symbol_lookup(struct symbol* tds,char* id);
struct symbol* symbol_newcst(struct symbol** tds, int nextquad);
struct symbol* symbol_newtemp(struct symbol** tds);
struct symbol* symbol_add(struct symbol** tds, char* id);
void symbol_print(struct symbol* tds);
