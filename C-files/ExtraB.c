//A. Find the sum of the elements of each row of a 2x3 matrix

#include <stdio.h>

int main() {
    // Define the dimensions of the matrix
    int rows = 2;
    int columns = 3;

    // Declare a 2x3 matrix
    int matrix[2][3];

    // Input elements for the matrix
    printf("Enter elements for the 2x3 matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate and display the sum of each row
    printf("Sum of each row:\n");
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < columns; j++) {
            rowSum += matrix[i][j];
        }
        printf("Row %d: %d\n", i + 1, rowSum);
    }

    return 0;
}



//-------------------------------------------------------------//
