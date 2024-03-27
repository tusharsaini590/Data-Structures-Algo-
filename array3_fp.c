// C program to create dynamic array
// with function and pointers


#include <stdio.h>
#include <stdlib.h> // For dynamic memory allocation

// Function to read the size of the array
int readArraySize() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    return size;
}

// Function to read array elements
void readArrayElements(int* arr, int size) {
    printf("Enter %d elements for the array: ", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }
}

// Function to display array elements
void displayArray(const int* arr, int size) {
    printf("The elements of the array are: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int* newarray = (int*)malloc(size * sizeof(int)); // MALLOC FOR MEMORY ALLOCATION ; ITS OUTPUT IS TYPECASTED INTO INT DATA TYPE
    if (newarray == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    readArrayElements(newarray, size);
    displayArray(newarray, size);

    // Free dynamically allocated memory
    free(newarray);

    return 0;
}
