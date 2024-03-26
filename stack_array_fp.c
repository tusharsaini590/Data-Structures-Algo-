// C program for Implementation of stack in array using functions and pointers
#include <stdio.h>
#define MAX_SIZE 101

int pushElement(int*);
void displayElements();
int popElement();
int peekElement();

int stackArray[MAX_SIZE];
int* topPtr = NULL;  // Pointer to the top of the stack

int peekElement() {
    if (topPtr == stackArray - 1) {
        printf("Stack is empty\n");
    } else {
        printf("Top element is: %d\n", *topPtr);
    }
    return 0;
}

int main() {
    int choice;
    topPtr = stackArray - 1;  // Initialize topPtr to point before the start of stackArray
    do {
        printf("\t\tMAIN MENU fro operations on Stack in array\n");
        printf("\n1. Push the element\n");
        printf("2. Pop the element\n");
        printf("4. Display the elements\n");
        printf("3. Peek the element\n");
        printf("5. EXIT\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);
        if (choice > 5 || choice < 1) {
            printf("Invalid choice\n");
        }

        switch (choice) {
            case 1: {
                int value, *valuePtr;
                printf("Enter the value: ");
                scanf("%d", &value);
                valuePtr = &value;
                pushElement(valuePtr);
                break;
            }
            case 2: {
                popElement();
                break;
            }
            case 3: {
                displayElements();
                break;
            }
            case 4: {
                peekElement();
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

void displayElements() {
    int* ptr = topPtr;
    if (ptr == stackArray - 1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements:\n");
        while (ptr >= stackArray) {
            printf("%d\n", *ptr);
            ptr--;  // Move the pointer down
        }
    }
}

int popElement() {
    int item;
    if (topPtr == stackArray - 1) {
        printf("Stack is Empty\n");
        return 0;
    } else {
        item = *topPtr;  // Get the value at the top position
        topPtr--;  // Move the pointer down to the previous position
        printf("Popped value is: %d\n", item);
    }
    return 0;
}

int pushElement(int* valuePtr) {
    if (topPtr == stackArray + MAX_SIZE - 1) {
        printf("Stack is Full\n");
    } else {
        topPtr++;  // Move the pointer to the next available position
        *topPtr = *valuePtr;  // Store the value at the top position
    }
    return 0;
}