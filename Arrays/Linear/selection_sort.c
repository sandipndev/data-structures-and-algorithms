#include <stdio.h>
#include "linear_proto.h"

array selection_sort(array);

int main() {
    // Maximum length
    int n;
    printf("?Max: ");
    scanf("%d", &n);

    // Creating the array
    array arr = create_array(n);

    // User input array elements
    printf("Enter the array elements:\n");
    array_user_input(arr);

    // Showing what user entered
    printf("Entered array: ");
    print_array(arr);

    // Sorting
    array result = selection_sort(arr);
    
    // Printing
    printf("Sorted array: ");
    print_array(result);

    free_array(arr);
    free_array(result);
}

array selection_sort(array rx) {
    array tx = create_array(rx.len);
    int i, j, temp, min;

    // Copying
    for (i=0; i<rx.len; i++) {
        tx.base[i] = rx.base[i];
    }

    // Sorting
    for (i=0; i<tx.len-1; i++) {
        min = i;
        for (j=i+1; j<tx.len; j++) {
            if (tx.base[min] > tx.base[j]) {
                min = j;
            }
        }
        if (min != i) {
            temp = tx.base[i];
            tx.base[i] = tx.base[min];
            tx.base[min] = temp;
        }
    }

    return tx;
}