// Name: Heagen Bell
// Date: 10/22/2025
// Lab: 09
// Description: Read Matrix from file, print, add, multipy, and transpose matrices
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int** createMatrix(int size) {
    /* Create square matrix
    Args:
        size (int): size of the square matrix
    Returns:
        int**: pointer to the created square matrix
    */
    int** matrix = new int*[size]; // Assign pointer to array of rows
    for (int i = 0; i < size; i++) { // For each row
        matrix[i] = new int[size]; // Assign pointer to each column
    }
    return matrix; // Return pointer of the matrix
}

int** copyMatrix(int** matrix, int size) {
    /* Copy a matrix
    Args:
        matrix (int**): pointer to the original matrix
        size (int): size of the matrix
    Returns:
        int**: pointer to the copied matrix
    */
    int** copy = createMatrix(size); // Assign pointer to new matrix
    for (int i = 0; i < size; i++) { // For each row
        for (int j = 0; j < size; j++) { // For each column
            copy[i][j] = matrix[i][j]; // Copy element
        }
    }
    return copy; // Return pointer of the copied matrix
}

void readMatricesFromFile(string filename, int**& matrixA, int**& matrixB, int& size) {
    /* Read matrices from a file
    Args:
        filename (string): name of the file to read
        matrixA (int**&): reference to pointer of matrix A
        matrixB (int**&): reference to pointer of matrix B
        size (int&): reference to the size of the matrices
    */
    ifstream infile(filename); // Open file
    if (!infile) { // Check if file opened successfully
        cerr << "Error opening file: " << filename << endl; // Print error message
        return; // Exit function
    }
    
    infile >> size; // Read size of matrices
    
    matrixA = createMatrix(size); // Create matrix A
    matrixB = createMatrix(size); // Create matrix B
    
    for (int i = 0; i < size; i++) { // Read matrix A, for each row
        for (int j = 0; j < size; j++) { // For each column
            infile >> matrixA[i][j]; // Read element
        }
    }
    
    for (int i = 0; i < size; i++) { // Read matrix B, for each row
        for (int j = 0; j < size; j++) { // For each column
            infile >> matrixB[i][j]; // Read element
        }
    }
    
    infile.close(); // Close file
}

void printMatrix(int** matrix, int size) {
    /* Print a matrix
    Args:
        matrix (int**): pointer to the matrix
        size (int): size of the matrix
    */
    for (int i = 0; i < size; i++) { // For each row
        for (int j = 0; j < size; j++) { // For each column
            cout << setw(4) << matrix[i][j]; // Print element with padding
        }
        cout << endl; // New line 
    }
    cout << endl; // New line
}

int** addMatrices(int** matrixA, int** matrixB, int size) {
    /* Add two matrices
    Args:
        matrixA (int**): pointer to the first matrix
        matrixB (int**): pointer to the second matrix
        size (int): size of the matrices
    Returns:
        int**: pointer to the resulting matrix
    */
    int** result = createMatrix(size); // Create result matrix
    
    for (int i = 0; i < size; i++) { // For each row
        for (int j = 0; j < size; j++) { // For each column
            result[i][j] = matrixA[i][j] + matrixB[i][j]; // Add elements
        }
    }
    
    return result; // Return pointer of the resulting matrix
}

int** multiplyMatrices(int** matrixA, int** matrixB, int size) {
    /*
    Multiply two matrices
    Args:
        matrixA (int**): pointer to the first matrix
        matrixB (int**): pointer to the second matrix
        size (int): size of the matrices
    Returns:
        int**: pointer to the resulting matrix
    */
    int** result = createMatrix(size); // Create result matrix

    for (int i = 0; i < size; i++) { // For each row
        for (int j = 0; j < size; j++) { // For each column
            result[i][j] = 0;  // Initialize element to 0
            for (int k = 0; k < size; k++) { // Perform multiplication
                result[i][j] += matrixA[i][k] * matrixB[k][j]; // Multiply and accumulate
            }
        }
    }
    
    return result; // Return pointer of the resulting matrix
}

void diagonalSum(int** matrix, int size) {
    /* 
    Calculate sum of diagonal elements
    Args:
        matrix (int**): pointer to the matrix
        size (int): size of the matrix
    */
    int mainDiagonalSum = 0; // Sum of main diagonal
    int secondaryDiagonalSum = 0; // Sum of secondary diagonal
    
    for (int i = 0; i < size; i++) { // For each row
        mainDiagonalSum += matrix[i][i]; // Main diagonal element
        secondaryDiagonalSum += matrix[i][size - 1 - i]; // Secondary diagonal element
    }
    
    cout << "Sum of main diagonal elements: " << mainDiagonalSum << endl; // Print main diagonal sum
    cout << "Sum of secondary diagonal elements: " << secondaryDiagonalSum << endl; // Print secondary diagonal sum
    cout << endl; // New line
}

