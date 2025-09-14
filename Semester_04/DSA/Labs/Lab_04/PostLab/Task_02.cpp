#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to check if a character is an operand (alphanumeric)
bool isOperand(char c) {
    return isalnum(c);
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // Ignore spaces in the input
        if (c == ' ') continue;

        if (isOperand(c)) {
            // Append operands directly to the result
            postfix += c;
        } else if (c == '(') {
            // Push '(' to stack
            s.push(c);
        } else if (c == ')') {
            // Pop from stack until '(' is found
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop '(' from the stack
        } else {
            // Operator encountered, pop based on precedence
            while (!s.empty() && precedence(c) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            // Push the current operator to the stack
            s.push(c);
        }
    }

    // Pop all remaining operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);  // Read the infix expression from user input

    string postfix = infixToPostfix(infix);  // Convert to postfix
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}

//A + B * (C - D) / E