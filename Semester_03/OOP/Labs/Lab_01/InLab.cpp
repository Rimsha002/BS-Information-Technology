#include <iostream>
using namespace std;

int findCount();
int inputArray1(int arr1[], int size1);
int inputArray2(int arr2[], int size2);
int unionArray(int arr1[], int arr2[], int size1, int size2);

int main()
{
    
    // int result = findCount();
    // cout << "Count: " << result;

    // Task no 02

    int array1[5];
    int array2[5];

    inputArray1(array1, 5);
    inputArray2(array2, 5);
    unionArray(array1, array2, 5, 5);
}

// Task no 01
int findCount()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    int count = 0;
    for (int i = 1; i <= str.length(); i++)
    {

        int temp = str[0] - str[i];

        if (temp == 0)
        {
            break;
        }
        count++;
    }

    return count;
}

// Task no 02
int inputArray1(int arr1[], int size1)
{
    cout << "Input data for array 1: ";
    for (int i = 0; i < size1; i++)
    {
        cin >> arr1[i];
    }

    return 0;
}
int inputArray2(int arr2[], int size2)
{
    cout << "Input data for array 2: ";
    for (int i = 0; i < size2; i++)
    {
        cin >> arr2[i];
    }

    return 0;
}

int unionArray(int arr1[], int arr2[], int size1, int size2)
{
    int arr3[size1];

    for (int i = 0; i < size1 ; i++)
    {
        arr3[i] = arr1[i];
        cout << arr3[i] << " "; 

    }
    
   
    for (int i = 0; i < size1; i++)
    {
        // cout << i << endl;
        for (int j = 0; j < size2; j++)
        {
            if (arr3[i] != arr2[j])
            {
             cout << arr2[i] << " ";  
            }

        }
        cout << endl;
       
    }


}