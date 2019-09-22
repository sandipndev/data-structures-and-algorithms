#include <stdio.h>
#include <stdlib.h>

void array_user_input(int *, int);

void print_array(int *, int);

int get_delete_position(int *, int, int);

int *delete_element_from_array(int *, int, int);

int main() {
	system("clear");
	int l;
	printf("Length of array: ");
	scanf("%d", &l);
	int *arr = (int *) malloc(l * sizeof(l));
	array_user_input(arr, l);
	printf("The entered array is : ");
	print_array(arr, l);
	
	while (1) {
		int ele, pos;
		while (1) {
			printf("Delete (-1 to cancel): ");
			scanf("%d", &ele);
			if (ele == -1) {
				printf("Goodbye!\n");
				return 0;
			}
			pos = get_delete_position(arr, l, ele);
			if (pos == -1) {
				printf("We couldn't find a value or position with a match! Try again. \n");
				continue;
			} else {
				break;
			}
		}
		arr = delete_element_from_array(arr, l, pos);
		l--;
		printf("Shrinked array is = ");
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

int get_delete_position(int *arr, int len, int val) {
	// Returns -1 if not found
	int chkPos = -1, chkVal = -1;
	if (val-1 < len && val-1 >= 0) {
		chkPos = val;
	} else {
		int i;
		for (i=0; i<len; i++) {
			if (arr[i] == val)
				return i+1;
		}
	}
	return -1;
}

int *delete_element_from_array(int *arr, int l, int pos) {
	int *new_arr = (int *) malloc ((l-1) * sizeof(int));
	int i, c=0;
	for(i=0; i<l; i++) {
		if (i==pos-1)
			continue;
		new_arr[c++] = arr[i];
	}
	free(arr);
	return new_arr;
}
