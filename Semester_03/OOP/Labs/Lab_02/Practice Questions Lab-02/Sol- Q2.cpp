#include<iostream>
using namespace std;


void printArray(int array[], int size)
{
    for(int i=0;i<size;i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
int main()
{
    int *array;
    int size = 0;
    cout << "Enter the size of the array : ";
    cin >> size;
    array = new int[size];
    
    cout << "Enter " << size << " Elements " << endl;

    for(int i = 0; i < size; i++)
    {
        cin>>array[i];
    }

    cout << "Original Array" << endl;
    printArray(array, size);
    cout << endl;

    // reversing the array using the pointer
    int *ptr = array;
    for(int i = 0; i < size/2; i++)
    {
        int temp = ptr[i];
        ptr[i] = ptr[size-1-i];
        ptr[size-1-i] = temp;

    }   

    cout << "Reversed Array" << endl;
    printArray(array, size);
    cout << endl;




    delete[] array;
    array = nullptr;
    return 0;
}