//Write a menu-driven program which will accept an array of 10 integer values and sort them with any two sorting algorithms of your choice.


#include <stdio.h>

// Function prototypes
void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);

int main() {
    const int arraySize = 10;
    int arr[arraySize];

    // Input values into the array
    printf("Enter 10 integer values:\n");
    for (int i = 0; i < arraySize; ++i) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Menu for sorting algorithms
    int choice;
    do {
        printf("\nSorting Menu:\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubbleSort(arr, arraySize);
                printf("Array after Bubble Sort:\n");
                break;
            case 2:
                insertionSort(arr, arraySize);
                printf("Array after Insertion Sort:\n");
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }

        // Display the sorted array
        for (int i = 0; i < arraySize; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");

    } while (choice != 3);

    return 0;
}

// Bubble Sort algorithm
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort algorithm
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}
