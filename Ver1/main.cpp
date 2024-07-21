#include <iostream>
#include <vector>

using namespace std;

// type alias for 2D vector of integers
typedef vector<vector<int>>> Matrix;

// input matrix elements from user
void inputMatrix(Matrix &matrix, int rows, int cols) {
    cout << "Enter matrix elements: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
}

// print matrix elements
void printMatrix(const Matrix &matrix) {
    for (const auto &row : matrix) {
        for (const auto &element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

// add two matrices
Matrix addMatrices(const Matrix &m1, const Matrix &m2, int rows, int cols) {
    // create a result matrix
    Matrix result(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return result;
}

// subtract two matrices
Matrix subtractMatrices(const Matrix &m1, const Matrix &m2, int rows, int cols) {
    // create a result matrix
    Matrix result(rows, vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return result;
}

// multiply two matrices
Matrix multiplyMatrices(const Matrix &m1, const Matrix &m2, int rows, int cols) {

}