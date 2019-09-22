#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int *base_addr;
	int length;
} array;

void array_user_input(array);

void print_array(array);

array generate_array(int);

int second_largest(array);

int main() {
	system("clear");
	int l;
	printf("Enter length = ");
	scanf("%d", &l);
	array arr = generate_array(l);
	array_user_input(arr);
	int seclargest = second_largest(arr);
	printf("Second largest = %d\n", seclargest);
	return 0;
}

int second_largest(array rx) {
	int *arr = rx.base_addr;
	int i, max=0, seclarge=0;
	for (i=0; i<rx.length; i++) {
		if (max<arr[i]) {
			seclarge = max;
			max = arr[i];
		} else if (arr[i] > seclarge && arr[i] != max) {
			seclarge = arr[i];
		}
	}
	return seclarge;
}

array generate_array(int len) {
	array tx;
	tx.base_addr = (int *) malloc(len * sizeof(int));
	tx.length = len;
	return tx;
}

void array_user_input(array tx) {
	int *arr = tx.base_addr;
	int n = tx.length;
	int i;
	for (i=0; i<n; i++) {
		printf("%dth element = ", i+1);
		scanf("%d", &arr[i]);
	}
}

void print_array(array tx) {
	int *arr = tx.base_addr;
	int n = tx.length;
	printf("[");
	int i;
	for (i=0; i<n; i++) {
		printf("%d,", arr[i]);
	}
	printf("\b]\n");
}
