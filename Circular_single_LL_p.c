// c program for  insertion and deletion in circular single linked list using pointers

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *start = NULL;
    int option;

    printf("NAMASKARAM! This program demonstrates insertion and deletion in a circular linked list(SINGLE).\n");

    // Main menu loop
    do {
        printf("\n\n\t\t**********MAIN MENU**********");
        printf("\n 1:) Create a Circular Linked List");
        printf("\n 2:) Display the Circular Linked List");
        printf("\n 3:) Insert a node in the CLL");
        printf("\n 4:) Delete a node in the CLL");
        printf("\n 5:) Exit the program");
        printf("\n\n Enter your choice : ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                // Create a circular linked list
                struct node *newNode, *ptr;
                int num;

                printf("\nEnter numbers to create a Circular Linked List (enter -1 to end):\n");
                scanf("%d", &num);

                while (num != -1) {
                    newNode = (struct node *)malloc(sizeof(struct node));

                    if (newNode == NULL) {
                        printf("Memory allocation failed. Circular linked list creation aborted.\n");
                        break;
                    }

                    newNode->data = num;

                    if (start == NULL) {
                        start = newNode;
                        newNode->next = start; // Circular link
                    } else {
                        ptr = start;
                        while (ptr->next != start) {
                            ptr = ptr->next;
                        }
                        ptr->next = newNode;
                        newNode->next = start; // Circular link
                    }

                    printf("Enter data to create the Circular Linked List (enter -1 to end): ");
                    scanf("%d", &num);
                }
                break;
            }
            case 2: {
                // Display the circular linked list
                struct node *ptr = start;

                if (start == NULL) {
                    printf("\nList is empty.");
                } else {
                    printf("\nCircular Linked List: ");
                    do {
                        printf("%d -> ", ptr->data);
                        ptr = ptr->next;
                    } while (ptr != start);
                    printf("... (circular)\n");
                }
                break;
            }
            case 3: {
                // Insert a node into the circular linked list
                struct node *newNode, *ptr;
                int num, val, choice;

                printf("\nChoose method of insertion:");
                printf("\n 1:) Insert at the beginning");
                printf("\n 2:) Insert at the end");
                printf("\n 3:) Insert after a specific value");
                printf("\n 4:) Insert before a specific value");
                printf("\n\nEnter your choice: ");
                scanf("%d", &choice);

                switch(choice) {
                    case 1:
                        printf("\nEnter the data to be inserted at the beginning: ");
                        scanf("%d", &num);

                        newNode = (struct node *)malloc(sizeof(struct node));
                        if (newNode == NULL) {
                            printf("Memory allocation failed. Unable to insert node.\n");
                            break;
                        }
                        newNode->data = num;

                        ptr = start;
                        while (ptr->next != start) {
                            ptr = ptr->next;
                        }
                        newNode->next = start;
                        ptr->next = newNode;
                        start = newNode;
                        break;

                    case 2:
                        printf("\nEnter the data to be inserted at the end: ");
                        scanf("%d", &num);

                        newNode = (struct node *)malloc(sizeof(struct node));
                        if (newNode == NULL) {
                            printf("Memory allocation failed. Unable to insert node.\n");
                            break;
                        }
                        newNode->data = num;

                        ptr = start;
                        while (ptr->next != start) {
                            ptr = ptr->next;
                        }
                        newNode->next = start;
                        ptr->next = newNode;
                        break;

                    case 3:
                        printf("\nEnter the data to be inserted after a specific value: ");
                        scanf("%d", &num);
                        printf("Enter the value after which you want to insert: ");
                        scanf("%d", &val);

                        ptr = start;
                        do {
                            if (ptr->data == val) {
                                newNode = (struct node *)malloc(sizeof(struct node));
                                if (newNode == NULL) {
                                    printf("Memory allocation failed. Unable to insert node.\n");
                                    break;
                                }
                                newNode->data = num;
                                newNode->next = ptr->next;
                                ptr->next = newNode;
                                break;
                            }
                            ptr = ptr->next;
                        } while (ptr != start);
                        if (ptr == start) {
                            printf("Value not found in the list.\n");
                        }
                        break;

                    case 4:
                        printf("\nEnter the data to be inserted before a specific value: ");
                        scanf("%d", &num);
                        printf("Enter the value before which you want to insert: ");
                        scanf("%d", &val);

                        ptr = start;
                        do {
                            if (ptr->next->data == val) {
                                newNode = (struct node *)malloc(sizeof(struct node));
                                if (newNode == NULL) {
                                    printf("Memory allocation failed. Unable to insert node.\n");
                                    break;
                                }
                                newNode->data = num;
                                newNode->next = ptr->next;
                                ptr->next = newNode;
                                break;
                            }
                            ptr = ptr->next;
                        } while (ptr != start);
                        if (ptr == start) {
                            printf("Value not found in the list.\n");
                        }
                        break;

                    default:
                        printf("\nInvalid choice.\n");
                }
                break;
            }
            case 4: {
                // Delete a node from the circular linked list
                struct node *ptr, *prev;
                int choice, val;

                if (start == NULL) {
                    printf("\nList is empty. Nothing to delete.");
                    break;
                }

                printf("\nChoose method of deletion:");
                printf("\n 1:) Delete at the beginning");
                printf("\n 2:) Delete at the end");
                printf("\n 3:) Delete a specific value");
                printf("\n\nEnter your choice: ");
                scanf("%d", &choice);

                switch(choice) {
                    case 1:
                        ptr = start;
                        while (ptr->next != start) {
                            ptr = ptr->next;
                        }
                        if (ptr == start) {
                            free(start);
                            start = NULL;
                        } else {
                            ptr->next = start->next;
                            free(start);
                            start = ptr->next;
                        }
                        break;

                    case 2:
                        ptr = start;
                        while (ptr->next->next != start) {
                            ptr = ptr->next;
                        }
                        free(ptr->next);
                        ptr->next = start;
                        break;

                    case 3:
                        printf("\nEnter the value to be deleted: ");
                        scanf("%d", &val);

                        ptr = start;
                        prev = NULL;
                        do {
                            if (ptr->data == val) {
                                if (prev == NULL) {
                                    while (ptr->next != start) {
                                        ptr = ptr->next;
                                    }
                                    if (ptr == start) {
                                        free(start);
                                        start = NULL;
                                    } else {
                                        ptr->next = start->next;
                                        free(start);
                                        start = ptr->next;
                                    }
                                } else {
                                    prev->next = ptr->next;
                                    free(ptr);
                                }
                                break;
                            }
                            prev = ptr;
                            ptr = ptr->next;
                        } while (ptr != start);
                        if (ptr == start) {
                            printf("Value not found in the list.\n");
                        }
                        break;

                    default:
                        printf("\nInvalid choice.\n");
                }
                break;
            }
            case 5:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid option. Please try again.");
        }
    } while(option != 5);

    return 0;
}