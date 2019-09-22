#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *addr;
	int FRONT;
	int REAR;
	int CAPACITY;
} Queue;

Queue create_queue(int);
void print_queue(Queue);
int is_full(Queue);
int is_empty(Queue);
void en_queue_rear(Queue *, int);
void en_queue_front(Queue *, int);
int de_queue_front(Queue *);
int de_queue_rear(Queue *);

int main () {
	system("clear");
	int m, ch, term;
	printf("?MaxCap: ");
	scanf("%d", &m);
	Queue qx = create_queue(m);
	printf("1. Print\n2. EnQueue Rear\n3. EnQueue Front\n4. DeQueue Front\n5. DeQueue Rear\n6. Is Empty?\n7. Is Full?\n");
	while(1) {
		printf("?Choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1:	print_queue(qx);
			break;
			case 2:	printf("?Term: ");
				scanf("%d", &term);
				en_queue_rear(&qx, term);
			break;
			case 3: printf("?Term: ");
				scanf("%d", &term);
				en_queue_front(&qx, term);
			break;
			case 4:	term = de_queue_front(&qx);
				if (term == -1)
					printf("[!] Queue Underflow\n");
				else
					printf("Popped Element: %d\n", term);
			break;
			case 5: term = de_queue_rear(&qx);
				if (term == -1)
					printf("[!] Queue Underflow\n");
				else
					printf("Popped Element: %d\n", term);
			case 6:	term = is_empty(qx);
				if (term)	printf("[!] Empty\n");
				else		printf("[!] Non Empty\n");
			break;
			case 7: term = is_full(qx);
				if (term)	printf("[!] Full\n");
				else		printf("[!] Non Full\n");
			break;
			default: 	free(qx.addr);
					printf("Goodbye\n");
					return 0;
		}
	}
	free(qx.addr);
	return 0;
}

Queue create_queue(int max) {
	Queue tx;
	tx.addr = (int *) calloc(max, sizeof(int));
	tx.FRONT = -1;
	tx.REAR = -1;
	tx.CAPACITY = max;
	return tx;
}

void print_queue(Queue rx) {
	printf("FRONT=%d, REAR=%d\n", rx.FRONT, rx.REAR);
	printf("[ ");
	int i;
	for (i=rx.FRONT; i!=rx.REAR; i= (i+1)%rx.CAPACITY)
		printf("%d,", rx.addr[i]);
	if (rx.REAR != -1)	printf("%d,", rx.addr[rx.REAR]);
	printf("\b]\n");
}

int is_full(Queue rx) {
	return (rx.REAR+1)%rx.CAPACITY == rx.FRONT;
}

int is_empty(Queue rx) {
	return rx.REAR == -1;
}

void en_queue_rear(Queue *rx, int key) {
	if (is_full(*rx)) {
		printf("[!] Queue Overflow\n");
		return;
	}
	if (rx->FRONT == -1) {
		rx->FRONT = 0;
		rx->REAR = 0;
	} else {
		rx->REAR = (rx->REAR+1)%rx->CAPACITY;
	}
	rx->addr[rx->REAR] = key;
}

void en_queue_front(Queue *rx, int key) {
	if ((rx->REAR+1)%rx->CAPACITY == rx->FRONT) {
		printf("[!] Queue Overflow\n");
		return;
	}
	if (rx->FRONT == -1) {
		rx->FRONT = 0;
		rx->REAR = 0;
	} else {
		rx->FRONT = (rx->FRONT - 1 + rx->CAPACITY) % rx->CAPACITY;
	}
	rx->addr[rx->FRONT] = key;
}

int de_queue_front(Queue *rx) {
	if (is_empty(*rx))
		return -1;
	if (rx->FRONT == rx->REAR) {
		int term = rx->addr[rx->FRONT];
		rx->FRONT = -1; rx->REAR = -1;
		return term;
	} else {
		int term = rx->addr[rx->FRONT];
		rx->FRONT = (rx->FRONT + 1) % rx->CAPACITY;
		return term;
	}
}

int de_queue_rear(Queue *rx) {
	if (rx->REAR == -1)
		return -1;
	if(rx->FRONT == rx->REAR) {
		int term = rx->addr[rx->REAR];
		rx->FRONT = -1; rx->REAR = -1;
		return term;
	} else {
		int term = rx->addr[rx->REAR];
		if (rx->REAR == 0)
			rx->REAR = rx->CAPACITY-1;
		else
			rx->REAR = rx->REAR - 1;
		return term;
	}
}
