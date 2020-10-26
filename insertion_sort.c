#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *data, int n);

int main() {
    int arr[] = {4, 3, 1, 5, 2};

    printf("Unsorted: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    insertionSort(arr, 5);

    printf("\nSorted: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

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
