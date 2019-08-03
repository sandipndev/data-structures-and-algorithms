#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *base;
    int len;
} array;

array create_array(int);
void array_user_input(array);
void print_array(array);
void free_array(array);

array create_array(int max) {
    array tx;
    tx.base = (int *) calloc(max, sizeof(int));
    tx.len = max;
    return tx;
}

void array_user_input(array rx) {
    int i;
    for (i=0; i<rx.len; i++) {
        printf("?%dth ele: ", i+1);
        scanf("%d", &rx.base[i]);
    }
}

void print_array(array rx) {
    int i;
    printf("[");
    for (i=0; i<rx.len; i++) {
        printf("%d,", rx.base[i]);
    }
    if (i!=0)   printf("\b]\n");
    else        printf("]\n");
}

void free_array(array rx) {
    free(rx.base);
}