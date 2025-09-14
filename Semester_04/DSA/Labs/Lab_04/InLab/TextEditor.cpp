#include <iostream>
#include "Stack.h"
using namespace std;

Stack<char> undo;
Stack<char> redo;

const void performAction(const char &ch)
{
    undo.push(ch);
}
void undoAction()
{
    redo.push(undo.stackTop());
    cout << undo.stackTop() << " is Undo" << endl;
    undo.pop();
}
void redoAction()
{
    undo.push(redo.stackTop());
    cout << redo.stackTop() << " is Redo" << endl;
    redo.pop();
}

int main()
{
    string str = "Maryem";
    for (int i = 0; i < str.length(); i++)
    {
        performAction(str[i]);
    }
    cout << "String is: " << str << endl;

    undoAction();
    undoAction();
    redoAction();
    redoAction();

    // cout << "New String is: " << str << endl;
    string newstr;
    // cout << undo.getNoOfElements();
    // while(!undo.isEmpty())
    for (int i = undo.getNoOfElements(); i > 0; --i)
    {
        newstr[i] = undo.stackTop();
        undo.pop();
    }

    // cout << "hhhhhh";
    for (int i = 0; i < newstr.length(); i++)
    {
        cout << "New string is: " << newstr[i];
    }
    return 0;
}