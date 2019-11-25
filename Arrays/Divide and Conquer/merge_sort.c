#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_sort(int *, int, int);
void merge(int *, int, int, int);
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

    merge_sort(arr, 0, len-1);

    printf("After sorting: ");
    print_array(arr, len);
    
    return EXIT_SUCCESS;
}

void merge_sort(int *arr, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int *arr, int low, int mid, int high) {
    int n1 = mid-low+1, n2=high-mid;
    int *first_part = (int *) calloc(n1, sizeof(int));
    int *second_part = (int *) calloc(n2, sizeof(int));

    int i, j, k;
    for (i=0; i<n1; i++) {
        first_part[i] = arr[low+i];
    }
    for (i=0; i<n2; i++) {
        second_part[i] = arr[mid+1+i];
    }

    i=0;
    j=0;
    k=low;
    while (i<n1 && j<n2) {
        if (first_part[i] <= second_part[j]) {
            arr[k++] = first_part[i];
            i++;
        } else {
            arr[k++] = second_part[j];
            j++;
        }
    }

    while (i<n1) {
        arr[k++] = first_part[i];
        i++;
    }

    while (j<n2) {
        arr[k++] = second_part[j];
        j++;
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