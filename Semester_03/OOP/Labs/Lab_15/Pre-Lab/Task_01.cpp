#include <iostream>
#include <stdexcept>
using namespace std;

class divideByZero : public runtime_error
{
    int b;
    public:
    
    divideByZero() : runtime_error("Invalid! Divide by zero exception")
    {}
};

int main()
{

    cout << "---Task 01: Basic Exception Handling---" << endl;
    int num1, num2;
    float result;
    cout << "Enter 1st number: ";
    cin >> num1;
    cout << "Enter 2nd number: ";
    cin >> num2;

    try
    {
        if(num2 == 0)
        {
            throw divideByZero();
        }
 
    }
    catch(divideByZero &e)
    {
        while(num2 == 0)
        {
            cout << endl;
            cout << e.what() << endl;
            cout << "Enter 2nd number again: ";
            cin >> num2;
        }
    }

        result = (float)num1/num2;
        cout << "Result: " << result << endl;
 
   return 0;
}