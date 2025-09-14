#include <iostream>
#include "Linked_Stack.h"
using namespace std;
int main()
{
    cout << "\nWelcome to my Stack Program" << endl;

    StackNode<int> *N1 = new StackNode<int>(1);
    Stack<int> S1(N1);

    cout << "Original ";
    S1.printStack();

    int choice = 0;
    do
    {
        cout << "\nMenu" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Get Top" << endl;
        cout << "4. Get Size" << endl;
        cout << "5. Peek" << endl;
        cout << "6. Print Stack" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Pushing" << endl;
            int data;
            cout << "Enter data: ";
            cin >> data;
            S1.push(data);

            S1.printStack();

            break;
        }
        case 2:
        {
            cout << "Popping" << endl;
            S1.pop();
            S1.printStack();
            break;
        }
        case 3:
        {
            cout << "Getting top" << endl;
            cout << "Top: " << S1.getTop() << endl;
            break;
        }
        case 4:
        {
            cout << "Getting size" << endl;
            cout << "Size: " << S1.getSize() << endl;
            break;
        }
        case 5:
        {
            cout << "Peeking" << endl;
            int index;
            cout << "Enter index: ";
            cin >> index;
            try
            {

                cout << "Element at index " << index << " is " << S1.Peek(index) << endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << '\n';
            }

            break;
        }
        case 6:
        {
            cout << "Printing Stack" << endl;
            S1.printStack();
            break;
        }
        case 7:
        {
            cout << "Exiting" << endl;
            choice = -1;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    } while (choice != -1);

    cout << "\t Goodbye!" << endl;
    return 0;
}