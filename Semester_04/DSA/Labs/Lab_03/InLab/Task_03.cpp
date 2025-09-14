#include <iostream>
using namespace std;

class mapping
{
    int **arr;
    int rows;
    int col;

public:
    mapping()
    {
        rows = 0;
        col = 0;
        *arr = new int[rows];
        for (int i = 0; i < rows; i++)
        {
            arr[rows] = new int[rows * col];
        }
    }
    // parametrize Constructor
    mapping(int r, int c)
    {
        rows = r;
        col = c;
        *arr = new int[rows];
        for (int i = 0; i < rows; i++)
        {
            // arr[rows] = new int[rows * col];
            for (int j = 0; j < rows; j++)
            {
                arr[i][j] = rows * i + j;
            }
        }
    }

    // Copy Constructor
    mapping(const mapping &arr1)
    {
        rows = arr1.rows;
        col = arr1.col;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                // arr.rows *i + j = arr1.rows * i + j;
            }
        }
    }

    ~mapping()
    {
        delete[] arr;
        for (int i = 0; i < rows; i++)
        {
            delete[] arr[rows];
        }
    }

    int getIndexValue(int i, int j)
    {
        return arr[i][j];
    }

    void setIndexValue(int i, int j, int val)
    {
        cout << "set ";
        arr[i][j] = val;
        cout << "valuse";
    }

    void printArr(const mapping &arr)
    {
        cout << "Array is: " << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < j; j++)
            {
               cout << *(*arr + i) +j << " ";
            }
        }
    }

    void addressOfindex(int i, int j)
    {
        cout << "Address of index [" << i << "][" << j << "]" << endl;
        cout << &arr[i][j] << endl;
    }

    mapping operator+(const mapping &arr1)
    {
        mapping arr2;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr2[i][j] = rows * i + j + arr1.rows * i + j;
            }
        }
    }
    void printSubArray(int r1, int r2, int c1, int c2)
    {

            for (int j = r1; j < r2; j++)
            {
                for (int k = c1; k < c2; k++)
                {
                    arr[j][k] = 0;
                    // cout << *(*(*arr + i) + j) + k << " ";
                }
               
            }       
    }
};



int main()
{
    mapping arr = mapping(2, 2);
    arr.setIndexValue(0, 0, 2);
    arr.setIndexValue(0, 1, 4);
    arr.setIndexValue(1, 0, 6);
    arr.setIndexValue(1, 1, 8);

    arr.printArr(arr);

    return 0;
}