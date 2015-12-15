#include <stdio.h>

FILE* open(char* add);
void convert(struct quad* code, struct symbol* tds);
void generateFile(struct quad* quads);
void close(FILE* file);