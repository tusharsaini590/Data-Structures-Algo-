// C program for queue in Linked list

#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, value;

    do {
        printf("\nQueue Operations:\n");
        printf("1.) Enqueue\n");
        printf("2.) Dequeue\n");
        printf("3.) Display Queue\n");
        printf("4.) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);

                // Enqueue logic
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = value;
                newNode->next = NULL;

                if (front == NULL && rear == NULL) {
                    front = newNode;
                    rear = newNode;
                } else {
                    rear->next = newNode;
                    rear = newNode;
                }

                printf("Value %d enqueued successfully.\n", value);
                break;
            }
            case 2: {
                // Dequeue logic
                if (front == NULL) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    struct Node* temp = front;
                    value = temp->data;
                    front = front->next;

                    if (front == NULL) {
                        rear = NULL;
                    }

                    free(temp);
                    printf("Dequeued value: %d\n", value);
                }
                break;
            }
            case 3: {
                // Display Queue logic
                if (front == NULL) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue: ");
                    struct Node* temp = front;
                    while (temp != NULL) {
                        printf("%d ", temp->data);
                        temp = temp->next;
                    }
                    printf("\n");
                }
                break;
            }
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}