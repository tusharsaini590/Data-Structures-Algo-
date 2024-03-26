// c program to perform insertion and deletion in single linked list with  pointers



#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node. It is a self-referential structure
struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *start = NULL;
    int option;

    printf("Namaskaram!, The following code is for both insertion and deletion in case of a single linked list.\n");

    // Main menu loop
    do {
        printf("\n\n\t\t**********MAIN MENU**********");
        printf("\n 1:) Create a Linked-List");
        printf("\n 2:) Display the Linked-List");
        printf("\n 3:) Insert a node in the LL");
        printf("\n 4:) Delete a node in the LL");
        printf("\n 5:) Exit the program");
        printf("\n\n Enter your choice : ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                // Create a linked list
                struct node *newNode, *ptr;
                int num;

                printf("\n Type numbers to create a Linked list (enter -1 to end):\n ");
                scanf("%d", &num);

                while (num != -1) {
                    newNode = (struct node *)malloc(sizeof(struct node));

                    if (newNode == NULL) {
                        printf("Memory allocation failed. Linked list creation aborted.\n");
                        break;
                    }

                    newNode->data = num;
                    newNode->next = NULL;

                    if (start == NULL) {
                        start = newNode;
                    } else {
                        ptr = start;
                        while (ptr->next != NULL){
                            ptr = ptr->next;
                        }
                        ptr->next = newNode;
                    }

                    printf(" Enter data to create the Linked-List (enter -1 to end): ");
                    scanf("%d", &num);
                }
                break;
            }
            case 2: {
                // Display the linked list
                struct node *ptr = start;
                if (start == NULL) {
                    printf("\nList is empty.");
                } else {
                    printf("\nLinked List: ");
                    while (ptr != NULL) {
                        printf("%d -> ", ptr->data);
                        ptr = ptr->next;
                    }
                    printf("NULL\n");
                }
                break;
            }
            case 3: {
                // Insert a node into the linked list
                struct node *newNode, *ptr, *prev;
                int num, val, choice;

                printf("\n Choose method of insertion:");
                printf("\n 1:) Insert at the beginning");
                printf("\n 2:) Insert at the end");
                printf("\n 3:) Insert after a specific value");
                printf("\n 4:) Insert before a specific value");
                printf("\n\n Enter your choice: ");
                scanf("%d", &choice);

                switch(choice) {
                    case 1:
                        printf("\n Enter the data to be inserted at the beginning: ");
                        scanf("%d", &num);

                        newNode = (struct node *)malloc(sizeof(struct node));
                        if (newNode == NULL) {
                            printf("Memory allocation failed. Unable to insert node.\n");
                            break;
                        }
                        newNode->data = num;
                        newNode->next = start;
                        start = newNode;
                        break;

                    case 2:
                        printf("\n Enter the data to be inserted at the end: ");
                        scanf("%d", &num);

                        newNode = (struct node *)malloc(sizeof(struct node));
                        if (newNode == NULL) {
                            printf("Memory allocation failed. Unable to insert node.\n");
                            break;
                        }
                        newNode->data = num;
                        newNode->next = NULL;

                        if (start == NULL) {
                            start = newNode;
                        } else {
                            ptr = start;
                            while (ptr->next != NULL) {
                                ptr = ptr->next;
                            }
                            ptr->next = newNode;
                        }
                        break;

                    case 3:
                        printf("\n Enter the data to be inserted  after a specific value: ");
                        scanf("%d", &num);
                        printf(" Enter the value after which you wanna insert: ");
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
                            ptr->next = newNode;
                        }
                        break;

                    case 4:
                        printf("\n Enter the data to be inserted before a specific value: ");
                        scanf("%d", &num);
                        printf(" Enter the value before which to insert: ");
                        scanf("%d", &val);

                        ptr = start;
                        prev = NULL;
                        while (ptr != NULL && ptr->data != val) {
                            prev = ptr;
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
                            newNode->next = ptr;
                            if (prev == NULL) {
                                start = newNode;
                            } else {
                                prev->next = newNode;
                            }
                        }
                        break;
                    default:
                        printf("\nInvalid choice.\nBaawle 4 ke alawa or konsa case dikh gya tenne!!");
                }
                break;
            }
            case 4: {
                // Delete a node from the linked list
                struct node *ptr = start, *prev = NULL;
                int choice, pos;

                if (start == NULL) {
                    printf("\nList is empty. Nothing to delete.");
                    break;
                }

                printf("\n Choose method of deletion:");
                printf("\n 1:) Delete at the beginning");
                printf("\n 2:) Delete at the end");
                printf("\n 3:) Delete at a specific position");
                printf("\n\n Enter your choice: ");
                scanf("%d", &choice);

                switch(choice) {
                    case 1:
                        // Delete at the beginning
                        start = start->next;
                        free(ptr);
                        break;

                    case 2:
                        // Delete at the end
                        while (ptr->next != NULL) {
                            prev = ptr;
                            ptr = ptr->next;
                        }
                        if (prev != NULL) {
                            prev->next = NULL;
                            free(ptr);
                        } else {
                            // If there is only one node
                            free(start);
                            start = NULL;
                        }
                        break;

                    case 3:
                        // Delete at a specific position
                        printf("\n Enter the position to be deleted: ");
                        scanf("%d", &pos);

                        if (pos < 1) {
                            printf("\nInvalid position.");
                            break;
                        }

                        int count = 1;
                        ptr = start;
                        while (ptr != NULL && count < pos) {
                            prev = ptr;
                            ptr = ptr->next;
                            count++;
                        }

                        if (ptr == NULL) {
                            printf("\nPosition not found in the list.");
                        } else {
                            if (prev != NULL) {
                                prev->next = ptr->next;
                            } else {
                                start = ptr->next;
                            }
                            free(ptr);
                        }
                        break;
                    default:
                        printf("\nInvalid choice.");
                }
                break;
            }
            case 5:
                printf("\nExiting...");
                break;
            default:
                printf("\nTry again, Moye More event occurs for you,lol!");
        }
    } while(option != 5);

    return 0;
}