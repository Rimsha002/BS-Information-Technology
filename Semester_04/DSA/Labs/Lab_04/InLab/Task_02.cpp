#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
    Stack <int> stk1, stk2;
    stk1.push(10);
    stk1.push(20);
    stk1.push(30);
    stk1.pop();

    cout << "Capacity of stack 1: " << stk1.getCapacity() << endl;

    if(stk1.isEmpty())
    {
        cout << "Stack 1 is empty" << endl;
    }
    else
    {
        cout << "Stack 1 is not empty" << endl;
    }

    if(stk1.isFull())
    {
        cout << "Stack 1 is full" << endl;
    }
    else
    {
        cout << "Stack 1 is not full" << endl;
    }

    cout << "Number of elements in stack 1: " << stk1.getNoOfElements() << endl;

    cout << "Top element of stack 1: " << stk1.stackTop() << endl;

    //Assignment operator
    stk2 = stk1;

    //Copy constructor
    Stack <int> stk3(stk1);

    stk1.~Stack();


   return 0;
}