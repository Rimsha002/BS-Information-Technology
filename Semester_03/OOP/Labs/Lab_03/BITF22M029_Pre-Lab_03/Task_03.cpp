#include <iostream>
using namespace std;
// Task # 03 : Function Overloading

int displayList();
void multiply(int, int);
void multiply(float, float);
void division(int, int);
void division(float, float);
void multiply(int, float);
void division(int, float);
void division(float, int);

int main()
{
    int choice;
    do
    {
        choice = displayList();
        cin.ignore();

        int num1, num2;
        float num3, num4;

        switch (choice)
        {
        case 1:
        {
            cout << "\n--Multiplication of two integers--\n" << endl;

            cout << "Enter 1st Integers: ";
            cin >> num1;
            cout << "Enter 2nd Integers: ";
            cin >> num2;
            multiply(num1, num2);
            break;
        }
        case 2:
        {
            cout << "\n--Multiplication of two Doubles--\n" << endl;
            cout << "Enter 1st double: ";
            cin >> num3;
            cout << "Enter 2nd double: ";
            cin >> num4;
            multiply(num3, num4);
            break;
        }
        case 3:
        {
            cout << "\n--Division of two integers--\n" << endl;
            cout << "Enter 1st Integers: ";
            cin >> num1;
            cout << "Enter 2nd Integers: ";
            cin >> num2;
            division(num1, num2);
            break;
        }
        case 4:
        {
            cout << "\n--Division of two doubles--\n" << endl;
            cout << "Enter 1st double: ";
            cin >> num3;
            cout << "Enter 2nd double: ";
            cin >> num4;
            division(num3, num4);
            break;
        }
        case 5:
        {
            cout << "\n--Multiplication of integer and Double--\n" << endl;
            cout << "Enter an integer: ";
            cin >> num1;
            cout << "Enter a double: ";
            cin >> num3;
            multiply(num1, num3);
            break;
        }
        case 6:
        {
            cout << "\n--Division of two integers--\n" << endl;
          cout << "Enter an integer: ";
            cin >> num1;
            cout << "Enter a double: ";
            cin >> num3;
           division(num1, num3);
            break;
        }
        case 7:
        {
            cout << "\n--Division of double and integer--\n" << endl;
            cout << "Enter a double: ";
            cin >> num3;
            cout << "Enter integer: ";
            cin >> num1;
            division(num3, num1);
            break;
        }
        }

    } while (choice != -1);
    return 0;
}

int displayList()
{
    int choose;
    cout << "\n\n\t----Select one of the option: ----" << endl
         << endl;

    cout << "1- Multiplication for integers " << endl;
    cout << "2- Multiplication for doubles " << endl;
    cout << "3- Division for integers " << endl;
    cout << "4- Division for doubles " << endl;
    cout << "5- Multiplication of integer and double " << endl;
    cout << "6- Division of integer to double " << endl;
    cout << "7- Division of double to integer " << endl;
    cout << "OR \n Press -1 to terminate program  ";

    while (!(cin >> choose) || (choose < 1 || choose > 7) && choose != -1)
    {
        cout << "Invalid input. Please enter a valid option: ";
        cin.clear();
        while (cin.get() != '\n')
        {
        }
    }
    return choose;
}

// Integer Multiplication
void multiply(int a, int b)
{
    int result = a * b;
    cout << "Multiply of two Integers is: " << result;
}

// Float Multiplication
void multiply(float a, float b)
{
    float result = a * b;
    cout << "Multiply of two doubles is: " << result;
}

// Integer Division
void division(int a, int b)
{
    float result = 0;

    while (b == 0)
    {
        if (b == 0)
        {
            cout << "Error! Division by 0" << endl;
        }
        cout << "Enter again: ";
        cin >> b;
    }

    if (b != 0)
    {
        result = (float)a / b;
    }

    cout << "Disivion of two Integers is: " << result;
}

// Float Division
void division(float a, float b)
{
    float result = 0;

    while (b == 0)
    {
        if (b == 0)
        {
            cout << "Error! Division by 0" << endl;
        }
        cout << "Enter again: ";
        cin >> b;
    }

    if (b != 0)
    {
        result = a / b;
    }

    cout << "Disivion of two Doubles is: " << result;
}

// Multiplication of Integer and Float
void multiply(int a, float b)
{
    float result = a * b;
    cout << "Multiply of integer and float is: " << result;
}

//Division of Integer with Float
void division(int a, float b)
{
    
    float result = 0;

    while (b == 0)
    {
        if (b == 0)
        {
            cout << "Error! Division by 0" << endl;
        }
        cout << "Enter again: ";
        cin >> b;
    }

    if (b != 0)
    {
        result = a / (float) b;
    }

    cout << "Disivion of integer with Double is: " << result;
}

//Division of Float with Integer
void division(float a, int b)
{
    float result = 0;

    while (b == 0)
    {
        if (b == 0)
        {
            cout << "Error! Division by 0" << endl;
        }
        cout << "Enter again: ";
        cin >> b;
    }

    if (b != 0)
    {
        result = (float)a / b;
    }

    cout << "Disivion of integer with Double is: " << result;
}