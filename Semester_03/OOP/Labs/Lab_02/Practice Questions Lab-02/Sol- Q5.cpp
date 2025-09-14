#include<iostream>
using namespace std;

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


     cout << "The array is: " << endl;
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;	


    bool isPal = true;

    for(int i = 0; i < size/2; i++)
    {
        if(array[i] != array[size-i-1])
        {
            isPal = false;
        }

    }

    if(isPal)
    {
        cout << "The Given array is Palindrome" << endl;
    }
    else
    {
        cout << "The Given array is not Palindrome" << endl;
    }



    delete[] array;
    array = nullptr;
    return 0;
}