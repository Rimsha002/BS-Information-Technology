#include <iostream>
#include <stack>
using namespace std;

// Palindrome Number or Not
bool palindrome(stack<int> &s);

int main()
{
    stack<int> s;
    string num;
    char element;

    cout << "Enter input: ";
    getline(cin, num);

    for (int i = 0; num[i] != '\0'; i++)
    {
        element = num[i];

        if (isdigit(element))
        {
            s.push(element - '0');
        }
    }

    bool result = palindrome(s);
    if(!result)
    {
        cout << "false";
    }
    else{
        cout << "true";
    }

    return 0;
}

bool palindrome(stack<int> &s)
{
    //copy of s it as next s is deleted
    stack<int> s_copy = s;

    bool check = true;

    stack<int> s2;
    //   s2 fill
    while (!s.empty())
    {
        s2.push(s.top());
        s.pop();
    }
      

    cout << "Ouput \n";

    while (!s_copy.empty() && !s2.empty())
    {
        if (s_copy.top() != s2.top())
        {
            check = false;
            break;
        }
        s2.pop();
        s_copy.pop();
    }
    return check;
}