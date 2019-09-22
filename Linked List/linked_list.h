#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *link;
} node;

node *create_node(int key) {
	node *temp;
	temp = (node *) calloc(1, sizeof(node));
	if (temp == NULL) {
		printf("[OUT_OF_MEM] Memory Error\n");
		exit(0);
	}
	temp -> data = key;
	temp -> link = NULL;
	return temp;
}

void free_list(node *head) {
	node *p=head, *q;
	while(p != NULL) {
		q = p->link;
		free(p);
		p = q;
	}
}

void display_list(node *head) {
	printf("[ ");
	while (head!=NULL) {
		printf("%d,", head->data);
		head = head->link;
	}
	printf("\b]\n");
}

void display_list_with_mem(node *head) {
	printf("[ ");
	while (head!=NULL) {
		printf("<%u> -> %d,", head, head->data);
		head = head->link;
	}
	printf("\b]\n");
}

node *insert_first(node *head, int key) {
	node *temp;
	temp = create_node(key);
	if (head == NULL) {
		head = temp;
	} else {
		temp->link = head;
		head = temp;
	}
	return head;
}

node *insert_last(node *head, int key) {
	node *temp, *p = head;
	temp = create_node(key);
	if (head == NULL) {
		head = temp;
	} else {
		while ((head->link)!=NULL) {
			head = head->link;
		}
		head->link = temp;
	}
	return p;
}

node *insert_before(node *head, int data, int key) {
	node *temp, *p;
	if (head == NULL) {
		printf("[!] Empty List.\n");
		return head;
	}
	p = head;
	while (p->link!=NULL) {
		if((p->link)->data == data)
			break;
		p = p->link;
	}
	if (p->link == NULL)
		printf("[X] Data Not Found.\n");
	else {
		temp = create_node(key);
		temp->link = p->link;
		p->link = temp;
	}
	return head;
}

node *insert_after(node *head, int data, int key) {
	node *temp, *p;
	if (head == NULL) {
		printf("[!] Empty List. \n");
		return head;
	}
	p = head;
	while(p!=NULL) {
		if (p->data == data)
			break;
		p = p->link;
	}
	if (p==NULL) {
		printf("[X] Data Not Found.\n");
	} else {
		temp = create_node(key);
		temp->link = p->link;
		p->link = temp;
	}
	return head;
}

node *delete_first(node *head) {
	if (head == NULL) {
		printf("[LLIST_UFLOW] Linked List was Underflow!\n");
		return head;
	}
	node *temp = head;
	head = head -> link;
	printf("Deleted %d.\n", temp->data);
	free(temp);
	return head;
}

node *delete_last(node *head) {
	if (head == NULL) {
		printf("[LLIST_UFLOW] Linked List was Underflow!\n");
		return head;
	}
	// If one element
	if (head->link == NULL) {
		printf("Deleted %d.\n", head->data);
		free(head);
		return NULL;
	}
	node *temp = head, *p = head;
	head = head->link;
	while (head->link != NULL) {
		temp = head;
		head = head->link;
	}
	temp->link = NULL;
	printf("Deleted %d.\n", head->data);
	free(head);
	return p;
}
node *delete_any(node *head, int key) {
	node *p, *q;
	if(head == NULL) {
		printf("[!] Empty List. \n" );
		return head;
	}
	if (head -> data == key) {
		p = head;
		head = head -> link;
		free(p);
	} else {
		p = head;
		while (p!= NULL && p->data != key) {
			q = p;
			p = p->link;
		}
		if (p == NULL)
			printf("[X] Key Not Found.\n");
		else {
			q->link = p->link;
			free(p);
		}
	}
	return head;
}

node *insert_elem_sorted(node *head, int key) {
	node *p, *q, *temp = create_node(key);
	if (head == NULL) {
		head = temp;
		return head;
	}
	if (head->data >= key) {
		temp->link = head;
		head = temp;
	} else {
		p = head;
		while (p!=NULL && p->data <= key) {
			q = p;
			p = p->link;
		}
		q->link = temp;
		temp->link = p;
	}
	return head;
}

node *reverse(node *head) {
	if (head == NULL) {
		return head;
	}
	node *rev = NULL;
	while (head != NULL) {
		rev = insert_first(rev, head->data);
		head = head->link;
	}
	return rev;
}

node *sort(node *head) {

	// empty or only one element is already sorted
	if (head == NULL || head->link == NULL) {
		return head;
	}

	node *i = head, *j, *min;
	while (i->link != NULL) { // will run till second last element
		min = i;
		j = i->link;
		while (j != NULL) {
			if (min->data > j->data) {
				min = j;
			}
			// updation
			j = j->link;
		}
		if (min != i) {
			// interchange min and i
			int temp = min->data;
			min->data = i->data;
			i->data = temp;
		}

		// updation
		i = i->link;
	}

	return head;
}