#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *, int);
void heapify(int *, int, int);
void print_array(int *, int);

int main() {
    int i, len;
    printf("? Length: ");
    scanf("%d", &len);

    int *arr = (int *) calloc(len, sizeof(int));

    for (i=0; i<len; i++) {
        printf("? arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("You've entered: ");
    print_array(arr, len);

    heap_sort(arr, len);

    printf("After sorting: ");
    print_array(arr, len);
    
    return EXIT_SUCCESS;
}

void heapify(int *arr, int len, int root) {
    int largest = root;
    int left = 2*root + 1;
    int right = 2*root + 2;

    if (left<len && arr[left]>arr[largest]) {
        largest = left;
    } 
    if (right<len && arr[right]>arr[largest]) {
        largest = right;
    }

    if (largest != root) {
        int temp;
        temp = arr[largest];
        arr[largest] = arr[root];
        arr[root] = temp;

        heapify(arr, len, largest);
    }
}

void heap_sort(int *arr, int len) {

    int i;
    for (i=len/2-1; i>=0; i--) {
        heapify(arr, len, i);
    }

    for (i=len-1; i>=0; i--) {

        // move current root to end, using max heap
        int temp;
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);

    }
    
}

void print_array(int *arr, int len) {
    printf("[ ");
    int i;
    for (i=0; i<len; i++) {
        printf("%d,", arr[i]);
    }
    printf("\b]\n");
}