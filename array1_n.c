// C program to create dynamic array
// without function without pointer

#include "stdio.h"  // includibg header file(important)
int main() {
    int size; // initializing global variables
    int newarray[size]; // declaring array variable with size as variable size 

    printf("Enter size of array: "); //built in function to print on console
    scanf("%d", &size);              // built in function to read data written on console



    printf("Enter %d elements for the array", size);
    for (int i = 0; i < size; ++i)      // iteration loop (**imp:- "i<size" -yes, "i<=size"- no; bcz then we have to put i+1 elements to print i elements
    {
        scanf("%d", &newarray[i]);
       }
    printf("The elements of the array are ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", newarray[i]);
    }
}



