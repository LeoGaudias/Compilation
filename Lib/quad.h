struct quad {
    int label;
    char* op;
    struct symbol* arg1;
    struct symbol* arg2;
    struct symbol* res;
    struct quad* nextquad;
};

struct quad_list {
    struct quad* first_quad;
};

struct quad* quad_gen(int* label, char* op, struct symbol* arg1, struct symbol* arg2, struct symbol* res);
void quad_add(struct quad** list, struct quad* new);
void quad_print(struct quad* list);
struct quad* concatQuad(struct quad * q1, struct quad * q2);

struct quad_list* newlist(struct quad *q);
struct quad_list* concatList(struct quad_list* l1, struct quad_list* l2);
void complete(struct quad_list* l, struct symbol* tag);
