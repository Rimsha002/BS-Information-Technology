#include <iostream>
#include <stack>
#include <vector>
#include <string>

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

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isOperand(c)) {
            postfix += c; // Append operands directly to the result
        } else if (c == '(') {
            s.push(c); // Push '(' to stack
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop '('
        } else {
            while (!s.empty() && precedence(c) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c); // Push the current operator to stack
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

// Function to generate assembly code for postfix expression
void generateAssemblyCode(string postfix) {
    stack<string> s;
    vector<string> assembly;

    for (char c : postfix) {
        if (isOperand(c)) {
            s.push(string(1, c)); // Push operands as strings
        } else {
            string operand2 = s.top(); s.pop();
            string operand1 = s.top(); s.pop();
            string temp = "TEMP";

            if (c == '+') {
                assembly.push_back("LD AX " + operand1);
                assembly.push_back("ADD AX " + operand2);
                assembly.push_back("ST AX " + temp);
            } else if (c == '-') {
                assembly.push_back("LD AX " + operand1);
                assembly.push_back("SUB AX " + operand2);
                assembly.push_back("ST AX " + temp);
            } else if (c == '*') {
                assembly.push_back("LD AX " + operand1);
                assembly.push_back("MUL AX " + operand2);
                assembly.push_back("ST AX " + temp);
            } else if (c == '/') {
                assembly.push_back("LD AX " + operand1);
                assembly.push_back("DIV AX " + operand2);
                assembly.push_back("ST AX " + temp);
            }

            s.push(temp); // Push result back as TEMP
        }
    }

    // Output assembly code
    for (string line : assembly) {
        cout << line << endl;
    }
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    cout << "Assembly code:" << endl;
    generateAssemblyCode(postfix);

    return 0;
}
