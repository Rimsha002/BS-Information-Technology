#include <iostream>
#include <fstream>
using namespace std;

class Matrix
{
private:
    int **data;
    int rows;
    int cols;
    ifstream file;

public:
    Matrix(int numRows = 0, int numCols = 0)
    {
        rows = numRows;
        cols = numCols;
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
        }

        // Initialize matrix with 0
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = 0;
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    void setValue(int row, int col, int val)
    {
        data[row][col] = val;
    }

    int getValue(int row, int col) const
    {
        return data[row][col];
    }

    int getRows() const
    {
        return rows;
    }

    int getCols() const
    {
        return cols;
    }

    void read_SparseMatrix(const string &filename)
    {
        file.open(filename);

        if (!file.is_open())
        {
            cerr << "Error opening file!" << endl;
            return;
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                file >> data[i][j];
            }
        }
        file.close();
    }

    void display() const
    {
        cout << "\nOriginal Matrix is: " << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Overload operator[] to return a pointer to a row
    int *operator[](int row)
    {
        if (row >= rows || row < 0)
        {
            cerr << "Index out of bounds!" << endl;
            return 0;
        }
        return data[row];
    }

    // Const version of operator[] for constant access
    const int *operator[](int row) const
    {
        if (row >= rows || row < 0)
        {
            cerr << "Index out of bounds!" << endl;
            return 0;
        }
        return data[row]; // Return the pointer to the row
    }
};

//////////////////////////////
class SparseMatrix
{
private:
    int **S_Mat;
    int non_zero;
    const int colms = 3;
    Matrix m;

public:
    SparseMatrix(const string &filename, int numRows, int numCols) : m(numRows, numCols)
    {
        non_zero = 0;

        m.read_SparseMatrix(filename);
     
        non_zero = countNonZero();

        // Initialize sparse matrix
        S_Mat = new int *[non_zero];
        for (int i = 0; i < non_zero; i++)
        {
            S_Mat[i] = new int[colms];
        }

        // Store non-zero elements in Sparse matrix
        int idx = 0;
        for (int i = 0; i < m.getRows(); i++)
        {
            for (int j = 0; j < m.getCols(); j++)
            {
                if (m.getValue(i, j) != 0)
                {
                    S_Mat[idx][0] = i;
                    S_Mat[idx][1] = j;
                    S_Mat[idx][2] = m.getValue(i, j);
                    idx++;
                }
            }
        }
    }

    ~SparseMatrix()
    {
        for (int i = 0; i < non_zero; i++)
        {
            delete[] S_Mat[i];
        }
        delete[] S_Mat;
    }

    int countNonZero()
    {
        int count = 0;
        for (int i = 0; i < m.getRows(); i++)
        {
            for (int j = 0; j < m.getCols(); j++)
            {
                if (m.getValue(i, j) != 0)
                {
                    count++;
                }
            }
        }
        return count;
    }

//    // Adding two sparse matrices
    SparseMatrix addSparseMatrix(const SparseMatrix &sparse2)
    {
        if (m.getRows() != sparse2.m.getRows() || m.getCols() != sparse2.m.getCols())
        {
            cout << "Matrices are not of the same size." << endl;
            exit(1);
        }

        SparseMatrix result;

        int i = 0, j = 0, k = 0;
        while (i < non_zero && j < sparse2.non_zero)
        {
            if (S_Mat[i][0] == sparse2.S_Mat[j][0] && S_Mat[i][1] == sparse2.S_Mat[j][1])
            {
                result.S_Mat[k][0] = S_Mat[i][0];
                result.S_Mat[k][1] = S_Mat[i][1];
                result.S_Mat[k][2] = S_Mat[i][2] + sparse2.S_Mat[j][2];
                i++;
                j++;
                k++;
            }
            else if (S_Mat[i][0] < sparse2.S_Mat[j][0] || (S_Mat[i][0] == sparse2.S_Mat[j][0] && S_Mat[i][1] < sparse2.S_Mat[j][1]))
            {
                result.S_Mat[k][0] = S_Mat[i][0];
                result.S_Mat[k][1] = S_Mat[i][1];
                result.S_Mat[k][2] = S_Mat[i][2];
                i++;
                k++;
            }
            else
            {
                result.S_Mat[k][0] = sparse2.S_Mat[j][0];
                result.S_Mat[k][1] = sparse2.S_Mat[j][1];
                result.S_Mat[k][2] = sparse2.S_Mat[j][2];
                j++;
                k++;
            }
        }

        while (i < non_zero)
        {
            result.S_Mat[k][0] = S_Mat[i][0];
            result.S_Mat[k][1] = S_Mat[i][1];
            result.S_Mat[k][2] = S_Mat[i][2];
            i++;
            k++;
        }

        while (j < sparse2.non_zero)
        {
            result.S_Mat[k][0] = sparse2.S_Mat[j][0];
            result.S_Mat[k][1] = sparse2.S_Mat[j][1];
            result.S_Mat[k][2] = sparse2.S_Mat[j][2];
            j++;
            k++;
        }

        result.non_zero = k;
        return result;
    }

    void displaySparse() const
    {
        cout << "\nSparse Matrix is: " << endl
             << endl;
        cout << "Row: Col: Value" << endl;
        for (int i = 0; i < non_zero; i++)
        {
            for (int j = 0; j < colms; j++)
            {
                cout << S_Mat[i][j] << "    ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix m(3, 3);
    m.read_SparseMatrix("matrixA.txt");
    m.display();

    SparseMatrix sm("matrixA.txt", 3, 3);
    sm.displaySparse();


    Matrix m2(3, 3);
    m2.read_SparseMatrix("matrixB.txt");
    m2.display();
    //Adding two sparse matrices
    SparseMatrix sm2("matrixB.txt", 3, 3);
    sm2.displaySparse();


    sm2.addSparseMatrix(sm);
    sm2.displaySparse();

    
    return 0;
}
