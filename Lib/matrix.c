#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "quad.h"
#include "symbol.h"
#include "matrix.h"

//int
// struct matrix_int* matrix_int_init(int r, int c)
// {
//   struct matrix_int* matrix = malloc(sizeof(*matrix));
//   matrix->row = r;
//   matrix->column = c;
 
//   int i;
//   matrix->tab = malloc(r * sizeof(*matrix->tab));
//   for (i = 0; i < r ; i++) { // j'ai modifié i<c en i<r je pense que c'est plus juste
//     matrix->tab[i] = malloc(c * sizeof(int));
//   }
//   return matrix;
// }

// struct matrix_int* matrix_int_trans(matrix_int* matrix)
// {
// 	matrix_int* new_matrix=matrix_int_init(matrix->column,matrix->row);
// 	int i,j,c,r;
	
// 	for(i=0;i<matrix->column;i++)
// 	{
// 		for(j=0;j<matrix->row;j++)
// 		{
// 			new_matrix->tab[i][j]=matrix->tab[j][i];
// 		}
// 	}
// 	return new_matrix;
// }

// struct matrix_int* matrix_int_add_sub(matrix_int* matrix1, matrix_int* matrix2,char op)
// {
// 	if(matrix1->column==matrix2->column && matrix1->row==matrix2->row)
// 	{
// 		struct matrix_int* new_matrix=matrix_int_init(matrix1->row,matrix1->column);
// 		int i,j,c,r;
		
// 		for(i=0;i<matrix1->row;i++)
// 		{
// 			for(j=0;j<matrix1->column;j++)
// 			{
// 				if(op=='+')
// 				{
// 					new_matrix->tab[i][j]=matrix1->tab[i][j]+matrix2->tab[i][j];
// 				}
// 				else
// 				{
// 					new_matrix->tab[i][j]=matrix1->tab[i][j]-matrix2->tab[i][j];
// 				}
// 			}
// 		}
// 		return new_matrix;
// 	}
// 	else
// 	{
// 		fprintf(stderr,"error : size of matrix aren't the same \n");
// 		return NULL;
// 	}
// }

// struct matrix_int* matrix_int_mul_cst(matrix_int* matrix, int cst)
// {
// 	struct matrix_int* new_matrix=matrix_int_init(matrix->row,matrix->column);
// 	int i,j;
	
// 	for(i=0;i<matrix->row;i++)
// 	{
// 		for(j=0;j<matrix->column;j++)
// 		{
// 			new_matrix->tab[i][j]=matrix->tab[i][j]*cst;
// 		}
// 	}
// 	return new_matrix;
// }

// struct matrix_int* matrix_int_mul_div(matrix_int* matrix1, matrix_int* matrix2,char op)
// {
// 	if(matrix1->column==matrix2->row)
// 	{
// 		struct matrix_int* new_matrix=matrix_int_init(matrix2->column,matrix1->row);
// 		int i,j,k,temp;
		
// 		for(i=0;i<new_matrix->row;i++)
// 		{
// 			for(j=0;j<new_matrix->column;j++)
// 			{
// 				temp=0;
// 				for(k=0;k<matrix1->column;k++)
// 			{	
// 					if(op=='*')
// 					{
// 						temp+=matrix1->tab[i][k]*matrix2->tab[j][k];
// 					}
// 					else
// 					{
// 						temp+=matrix1->tab[i][k]/matrix2->tab[j][k];
// 					}
// 				}
// 				new_matrix->tab[i][j]=temp;
// 			}
// 		}
// 		return new_matrix;
// 	}
// 	else
// 	{
// 		fprintf(stderr, "error : column of matrix1 isn't the same as row of matrix2 \n");
// 		return NULL;
// 	}
// }

// struct matrix_int* matrix_int_extract(matrix_int* matrix,char* rows,char* columns)
// {
// 	// check what's to do for the rows
// 	int* row;
// 	char* cop=strdup(rows);
// 	char* check=strtok(cop,";");
	
// 	int i=0;
// 	while(check!=NULL) // gets every strings delimited by ;
// 	{
// 		if(strlen(check)>1) // something like 4..7
// 		{
// 			char* temp;
// 			int start=atoi(strncpy(temp, check, 1)); // gets 4
// 			int end=atoi(strncpy(temp, check+3, 1)); // get 7
// 			row=realloc(row,sizeof(int)*(i+(end-start+1))); // la flemme de faire une liste chaînée ... si tu trouves mieux
			
