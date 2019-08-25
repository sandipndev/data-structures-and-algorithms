#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int *base;
    int FRONT;
    int REAR;
    int MAX;
} queue;

queue create_queue(int);
int is_queue_empty(queue);
int is_queue_full(queue);
void enqueue(queue *, int);
int dequeue(queue *);
void print_queue(queue);
void free_queue(queue);

queue create_queue(int max) {
    queue tx;
    tx.base = (int *) calloc(max, sizeof(int));
    tx.FRONT = -1;
    tx.REAR = -1;
    tx.MAX = max;
    return tx;
}

int is_queue_empty(queue rx) {
    return rx.FRONT == -1 && rx.REAR == -1;
}

int is_queue_full(queue rx) {
    return rx.REAR == rx.MAX-1;
}

void enqueue(queue *rx, int key) {
    if (is_queue_full(*rx)) {
        printf("[!] Queue Overflow!\n");
        return;
    }
    if (is_queue_empty(*rx)) {
        rx->FRONT = 0;
    }
    rx->base[++rx->REAR] = key;
}

int dequeue(queue *rx) {
    if (is_queue_empty(*rx)) {
        printf("[!] Queue Underflow!\n");
        return INT_MIN;
    }
    int key = rx->base[rx->FRONT];
    rx->FRONT++;
    if(rx->FRONT > rx->REAR) {
        rx->FRONT = -1;
        rx->REAR = -1;
    }
    return key;
}

void print_queue(queue rx) {
    if (is_queue_empty(rx)) {
        printf("[]\n");
        return;
    }

    printf("[");
    int i;
    for (i=rx.FRONT; i<=rx.REAR; i++) {
        printf("%d,", rx.base[i]);
    }
    if (i!=rx.FRONT)    printf("\b]\n");
    else                printf("]\n");
}

void free_queue(queue rx) {
    free(rx.base);
}