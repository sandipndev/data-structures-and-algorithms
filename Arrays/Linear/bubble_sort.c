#include <stdio.h>
#include "linear_proto.h"

array bubble_sort(array);

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
    array result = bubble_sort(arr);
    
    // Printing
    printf("Sorted array: ");
    print_array(result);

    free_array(arr);
    free_array(result);
}

array bubble_sort(array rx) {
    array tx = create_array(rx.len);
    int i, j, temp;

    // Copying
    for (i=0; i<rx.len; i++) {
        tx.base[i] = rx.base[i];
    }

    // Sorting
    for (i=0; i<tx.len-1; i++) {
        for (j=0; j<(tx.len-i-1); j++) {
            if (tx.base[j] > tx.base[j+1]) {
                temp = tx.base[j];
                tx.base[j] = tx.base[j+1];
                tx.base[j+1] = temp;
            }
        }
    }

    return tx;
}