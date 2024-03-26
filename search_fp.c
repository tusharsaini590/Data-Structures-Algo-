// c program to search using both linear and binary search with functions and pointers


#include <stdio.h>
#include <stdlib.h>
void linearSearch(int *arr, int size, int key) {
    int found = 0, index = -1;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == key) {
            found = 1;
            index = i;
            break;
        }
    }
    if (found) {
        printf("\nElement found at index %d", index);
    } else {
        printf("\nElement not found in the array");
    }
}

void binarySearch(int *arr, int size, int key) {
    int found = 0, index = -1;
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (*(arr + mid) == key) {
            found = 1;
            index = mid;
            break;
        } else if (*(arr + mid) < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (found) {
        printf("\nElement found at index %d", index);
    } else {
        printf("\nElement not found in the array");
    }
}

int main() {
    int size, *key, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *arr = (int*)malloc(size * sizeof(int));

    printf("Enter %d elements in sorted order: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);
    }

    key = (int*)malloc(sizeof(int));
    printf("Enter the element to search: ");
    scanf("%d", key);

    printf("\nChoose the search algorithm:");
    printf("\n1. Linear Search");
    printf("\n2. Binary Search");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nLinear Search:");
            linearSearch(arr, size, *key);
            break;
        case 2:
            printf("\nBinary Search:");
            binarySearch(arr, size, *key);
            break;
        default:
            printf("\nInvalid choice.");
    }

    free(arr);
    free(key);

    return 0;
}