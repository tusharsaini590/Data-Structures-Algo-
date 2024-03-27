// C program for Implementation of stack in Linked LIat  using functions and pointers

#include <stdio.h>
#include <stdlib.h>

struct NodeStruct {
    int value;
    struct NodeStruct *nextPtr;
};
struct NodeStruct *topPtr = NULL;

int peekElement();
void displayElements();
int popElement();
int pushElement(int);

int peekElement() {
    if (topPtr == NULL) {
        printf("Stack is Empty\n");
        return 0;
    } else {
        printf("The top of the Data is %d\n", topPtr->value);
    }
    return 1;
}

int main() {
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
                pushElement(data);
                break;
            }
            case 2: {
                peekElement();
                break;
            }
            case 3: {
                popElement();
                break;
            }
            case 4: {
                displayElements();
                break;
            }
            case 5: {
                printf("hmm bhadiya execute hua hai tera code. V. K ka khoof kuch kaam to aaya\n");
                break;
            }
        }
    } while (choice < 5);

    return 0;
}

void displayElements() {
    struct NodeStruct *temp;
    if (topPtr == NULL) {
        printf("Stack is Empty\n");
        return;
    } else {
        temp = topPtr;
        while (temp != NULL) {
            printf("%d\n", temp->value);
            temp = temp->nextPtr;
        }
    }
}

int popElement() {
    struct NodeStruct *temp;
    if (topPtr == NULL) {
        printf("The stack is Empty\n");
        return 0;
    } else {
        temp = topPtr;
        topPtr = topPtr->nextPtr;
        free(temp);
    }
    return 1;
}

int pushElement(int data) {
    struct NodeStruct *newNode;
    newNode = (struct NodeStruct *)malloc(sizeof(struct NodeStruct));
    newNode->value = data;
    newNode->nextPtr = topPtr;
    topPtr = newNode;
    return 1;
}

