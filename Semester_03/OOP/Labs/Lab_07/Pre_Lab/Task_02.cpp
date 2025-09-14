#include <iostream>
using namespace std;

class Array
{
    int *arr;
    int size;

public:
    Array(int s = 0) // Defualt + Parametrize
    {
        this->size = s;
        arr = new int[size];
    }
 
    Array(const Array &obj)
    {
        size = obj.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }
    }
    void inputArray()
    {
        cout << "Enter " << size << " elements of array: ";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }
    int operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            try
            {
                throw "Index out of range";
            }
            catch (const char *e)
            {
                cout << e << endl;
            }
            return -1;
        }
        else
        {
            return arr[index];
        }
    }

    Array operator+(Array a1)
    {
        Array a2(size);

        for (int i = 0; i < size; i++)
        {
            a2.arr[i] = arr[i] + a1.arr[i];
        }
        return a2;
    }

    Array operator-(Array a1)
    {
        Array a2(size);
        for (int i = 0; i < size; i++)
        {
            a2.arr[i] = arr[i] - a1.arr[i];
        }

        return a2;
    }
    Array &operator=(Array a1)
    {
        if (arr)
        {
            delete[] arr;
        }

        arr = new int[a1.size];
        size = a1.size;

        for (int i = 0; i < size; i++)
        {
            arr[i] = a1.arr[i];
        }

        return *this;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

       ~Array()
    {
        delete[] arr;
    }
};

int main()
{
    int size;
    int index;

    cout << "\n---Array 1---" << endl;
    cout << "Enter the size of array: ";
    cin >> size;

    Array a1(size);
    a1.inputArray();

    cout << "\nEnter index to access element: ";
    cin >> index;

    cout << "Element at index " << index << " is: " << a1[index] << endl;

    cout << "\n---Array 2---" << endl;

    Array a2(size);
    Array a3(size);

    a2.inputArray();

    a3 = a1 + a2;
    cout << "\nSum of two arrays is: ";
    a3.display();

    cout << "\nSubtraction of two arrays is: ";
    a3 = a2 - a1;
    a3.display();
    return 0;
}