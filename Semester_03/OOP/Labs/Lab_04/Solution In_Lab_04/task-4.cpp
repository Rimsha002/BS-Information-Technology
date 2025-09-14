#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Equation
{
    string equation;

public:
    Equation() : equation("") {}
    void setEquation(string eq)
    {
        this->equation = eq;
    }
    bool isEquationValid()
    {
        stack<char> bracket_stack;
        for (int i = 0; i < equation.size(); i++)
        {
            if (equation[i] == ')' && bracket_stack.empty())
            {
                return false;
            }
            else if (equation[i] == ')' && !bracket_stack.empty())
            {
                bracket_stack.pop();
            }
            else if (equation[i] == '(')
            {
                bracket_stack.push(equation[i]);
            }
        }
        if (!bracket_stack.empty())
        {
            return false;
        }
        return true;
    }
    void display_equation()
    {
        cout<<"Equation "<<equation<<endl;
    }
};
int main()
{
    Equation eq;
    eq.setEquation("((a+b)+c+(d+e))");
    if(eq.isEquationValid())
    {
        cout<<"Equation is valid "<<endl; 
    }
    else{
        cout<<"Equation is not valid "<<endl;
    }
}