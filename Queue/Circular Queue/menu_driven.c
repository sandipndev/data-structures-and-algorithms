#include <stdio.h>
#include <limits.h>
#include "circular_queue_proto.h"

int main () {
	system("clear");
	int m, ch, term;
	printf("?MaxCap: ");
	scanf("%d", &m);
	queue qx = create_queue(m);
	printf("1. Print\n2. EnQueue\n3. DeQueue\n4. Is Empty?\n5. Is Full?\n");
	while(1) {
		printf("?Choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1:	print_queue(qx);
			break;
			case 2:	printf("?Term: ");
				scanf("%d", &term);
				enqueue(&qx, term);
			break;
			case 3:	term = dequeue(&qx);
				if (term == INT_MIN)
					printf("[!] Queue Underflow\n");
				else
					printf("Popped Element: %d\n", term);
			break;
			case 4:	term = is_queue_empty(qx);
				if (term)	printf("[!] Empty\n");
				else		printf("[!] Non Empty\n");
			break;
			case 5: term = is_queue_full(qx);
				if (term)	printf("[!] Full\n");
				else		printf("[!] Non Full\n");
			break;
			default: 	free_queue(qx);
					printf("Goodbye\n");
					return 0;
		}
	}
	free_queue(qx);
	return 0;
}