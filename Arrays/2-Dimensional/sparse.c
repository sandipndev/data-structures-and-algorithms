#include <stdio.h>
#include <stdlib.h>
#include "two_dimensional_array_int.h"

int check_sparse(matrix);
matrix sparse_matrix_three_tuple(matrix);
matrix recreate_from_sparse_three_tuple(matrix);

int main() {
    int r, c;
    printf("?Rows: ");
    scanf("%d", &r);
    printf("?Cols: ");
    scanf("%d", &c);

    matrix mx = create_matrix(r, c);
    printf("Enter the matrix:\n");
    matrix_user_input(mx);

    printf("You have entered:\n");
    print_matrix(mx);

    if (check_sparse(mx) == -1) {
        printf("[X] Not a sparse matrix!\n");
        return 0;
    } else {
        printf("[Y] Is a sparse matrix!\n");
        printf("The Sparse Matrix for the same is:\n");
        print_matrix(sparse_matrix_three_tuple(mx));
    }

    free_matrix(mx);

    return 0;
}

int check_sparse(matrix rx) {
    // If sparse, returns number of zero positions, else returns -1

    int i, j, n_zeros=0;
    for (i=0; i<rx.rows; i++) {
        for (j=0; j<rx.cols; j++) {
            if(rx.base[i][j] == 0) {
                n_zeros++;
            }
        }
    }

    if ((float) n_zeros >= 2.0 / 3.0 * ((float) rx.rows * rx.cols))
        return n_zeros;
    else
        return -1;
}

matrix sparse_matrix_three_tuple(matrix rx) {
    int n_zeros = check_sparse(rx);
    if (n_zeros == -1) {
        n_zeros = 0;
    }
    int n_nonzeros = (rx.rows * rx.cols) - n_zeros;
    matrix sparse = create_matrix(n_nonzeros + 1, 3);

    sparse.base[0][0] = rx.rows;
    sparse.base[0][1] = rx.cols;
    sparse.base[0][2] = n_nonzeros;

    int i, j, c=1;

    for (i=0; i<rx.rows; i++) {
        for (j=0; j<rx.cols; j++) {
            if (rx.base[i][j] != 0) {
                sparse.base[c][0] = i;
                sparse.base[c][1] = j;
                sparse.base[c][2] = rx.base[i][j];
                c++;
            }
        }
    }

    return sparse;
}

matrix recreate_from_sparse_three_tuple(matrix rx) {
    int req_rows = rx.base[0][0];
    int req_cols = rx.base[0][1];
    int n_nz_eles = rx.base[0][2];

    matrix original = create_matrix(req_rows, req_cols);
    int i, row, col;

    for (i=1; i<=n_nz_eles; i++) {
        row = rx.base[i][0];
        col = rx.base[i][1];
        original.base[row][col] = rx.base[i][2];
    }

    return original;
}