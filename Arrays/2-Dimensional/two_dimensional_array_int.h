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

matrix create_matrix(int rows, int cols) {
    matrix tx;
    
    // For the matrix data
    tx.base = (int **) calloc(rows, sizeof(int *));
    int i;
    for (i=0; i<rows; i++) {
        tx.base[i] = (int *) calloc(cols, sizeof(int));
    }

    // And some metadata
    tx.cols = cols;
    tx.rows = rows;

    return tx;
}

void matrix_user_input(matrix rx) {
    fflush(stdin);
    int i, j;
    for (i=0; i<rx.rows; i++) {
        for (j=0; j<rx.cols; j++) {
            printf("?(%d,%d): ", i+1, j+1);
            scanf("%d", &rx.base[i][j]);
        }
    }
}

void print_matrix(matrix rx) {
    int i, j;
    for (i=0; i<rx.rows; i++) {
        if(i==0)    printf("[  [");
        else        printf("   [");
        for (j=0; j<rx.cols; j++) {
            printf(" %4d,", rx.base[i][j]);
        }
        if (j==0)   printf("]");
        else        printf("\b]");
        if (i==rx.rows-1)   printf("  ");
        else                printf("\n");
    }
    printf("]\n");
}

void free_matrix(matrix rx) {
    int i;
    for (i=0; i<rx.rows; i++) {
        free(rx.base[i]);
    }
    free(rx.base);
}