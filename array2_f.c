// C program to create dynamic array
// with function

#include <stdio.h>

// Function to read the size of the array
int readArraySize() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    return size;
}

// Function to read array elements
void readArrayElements(int arr[], int size) {
    printf("Enter %d elements for the array: ", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }
}

// Function to display array elements
void displayArray(int arr[], int size) {
    printf("The elements of the array are: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    size = readArraySize();
    int newarray[size];
    readArrayElements(newarray, size);
    displayArray(newarray, size);

    return 0;

}
