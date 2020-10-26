#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *data, int n);
void printArray(int *arr, int n);

int main() {
    int arr[] = {4, 3, 1, 5, 2, 5, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]); 

    printf("Unsorted: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted: ");
    printArray(arr, n);


    return 0;
}

void insertionSort(int *data, int n) {
    int i, j, key;

    for (i = 0; i < n; i++) {
        key = data[i];
        j = i - 1;

        while ((j >= 0) && (key < data[j])) {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = key;
    }
}

void printArray(int *arr, int n) { 
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);

    printf("\n"); 
}
