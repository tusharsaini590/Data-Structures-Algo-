// C program to create dynamic array
// with pointers

#include <stdio.h>
#include <stdlib.h> // For dynamic memory allocation

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int* newarray = (int*)malloc(size * sizeof(int));
    if (newarray == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Read array elements using pointers
    int* ptr = newarray;
    printf("Enter %d elements for the array: ", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", ptr);
        ptr++;
    }

    // Display array elements using pointers
    ptr = newarray;
    printf("The elements of the array are: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", *ptr);
        ptr++;
    }
    printf("\n");

    // Free dynamically allocated memory
    free(newarray);

    return 0;
}
