#include <iostream>
using namespace std;

class TwoDArray {
private:
    int* arr;
    int rows, cols;

public:
    // Constructor
    TwoDArray(int r, int c) : rows(r), cols(c) {
        arr = new int[rows * cols];
    }

    // Copy constructor
    TwoDArray(const TwoDArray &other) : rows(other.rows), cols(other.cols) {
        arr = new int[rows * cols];
        for (int i = 0; i < rows * cols; ++i) {
            arr[i] = other.arr[i];
        }
    }

    // Destructor
    ~TwoDArray() {
        delete[] arr;
    }

    // Set value at (i, j)
    void setIndexValue(int i, int j, int val) {
        arr[j * rows + i] = val;  // Column-major mapping
    }

    // Get value at (i, j)
    int getIndexValue(int i, int j) const {
        return arr[j * rows + i];
    }

    // Print array in 2D format
    void printArray() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << getIndexValue(i, j) << " ";
            }
            cout << endl;
        }
    }

    // Calculate address of (i, j) in 1D array
    int addressOfIndex(int i, int j, int startIndex = 0) const {
        return startIndex + j * rows + i;
    }

    // Overload + operator
    TwoDArray operator+(const TwoDArray &other) const {
        TwoDArray result(rows, cols);
        for (int i = 0; i < rows * cols; ++i) {
            result.arr[i] = this->arr[i] + other.arr[i];
        }
        return result;
    }

    // Print subarray from (r1, c1) to (r2, c2)
    void printSubArray(int r1, int r2, int c1, int c2) const {
        for (int i = r1; i <= r2; ++i) {
            for (int j = c1; j <= c2; ++j) {
                cout << getIndexValue(i, j) << " ";
            }
            cout << endl;
        }
    }

    // Clear rows and columns from m to n
    void clear(int m, int n) {
        for (int i = m; i <= n && i < rows; ++i) {
            for (int j = m; j <= n && j < cols; ++j) {
                setIndexValue(i, j, 0);
            }
        }
    }
};

int main() {
    TwoDArray arr(3, 3);

    // Setting values
    arr.setIndexValue(0, 0, 1);
    arr.setIndexValue(0, 1, 2);
    arr.setIndexValue(0, 2, 3);
    arr.setIndexValue(1, 0, 4);
    arr.setIndexValue(1, 1, 5);
    arr.setIndexValue(1, 2, 6);
    arr.setIndexValue(2, 0, 7);
    arr.setIndexValue(2, 1, 8);
    arr.setIndexValue(2, 2, 9);

    cout << "2D Array:\n";
    arr.printArray();

    cout << "\nSubArray (0,0) to (1,1):\n";
    arr.printSubArray(0, 1, 0, 1);

    return 0;
}
