//Write a program that performs the matrix manipulations such as addition and deletion. The matrix class will have the member functions Create, Add, Delete, Display.

#include <stdio.h>
#include <stdlib.h>

// Define the Matrix structure
typedef struct {
    int rows;
    int cols;
    int **data;
} Matrix;

// Function prototypes
Matrix createMatrix(int rows, int cols);
Matrix addMatrices(Matrix mat1, Matrix mat2);
void deleteMatrix(Matrix mat);
void displayMatrix(Matrix mat);

int main() {
    // Example usage
    Matrix matrix1, matrix2, resultMatrix;

    // Create matrices
    matrix1 = createMatrix(3, 3);
    matrix2 = createMatrix(3, 3);

    // Display matrices
    printf("Matrix 1:\n");
    displayMatrix(matrix1);

    printf("\nMatrix 2:\n");
    displayMatrix(matrix2);

    // Add matrices
    resultMatrix = addMatrices(matrix1, matrix2);

    // Display the result
    printf("\nResult Matrix (Sum of Matrix 1 and Matrix 2):\n");
    displayMatrix(resultMatrix);

    // Delete matrices
    deleteMatrix(matrix1);
    deleteMatrix(matrix2);
    deleteMatrix(resultMatrix);

    return 0;
}

// Function to create a matrix
Matrix createMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;

    // Allocate memory for the matrix data
    mat.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; ++i) {
        mat.data[i] = (int *)malloc(cols * sizeof(int));
    }

    // Input values into the matrix (you can modify this part as needed)
    printf("Enter %d x %d matrix elements:\n", rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Enter element at row %d, column %d: ", i + 1, j + 1);
            scanf("%d", &mat.data[i][j]);
        }
    }

    return mat;
}

// Function to add two matrices
Matrix addMatrices(Matrix mat1, Matrix mat2) {
    Matrix result;
    result.rows = mat1.rows;
    result.cols = mat1.cols;

    // Allocate memory for the result matrix data
    result.data = (int **)malloc(result.rows * sizeof(int *));
    for (int i = 0; i < result.rows; ++i) {
        result.data[i] = (int *)malloc(result.cols * sizeof(int));
    }

    // Perform matrix addition
    for (int i = 0; i < result.rows; ++i) {
        for (int j = 0; j < result.cols; ++j) {
            result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
    }

    return result;
}

// Function to delete a matrix and free memory
void deleteMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; ++i) {
        free(mat.data[i]);
    }
    free(mat.data);
}

// Function to display a matrix
void displayMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.cols; ++j) {
            printf("%d\t", mat.data[i][j]);
        }
        printf("\n");
    }
}
