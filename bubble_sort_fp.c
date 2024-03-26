// C program for bubble sort with functions and pointers

#include <stdio.h>

void inputArray(int *arr, int *size);
void displayArray(int *arr, int size);
void bubbleSort(int *arr, int size);

int main() {
    int arr[100], size;

    inputArray(arr, &size);

    printf("Unsorted array:\n");
    displayArray(arr, size);

    bubbleSort(arr, size);

    printf("Sorted array:\n");
    displayArray(arr, size);

    return 0;
}

void inputArray(int *arr, int *size) {
    printf("Enter the size of the array: ");
    scanf("%d", size);

    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        scanf("%d", arr + i);
    }
}

void displayArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void bubbleSort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                // Swap *(arr + j) and *(arr + j + 1)
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}
