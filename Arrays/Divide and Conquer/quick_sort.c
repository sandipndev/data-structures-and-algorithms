#include <stdio.h>
#include <stdlib.h>

int partition(int *, int, int);
void quick_sort(int *, int, int);
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

    quick_sort(arr, 0, len-1);

    printf("After sorting: ");
    print_array(arr, len);
    
    return EXIT_SUCCESS;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    int j;

    for (j=low; j<=high-1; j++) {
        if (arr[j] < pivot) {
            i++;

            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi-1);
        quick_sort(arr, pi+1, high);
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