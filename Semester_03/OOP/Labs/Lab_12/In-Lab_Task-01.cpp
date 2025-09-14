#include <iostream>
using namespace std;

class Operator
{
public:
    Operator(){};
    virtual void calculate() = 0;
    virtual ~Operator(){};
};

// Addition
class Addition : public Operator
{
protected:
    int a, b;
    int result;

public:
    Addition() : Operator(){};
    Addition(int x, int y) : Operator()
    {
        a = x;
        b = y;
    };
    void calculate()
    {
        result = a + b;
        cout << "Addition: " << result << endl;
    }
    ~Addition(){};
};

// Subtraction
class Subtraction : public Operator
{
protected:
    int a, b;
    int result;

public:
    Subtraction() : Operator(){};
    Subtraction(int x, int y) : Operator()
    {
        a = x;
        b = y;
    };
    void calculate()
    {
        result = a - b;
        cout << "Subtraction: " << result << endl;
    }
    ~Subtraction(){};
};

// Multiplication
class Multiplication : public Operator
{
protected:
    int a, b;
    int result;

public:
    Multiplication() : Operator(){};
    Multiplication(int x, int y) : Operator()
    {
        a = x;
        b = y;
    };
    void calculate()
    {
        result = a * b;
        cout << "Multiplication: " << result << endl;
    }
    ~Multiplication(){};
};

// Division
class Division : public Operator
{
protected:
    int a, b;
    float result;

public:
    Division() : Operator(){};
    Division(int x, int y) : Operator()
    {
        a = x;
        b = y;
    };
    void calculate()
    {
        int min;
        int max;

        if (a < b)
        {
            min = a;
            max = b;
        }
        else
        {
            min = b;
            max = a;
        }

        if (min <= 0)
        {
            cout << "Division by zero or -ve is not possible." << endl;
            while (min <= 0)
            {
                cout << "Enter a non-zero value for 2nd num: ";
                cin >> min;
            }
        }
        else
        {
            result = float(max)/ min;
            cout << "Division: " << result << endl;
        }
    }
    ~Division(){};
};

int main()
{
    // Menu based calculator
    Operator *opera;

    int choice;
    cout << "---Welcome to My Calculator----" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "Enter your choice or -1 to quite: ";
    cin >> choice;

    while (choice != -1)
    {
        int a, b;

        switch (choice)
        {
        case 1:
            cout << "Enter 1st numbers: ";
            cin >> a;
            cout << "Enter 2nd numbers: ";
            cin >> b;
            opera = new Addition(a, b);
            opera->calculate();
            delete opera;
            break;
        case 2:
            cout << "Enter 1st numbers: ";
            cin >> a;
            cout << "Enter 2nd numbers: ";
            cin >> b;
            opera = new Subtraction(a, b);
            opera->calculate();
            delete opera;
            break;
        case 3:
            cout << "Enter 1st numbers: ";
            cin >> a;
            cout << "Enter 2nd numbers: ";
            cin >> b;
            opera = new Multiplication(a, b);
            opera->calculate();
            delete opera;
            break;
        case 4:
            cout << "Enter 1st numbers: ";
            cin >> a;
            cout << "Enter 2nd numbers: ";
            cin >> b;
            opera = new Division(a, b);
            opera->calculate();
            delete opera;
            break;
        default:
            cout << "Invalid choice." << endl;
        }

        cout << "Enter your choice or -1 to quite: ";
        cin >> choice;
    }

    cout << "\t----GoodBye----\t" << endl << endl;
    return 0;
}
