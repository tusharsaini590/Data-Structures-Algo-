// c program for bubble sort using pointers only

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr, size;

    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array dynamically
    arr = (int*)malloc(size * sizeof(int));

    // Input array elements
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);
    }

    // Display the unsorted array
    printf("Unsorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // Bubble sort logic
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

    // Display the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}