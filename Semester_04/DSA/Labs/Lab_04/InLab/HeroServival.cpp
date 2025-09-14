#include <iostream>
#include "Stack.h"
using namespace std;

void KillWeaker(int* arr, int n)
{
    Stack <int> stk;
    stk.push(arr[0]);

    for(int i = 0; i < n-1 ; i++ )
    {
        // cout << stk.stackTop() << endl;
        if(arr [i + 1] > stk.stackTop())
        {
            stk.pop();
            // cout << "\t"<<arr[i + 1] << endl;
            stk.push(arr[i + 1]);
            // cout << stk.stackTop() << endl;
        }
    }

 cout << "Winner is: " << stk.stackTop();
}
int main()
{
    int n = 5;
    int * arr = new int[5];
    cout << "Enter " << n << " values for array: ";
    for(int i = 0; i < n ; i++ )
    {
        cin >> arr[i];
    }
    KillWeaker(arr, n);

    delete[] arr;
   return 0;
}