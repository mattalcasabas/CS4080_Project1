package Ver4;

import java.util.Random;
import java.util.Scanner;

public class Matrix {
    private float[][] data;
    private int rows;
    private int cols;

    public Matrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;

        data = new float[rows][cols];
    }

    // input matrix elements from the user
    public void inputMatrix(Scanner sc) {
        System.out.println("Enter matrix elements of matrix (" + rows + "x" + cols + "):");
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = sc.nextFloat();
            }
        }
    }

    // generate random matrices
    public void randomizeMatrix(Random rd) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // create random floats between 0 and 99.99
                data[i][j] = rd.nextFloat() * 100.0f;
            }
        }
    }

    // print matrix elements
    public void printMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                System.out.printf("%8.2f ", data[i][j]);
            }
            System.out.println();
        }
    }

    // do matrix addition
    public Matrix add(Matrix other) {
        if (rows != other.rows || cols != other.cols) {
            throw new IllegalArgumentException("Matrices need to bew the same dimensions for addition!");
        }
        Matrix result = new Matrix(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    // do matrix subtraction
    public Matrix subtract(Matrix other) {
        if (rows != other.rows || cols != other.cols) {
            throw new IllegalArgumentException("Matrices need to bew the same dimensions for subtraction!");
        }
        Matrix result = new Matrix(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return result;
    }

    // do matrix multiplication
    public Matrix multiply(Matrix other) {
        if (cols != other.rows) {
            throw new IllegalArgumentException("Number of columns of first matrix must match the number of rows for the second matrix!");
        }
        Matrix result = new Matrix(rows, other.cols);
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
}
