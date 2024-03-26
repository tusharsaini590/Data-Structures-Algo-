// C program to implement queue in array using functions

#include <stdio.h>
#define MAX_SIZE 1001

int addElement(int);
void showElements(int, int);
int removeElement(int, int);
void peekElement(int);

int queueArray[MAX_SIZE];
int frontIndex = -1;
int rearIndex = -1;

int peek() {
    if (frontIndex == -1 && rearIndex == -1) {
        printf("Queue is Empty(like yor brain rn)\n");
    } else {
        printf("%d\n", queueArray[frontIndex]);
    }
    return 0;
}

int main() {
    int choice;

    do {
        printf("\t\tMain Menu for Opertions on queue\n");
        printf("\n1. Insert Element.\n");
        printf("2. Display the elements\n");
        printf("3. Delete the element\n");
        printf("4. Peek the element\n");
        printf("5. EXIT\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice > 5 || choice < 1) {
            printf("Invalid choice\n");
        }

        switch (choice) {
            case 1: {
                int value;
                printf("Enter the value: ");
                scanf("%d", &value);
                addElement(value);
                break;
            }
            case 2: {
                showElements(frontIndex, rearIndex);
                break;
            }
            case 3: {
                removeElement(frontIndex, rearIndex);
                break;
            }
            case 4: {
                peek();
                break;
            }
            case 5: {
                printf("Or Bhai aa gye Sawad DSA ke\n");
                break;
            }
        }
    } while (choice < 5);

    return 0;
}

int addElement(int value) {
    if (rearIndex == MAX_SIZE - 1) {
        printf("Queue is FULL\n");
    } else if (frontIndex == -1 && rearIndex == -1) {
        frontIndex = rearIndex = 0;
        queueArray[rearIndex] = value;
    } else {
        rearIndex++;
        queueArray[rearIndex] = value;
    }
    return 0;
}

void showElements(int front, int rear) {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty(just like your brain rn\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d\n", queueArray[i]);
        }
    }
}

int removeElement(int front, int rear) {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else if (front == rear) {
        printf("Deleted Element is : %d\n", queueArray[front]);
        front = rear = -1;
    } else {
        printf("Deleted Element is : %d\n", queueArray[front]);
        front++;
    }
    return 0;
}