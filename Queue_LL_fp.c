//c program for implementation of queue in Linked list using functions and pointers

#include <stdio.h>
#include <stdlib.h>

struct QueueNode {
    int value;
    struct QueueNode* next;
};

struct QueueNode* head = NULL;
struct QueueNode* tail = NULL;
struct QueueNode* newNode, * temp;

int enqueueElement(int);
void displayQueue();
int dequeueElement();
void peekQueue();

int main() {
    int choice;
    do {
        printf("\n1. Insert the element in the Queue.\n");
        printf("2. Display\n");
        printf("3. Delete the element from Queue\n");
        printf("4. Peek the element\n");
        printf("5. EXIT\n");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice > 5 || choice < 0) {
            printf("Invalid choice\n");
        }

        switch (choice) {
            case 1: {
                int x;
                printf("Enter the data: ");
                scanf("%d", &x);
                enqueueElement(x);
                break;
            }
            case 2: {
                displayQueue();
                break;
            }
            case 3: {
                dequeueElement();
                break;
            }
            case 4: {
                peekQueue();
                break;
            }
            case 5: {
                printf("THANKYOU FOR USING");
                break;
            }
        }
    } while (choice < 5);

    return 0;
}

int dequeueElement() {
    temp = head;
    if (head == NULL && tail == NULL) {
        printf("Queue is Empty\n");
    } else {
        printf("Deleted element %d\n", head->value);
        head = head->next;
        free(temp);
    }
    return 0;
}

void peekQueue() {
    if (head == NULL && tail == NULL) {
        printf("Queue is Empty\n");
    } else {
        printf("%d\n", head->value);
    }
}

int enqueueElement(int x) {
    newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->value = x;
    newNode->next = NULL;

    if (head == NULL && tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    return 0;
}

void displayQueue() {
    if (head == NULL && tail == NULL) {
        printf("Queue is Empty\n");
    } else {
        temp = head;
        while (temp != NULL) {
            printf("%d\n", temp->value);
            temp = temp->next;
        }
    }
}