void swapRows(int** matrix, int size, int row1, int row2) {
    /* Swap matrix rows
    Args:
        matrix (int**): pointer to the matrix
        size (int): size of the matrix
        row1 (int): index of the first row to swap
        row2 (int): index of the second row to swap
    */
    if (row1 < 0 || row1 >= size || row2 < 0 || row2 >= size) { // Validate row indices
        cout << "Error: Invalid row indices!" << endl; // Error message
        return; // Exit function
    }

    int* temp = matrix[row1]; // Swap rows using a temporary pointer
    matrix[row1] = matrix[row2]; // Swap first row with second row
    matrix[row2] = temp; // Assign temporary pointer to second row
    
    cout << "Matrix after swapping rows " << row1 << " and " << row2 << ":" << endl; // Print header
    printMatrix(matrix, size); // Print matrix
}

void swapColumns(int** matrix, int size, int col1, int col2) {
    /* Swap matrix columns
    Args:
        matrix (int**): pointer to the matrix
        size (int): size of the matrix
        col1 (int): index of the first column to swap
        col2 (int): index of the second column to swap
    */
    if (col1 < 0 || col1 >= size || col2 < 0 || col2 >= size) { // Validate column indices
        cout << "Error: Invalid column indices!" << endl; // Error message
        return; // Exit function
    }
    
    for (int i = 0; i < size; i++) { // For each row
        int temp = matrix[i][col1]; // Swap elements using a temporary variable
        matrix[i][col1] = matrix[i][col2]; // Swap first column element with second column element
        matrix[i][col2] = temp; // Assign temporary variable to second column element
    }
    
    cout << "Matrix after swapping columns " << col1 << " and " << col2 << ":" << endl; // Print header
    printMatrix(matrix, size); // Print matrix
}

void updateElement(int** matrix, int size, int row, int col, int newValue) {
    /* Update matrix element
    Args:
        matrix (int**): pointer to the matrix
        size (int): size of the matrix
        row (int): index of the row to update
        col (int): index of the column to update
        newValue (int): new value to set
    */
    if (row < 0 || row >= size || col < 0 || col >= size) { // Validate indices
        cout << "Error: Invalid indices!" << endl; // Error message
        return; // Exit function
    }
    
    matrix[row][col] = newValue; // Update element
    cout << "Matrix after updating element at position (" << row << ", " << col << ") to " << newValue << ":" << endl; // Print header
    printMatrix(matrix, size); // Print matrix
}

int main() {
    /* Main function 
    */
    int** matrixA = nullptr; // Pointer to matrix A
    int** matrixB = nullptr; // Pointer to matrix B
    int size; // Size of the matrices
    string filename; // Filename to read matrices from
    
    cout << "Enter the filename: "; // Prompt for filename
    cin >> filename; // Read filename from user
    
    readMatricesFromFile(filename, matrixA, matrixB, size); // Read and print matrices
    
    cout << "Matrix A:" << endl; // Print header
    printMatrix(matrixA, size);  // Print matrix A
    
    cout << "Matrix B:" << endl; // Print header
    printMatrix(matrixB, size); // Print matrix B
    
    int** sum = addMatrices(matrixA, matrixB, size); // Add matrices
    cout << "Matrix Sum (A + B):" << endl; // Print header
    printMatrix(sum, size); // Print sum matrix
    
    int** product = multiplyMatrices(matrixA, matrixB, size); // Multiply matrices
    cout << "Matrix Product (A * B):" << endl; // Print header
    printMatrix(product, size); // Print product matrix

    cout << "Diagonal sums for Matrix A:" << endl; // Print header
    diagonalSum(matrixA, size); // Diagonal sums for Matrix A
    
    int** matrixA_copy = copyMatrix(matrixA, size); // Create copy of Matrix A for row swap
    swapRows(matrixA_copy, size, 0, 1); // Swap rows
    
    int** matrixB_copy = copyMatrix(matrixB, size); // Create copy of Matrix B for column swap
    swapColumns(matrixB_copy, size, 0, 1); // Swap columns

    matrixA_copy = copyMatrix(matrixA, size); // Create copy of Matrix A for element update
    updateElement(matrixA_copy, size, 0, 0, 99); // Update element
    
    return 0; // Exit program
}