#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// type alias for 2D vector of integers
typedef vector<vector<int>> Matrix;

// input matrix elements from user
void inputMatrix(int **matrix, int rows, int cols) {
    cout << "Enter matrix elements: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
}

// generate random matrices
void randomizeMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            // create random numbers between 0 and 99
            matrix[i][j] = rand() % 100; 
        }
    }
}

// print matrix elements
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// create a matrix
int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

// delete a matrix
void deleteMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// add two matrices
int** addMatrices(int **m1, int **m2, int rows, int cols) {
    // create a result matrix
    int **result = createMatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return result;
}

// subtract two matrices
int** subtractMatrices(int **m1, int **m2, int rows, int cols) {
    // create a result matrix
    int **result = createMatrix(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return result;
}

// multiply two matrices
int** multiplyMatrices(int **m1, int **m2, int r1, int c1, int c2) {
    int **result = createMatrix(r1, c2);
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < c1; ++k) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return result;
}

int main() {
    int r1, c1, r2, c2;
    char generateRandom;
    unsigned int seed;

    // get dims of first matrix from user
    cout << "Enter number of rows/columns for first matrix: ";
    cin >> r1 >> c1;
    
    // get dims of second matrix from user
    cout << "Enter number of rows/columns for second matrix: ";
    cin >> r2 >> c2;

    // check if dimensions work for addition and subtraction
    if (r1 != r2 || c1 != c2) {
        cout << "Matrices must have the same dimensions for addition and subtraction." << endl;
        return 1;
    }

    // init matrices with given dimensions
    int **m1 = createMatrix(r1, c1);
    int **m2 = createMatrix(r2, c2);

    // check if user wants to input their own numbers or generate random matrices
    cout << "Generate random matrices? (y/n): " << endl;
    cin >> generateRandom;

    // have user enter a seed for RNG
    if (generateRandom == 'y' || generateRandom == 'Y') {
        cout << "Enter a seed for the RNG: ";
        cin >> seed;
        srand(seed);
    }

    if (generateRandom == 'n' || generateRandom == 'N') {
        cout << "Input for first matrix:" << endl;
        inputMatrix(m1, r1, c1);
        cout << "Input for second matrix:" << endl;
        inputMatrix(m2, r2, c2);
    }
    else if (generateRandom == 'y' || generateRandom == 'Y') {
        randomizeMatrix(m1, r1, c1);
        randomizeMatrix(m2, r2, c2);
        cout << "First generated matrix:" << endl;
        printMatrix(m1, r1, c1);
        cout << "Second generated matrix:" << endl;
        printMatrix(m2, r2, c2);
    }
    else {
        cout << "Invalid choice." << endl;
        return 1;
    }

    // do matrix addition
    cout << "Addition:" << endl;
    int **addResult = addMatrices(m1, m2, r1, c1);
    printMatrix(addResult, r1, c1);
    deleteMatrix(addResult, r1);

    // do matrix subtraction
    cout << "Subtraction:" << endl;
    int **subResult = subtractMatrices(m1, m2, r1, c1);
    printMatrix(subResult, r1, c1);
    deleteMatrix(subResult, r1);

    // check if dimensions work for matrix multiplication
    if (c1 != r2) {
        cout << "Number of columns of first matrix must match the number of rows for the second matrix." << endl;
        return 1;
    }

    // do matrix multiplication
    cout << "Multiplication:" << endl;
    int **multResult = multiplyMatrices(m1, m2, r1, c1, c2);
    printMatrix(multResult, r1, c2);
    deleteMatrix(multResult, r1);

    // delete matrices
    deleteMatrix(m1, r1);
    deleteMatrix(m2, r2);

    // end program
    return 0;
}