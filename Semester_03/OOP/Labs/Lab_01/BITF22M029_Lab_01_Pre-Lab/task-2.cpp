#include <iostream>
using namespace std;

/*Task 02: Middle Number

Write a C++ program which:
 Declares three integers
 Read the integers from the user
 Displays the integer which is neither the smallest nor the largest among the three */

int main()
{
    int a, b, c;
    int temp = 0;
    cout << "Enter three integers: ";
    cin >> a >> b >> c;

    if ((a < b && b < c) || (c < b && b < a))
    {
        temp = b;
    }
    else if ((a < c && c < b) || (b < c && c < a))
    {
        temp = c;
    }
    else if ((b < a && a < c) || (c < a && a < b))
    {
        temp = a;
    }
    else
    {
        cout << "All numbers are equal";
    }

    if (temp != 0)
    {
        cout << "Middle number is: " << temp;
    }

    return 0;
}