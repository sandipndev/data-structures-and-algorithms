#include <stdio.h>
#include <stdlib.h>
#include "linear_proto.h"

void delete_element(array *, int);

int main() {
    int length;
    printf("? Length of array: ");
    scanf("%d", &length);

    array arr = create_array(length);
    array_user_input(arr);
    printf("Your array: ");
    print_array(arr);

    int element;
    printf("? Element to be deleted: ");
    scanf("%d", &element);
    delete_element(&arr, element);
    print_array(arr);

    return 0;
}

void delete_element(array *tx, int key) {
    int i, j;
    int wasFound = 0;

    for (i=0; i<tx->len; i++) {
        if (tx->base[i] == key) {

            wasFound = 1;

            // Shifting logic
            for (j=i+1; j<tx->len; j++) {
                tx->base[j-1] = tx->base[j];
            }

        }
    }

    if (wasFound == 1) {
        tx->base = realloc(tx->base, tx->len-1);
        tx->len--;
    } else {
        printf("Element was not found.\n");
    }

}