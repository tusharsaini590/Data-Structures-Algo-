// c program for  implementation of queue in array without functions and pointers

#include <stdio.h>

int main() {
    int choice, size, value, front = -1, rear = -1;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    int queueArray[size];

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

                // Enqueue logic
                if (rear == size - 1) {
                    printf("Queue is FULL\n");
                } else if (front == -1 && rear == -1) {
                    front = rear = 0;
                    queueArray[rear] = value;
                } else {
                    rear++;
                    queueArray[rear] = value;
                }
                break;
            }
            case 2: {
                // Display Queue logic
                if (front == -1 && rear == -1) {
                    printf("Queue is Empty(like your brain rn)\n");
                } else {
                    for (int i = front; i <= rear; i++) {
                        printf("%d\n", queueArray[i]);
                    }
                }
                break;
            }
            case 3: {
                // Dequeue logic
                if (front == -1 && rear == -1) {
                    printf("Queue is Empty\n");
                } else if (front == rear) {
                    printf("Deleted Element is : %d\n", queueArray[front]);
                    front = rear = -1;
                } else {
                    printf("Deleted Element is : %d\n", queueArray[front]);
                    front++;
                }
                break;
            }
            case 4: {
                // Peek logic
                if (front == -1 && rear == -1) {
                    printf("Queue is Empty\n");
                } else {
                    printf("%d\n", queueArray[front]);
                }
                break;
            }
            case 5: {
                printf("Or aa gaye sawad DSA ke saath \n");
                break;
            }
        }
    } while (choice < 5);

    return 0;
}