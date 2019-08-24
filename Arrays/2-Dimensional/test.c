#include <stdio.h>
#include "two_dimensional_array_int.h"

int main() {
    int r, c;
    printf("?Rows: ");
    scanf("%d", &r);
    printf("?Cols: ");
    scanf("%d", &c);

    matrix mat = create_matrix(r, c);
    matrix_user_input(mat);
    print_matrix(mat);
    free_matrix(mat);
}