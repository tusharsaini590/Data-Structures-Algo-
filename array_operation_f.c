#include <stdio.h>
#define max 100
int size = 0;

int arr[max];

void displayMenu() {
    printf("\n\n\t\t**********MAIN MENU**********");
    printf("\n1. Create an Array");
    printf("\n2. Display the Array");
    printf("\n3. Insert an Element");
    printf("\n4. Delete an Element");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
}

void enterElements() {
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    if (size > max) {
        printf("Size exceeds array limit.\n");
    } else if (size == 0) {
        printf("NO MEMORY ALLOCATION\n");
    } else {
        printf("Enter elements: ");
        for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }
    }
}

void displayArray() {
    printf("Array contains: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement() {
    int element, position;
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert: ");
    scanf("%d", &position);
    if (position < 0 || position > size) {
        printf("Invalid position.\n");
    } else if (size >= max) {
        printf("Array is full.\n");
    } else {
        for (int i = size; i > position; i--) {
            arr[i] = arr[i - 1];
        }
        arr[position] = element;
        size++;
    }
    displayArray();
}

void deleteElement() {
    int position;
    printf("Enter the position to delete: ");
    scanf("%d", &position);
    if (position < 0 || position >= size) {
        printf("Invalid position.\n");
    } else {
        for (int i = position; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    displayArray();
}

int main() {
    int choice,m;
   // printf("enter max size of the array: ");
    //scanf("%d", &m);




    do {
        displayMenu();
        scanf("%d", &choice);
        if (choice > 5 || choice <= 0) {
            printf("INVALID CHOICE\n");
        } else {
            switch (choice) {
                case 1:
                    enterElements();
                    break;
                case 2:
                    displayArray();
                    break;
                case 3:
                    insertElement();
                    break;
                case 4:
                    deleteElement();
                    break;
                case 5:
                    printf("Aapka Din Shub ho\n");
                    break;
            }
        }
    } while (choice != 5);

    return 0;
}