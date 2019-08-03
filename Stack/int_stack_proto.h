#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *base;
    int TOP;
    int MAX;
} stack;

stack create_stack (int);
int is_empty (stack);
int is_full (stack);
void push (stack *, int);
int pop (stack *);
int peek (stack);
void print_stack (stack);
void free_stack (stack);

stack create_stack (int max) {
    stack tx;
    tx.base = (int *) calloc(max, sizeof(int));
    tx.TOP = -1;
    tx.MAX = max;
    return tx;
}

int is_empty (stack rx) {
    return rx.TOP == -1;
}

int is_full (stack rx) {
    return rx.TOP == rx.MAX-1;
}

void push (stack *rx, int key) {
    if (is_full(*rx)) {
        printf("[!] Stack Overflow\n");
        return;
    }
    rx->base[++rx->TOP] = key;
}

int pop (stack *rx) {
    if (is_empty(*rx)) {
        printf("[!] Stack Underflow\n");
        return INT_MIN;
    }
    return rx->base[rx->TOP--];
}

int peek (stack rx) {
    if (is_empty(rx)) {
        printf("Nothing to peek\n");
        return INT_MIN;
    }
    return rx.base[rx.TOP];
}

void print_stack(stack rx) {
    printf("[");
    int i;
    for (i=0; i<=rx.TOP; i++) {
        printf("%d,", rx.base[i]);
    }
    if (i!=0)   printf("\b]\n");
    else        printf("]\n");
}

void free_stack(stack rx) {
    free(rx.base);
}