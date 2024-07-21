package Ver4;

import java.util.Random;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rd = new Random();

        // get dims of first matrix from user
        System.out.print("Enter number of rows/columns for first matrix: ");
        int r1 = sc.nextInt();
        int c1 = sc.nextInt();

        // get dims of second matrix from user
        System.out.print("Enter number of rows/columns for second matrix: ");
        int r2 = sc.nextInt();
        int c2 = sc.nextInt();

        // init matrices with given dimensions
        Matrix m1 = new Matrix(r1, c1);
        Matrix m2 = new Matrix(r2, c2);

        // check if user wants to input their own numbers or generate random numbers
        System.out.print("Generate random matrices? (y/n): ");
        char generateRandom = sc.next().charAt(0);

        // have user enter seed for RNG
        if (generateRandom == 'y' || generateRandom == 'Y') {
            System.out.print("Enter a seed for the RNG: ");
            long seed = sc.nextLong();
            rd.setSeed(seed);
        }

        if (generateRandom == 'n' || generateRandom == 'N') {
            System.out.println("Input for first matrix:");
            m1.inputMatrix(sc);
            System.out.println("Input for second matrix:");
            m2.inputMatrix(sc);
        }
        else if (generateRandom == 'y' || generateRandom == 'Y') {
            m1.randomizeMatrix(rd);
            m2.randomizeMatrix(rd);

            System.out.println("First generated matrix:");
            m1.printMatrix();
            System.out.println("Second generated matrix:");
            m2.printMatrix();
        }
        else {
            System.out.println("Invalid choice");
            sc.close();
            System.exit(1);
        }

        try {
            // do addition
            System.out.println("Addition:");
            Matrix addResult = m1.add(m2);
            addResult.printMatrix();

            // do subtraction
            System.out.println("Subtraction:");
            Matrix subResult = m1.subtract(m2);
            subResult.printMatrix();

            // do multiplication
            if (c1 == r2) {
                System.out.println("Multiplication:");
                Matrix multResult = m1.multiply(m2);
                multResult.printMatrix();
            }
            else {
                System.out.println("Number of columns of first matrix must match the number of rows for the second matrix.");
            }
        }
        catch (IllegalArgumentException e) {
            // print error message
            System.err.println(e.getMessage()); 
        }

        // close the scanner
        sc.close();
    }
}