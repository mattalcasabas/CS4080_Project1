#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Matrix {
    private:
        float **data;
        int rows;
        int cols;

        void allocateMemory() {
            data = new float*[rows];
            for (int i = 0; i < rows; ++i) {
                data[i] = new float[cols];
            }
        }

        void deallocateMemory() { 
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
        }
    
    public:
        // constructor: create a matrix
        Matrix(int rows, int cols) : rows(rows), cols(cols) {
            allocateMemory();
        }
        // destructor: delete a matrix
        ~Matrix() {
            deallocateMemory();
        }
    
        // input matrix elements from user
        void inputMatrix() {
            cout << "Enter matrix elements of matrix (" << rows << "x" << cols << "):" << endl;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    cin >> data[i][j];
                }
            }
        }

        // generate random matrices
        void randomizeMatrix() {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < rows; ++j) {
                    // create random floats between 0 and 99.99
                    data[i][j] = static_cast<float>(rand()) / RAND_MAX * 100.0f; 
                }
            }
        }

        // print matrix elements
        void printMatrix() const {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    cout << data[i][j] << " ";
                }
                cout << endl;
            }
        }

        Matrix operator+(const Matrix &other) const {
            // ensure that the dims are the same for addition
            if (rows != other.rows || cols != other.cols) {
                throw invalid_argument("Matrices need to be same dimensions for addition!");
            }

            Matrix result(rows, cols);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    result.data[i][j] = data[i][j] + other.data[i][j];
                }
            }
            return result;
        }
        
        Matrix operator-(const Matrix &other) const {
            // ensure that the dims are the same for subtraction
            if (rows != other.rows || cols != other.cols) {
                throw invalid_argument("Matrices need to be same dimensions for subtraction!");
            }

            Matrix result(rows, cols);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    result.data[i][j] = data[i][j] - other.data[i][j];
                }
            }
            return result;
        }

        Matrix operator*(const Matrix &other) const {
            // ensure that cols of first matrix match rows of second matrix for multiplication
            if (cols != other.rows) {
                throw invalid_argument("Number of columns of first matrix must match the number of rows for the second matrix.");
            }

            Matrix result(rows, cols);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    result.data[i][j] = 0;
                    for (int k = 0; k < cols; ++k) {
                        result.data[i][j] += data[i][k] * other.data[k][j];
                    }
                }
            }
            return result;
        }
};

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

    // init matrices with given dimensions
    Matrix m1(r1, c1);
    Matrix m2(r2, c2);

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
        m1.inputMatrix();
        cout << "Input for second matrix:" << endl;
        m2.inputMatrix();
    }
    else if (generateRandom == 'y' || generateRandom == 'Y') {
        m1.randomizeMatrix();
        m2.randomizeMatrix();
        cout << "First generated matrix:" << endl;
        m1.printMatrix();
        cout << "Second generated matrix:" << endl;
        m2.printMatrix();
    }
    else {
        cout << "Invalid choice." << endl;
        return 1;
    }

    // do matrix operations using overloaded operators
    try {
        // do addition
        cout << "Addition:" << endl;
        Matrix addResult = m1 + m2;
        addResult.printMatrix();

        // do subtraction
        cout << "Subtraction:" << endl;
        Matrix subResult = m1 - m2;
        subResult.printMatrix();

        // do multiplication
        if (c1 == c2) {
            cout << "Multiplication:" << endl;
            Matrix multResult = m1 * m2;
            multResult.printMatrix();
        }
        else {
            cout << "Number of columns of first matrix must match the number of rows for the second matrix." << endl;
        }
    }
    catch (const invalid_argument &e) {
        // print error message to stderr
        cerr << e.what() << endl;
    }

    // end program
    return 0;
}