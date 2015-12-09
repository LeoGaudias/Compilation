typedef struct matrix_int{
  int row;
  int column;
  //pas tellement sur que ça fonctionne ça
  int **tab;
} matrix_int;

typedef struct matrix_float{
  int row;
  int column;
  //pas tellement sur que ça fonctionne ça
  float **tab;
} matrix_float;

//int
struct matrix_int* matrix_int_init(int r, int c);
struct matrix_int* matrix_int_trans(matrix_int* matrix);
struct matrix_int* matrix_int_add_sub(matrix_int* matrix1, matrix_int* matrix2,char op);
struct matrix_int* matrix_int_mul_cst(matrix_int* matrix, int cst);
struct matrix_int* matrix_int_mul_div(matrix_int* matrix1, matrix_int* matrix2,char op);
struct matrix_int* matrix_int_extract(matrix_int* matrix,char* rows,char* columns);
void free_matrix_int(matrix_int* matrix);
void matrix_int_print(struct matrix_int* mat);

//float
struct matrix_float* matrix_float_init(int r, int c);
struct matrix_float* matrix_float_trans(matrix_float* matrix);
struct matrix_float* matrix_float_add_sub(matrix_float* matrix1, matrix_float* matrix2,char op);
struct matrix_float* matrix_float_mul_cst(matrix_float* matrix, int cst);
struct matrix_float* matrix_float_mul_div(matrix_float* matrix1, matrix_float* matrix2,char op);
struct matrix_float* matrix_float_extract(matrix_float* matrix,char* rows,char* columns);
void free_matrix_float(matrix_float* matrix);
void matrix_float_print(struct matrix_float* mat);