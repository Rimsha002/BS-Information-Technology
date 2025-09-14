#include <iostream>
using namespace std;

void increaseMemory(int *&arr, int &size, int num)
{
    int *temp = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];
    }
    temp[size] = num;
    delete[] arr;
    arr = temp;
    size++;
}
int main()
{
    int size = 0;
    cout << "Enter size of Array: ";
    cin >> size;
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element for index " << i<<": ";
        cin >> arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element at index " << i << " is: " << arr[i] << endl;
    }
    int var=0;
    cout<<"Enter new number to insert into array: ";
    cin>>var;
    increaseMemory(arr,size,var);

    cout<<"After inserting a new Number into array"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element at index " << i << " is: " << arr[i] << endl;
    }
    return 0;
}
