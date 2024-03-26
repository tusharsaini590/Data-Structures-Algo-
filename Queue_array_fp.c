// c program for  implementation of queue in array with functions and pointers

#include <stdio.h>

int main() {
    int choice, size, value;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    int queueArray[size];
    int front = -1;
    int rear = -1;

    void enqueueElement(int*, int*, int*, int);
    void displayQueue(int*, int, int);
    void dequeueElement(int*, int*);
    void peekQueue(int*, int);

    do {
        printf("\n1. Insert the element in the queue.\n");
        printf("2. Display the elements\n");
        printf("3. Delete the element from the Queue\n");
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
                enqueueElement(queueArray, &front, &rear, size);
                break;
            }
            case 2: {
                displayQueue(queueArray, front, rear);
                break;
            }
            case 3: {
                dequeueElement(&front, &rear);
                break;
            }
            case 4: {
                peekQueue(queueArray, front);
                break;
            }
            case 5: {
                printf("THANK YOU FOR USING\n");
                break;
            }
        }
    } while (choice < 5);

    return 0;
}

void dequeueElement(int* frontPtr, int* rearPtr) {
    if (*frontPtr == -1 && *rearPtr == -1) {
        printf("Queue is Empty\n");
    } else if (*frontPtr == *rearPtr) {
        printf("Deleted Element is : %d\n", *frontPtr);
        *frontPtr = *rearPtr = -1;
    } else {
        printf("Deleted Element is : %d\n", *frontPtr);
        (*frontPtr)++;
    }
}

void peekQueue(int* queueArray, int front) {
    if (front == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("%d\n", queueArray[front]);
    }
}

void enqueueElement(int* queueArray, int* frontPtr, int* rearPtr, int size) {
    int value;
    printf("Enter the value: ");
    scanf("%d", &value);

    if (*rearPtr == size - 1) {
        printf("Queue is FULL\n");
    } else if (*frontPtr == -1 && *rearPtr == -1) {
        *frontPtr = *rearPtr = 0;
        queueArray[*rearPtr] = value;
    } else {
        (*rearPtr)++;
        queueArray[*rearPtr] = value;
    }
}

void displayQueue(int* queueArray, int front, int rear) {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queueArray[i]);
        }
    }
}
