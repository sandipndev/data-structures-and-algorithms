#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main() {
	node *head = NULL;
	int choice, key, pdata;

	printf("[ THE CELEBRATED LINKED LIST MENU DRIVEN PROGRAM ]\n");
	printf("These are your options :-\n");
	printf("1. Display list\n");
	printf("2. Display list along with mem addr\n");
	printf("3. Insert element at first\n");
	printf("4. Insert element at last\n");
	printf("5. Delete element from first\n");
	printf("6. Delete element from last\n");
	printf("7. Insert element before another element\n");
	printf("8. Insert element after another element\n");
	printf("9. Delete any element\n");
	printf("10. Reverse Linked List\n");
	printf("11. Insert Element in Sorted Manner\n");
	printf("12. Sort\n");


	while (1) {
		fflush(stdin);
		printf("? Your choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1: display_list(head);
			break;
			case 2: display_list_with_mem(head);
			break;
			case 3: printf("? Term to enter: ");
				scanf("%d", &key);
				head = insert_first(head, key);
			break;
			case 4: printf("? Term to enter: ");
				scanf("%d", &key);
				head = insert_last(head, key);
			break;
			case 5: head = delete_first(head);
			break;
			case 6: head = delete_last(head);
			break;
			case 7: printf("? Data before which element needs to be added: ");
				scanf("%d", &pdata);
				printf("? Data to be added: ");
				scanf("%d", &key);
				head = insert_before(head, pdata, key);
			break;
			case 8: printf("? Data after which element needs to be added: ");
				scanf("%d", &pdata);
				printf("? Data to be added: ");
				scanf("%d", &key);
				head = insert_after(head, pdata, key);
			break;
			case 9: printf("? Element to delete: ");
				scanf("%d", &key);
				head = delete_any(head, key);
			break;
			case 10: printf("Reversed: ");
				display_list(reverse(head));
			break;
			case 11: printf("? Term to enter: ");
				scanf("%d", &key);
				head = insert_elem_sorted(head, key);
			break;
			case 12: printf("Sorted List: ");
				display_list(sort(head));
			break;
			default: 
				printf("Goodbye!\n");
				free(head);
				exit(0);
		}
	}
}
