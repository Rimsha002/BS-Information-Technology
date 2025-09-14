#include <iostream>
#include <vector>
#include "SparseMatrixADT.h"
using namespace std;
int main()
{
    cout << "Welcome to Sparse Matrix ADT" << endl;
    cout << "=============================" << endl;

    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;
    SparseMatrixADT<int> matrix(rows, cols);
    matrix.SetValue(0, 0, 5);
    matrix.SetValue(0, 1, 7);
    matrix.SetValue(1, 2, 10);
    matrix.SetValue(2, 2, 15);
    matrix.SetValue(3, 3, 20);

    cout << "Matrix created and values set successfully!" << endl;

    int choice = 0;
    do
    {
        cout << "\nSelect an option:" << endl;
        cout << "1. Display the Sparse Matrix" << endl;
        cout << "2. Sum of Diagonal Elements" << endl;
        cout << "3. Transpose of the Matrix" << endl;
        cout << "4. Multiply two Matrices" << endl;

        cout << "Enter -1 to exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            matrix.display();
            break;
        }
        case 2:
        {
            int diagonalSum = matrix.RecursiveDiagonalSum(0);
            cout << "Sum of diagonal elements: " << diagonalSum << endl
                 << endl;
            break;
        }
        case 3:
        {
            cout << "Transpose of the ";
            matrix.Transpose().display();
            break;
        }
        case 4:
        {
            SparseMatrixADT<int> matrix1(2, 2);
            SparseMatrixADT<int> matrix2(2, 2);
            matrix1.SetValue(0, 0, 1);
            matrix1.SetValue(0, 1, 2);
            matrix2.SetValue(0, 0, 3);
            matrix2.SetValue(1, 0, 4);

            cout << "Matrix 1:" << endl;
            matrix1.display();
            cout << "Matrix 2:" << endl;
            matrix2.display();

            SparseMatrixADT<int> result = matrix1.Multiply(matrix2);
            cout << "\nMatrix after Multiplication:" << endl;
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    cout << result.GetValue(i, j) << " ";
                }
                cout << endl;
            }
            break;
        }
        case -1:
        {
            cout << "GoodBye!!!" << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        }

    } while (choice != -1);

    
    return 0;
}