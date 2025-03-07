#include <stdio.h>

int main() {
    // Declare an array with 5 elements
    int arr[5] = {1, 2, 3, 4, 5};  // Initialize array with values
    int i;  // Declare an integer variable for the loop counter

    // Print the array elements using a loop
    printf("Array elements are:\n");

    // Use a for loop to traverse the array
    for(i = 0; i < 5; i++) {
        // Access each element using the index i
        printf("Element at index %d: %d\n", i, arr[i]);
    }

    return 0;
}