// 			int j=-1;
// 			for(j=start;j<=end;j++)
// 			{
// 				row[i]=j;
// 				i++;
// 			}
// 		}
// 		else // just a value
// 		{
// 			if(check[0]=='*') // * which means every row
// 			{
// 				row=realloc(row,sizeof(int)*(i+matrix->row));
// 				int j=-1;
// 				for(j=0;j<matrix->row;j++)
// 				{
// 					row[i]=j;
// 					i++;
// 				}
// 			}
// 			else // only int
// 			{
// 				row=realloc(row,sizeof(int)*(i+1)); // la flemme de faire une liste chaînée ... si tu trouves mieux
// 				row[i]=atoi(check);
// 				i++;
// 			}
// 		}
		
// 		check=strtok(NULL,";");
// 	}
	
// 	// check what's to do for the col
// 	int* col;
// 	cop=strdup(columns);
// 	check=strtok(cop,";");
	
// 	i=0;
// 	while(check!=NULL) // gets every strings delimited by ;
// 	{
// 		if(strlen(check)>1) // something like 4..7
// 		{
// 			char* temp;
// 			int start=atoi(strncpy(temp, check, 1)); // gets 4
// 			int end=atoi(strncpy(temp, check+3, 1)); // get 7
// 			col=realloc(col,sizeof(int)*(i+(end-start+1))); // la flemme de faire une liste chaînée ... si tu trouves mieux
			
// 			int j=-1;
// 			for(j=start;j<=end;j++)
// 			{
// 				col[i]=j;
// 				i++;
// 			}
// 		}
// 		else // just a value
// 		{
// 			if(check[0]=='*') // * which means every col
// 			{
// 				col=realloc(col,sizeof(int)*(i+matrix->column));
// 				int j=-1;
// 				for(j=0;j<matrix->column;j++)
// 				{
// 					col[i]=j;
// 					i++;
// 				}
// 			}
// 			else // only int
// 			{
// 				col=realloc(col,sizeof(int)*(i+1)); // la flemme de faire une liste chaînée ... si tu trouves mieux
// 				col[i]=atoi(check);
// 				i++;
// 			}
// 		}
		
// 		check=strtok(NULL,";");
// 	}
	
// 	// do what's to do (derp)
	
// 	struct matrix_int* new_matrix=matrix_int_init(sizeof(row)/sizeof(row[0]),sizeof(col)/sizeof(col[0]));
	
// 	int r=0,c=0;
// 	int j=-1;
// 	for(i=0;i<sizeof(row)/sizeof(row[0]);i++)
// 	{
// 		for(j=0;j<sizeof(col)/sizeof(col[0]);j++)
// 		{
// 			new_matrix->tab[r][c]=matrix->tab[row[i]][col[j]]; // does it work ? ...
// 			c++;
// 		}
// 		r++;
// 	}
	
	
// 	return new_matrix;
// }

// void free_matrix_int(matrix_int* matrix)
// {
// 	int i=0;
// 	for(i=0;i<matrix->row;i++)
// 	{
// 		free(matrix->tab[i]);
// 	}
// 	free(matrix->tab);
// }

// void matrix_int_print(struct matrix_int* mat)
// {
//   int i, j;
//   for (i = 0; i < mat->row; i++) {
//     printf("| ");
//     for (j = 0; j < mat->column; j++) {
//       printf("%d ",mat->tab[i][j]);
//     }
//     printf("|\n");
//   }
// }


//float
// nouveau symbol puis affect
struct matrix_float* matrix_float_init(int r, int c)
{
  struct matrix_float* m = malloc(sizeof(*m));
  m->row = r;
  m->column = c;
  
  int i;
  m->tab = malloc(r * sizeof(*m->tab));
  for (i = 0; i < r ; i++)
  {
    m->tab[i] = malloc(c * sizeof(float));
  }
  return m;
}

// symbol lookup puis générer quad d'affectation
struct matrix_float* matrix_float_trans(struct matrix_float* matrix)
{
	struct matrix_float* m = matrix_float_init(matrix->column, matrix->row);
	int i,j;
	
	for(i = 0; i < matrix->column; i++)
	{
		for(j = 0; j < matrix->row; j++)
		{
			m->tab[i][j] = matrix->tab[j][i];
		}
	}
	return m;
}

