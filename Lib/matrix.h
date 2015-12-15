// typedef struct matrix_int{
//   int row;
//   int column;
//   int **tab;
// } matrix_int;

struct matrix_float{
  int row;
  int column;
  float **tab;
};

//int
// struct matrix_int* matrix_int_init(int r, int c);
// struct matrix_int* matrix_int_trans(matrix_int* matrix);
// struct matrix_int* matrix_int_add_sub(matrix_int* matrix1, matrix_int* matrix2,char op);
// struct matrix_int* matrix_int_mul_cst(matrix_int* matrix, int cst);
// struct matrix_int* matrix_int_mul_div(matrix_int* matrix1, matrix_int* matrix2,char op);
// struct matrix_int* matrix_int_extract(matrix_int* matrix,char* rows,char* columns);
// void free_matrix_int(matrix_int* matrix);
// void matrix_int_print(struct matrix_int* mat);

//float

struct matrix_float* matrix_float_init(int r, int c);

struct matrix_float* matrix_float_trans(struct matrix_float* matrix);

struct matrix_float* matrix_float_add_sub(struct matrix_float* matrix1,
                                          struct matrix_float* matrix2,
                                          char op,
                                          struct symbol ** tds,
                                          struct quad ** q,
                                          int* nextquad);

struct matrix_float* matrix_float_mul_cst(struct matrix_float* matrix,
                                          struct symbol * cst,
                                          struct symbol ** tds,
                                          struct quad ** q,
                                          int* nextquad);

struct matrix_float* matrix_float_mul_div(struct matrix_float* matrix1,
                                          struct matrix_float* matrix2,
                                          char op,
                                          struct symbol ** tds,
                                          struct quad ** q,
                                          int* nextquad);

struct matrix_float* matrix_float_extract(struct matrix_float* matrix, 
                                          char* rows,
                                          char* columns);

void matrix_float_free(struct matrix_float* matrix);

void matrix_float_print(struct matrix_float* mat);