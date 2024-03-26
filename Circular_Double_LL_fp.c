// c program for  insertion and deletion in circular double linked list using functions and pointers

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

// Main Menu Functions
struct node *create_cdll();
void display_cdll(struct node *);
struct node *insert_Node(struct node *);
struct node *delete_Node(struct node *);

int main() {
    struct node *start = NULL;
    int option;

    printf("NAMASKARAM! This program demonstrates insertion and deletion in a circular doubly linked list.\n");

    // Main menu loop
    do {
        printf("\n\n\t\t**********MAIN MENU**********");
        printf("\n 1:) Create a Circular Doubly Linked List");
        printf("\n 2:) Display the Circular Doubly Linked List");
        printf("\n 3:) Insert a node in the CDLL");
        printf("\n 4:) Delete a node in the CDLL");
        printf("\n 5:) Exit the program");
        printf("\n\n Enter your choice : ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                start = create_cdll();
                break;
            case 2:
                display_cdll(start);
                break;
            case 3:
                start = insert_Node(start);
                break;
            case 4:
                start = delete_Node(start);
                break;
            case 5:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid option. Please try again.");
        }
    } while(option != 5);

    return 0;
}

struct node *create_cdll() {
    struct node *start = NULL;
    struct node *newNode, *ptr;
    int num;

    printf("\nEnter numbers to create a Circular Doubly Linked List (enter -1 to end):\n");
    scanf("%d", &num);

    while (num != -1) {
        newNode = (struct node *)malloc(sizeof(struct node));

        if (newNode == NULL) {
            printf("Memory allocation failed. Circular doubly linked list creation aborted.\n");
            return start;
        }

        newNode->data = num;

        if (start == NULL) {
            start = newNode;
            newNode->next = start;
            newNode->prev = start;
        } else {
            ptr = start->prev;
            ptr->next = newNode;
            newNode->prev = ptr;
            newNode->next = start;
            start->prev = newNode;
        }

        printf("Enter data to create the Circular Doubly Linked List (enter -1 to end): ");
        scanf("%d", &num);
    }

    return start;
}

void display_cdll(struct node *start) {
    struct node *ptr = start;

    if (start == NULL) {
        printf("\nList is empty.");
        return;
    }

    printf("\nCircular Doubly Linked List: ");
    do {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);
    printf("(head)\n");
}

struct node *insert_Node(struct node *start) {
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
                return start;
            }
            newNode->data = num;

            newNode->next = start;
            newNode->prev = start->prev;
            start->prev->next = newNode;
            start->prev = newNode;
            start = newNode;
            break;

        case 2:
            printf("\nEnter the data to be inserted at the end: ");
            scanf("%d", &num);

            newNode = (struct node *)malloc(sizeof(struct node));
            if (newNode == NULL) {
                printf("Memory allocation failed. Unable to insert node.\n");
                return start;
            }
            newNode->data = num;

            newNode->next = start;
            newNode->prev = start->prev;
            start->prev->next = newNode;
            start->prev = newNode;
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
                        return start;
                    }
                    newNode->data = num;
                    newNode->next = ptr->next;
                    newNode->prev = ptr;
                    ptr->next->prev = newNode;
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
                if (ptr->data == val) {
                    newNode = (struct node *)malloc(sizeof(struct node));
                    if (newNode == NULL) {
                        printf("Memory allocation failed. Unable to insert node.\n");
                        return start;
                    }
                    newNode->data = num;
                    newNode->next = ptr;
                    newNode->prev = ptr->prev;
                    ptr->prev->next = newNode;
                    ptr->prev = newNode;
                    if (ptr == start) {
                        start = newNode;
                    }
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

    return start;
}

struct node *delete_Node(struct node *start) {
    struct node *ptr, *prev;
    int choice, val;

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
            start->prev = ptr->prev;
            ptr->prev->next = start;
            free(ptr);
            break;

        case 2:
            ptr = start->prev;
            ptr->prev->next = start;
            start->prev = ptr->prev;
            free(ptr);
            break;

        case 3:
            printf("\nEnter the value to be deleted: ");
            scanf("%d", &val);

            ptr = start;
            do {
                if (ptr->data == val) {
                    if (ptr == start) {
                        start = ptr->next;
                    }
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                    free(ptr);
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

    return start;
}
