// c program to insert-delete element in a dynamic array with pointers


#include <stdio.h>
#define MAX 100

int main() {
    int size, *s;
    int arr[MAX];
    int choice;

    do {
        printf("\n\n\t\t**********MAIN MENU**********");
        printf("\n1. Create an Array");
        printf("\n2. Display the Array");
        printf("\n3. Insert an Element");
        printf("\n4. Delete an Element");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter the number of elements: ");
                scanf("%d", &size);
                s = &size;
                if (*s > MAX) {
                    printf("Size exceeds array limit.\n");
                } else if (*s == 0) {
                    printf("NO MEMORY ALLOCATION\n");
                } else {
                    printf("Enter elements: ");
                    for (int i = 0; i < *s; i++) {
                        scanf("%d", &arr[i]);
                    }
                }
                break;
            }
            case 2: {
                printf("Array contains: ");
                for (int i = 0; i < *s; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 3: {
                int element, position, *v, *p;
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                v = &element;
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                p = &position;
                if (*p < 0 || *p > *s) {
                    printf("Invalid position.\n");
                } else {
                    for (int i = *s; i > *p; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[*p] = *v;
                    (*s)++;
                }
                printf("Array contains: ");
                for (int i = 0; i < *s; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 4: {
                int position, *p;
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                p = &position;
                if (*p < 0 || *p >= *s) {
                    printf("Invalid position.\n");
                } else {
                    for (int i = *p; i < *s - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    (*s)--;
                }
                printf("Array contains: ");
                for (int i = 0; i < *s; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 5:
                printf("GOODBYE\n");
                break;
            default:
                printf("INVALID CHOICE\n");
        }
    } while (choice != 5);

    return 0;
}