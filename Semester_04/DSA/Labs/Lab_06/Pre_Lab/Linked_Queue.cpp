#include <iostream>
#include "Linked_Queue.h"
using namespace std;
int main()
{
    cout << "\nWelcome to my Queue Program" << endl;

    QNode<int> *N1 = new QNode<int>(1);
    Queue<int> Q1(N1);

    cout << "Original List";
    Q1.displayQueue();

    int choice = 0;
    do
    {
        cout << "\nMenu" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Current Size" << endl;
        cout << "5. Is Empty" << endl;
        cout << "6. Display Queue" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enqueuing" << endl;
            int data;
            cout << "Enter data: ";
            cin >> data;
            Q1.enqueue(data);

            Q1.displayQueue();

            break;
        }
        case 2:
        {
            cout << "Dequeuing" << endl;
            Q1.dequeue();
            Q1.displayQueue();
            break;
        }
        case 3:
        {
            cout << "Getting front element" << endl;
            cout << "Front Element: " << Q1.FrontElement() << endl;
            break;
        }
        case 4:
        {
            cout << "Getting current size" << endl;
            cout << "Current Size: " << Q1.currSize() << endl;
            break;
        }
        case 5:
        {
            cout << "Checking if empty" << endl;
            if (Q1.isEmpty())
            {
                cout << "Queue is empty" << endl;
            }
            else
            {
                cout << "Queue is not empty" << endl;
            }
            break;
        }
        case 6:
        {
            cout << "Displaying Queue" << endl;
            Q1.displayQueue();
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

    cout << "\nByeee!" << endl;

    return 0;
}