//c program for implementing queue in array using pointers

#include <stdio.h>

int main() {
    int choice, size, value;
    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    int queueArray[size];
    int* front = &queueArray[0];
    int* rear = &queueArray[0];

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
                if (rear - queueArray == size - 1) {
                    printf("Queue is FULL\n");
                } else if (front == &queueArray[0] && rear == &queueArray[0]) {
                    *front = *rear = value;
                } else {
                    rear++;
                    *rear = value;
                }
                break;
            }
            case 2: {
                // Display Queue logic
                if (front == &queueArray[0] && rear == &queueArray[0]) {
                    printf("Queue is Empty(like your brain rn)\n");
                } else {
                    int* temp = front;
                    while (temp <= rear) {
                        printf("%d\n", *temp);
                        temp++;
                    }
                }
                break;
            }
            case 3: {
                // Dequeue logic
                if (front == &queueArray[0] && rear == &queueArray[0]) {
                    printf("Queue is Empty\n");
                } else if (front == rear) {
                    printf("Deleted Element is : %d\n", *front);
                    front = rear = &queueArray[0];
                } else {
                    printf("Deleted Element is : %d\n", *front);
                    front++;
                }
                break;
            }
            case 4: {
                // Peek logic
                if (front == &queueArray[0] && rear == &queueArray[0]) {
                    printf("Queue is Empty\n");
                } else {
                    printf("%d\n", *front);
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