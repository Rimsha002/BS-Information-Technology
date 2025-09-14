#include <iostream>
using namespace std;

void printArray(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}
int main()
{
    int *array = nullptr;
    int size = 0;
    do
    {

        cout << "Enter the size of the array: ";
        cin >> size;

        if(size <= 0)
        {
            cout << "Enter size greater then zero " << endl;
        }
    } while (size <= 0);

    array = new int[size];


    cout << "Enter " << size <<" Elements" <<endl;
    for(int i = 0; i < size; i++)
    {
        cin>> array[i];
    }
    printArray(array, size);

    delete[] array;
    array = nullptr;
    return 0;
}