struct matrix_float* matrix_float_add_sub(struct matrix_float* matrix1, struct matrix_float* matrix2,  char op, struct symbol ** tds, struct quad ** q, int* nextquad)
{
	if(matrix1->column == matrix2->column && matrix1->row == matrix2->row)
	{
		struct matrix_float* new_matrix = matrix_float_init(matrix1->row, matrix1->column);
		int i,j;
		
		struct symbol * temp_1, *temp_2;
		
		for(i = 0; i < matrix1->row; i++)
		{
			for(j = 0; j < matrix1->column; j++)
			{
				if(op == '+')
				{
					new_matrix->tab[i][j] = matrix1->tab[i][j] + matrix2->tab[i][j]; 
					
					temp_1 = symbol_newtemp(tds);
					temp_1->type = "float";
					temp_1->value = matrix1->tab[i][j];
					
					temp_2 = symbol_newtemp(tds);
					temp_2->type = "float";
					temp_2->value = matrix2->tab[i][j];
					quad_add(q,quad_gen(
						nextquad,
						"+", 
						temp_1,
						temp_2,
						symbol_newtemp(tds)
						));
					// concatQuad(*q, quad_gen(
					// 	nextquad,
					// 	"+", 
					// 	temp_1,
					// 	temp_2,
					// 	symbol_newtemp(tds)
					// 	));
					(*nextquad)++; 
				}
				else
				{
					new_matrix->tab[i][j] = matrix1->tab[i][j] - matrix2->tab[i][j];
					temp_1 = symbol_newtemp(tds);
					temp_1->type = "float";
					temp_1->value = matrix1->tab[i][j];
					
					temp_2 = symbol_newtemp(tds);
					temp_2->type = "float";
					temp_2->value = matrix2->tab[i][j];
					quad_add(q,quad_gen(
						nextquad,
						"-", 
						temp_1,
						temp_2,
						symbol_newtemp(tds)
						));
					// concatQuad(*q, quad_gen(
					// 	nextquad,
					// 	"-", 
					// 	temp_1,
					// 	temp_2,
					// 	symbol_newtemp(tds)
					// 	));
					(*nextquad)++; 
				}
			}
		}
		return new_matrix;
	}
	else
	{
		fprintf(stderr,"error : size of matrix aren't the same \n");
		return NULL;
	}
}

struct matrix_float* matrix_float_mul_cst(struct matrix_float* matrix, struct symbol * cst, struct symbol ** tds, struct quad ** q, int* nextquad)
{
	struct matrix_float* new_matrix = matrix_float_init(matrix->row, matrix->column);
	int i, j;
	
	for(i = 0; i < matrix->row; i++)
	{
		for(j = 0; j < matrix->column; j++)
		{
			new_matrix->tab[i][j] = matrix->tab[i][j] * cst->value;
			
			struct symbol * temp_1 = symbol_newtemp(tds);
			temp_1->type = "float";
			temp_1->value = matrix->tab[i][j];
			
			quad_add(q,quad_gen(
				nextquad,
				"*", 
				temp_1,
				cst,
				symbol_newtemp(tds)
				));
			
			/*concatQuad(*q, quad_gen(
				nextquad,
				"*", 
				temp_1,
				cst,
				symbol_newtemp(tds)
				));*/
			(*nextquad)++; 
		}
	}
	return new_matrix;
}

struct matrix_float* matrix_float_mul_div(struct matrix_float* matrix1, struct matrix_float* matrix2, char op, struct symbol ** tds, struct quad ** q, int* nextquad)
{
	if(matrix1->column == matrix2->row)
	{
		struct matrix_float* new_matrix = matrix_float_init(matrix2->column, matrix1->row);
		int i,j,k;
		float temp;
		struct symbol * temp_1, * temp_2, * temp_3, * temp_4;
		
		for(i = 0; i < new_matrix->row; i++)
		{
			for(j = 0; j < new_matrix->column; j++)
			{
				temp = 0;
				
				temp_1 = symbol_newtemp(tds);
				temp_1->type = "float";
				temp_1->value = 0;
				
				for(k = 0; k < matrix1->column; k++)
				{	
					if(op == '*')
					{
						temp += matrix1->tab[i][k] * matrix2->tab[j][k];
						
						temp_2 = symbol_newtemp(tds);
						temp_2->type = "float";
						temp_2->value = matrix1->tab[i][k];
						
						temp_3 = symbol_newtemp(tds);
						temp_3->type = "float";
						temp_3->value = matrix2->tab[j][k];
						
						temp_4 = symbol_newtemp(tds);
						temp_4->type = "float";
						temp_4->value = matrix1->tab[i][k] * matrix2->tab[j][k];
						
						quad_add(q,quad_gen(
							nextquad,
							"*", 
							temp_2,
							temp_2,
							temp_4
							));
						// concatQuad(*q, quad_gen(
						// 	nextquad,
						// 	"*", 
						// 	temp_2,
						// 	temp_2,
						// 	temp_4
						// 	));
						(*nextquad)++;
					}
					else
					{
						temp += matrix1->tab[i][k] / matrix2->tab[j][k];
						
						temp_2 = symbol_newtemp(tds);
						temp_2->type = "float";
						temp_2->value = matrix1->tab[i][k];
						
						temp_3 = symbol_newtemp(tds);
						temp_3->type = "float";
						temp_3->value = matrix2->tab[j][k];
						
						temp_4 = symbol_newtemp(tds);
						temp_4->type = "float";
						temp_4->value = matrix1->tab[i][k] * matrix2->tab[j][k];
						
						quad_add(q,quad_gen(
							nextquad,
							"/", 
							temp_2,
							temp_2,
							temp_4
							));
						// concatQuad(*q, quad_gen(
						// 	nextquad,
						// 	"/", 
						// 	temp_2,
						// 	temp_2,
						// 	temp_4
						// 	));
						(*nextquad)++;
					}
				}
				
				quad_add(q,quad_gen(
							nextquad,
							"+", 
							temp_1,
							temp_4,
							symbol_newtemp(tds)
							));
				
				/*concatQuad(*q, quad_gen(
							nextquad,
							"+", 
							temp_1,
							temp_4,
							symbol_newtemp(tds)
							));*/
						(*nextquad)++;
						
				new_matrix->tab[i][j] = temp;
			}
		}
		return new_matrix;
	}
	else
	{
		fprintf(stderr, "error : column of matrix1 isn't the same as row of matrix2 \n");
		return NULL;
	}
}

