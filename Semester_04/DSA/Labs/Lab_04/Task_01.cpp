#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to check if a character is an operand
bool isOperand(char c) {
    return isalnum(c);
}

// Function to convert infix to prefix
string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end()); // Reverse the infix expression
    stack<char> s;
    string prefix;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isOperand(c)) {
            prefix += c; // Append operands directly to the result
        } else if (c == ')') {
            s.push(c); // Push ')' to stack
        } else if (c == '(') {
            while (!s.empty() && s.top() != ')') {
                prefix += s.top();
                s.pop();
            }
            s.pop(); // Pop ')'
        } else {
            while (!s.empty() && precedence(c) <= precedence(s.top())) {
                prefix += s.top();
                s.pop();
            }
            s.push(c); // Push the current operator to stack
        }
    }

    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    reverse(prefix.begin(), prefix.end()); // Reverse the result to get the prefix
    return prefix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
