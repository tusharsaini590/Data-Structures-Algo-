// C program to implement stack in linked list using pointers
#include <stdio.h>
#include <stdlib.h>

struct NodeStruct {
    int value;
    struct NodeStruct *nextPtr;
};

int main() {
    struct NodeStruct *topPtr = NULL;
    int choice;

    do {
        printf("\t\tMAIN MENU for operations on Stack in array\n");
        printf("\n1. Push the element\n");
        printf("2. Peek the element\n");
        printf("3. Pop the element\n");
        printf("4. Display\n");
        printf("5. EXIT\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice > 5 || choice < 0) {
            printf("Invalid choice\n");
        }

        switch (choice) {
            case 1: {
                int data;
                printf("Enter the data: ");
                scanf("%d", &data);

                // Push logic
                struct NodeStruct *newNode = (struct NodeStruct *)malloc(sizeof(struct NodeStruct));
                newNode->value = data;
                newNode->nextPtr = topPtr;
                topPtr = newNode;
                break;
            }
            case 2: {
                // Peek logic
                if (topPtr == NULL) {
                    printf("Stack is Empty\n");
                } else {
                    printf("The top of the Data is %d\n", topPtr->value);
                }
                break;
            }
            case 3: {
                // Pop logic
                if (topPtr == NULL) {
                    printf("The stack is Empty\n");
                } else {
                    struct NodeStruct *temp = topPtr;
                    topPtr = topPtr->nextPtr;
                    free(temp);
                }
                break;
            }
            case 4: {
                // Display logic
                struct NodeStruct *temp = topPtr;
                if (topPtr == NULL) {
                    printf("Stack is Empty\n");
                } else {
                    while (temp != NULL) {
                        printf("%d\n", temp->value);
                        temp = temp->nextPtr;
                    }
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
