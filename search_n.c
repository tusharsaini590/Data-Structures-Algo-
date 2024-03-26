// c program to search using both linear and binary search without functions and pointers


#include <stdio.h>

int main() {
    int size, key, choice, found = 0, index = -1;

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

    if (choice == 1) {
        printf("\nLinear Search:");
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
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
    } else if (choice == 2) {
        printf("\nBinary Search:");
        int low = 0, high = size - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == key) {
                found = 1;
                index = mid;
                break;
            } else if (arr[mid] < key) {
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
    } else {
        printf("\nInvalid choice.");
    }

    return 0;
}