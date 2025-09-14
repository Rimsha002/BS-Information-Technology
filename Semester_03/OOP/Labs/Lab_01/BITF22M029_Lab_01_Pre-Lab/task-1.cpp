#include <iostream>
#include <string>
using namespace std;

// Task 01: First C++ Program

/*Write a C++ program which input of string from user.
 After that take a character and
 then print the index of second occurrence of that character.
 If that character does not exist or the second occurrence does not exist then print -1.
 */

int main()
{
    string str;
    char character;
    int count = 0;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Enter a character: ";
    cin >> character;

    for (int i = 0; i != str.length(); i++)
    {
        if (str[i] == character)
        {
            count++;
            if (count == 2)
            {
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << "-1" << endl;

    return 0;
}