#include <iostream>
#include "Stack.h"
using namespace std;

void reverseWords(string& str) {
    Stack<char> stk;
    for (int i = 0 ; i < str.length(); i++)
     {
        char ch = str[i];
        if (ch != ' ') {
            stk.push(ch);
        } else {
            while (!stk.isEmpty()) {
                cout << stk.stackTop();
                stk.pop();
            }
            cout << " ";
        }
    }
    while (!stk.isEmpty()) {
        cout << stk.stackTop();
        stk.pop();
    }
    cout << endl;
}

int main() {
    string str = "Welcome to DSA";
    cout << "Original string: " << str << endl;
    cout << "Modified string: ";
    reverseWords(str);

    return 0;
}
