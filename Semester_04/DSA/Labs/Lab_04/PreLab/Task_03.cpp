#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(const string &str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            if (s.empty())
            {
                return false;
            }
            s.pop();
        }
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string str = "((a+b)*(c-d)";
    if (isBalanced(str))
    {
        cout << "Equation is Balanced" << endl;
    }
    else
    {
        cout << "Ooo ! Equation Not Balanced" << endl;
    }
    return 0;
}