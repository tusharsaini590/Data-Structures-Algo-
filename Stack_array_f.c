// C program for Implementation of stack in array  using functions

#include <stdio.h>
#define MAX_SIZE 5

int peekElement();
int popElement();
void displayElements();
int pushElement(int);

int stackArray[MAX_SIZE];
int topIndex = -1;

int peekElement() {
    if (topIndex == -1) {
        printf("Stack is empty\n");
    } else {
        printf("%d\n", stackArray[topIndex]);
    }
    return 0;
}

int main() {
    int choice;
    do {
        printf("\t\tMAIN MENU for operations on Stack in array\n");
        printf("\n1. Push the element\n");
        printf("2. Pop the element\n");
        printf("3. Peek the element\n");
        printf("4. Display the element\n");
        printf("5. EXIT\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice > 5 || choice < 0) {
            printf("Invalid choice\n");
        }

        switch (choice) {
            case 1: {
                int value;
                printf("Enter the value: ");
                scanf("%d", &value);
                pushElement(value);
                break;
            }
            case 2: {
                popElement();
                break;
            }
            case 3: {
                peekElement();
                break;
            }
            case 4: {
                displayElements();
                break;
            }
            case 5: {
                printf("Or Bhai aa gye swaad DSA ke\n");
                break;
            }
        }
    } while (choice < 5);

    return 0;
}

int popElement() {
    int item;
    if (topIndex == -1) {
        printf("Stack is Empty\n");
        return 0;
    } else {
        item = stackArray[topIndex];
        topIndex--;
        printf("Popped value is: %d\n", item);
    }
    return 0;
}

void displayElements() {
    for (int i = topIndex; i >= 0; i--) {
        printf("%d\n", stackArray[i]);
    }
}

int pushElement(int value) {
    if (topIndex == MAX_SIZE - 1) {
        printf("Stack is Full\n");
    } else {
        topIndex++;
        stackArray[topIndex] = value;
    }
    return 0;
}
