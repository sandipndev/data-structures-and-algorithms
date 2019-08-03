#include <stdio.h>
#include <stdlib.h>
#include "linear_proto.h"

array linear_search(array, int);

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

    // Asking for what to search
    int key;
    printf("?SearchTerm: ");
    scanf("%d", &key);

    // Searching, really!
    array results = linear_search(arr, key);

    // Showing results properly - prettified
    switch(results.len) {
        case 0: printf("[X] Not found\n");
        break;

        case 1: printf("[$] %d found at position %d\n", key, results.base[0]);
        break;

        default: printf("[$] %d was found in the following positions: ", key);
                 print_array(arr);
    }

    free_array(arr);
    free_array(results);
}

array linear_search(array tx, int key) {
    array res = create_array(tx.len);
    int i, c=0;
    for (i=0; i<tx.len; i++) {
        if (tx.base[i] == key) {
            res.base[c++] = i;
        }
    }
    realloc(res.base, c*sizeof(int));
    return res;
}