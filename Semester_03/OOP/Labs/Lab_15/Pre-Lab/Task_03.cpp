#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

int inputArray(int *arr, int size);
void addArray(int *arr, int size);
void updateArray(int *arr, int size);
void deleteElement(int *arr, int size);

int main()
{
    cout << "Task_03: Array Exception" << endl;
    int size;
    int inputSize = 0;

    cout << "Enter the allocation size for array: ";
    cin >> size;

    int *arr = new int[size];
    // cout << "Empty or initialized array is: " ;
    // for(int i = 0; i < size; i++)
    // {
    //     arr[i] = 0;
    //     cout << arr[i] << " " ;
    // }
    // cout << endl;

    int option = 0;

    do
    {
        cout << "\nSelect the option or -1 to exist: " << endl;
        cout << "1. Input Array" << endl;
        cout << "2. Insert New Element" << endl;
        cout << "3. Update Elements" << endl;
        cout << "4. Delete Elements" << endl;
        cout << "5. Display Array" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter the option: ";

        cin >> option;

        while (option < 1 || option > 5)
        {
            cout << "Invalid option! Please select the correct option: ";
            cin >> option;
        }

        switch (option)
        {
        case 1:
        {
            cout << "---Input Elements---" << endl;
            try
            {
                inputSize = inputArray(arr, size);
            }
            catch (const overflow_error &e)
            {
                cout << endl;
                cout << e.what() << endl;
            }
            break;
        }
        case 2:
        {
            cout << "---Insertion---" << endl;
            try
            {
                addArray(arr, inputSize);
            }
            catch (const out_of_range &e)
            {
                cout << endl;
                cout << e.what() << endl;
            }
            break;
        }
        case 3:
        {
            cout << "---Update Elements---" << endl;
            try
            {
                updateArray(arr, inputSize);
            }
            catch (const out_of_range &e)
            {
                cout << endl;
                cout << e.what() << endl;
            }
            break;
        }
        case 4:
        {
            cout << "---Delete Elements---" << endl;
            try
            {
                deleteElement(arr, inputSize);
            }
            catch (const out_of_range &e)
            {
                cout << endl;
                cout << e.what() << endl;
            }
            catch (const underflow_error &e)
            {
                cout << endl;
                cout << e.what() << endl;
            }
            break;
        }
        case 5:
        {
            cout << "---Display Array---" << endl;
            if(inputSize == 0)
            {
                cout << "Array is empty" << endl;
                break;
            }
            for (int i = 0; i < inputSize; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        case 6:
        {
            exit(0);
            option = -1;
            break;
        }
        default:
            cout << "Invalid option! Please select the correct option: ";
            break;
        }

    } while (option != -1);

    return 0;
}

// Input Array
int inputArray(int *arr, int size)
{
    int s;

    cout << "How many values want to entered in array?" << endl;
    cin >> s;

    for (int i = 0; i < s; i++)
    {
        cout << "Enter element: ";
        cin >> arr[i];
    }

    if (s > size)
    {
        throw overflow_error("Overflow! size \n(Entered values more than Allocated size)");
    }
     return s;
}

// Insertion
void addArray(int *arr, int s)
{
    cout << "Enter the element you want to insert: ";
    int element;
    cin >> element;

    int index;

    cout << "Enter the index for insertion: ";
    cin >> index;

    if (index < 0 || index > (s - 1))
    {
        throw out_of_range("Index out of range");
    }
    else
    {
        for (int i = (s - 1); i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        // s++;
    }
    cout << "Array after insertion: ";
    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Update Elements
void updateArray(int *arr, int size)
{
    cout << "Enter the index you want to update: ";
    int index;
    cin >> index;

    if (index < 0 || index > (size - 1))
    {
        throw out_of_range("Index out of range");
    }
    else
    {
        cout << "Enter the new value: ";
        cin >> arr[index];
    }
    cout << "Array after update: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Delete Elements
void deleteElement(int *arr, int size)
{
    cout << "Enter the index you want to delete: ";
    int index;
    cin >> index;

    if (index < 0 || index > (size - 1))
    {
        throw out_of_range("Index out of range");
    }
    else
    {
        if (arr[index] == -1)
        {
            throw underflow_error("Element already deleted");
        }
        if (arr[index] != -1)
        {
            arr[index] = -1;
        }
    }
    cout << "\nElement deleted successfully" << endl;


    cout << "Array after deletion: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}