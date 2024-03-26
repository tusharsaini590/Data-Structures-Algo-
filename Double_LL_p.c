// c program for insertion-deletion in double linked list using pointers


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node. It is a self-referential structure
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

int main() {
    struct node *start = NULL;
    int option;

    printf("Namaskaram! This program demonstrates insertion and deletion in a doubly linked list.\n");

    // Main menu loop
    do {
        printf("\n\n\t\t**********MAIN MENU**********");
        printf("\n 1:) Create a Doubly Linked List");
        printf("\n 2:) Display the Doubly Linked List");
        printf("\n 3:) Insert a node in the DLL");
        printf("\n 4:) Delete a node in the DLL");
        printf("\n 5:) Exit the program");
        printf("\n\n Enter your choice : ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                // Create a doubly linked list
                struct node *newNode, *ptr;
                int num;

                printf("\nEnter numbers to create a Doubly Linked List (enter -1 to end):\n");
                scanf("%d", &num);

                while (num != -1) {
                    newNode = (struct node *)malloc(sizeof(struct node));

                    if (newNode == NULL) {
                        printf("Memory allocation failed. Doubly linked list creation aborted.\n");
                        break;
                    }

                    newNode->data = num;
                    newNode->prev = NULL;
                    newNode->next = NULL;

                    if (start == NULL) {
                        start = newNode;
                    } else {
                        ptr = start;
                        while (ptr->next != NULL) {
                            ptr = ptr->next;
                        }
                        ptr->next = newNode;
                        newNode->prev = ptr;
                    }

                    printf("Enter data to create the Doubly Linked List (enter -1 to end): ");
                    scanf("%d", &num);
                }
                break;
            }
            case 2: {
                // Display the doubly linked list
                struct node *ptr = start;
                if (start == NULL) {
                    printf("\nList is empty.");
                } else {
                    printf("\nDoubly Linked List: NULL <- ");
                    while (ptr != NULL) {
                        printf("%d <-> ", ptr->data);
                        ptr = ptr->next;
                    }
                    printf("NULL\n");
                }
                break;
            }
            case 3: {
                // Insert a node into the doubly linked list
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
                        newNode->prev = NULL;
                        newNode->next = start;
                        if (start != NULL) {
                            start->prev = newNode;
                        }
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
                        newNode->next = NULL;

                        if (start == NULL) {
                            newNode->prev = NULL;
                            start = newNode;
                        } else {
                            ptr = start;
                            while (ptr->next != NULL) {
                                ptr = ptr->next;
                            }
                            ptr->next = newNode;
                            newNode->prev = ptr;
                        }
                        break;

                    case 3:
                        printf("\nEnter the data to be inserted after a specific value: ");
                        scanf("%d", &num);
                        printf("Enter the value after which you want to insert: ");
                        scanf("%d", &val);

                        ptr = start;
                        while (ptr != NULL && ptr->data != val) {
                            ptr = ptr->next;
                        }

                        if (ptr == NULL) {
                            printf("Value not found in the list.\n");
                        } else {
                            newNode = (struct node *)malloc(sizeof(struct node));
                            if (newNode == NULL) {
                                printf("Memory allocation failed. Unable to insert node.\n");
                                break;
                            }
                            newNode->data = num;
                            newNode->next = ptr->next;
                            newNode->prev = ptr;
                            if (ptr->next != NULL) {
                                ptr->next->prev = newNode;
                            }
                            ptr->next = newNode;
                        }
                        break;

                    case 4:
                        printf("\nEnter the data to be inserted before a specific value: ");
                        scanf("%d", &num);
                        printf("Enter the value before which you want to insert: ");
                        scanf("%d", &val);

                        ptr = start;
                        while (ptr != NULL && ptr->data != val) {
                            ptr = ptr->next;
                        }

                        if (ptr == NULL) {
                            printf("Value not found in the list.\n");
                        } else {
                            newNode = (struct node *)malloc(sizeof(struct node));
                            if (newNode == NULL) {
                                printf("Memory allocation failed. Unable to insert node.\n");
                                break;
                            }
                            newNode->data = num;
                            newNode->prev = ptr->prev;
                            newNode->next = ptr;
                            if (ptr->prev != NULL) {
                                ptr->prev->next = newNode;
                            } else {
                                start = newNode;
                            }
                            ptr->prev = newNode;
                        }
                        break;

                    default:
                        printf("\nInvalid choice.\n");
                }
                break;
            }
            case 4: {
                // Delete a node from the doubly linked list
                struct node *ptr;
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
                        start = start->next;
                        if (start != NULL) {
                            start->prev = NULL;
                        }
                        free(ptr);
                        break;

                    case 2:
                        ptr = start;
                        while (ptr->next != NULL) {
                            ptr = ptr->next;
                        }
                        if (ptr->prev != NULL) {
                            ptr->prev->next = NULL;
                        } else {
                            start = NULL;
                        }
                        free(ptr);
                        break;

                    case 3:
                        printf("\nEnter the value to be deleted: ");
                        scanf("%d", &val);

                        ptr = start;
                        while (ptr != NULL && ptr->data != val) {
                            ptr = ptr->next;
                        }

                        if (ptr == NULL) {
                            printf("Value not found in the list.\n");
                        } else {
                            if (ptr->prev != NULL) {
                                ptr->prev->next = ptr->next;
                            } else {
                                start = ptr->next;
                            }
                            if (ptr->next != NULL) {
                                ptr->next->prev = ptr->prev;
                            }
                            free(ptr);
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