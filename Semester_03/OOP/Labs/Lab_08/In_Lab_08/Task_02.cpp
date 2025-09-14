#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
    // Dynamic Array
    int row;
    int col;
    int **array = new int *[row];

public:
    Matrix(int row = 0, int col = 0)
    {
        this->row = row;
        this->col = col;

        for (int i = 0; i < row; ++i)
        {
            array[i] = new int[col];
        }
    }
    int input()
    {
        cout << "Enter element of array: ";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> array[i][j];
            }
        }
    }
    int display()
    {
        cout << "Array is:  " << endl;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << array[i][j] << "\t";
            }
            cout << endl;
        }
    }
    vector<int> operator()()
    {
        vector<int> v;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int element = array[i][j];
                v.push_back(element);
            }
            cout << endl;
        }
        return v;
    }
};
int main()
{
    int rows;
    int cols;
    cout << "Enter no of Rows: ";
    cin >> rows;
    cout << "Enter no of cols: ";
    cin >> cols;
    vector<int> v;

    Matrix m(rows, cols);
    m.input();
    m.display();

    v = m();

    cout << "1D Vector array is: " << endl;
    for (int j = 0; j < v.size(); j++)
    {
        cout << v[j] << " ";
    }

    return 0;
}