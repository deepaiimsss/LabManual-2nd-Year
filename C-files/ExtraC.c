//WAP to copy between arrays element by element and the two arrays must havethe same size.

#include <stdio.h>

int main() {
    const int arraySize = 5;  // Change this to the desired size of your arrays
    int sourceArray[arraySize];
    int destinationArray[arraySize];

    // Input values into the sourceArray (you can modify this part as needed)
    printf("Enter %d elements for the source array:\n", arraySize);
    for (int i = 0; i < arraySize; ++i) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &sourceArray[i]);
    }

    // Copy elements from sourceArray to destinationArray
    for (int i = 0; i < arraySize; ++i) {
        destinationArray[i] = sourceArray[i];
    }

    // Display the contents of the source and destination arrays
    printf("\nSource Array: ");
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", sourceArray[i]);
    }

    printf("\nDestination Array: ");
    for (int i = 0; i < arraySize; ++i) {
        printf("%d ", destinationArray[i]);
    }

    return 0;
}
