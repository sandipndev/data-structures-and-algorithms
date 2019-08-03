#include <stdio.h>
#include <stdlib.h>
#include "linear_proto.h"

int binary_search(array, int);

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
    int result = binary_search(arr, key);

    // Printing result
    if (result == -1) {
        printf("[X] Not found\n");
    } else {
        printf("[$] %d found at position %d\n", key, result);
    }

    free_array(arr);
}

int binary_search(array rx, int key) {
    int start = 0, end = rx.len-1, mid;
    while(start < end) {
        mid = (start + end) / 2;
        if (rx.base[mid] > key) {
            end = mid - 1;
        } else if (rx.base[mid] < key) {
            start = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}