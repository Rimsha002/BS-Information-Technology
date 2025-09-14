#include <iostream>
#include <string>
using namespace std;


void increaseMemory(int * arr , int size, int num);
// void increaseMemory(int * & arr , int & size, int num);

int main()
{

    // // Q no 01
    // string fristName;
    // string lastName;
    // string all = "My Name is ";

    // cout << "Enter your first name: ";
    // getline(cin, fristName);

    // cout << "Enter your last name: ";
    // getline(cin, lastName);

    // all = all + fristName + " " + lastName;

    // cout << all << endl;

    // for (int i = 0; i < all.length(); i++)
    // {
    //     cout << all[i];
    //     cout << endl;
    // }

    // int index;
    // string fullName = fristName + " " + lastName;

    // index = fullName.find(' ');        //keywords= find front , back, pop-back
    // string result = fullName.substr(index, fullName.size());

    // cout << result << endl;

    //    int value = 5;
    //    int * ptr = &value;
    //    *ptr += 20;
    //     cout << * ptr << endl;

    //     //Double Pointer
    //     int ** ptr2 = &ptr;
    //     cout << ptr2 << endl; //Value in Double pointer
    //     cout << ** ptr2 << endl;

    // int size = 5;
    // int array[size] = {1, 2, 3, 4, 5};

    // int *ptrArray = &array[1];

    // for (int i = 0; i < 4; i++)
    // {
    //     cout << array[i] << endl;
    //     cout << ptrArray[i] << endl;
    //     cout << *(ptrArray + i) << endl;
    // }

    // int *startPtr = &array[0];
    // int *endPtr = &array[size - 1];

    // for (int i = size - 1; i >= 0; i--)
    // {
    // cout << array[i] << endl;
    // }

    // Dynamic Memory Allocation
    int size;
    cout << " Enter size of array : ";
    cin >> size;

    int *array = new int [size];

    cout << "Enter " << size << " elements of array";
    for(int i = 0 ; i < size ; i++)
    {
        cin >> array[i];
    }
    increaseMemory(array, size, 6);

    for(int i = 0 ; i < size ; i++)
    {
        cout << array[i] << endl;;
    }
}

void increaseMemory(int * arr , int size, int num)
{
    int newSize =  size + 1;
    int * temp = new int [newSize];

    for(int i = 0 ; i < size ; i++)
    {
        temp [i] = arr [i];
    }

     delete[] arr;
     temp[size] = num; /// note size not size -1
    
    arr = temp;     //as previous arr delet so again arra point same on temp

}