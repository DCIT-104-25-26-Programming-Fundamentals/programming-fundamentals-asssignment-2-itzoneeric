#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 10;

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Part A: Transpose a matrix
void transposeMatrix(int matrix[10][10], int rows, int cols)
{
    int transpose[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix, rows, cols);

    cout << "\nTransposed Matrix:\n";
    displayMatrix(transpose, cols, rows);
}

// Part B: Add two matrices
void addMatrices(int A[10][10], int B[10][10],
                 int rows, int cols)
{
    int result[10][10];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nMatrix A:\n";
    displayMatrix(A, rows, cols);

    cout << "\nMatrix B:\n";
    displayMatrix(B, rows, cols);

    cout << "\nSum of Matrices:\n";
    displayMatrix(result, rows, cols);
}

// Part C: Multiply two matrices
void multiplyMatrices(int A[10][10], int B[10][10],
                      int rowsA, int colsA, int rowsB, int colsB)
{
    int result[10][10] = {0};

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            for (int k = 0; k < colsA; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nMatrix A:\n";
    displayMatrix(A, rowsA, colsA);

    cout << "\nMatrix B:\n";
    displayMatrix(B, rowsB, colsB);

    cout << "\nProduct of A x B:\n";
    displayMatrix(result, rowsA, colsB);
}

int main()
{
    int matrix[10][10];
    int A[10][10];
    int B[10][10];

    int rows, cols;

    // =========================================================
    // PART A - TRANSPOSE
    // =========================================================

    cout << "===== PART A: TRANSPOSE MATRIX =====\n";

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10)
    {
        cout << "Error: Matrix dimensions must be between 1 and 10."
             << endl;
        return 0;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    transposeMatrix(matrix, rows, cols);

    // =========================================================
    // PART B - ADDITION
    // =========================================================

    cout << "\n\n===== PART B: ADD TWO MATRICES =====\n";

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    if (rows <= 0 || rows > 10 || cols <= 0 || cols > 10)
    {
        cout << "Error: Matrix dimensions must be between 1 and 10."
             << endl;
        return 0;
    }

    cout << "\nEnter elements of Matrix A:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    cout << "\nEnter elements of Matrix B:\n";

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }

    addMatrices(A, B, rows, cols);

    // =========================================================
    // PART C - MULTIPLICATION
    // =========================================================

    int rowsA, colsA, rowsB, colsB;

    cout << "\n\n===== PART C: MULTIPLY TWO MATRICES =====\n";

    cout << "Enter rows of Matrix A: ";
    cin >> rowsA;

    cout << "Enter columns of Matrix A: ";
    cin >> colsA;

    cout << "Enter rows of Matrix B: ";
    cin >> rowsB;

    cout << "Enter columns of Matrix B: ";
    cin >> colsB;

    // Check dimensions
    if (rowsA <= 0 || rowsA > 10 ||
        colsA <= 0 || colsA > 10 ||
        rowsB <= 0 || rowsB > 10 ||
        colsB <= 0 || colsB > 10)
    {
        cout << "Error: Matrix dimensions must be between 1 and 10."
             << endl;
        return 0;
    }

    if (colsA != rowsB)
    {
        cout << "Error: Number of columns in Matrix A must equal "
             << "number of rows in Matrix B." << endl;
        return 0;
    }

    cout << "\nEnter elements of Matrix A:\n";

    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsA; j++)
        {
            cout << "Enter element A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    cout << "\nEnter elements of Matrix B:\n";

    for (int i = 0; i < rowsB; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            cout << "Enter element B[" << i << "][" << j << "]: ";
            cin >> B[i][j];
        }
    }

    multiplyMatrices(A, B, rowsA, colsA, rowsB, colsB);

    return 0;
}