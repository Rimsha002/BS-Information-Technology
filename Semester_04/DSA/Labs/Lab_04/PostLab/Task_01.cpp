#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// Function to check precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to check if a character is an operand (alphanumeric)
bool isOperand(char c)
{
    return isalnum(c);
}

// Function to convert infix to prefix
string infixToPrefix(string infix)
{

    reverse(infix.begin(), infix.end());

    stack<char> s;
    string prefix;

    // Iterate over the reversed infix expression
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        // Ignore spaces in the input
        if (c == ' ')
            continue;

        if (isOperand(c))
        {
            prefix += c;
        }
        else if (c == ')')
        {
            s.push(c);
        }
        else if (c == '(')
        {
            while (!s.empty() && s.top() != ')')
            {
                prefix += s.top();
                s.pop();
            }
            s.pop(); 
        }
        else
        {
            // Operator encountered, pop based on precedence
            while (!s.empty() && precedence(c) <= precedence(s.top()))
            {
                prefix += s.top();
                s.pop();
            }
            s.push(c); 
        }
    }

    // Pop all remaining operators from the stack
    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);

    string prefix = infixToPrefix(infix); 
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}

// A + B * (C - D)