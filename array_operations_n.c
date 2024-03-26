// c program to insert-delete element in a dynamic array without functions and pointers

#include <stdio.h>
#include <stdlib.h>

int main() {
    int* array = NULL;
    int size = 0;
    int option;

    printf("NAMASKARAM! This program allows insertion and deletion in a dynamic array.\n");

    do {
        printf("\n\n\t\t**********MAIN MENU**********");
        printf("\n 1:) Create a Dynamic Array");
        printf("\n 2:) Display the Dynamic Array");
        printf("\n 3:) Insert an element");
        printf("\n 4:) Delete an element");
        printf("\n 5:) Exit the program");
        printf("\n\n Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                int newSize; // Renamed to avoid shadowing
                printf("Enter size of array: ");
                scanf("%d", &newSize);

                // Allocate memory for the dynamic array
                array = (int*)malloc(newSize * sizeof(int));
                if (array == NULL) {
                    printf("Memory allocation failed. Exiting...\n");
                    return 1;
                }
                size = newSize;

                printf("Enter %d elements for the array: ", size);
                for (int i = 0; i < size; ++i) {
                    scanf("%d", &array[i]);
                }
                break; // Added break statement
            }
            case 2: {
                printf("The elements of the array are: ");
                for (int i = 0; i < size; ++i) {
                    printf("%d ", array[i]);
                }
                printf("\n");
                break;
            }
            case 3: {
                int element, position;
                printf("\nEnter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the index number on which to insert: ");
                scanf("%d", &position);
                if (position < 0 || position > size) {
                    printf("\nInvalid position. Array insertion aborted.\n");
                } else {
                    // Shift elements to make space for the new element
                    for (int i = size - 1; i >= position; --i) {
                        array[i + 1] = array[i];
                    }
                    array[position] = element;
                    ++size;
                }
                break;
            }
            case 4: {
                int position;
                printf("Enter the index number of the element to delete: ");
                scanf("%d", &position);
                if (position < 0 || position >= size) {
                    printf("\nInvalid position. Array deletion aborted.\n");
                } else {
                    // Shift elements to fill the gap left by the deleted element
                    for (int i = position; i < size - 1; ++i) {
                        array[i] = array[i + 1];
                    }
                    --size;
                }
                break;
            }
            case 5:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (option != 5);

    // Free dynamically allocated memory
    free(array);

    return 0;
}