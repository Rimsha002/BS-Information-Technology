#include <iostream>
#include <stack>
#include <vector>
#include <string>

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

// Function to check if a character is an operand
bool isOperand(char c)
{
    return isalnum(c);
}

// Function to convert infix to postfix
string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix;

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (c == ' ')
            continue;

        if (isOperand(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && precedence(c) <= precedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c); // Push the current operator to stack
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

void generateAssemblyCode(string postfix)
{
    stack<string> s;
    vector<string> assembly;
    int tempCounter = 1;

    for (char c : postfix)
    {
        if (isOperand(c))
        {
            s.push(string(1, c));
        }
        else
        {
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            string temp = "TEMP" + to_string(tempCounter++); // Unique TEMP variable

            if (c == '+')
            {
                assembly.push_back("LD AX, " + operand1);
                assembly.push_back("ADD AX, " + operand2);
                assembly.push_back("ST " + temp);
            }
            else if (c == '-')
            {
                assembly.push_back("LD AX, " + operand1);
                assembly.push_back("SUB AX, " + operand2);
                assembly.push_back("ST " + temp);
            }
            else if (c == '*')
            {
                assembly.push_back("LD AX, " + operand1);
                assembly.push_back("MUL AX, " + operand2);
                assembly.push_back("ST " + temp);
            }
            else if (c == '/')
            {
                assembly.push_back("LD AX, " + operand1);
                assembly.push_back("DIV AX, " + operand2);
                assembly.push_back("ST " + temp);
            }

            s.push(temp);
        }
    }

    // Output assembly code
    for (string line : assembly)
    {
        cout << line << endl;
    }
}

int main()
{
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix); // Use getline to handle spaces in input

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    cout << "Assembly code:" << endl;
    generateAssemblyCode(postfix);

    return 0;
}

// A + B + C *(D + E)
