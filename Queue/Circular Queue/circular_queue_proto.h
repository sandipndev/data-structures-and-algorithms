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
    return (rx.REAR+1)%rx.MAX == rx.FRONT;
}

void enqueue(queue *rx, int key) {
    if (is_queue_full(*rx)) {
        printf("[!] Queue Overflow!\n");
        return;
    }
    if (is_queue_empty(*rx)) {
        rx->FRONT = 0;
        rx->REAR = 0;
	} else {
		rx->REAR = (rx->REAR+1)%rx->MAX;
	}
    rx->base[rx->REAR] = key;
}

int dequeue(queue *rx) {
    if (is_queue_empty(*rx)) {
        return INT_MIN;
    }
    if (rx->FRONT == rx->REAR) {
		int term = rx->base[rx->FRONT];
		rx->FRONT = -1; rx->REAR = -1;
		return term;
	} else {
		int term = rx->base[rx->FRONT];
		rx->FRONT = (rx->FRONT + 1) % rx->MAX;
		return term;
	}
}

void print_queue(queue rx) {
	printf("FRONT=%d, REAR=%d\n", rx.FRONT, rx.REAR);

    if (is_queue_empty(rx)) {
        printf("[]\n");
        return;
    }

    printf("[ ");
	int i;
	for (i=rx.FRONT; i!=rx.REAR; i= (i+1)%rx.MAX)
		printf("%d,", rx.base[i]);
	if (rx.REAR != -1)	printf("%d,", rx.base[rx.REAR]);
	printf("\b]\n");
}

void free_queue(queue rx) {
    free(rx.base);
}