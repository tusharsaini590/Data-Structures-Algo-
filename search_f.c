// c program to search using both linear and binary search using functions

#include <stdio.h>

int linear_search(int arr[], int size, int key);
int binary_search(int arr[], int size, int key);

int main() {
    int size, key, choice;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements in sorted order: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    printf("\nChoose the search algorithm:");
    printf("\n1. Linear Search");
    printf("\n2. Binary Search");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nLinear Search:");
            if (linear_search(arr, size, key) != -1) {
                printf("\nElement found at index %d", linear_search(arr, size, key));
            } else {
                printf("\nElement not found in the array");
            }
            break;
        case 2:
            printf("\nBinary Search:");
            if (binary_search(arr, size, key) != -1) {
                printf("\nElement found at index %d", binary_search(arr, size, key));
            } else {
                printf("\nElement not found in the array");
            }
            break;
        default:
            printf("\nInvalid choice.");
    }

    return 0;
}

// Linear search algorithm
int linear_search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return the index of the key if found
        }
    }
    return -1; // Return -1 if key not found
}

// Binary search algorithm
int binary_search(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            return mid; // Return the index of the key if found
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Return -1 if key not found
}
