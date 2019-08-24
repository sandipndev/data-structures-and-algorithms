#include "two_dimensional_array_int.h"

int mat_multiply_possible(matrix, matrix);
matrix mat_multiply(matrix, matrix);
matrix transpose(matrix);

int mat_multiply_possible(matrix m1, matrix m2) {
    return m1.cols == m2.rows;
}

matrix mat_multiply(matrix m1, matrix m2) {

    if (!mat_multiply_possible(m1, m2)) {
        return create_matrix(0,0);
    }

    matrix multiplied = create_matrix(m1.rows, m2.cols);
    int i, j, k, sum=0;
    for (i=0; i<m1.rows; i++) {
        for (j=0; j<m2.cols; j++) {
            sum = 0;
            for (k=0; k<m1.cols; k++) {
                sum += m1.base[i][k] * m2.base[k][j];
            }
            multiplied.base[i][j] = sum;
        }
    }

    return multiplied;
}

matrix transpose(matrix m) {
    matrix transposed = create_matrix(m.cols, m.rows);
    int i, j;
    for (i=0; i<m.rows; i++) {
        for (j=0; j<m.cols; j++) {
            transposed.base[j][i] = m.base[i][j];
        }
    }
    return transposed;
}