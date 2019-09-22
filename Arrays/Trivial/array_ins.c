#include <stdio.h>
#include <stdlib.h>

void array_user_input(int *, int);

void print_array(int *, int);

int *insert_element_into_array(int *, int, int, int);

int main() {
	int l;
	printf("Length of array: ");
	scanf("%d", &l);
	int *arr = (int *) malloc(l * sizeof(l));
	array_user_input(arr, l);
	printf("The entered array is : ");
	print_array(arr, l);
	
	while (1) {
		int ele, pos;
		printf("Enter element to be inserted (-1 to cancel): ");
		scanf("%d", &ele);
		if (ele == -1) {
			printf("Goodbye!\n");
			break;
		}
		while(1) {
			printf("Position where the element is to be inserted: ");
			scanf("%d", &pos);
			if (!(pos-1 >= 0 && pos-1 < l))
				printf("The position needs to be within [1, %d]. Please try again.\n", pos);
			else
				break;
		}
		arr = insert_element_into_array(arr, l, ele, pos);
		l++;
		printf("Extended array is = ");
		print_array(arr, l);
	}
	free(arr);
	return 0;
}

void array_user_input(int *arr, int n) {
	int i;
	for (i=0; i<n; i++) {
		printf("%dth element = ", i+1);
		scanf("%d", &arr[i]);
	}
}

void print_array(int *arr, int n) {
	printf("[");
	int i;
	for (i=0; i<n; i++) {
		printf("%d,", arr[i]);
	}
	printf("\b]\n");
}

int *insert_element_into_array(int *arr, int l, int ele, int pos) {
	int *new_arr = (int *) malloc ((l+1) * sizeof(int));
	int i, c=0;
	for(i=0; i<l; i++) {
		if (i==pos-1)
			new_arr[c++] = ele;
		new_arr[c++] = arr[i];
	}
	free(arr);
	return new_arr;
}
