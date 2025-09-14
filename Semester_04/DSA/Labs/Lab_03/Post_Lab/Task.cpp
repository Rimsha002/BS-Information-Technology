#include <iostream>
#include <fstream>

using namespace std;

// Matrix class to store the general matrix
class Matrix {
private:
    int rows, cols;
    int** data;

public:
    // Constructor
    Matrix(int r, int c) 
    {
        rows = r; 
        cols = c;
        data = new int*[rows];  // Allocate rows
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];  // Allocate columns for each row
            for (int j = 0; j < cols; ++j) {
                data[i][j] = 0;  // Initialize with zeros
            }
        }
    }

    // Destructor to free the allocated memory
    ~Matrix() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];  
        }
        delete[] data;  
    }

    // Overloading () operator for accessing matrix elements
    int& operator(int r, int c) {
        return data[r][c];
    }

    // Function to read data from a file
    void readFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                file >> data[i][j];  
            }
        }

        file.close();
    }

    // Function to display the matrix
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Get number of rows
    int getRows() const {
        return rows;
    }

    // Get number of columns
    int getCols() const {
        return cols;
    }
};

// SparseMatrix class to store the sparse matrix and perform operations
class SparseMatrix {
private:
    struct Element {
        int row;
        int col;
        int value;
    };

    int rows, cols, nonZeroCount;
    Element* elements;  // Dynamic array to store non-zero elements

public:
    // Constructor
    SparseMatrix(int nonZero, int c) : nonZeroCount(nonZero), cols(c) {

        elements = new Element[nonZero];  // Allocate memory for non-zero elements
    }

    // Constructor to create SparseMatrix from a general Matrix
    SparseMatrix(const Matrix& matrix) {
        rows = matrix.getRows();
        cols = matrix.getCols();
        nonZeroCount = 0;

        // Count non-zero elements
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int elem = Matrix(i, j);
                if (elem != 0) {
                    ++nonZeroCount;
                }
            }
        }

        // Allocate memory for non-zero elements
        elements = new Element[nonZeroCount];

        // Store non-zero elements
        int index = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (Matrix(i, j) != 0) {
                    elements[index].row = i;
                    elements[index].col = j;
                    elements[index].value = Matrix(i, j);
                    ++index;
                }
            }
        }
    }

    // Destructor to free allocated memory
    ~SparseMatrix() {
        delete[] elements;
    }

    // Function to read the sparse matrix from a file
    void readSparseMatrix(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }

        for (int i = 0; i < nonZeroCount; ++i) {
            file >> elements[i].row >> elements[i].col >> elements[i].value;  // Read row, col, value
        }

        file.close();
    }

    // Function to add two sparse matrices
    SparseMatrix addSparseMatrix(const SparseMatrix& B) const {
        if (cols != B.cols) {
            cerr << "Matrices must have the same number of columns for addition!" << endl;
            exit(EXIT_FAILURE);
        }

        Matrix resultMatrix(rows, cols);

        // Insert non-zero elements from the first sparse matrix
        for (int i = 0; i < nonZeroCount; ++i) {
            resultMatrix(elements[i].row, elements[i].col) = elements[i].value;
        }

        // Insert non-zero elements from the second sparse matrix (add to existing values)
        for (int i = 0; i < B.nonZeroCount; ++i) {
            resultMatrix(B.elements[i].row, B.elements[i].col) += B.elements[i].value;
        }

        // Convert result matrix to sparse matrix and return
        return SparseMatrix(resultMatrix);
    }

    // Function to display the sparse matrix
    void display() const {
        cout << "Sparse Matrix Representation (row, col, value):" << endl;
        for (int i = 0; i < nonZeroCount; ++i) {
            cout << "(" << elements[i].row << ", " << elements[i].col << ", " << elements[i].value << ")" << endl;
        }
    }
};

int main() {
    // Read two matrices from files
    Matrix matA(3, 3);
    matA.readFromFile("matrixA.txt");

    Matrix matB(3, 3);
    matB.readFromFile("matrixB.txt");

    // Display the original matrices
    cout << "Matrix A:" << endl;
    matA.display();

    cout << "Matrix B:" << endl;
    matB.display();

    // Convert to sparse matrices
    SparseMatrix spA(matA);
    SparseMatrix spB(matB);

    // Display the sparse matrices
    cout << "\nSparse Matrix A:" << endl;
    spA.display();

    cout << "\nSparse Matrix B:" << endl;
    spB.display();

    // Add the sparse matrices and display the result
    SparseMatrix spResult = spA.addSparseMatrix(spB);

    cout << "\nResultant Sparse Matrix after Addition:" << endl;
    spResult.display();

    return 0;
}
