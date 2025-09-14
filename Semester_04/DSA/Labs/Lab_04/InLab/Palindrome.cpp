#include <iostream>
#include <string.h>
#include "Stack.h"
using namespace std;

bool isPalindrome(const string &str)
{
    Stack<char> stk;
    string str1;

    for (int i = 0; i < str.length(); i++)
    {
        stk.push(str[i]);
        // cout << stk.stackTop() << " ";

    }
    // while (!stk.isEmpty())
    // {
        for (int i = 0; i < str.length(); i++)
        {
            // cout << stk.stackTop();
            str1[i] = stk.stackTop();
            // cout << str1[i] << " ";
            stk.pop();
        }

    // }
    if(str == str1)
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    string str = "racec";
  
    if(isPalindrome(str))
    {
        cout << str << " is Palindrome. " << endl;
    }
    else{
         cout << str << " not a Palindrome. " << endl;
    }
    return 0;
}