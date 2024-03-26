// C program to create dynamic array
// with function

#include <stdio.h>   // headerfile containing imp prebuilt functions like scanf,printf, sprintf, gets etc

// Function to read the size of the array
int readArraySize() {
    int size;   //local variable to this function only
    printf("Enter size of array: ");
    scanf("%d", &size);
    return size;
}

// Function to read array elements
void create_array(int arr[], int size) {
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
    printf("\n");  //\n : a new line character
}

// Main function starts from here
int main() {
    int size;
    size = readArraySize();  // output from readArraySize stores in size variable declared in the main function's block 
    int newarray[size];
    create_array(newarray, size);
    displayArray(newarray, size);

    return 0;

}
