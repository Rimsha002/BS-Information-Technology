#include <iostream>
using namespace std;
class Array
{
    int size;
    int *arr;

public:
    Array(int s = 0) // Default and Parametirize
    {
        size = s;
        arr = new int[size];
    }
    // copy Constractor
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
        cout << "Enter elements of array: ";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int operator[](int index)
    {
        for (int i = 0; i < size; i++)
        {
            if (index == arr[i])
            {
                return i;
            }
        }

        try
        {
            throw("Invalid Index");
        }
        catch (char *msg)
        {
            cout << msg;
        }
        throw;
    }

    Array operator+(Array a1)
    {
        Array a2(size);
        for (int i = 0; i < size; i++)
        {
            a2.arr[i] = arr[i] + a1.arr[i];
        }

        for (int i = 0; i < size; i++)
        {
            cout << a2.arr[i] << " ";
        }
        cout << endl;
        // return a2;
    }

    Array operator-(Array a1)
    {
        Array a2(size);
        for (int i = 0; i < size; i++)
        {
            a2.arr[i] = arr[i] - a1.arr[i];
        }

        for (int i = 0; i < size; i++)
        {
            cout << a2.arr[i] << " ";
        }
        cout << endl;
        // return a2;
    }

    friend istream &operator>>(istream &i, Array a1);
    friend ostream &operator<<(ostream &o, Array a1);

    ~Array()
    {
        delete[] arr;
    }
};

istream &operator>>(istream &i, Array a1)
{
    cout << "Enter data in Array: ";
    for (int i = 0; i < a1.size; i++)
    {
        i >> a1.arr[i];
    }
};

ostream &operator<<(ostream &o, Array a1)
{
    o << "Data in Array is: ";
    for (int i = 0; i < a1.size; i++)
    {
        o << a1.arr[i] << endl;
    }
}

int main()
{
    int size;
    int index;
    int address;

    cout << "Enter size of array: ";
    cin >> size;
    Array a1(size);
    a1.inputArray();

    cout << "Enter index to which address you want? ";
    cin >> index;
    address = a1[index];
    cout << "Address of that index is: " << address;

    cout << "\n---Array 2---\n";

    Array a2(size);
    Array a3(size);
    a2.inputArray();

    cout << "Sum of two arrays is: ";
    a2 + a1;

    cout << "Subtraction of two arrays is: ";
    a2 - a1;

    // Insertion Operator
    cin >> a1;

    // Extraction Operator
    cout << a1;

    return 0;
}