struct matrix_float* matrix_float_extract(struct matrix_float* matrix, char* rows, char* columns)
{
	// check what's to do for the rows
	int* row;
	char* cop = strdup(rows);
	char* check = strtok(cop,";");
	
	int i=0;
	while(check!=NULL) // gets every strings delimited by ;
	{
		if(strlen(check)>1) // something like 4..7
		{
			char* temp=NULL;
			int start = atoi(strncpy(temp, check, 1)); // gets 4
			int end = atoi(strncpy(temp, check+3, 1)); // get 7
			row = realloc(row,sizeof(int)*(i+(end-start+1))); // la flemme de faire une liste chaînée ... si tu trouves mieux
			
			int j = -1;
			for(j=start;j<=end;j++)
			{
				row[i]=j;
				i++;
			}
		}
		else // just a value
		{
			if(check[0] == '*') // * which means every row
			{
				row = realloc(row,sizeof(int)*(i+matrix->row));
				int j = -1;
				for(j = 0; j < matrix->row; j++)
				{
					row[i] = j;
					i++;
				}
			}
			else // only int
			{
				row = realloc(row,sizeof(int)*(i+1)); // la flemme de faire une liste chaînée ... si tu trouves mieux
				row[i] = atoi(check);
				i++;
			}
		}
		
		check=strtok(NULL,";");
	}
	
	// check what's to do for the col
	int* col;
	cop=strdup(columns);
	check=strtok(cop,";");
	
	i=0;
	while(check!=NULL) // gets every strings delimited by ;
	{
		if(strlen(check)>1) // something like 4..7
		{
			char* temp=NULL;
			int start=atoi(strncpy(temp, check, 1)); // gets 4
			int end=atoi(strncpy(temp, check+3, 1)); // get 7
			col=realloc(col,sizeof(int)*(i+(end-start+1))); // la flemme de faire une liste chaînée ... si tu trouves mieux
			
			int j=-1;
			for(j=start;j<=end;j++)
			{
				col[i]=j;
				i++;
			}
		}
		else // just a value
		{
			if(check[0]=='*') // * which means every col
			{
				col=realloc(col,sizeof(int)*(i+matrix->column));
				int j=-1;
				for(j=0;j<matrix->column;j++)
				{
					col[i]=j;
					i++;
				}
			}
			else // only int
			{
				col=realloc(col,sizeof(int)*(i+1)); // la flemme de faire une liste chaînée ... si tu trouves mieux
				col[i]=atoi(check);
				i++;
			}
		}
		
		check=strtok(NULL,";");
	}
	
	// do what's to do (derp)
	struct matrix_float * new_matrix = matrix_float_init(sizeof(row)/sizeof(row[0]),sizeof(col)/sizeof(col[0]));
	
	int r = 0, c = 0;
	int j = -1;
	for(i = 0; i < sizeof(row) / sizeof(row[0]); i++)
	{
		for(j = 0;j < sizeof(col) / sizeof(col[0]); j++)
		{
			new_matrix->tab[r][c] = matrix->tab[row[i]][col[j]]; // does it work ? ...
			c++;
		}
		r++;
	}
	return new_matrix;
}

void matrix_float_free(struct matrix_float* matrix)
{
	int i=0;
	for(i = 0; i < matrix->row; i++)
	{
		free(matrix->tab[i]);
	}
	free(matrix->tab);
}

void matrix_float_print(struct matrix_float* mat)
{
  int i, j;
  for (i = 0; i < mat->row; i++)
  {
    printf("| ");
    for (j = 0; j < mat->column; j++)
    {
      printf("%f ",mat->tab[i][j]);
    }
    printf("|\n");
  }
}