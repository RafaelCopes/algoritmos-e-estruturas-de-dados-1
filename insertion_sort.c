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
    int i, j, tmp;

    for (j = 0; j < n; j++) {
        i = j - 1;
        tmp = data[j];

        while ((i >= 0) && (tmp < data[i])) {
            data[i+1] = data[i];
            i--;
        }

        data[i+1] = tmp;        
    }
}

void printArray(int arr[], int n) { 
    int i; 

    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]);

    printf("\n"); 
}
