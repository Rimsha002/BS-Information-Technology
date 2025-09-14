#include <iostream>
using namespace std;

/*
Task no 02
Mr Butcher is an old man now about 80 years old. He owns a shop where he regularly needs
to add and subtract different kind of amounts for the shop daily affairs. But Mr Butcher has a very old computer system
and with very limited storage. Request from the Old man:
He cant afford different functions for different data types.
 Also some times he has two sum and subtract two values and
 sometimes
three values.
Handle this functionality as well for him.*/

template <typename T>

class Shop
{
private:
    T num1;
    T num2;
    T num3;
    T result;

public:
    Shop()
    {
        num1 = 0;
        num2 = 0;
        num3 = 0;
        result = 0;
    }

    void add()
    {
        int choice;
        cout << "How many your values are? " << endl;
        cout << "1 - Two" << endl;
        cout << "2 - Three" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter values of both: ";
            cin >> num1 >> num2;
            result = num1 + num2;
            break;
        }
        case 2:
        {
            cout << "Enter all values: ";
             cin >> num1 >> num2 >> num3;
            result = num1 + num2 + num3;
            break;
        }
        }
    }
        void subtraction()
        {
            int choice2;
            cout << "How many your values are for subtraction? " << endl;
            cout << "1 - Two" << endl;
            cout << "2 - Three" << endl;
            cin >> choice2;

            switch (choice2)
            {
            case 1:
            {
                cout << "Enter values of both: ";
                cin >> num1 >> num2;
                if (num1 < num2)
                {
                    result = num2 - num1;
                }
                 else{ result = (num1 - num2);}
                break;
            }
            case 2:
            {
                cout << "Enter all 3 values: ";
                 cin >> num1 >> num2 >> num3;
                result = num1 - num2 - num3;
                break;
            }
            }
        }
        int getter()
            {
                return result;
            }
    };


    int main()
    {
        cout << "---Welcome to Mr Butcher Shop---- " << endl;
        int choice;

        Shop <int> shopObject;

        cout << "What you want to do? " << endl;
        cout << "1- Add" << endl;
        cout << "2- Substract" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            shopObject.add();
           break;
        }
        case 2: 
        {
            shopObject.subtraction();
            break;
        }
        }
         int result = shopObject.getter();
         cout << "Your Result is : " << result;
    }
