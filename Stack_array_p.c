// C program for Implementation of stack in array using  pointers

#include <stdio.h>
#define MAX_SIZE 101

int main() {
    int choice, value;
    int stackArray[MAX_SIZE];
    int* topPtr = stackArray;  // Initialize topPtr to point to the start of stackArray

    do {
        printf("\t\tMAIN MENU for operations on Stack in array\n");
        printf("\n1. Push the element\n");
        printf("2. Pop the element\n");
        printf("3. Display the elements\n");
        printf("4. Peek the element\n");
        printf("5. EXIT\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice > 5 || choice < 1) {
            printf("Invalid choice\n");
        }

        switch (choice) {
            case 1: {
                printf("Enter the value: ");
                scanf("%d", &value);

                // Push logic
                if (topPtr == stackArray + MAX_SIZE) {
                    printf("Stack is Full\n");
                } else {
                    *topPtr = value;  // Store the value at the top position
                    topPtr++;  // Move the pointer to the next available position
                }
                break;
            }
            case 2: {
                // Pop logic
                if (topPtr == stackArray) {
                    printf("Stack is Empty\n");
                } else {
                    topPtr--;  // Move the pointer down to the previous position
                    value = *topPtr;  // Get the value at the top position
                    printf("Popped value is: %d\n", value);
                }
                break;
            }
            case 3: {
                // Display logic
                int* ptr = stackArray;
                if (ptr == topPtr) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack elements:\n");
                    while (ptr < topPtr) {
                        printf("%d\n", *ptr);
                        ptr++;  // Move the pointer up
                    }
                }
                break;
            }
            case 4: {
                // Peek logic
                if (topPtr == stackArray) {
                    printf("Stack is empty\n");
                } else {
                    printf("Top element is: %d\n", *(topPtr - 1));
                }
                break;
            }
            case 5: {
                printf("Or bhai aa gye sawad DSA ke\n");
                break;
            }
        }
    } while (choice < 5);

    return 0;
}