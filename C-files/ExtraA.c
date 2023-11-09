//A. WAP to copy between arrays element by element and the two arrays must have the same size.

#include <stdio.h>

void copyArrays(int source[], int destination[], int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

int main() {
    int size = 5;

    int sourceArray[] = {1, 2, 3, 4, 5};

    int destinationArray[size];

    copyArrays(sourceArray, destinationArray, size);

    printf("Destination Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", destinationArray[i]);
    }

    return 0;
}

//---------------------------------------------------------------//

//B. WAP to Input 10 integers & sort them in ascending order.

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the element found is greater than the next element
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Define the size of the array
    int size = 10;

    // Declare an array to store 10 integers
    int numbers[size];

    // Input 10 integers
    printf("Enter 10 integers:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }

    // Sort the array in ascending order
    bubbleSort(numbers, size);

    // Display the sorted array
    printf("Sorted Array (in ascending order): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
