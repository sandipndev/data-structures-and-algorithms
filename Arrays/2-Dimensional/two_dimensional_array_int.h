#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int **base;
    int rows;
    int cols;
} matrix;

matrix create_matrix(int, int);
void matrix_user_input(matrix);
void print_matrix(matrix);
void free_matrix(matrix);

