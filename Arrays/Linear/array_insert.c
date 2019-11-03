#include <stdio.h>
#include <stdlib.h>
#include "linear_proto.h"

void insert_element(array *, int);

int main() {
    int length;
    printf("? Length of array: ");
    scanf("%d", &length);

    array arr = create_array(length);
    array_user_input(arr);
    printf("Your array: ");
    print_array(arr);

    int element;
    printf("? Element to be added: ");
    scanf("%d", &element);
    insert_element(&arr, element);
    print_array(arr);
}

void insert_element(array *tx, int key) {
    tx->base = realloc(tx->base, tx->len + 1);
    tx->base[tx->len] = key;
    tx->len++;
}