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

    int *ptr = array;
    int sum = 0;
    double avg = 0;
    for(int i = 0; i < size; i++)
    {
        sum += *(ptr+i);
    }

    avg = sum/(double)size;

    cout << "Sum = " << sum << endl;
    cout << "Average = " << avg << endl;

    delete [] array;
    array = nullptr;
    return 0;
}