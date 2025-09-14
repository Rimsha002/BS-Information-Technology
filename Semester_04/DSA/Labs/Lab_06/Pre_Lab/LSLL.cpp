#include <iostream>
#include "LSLL.h"
using namespace std;
int main()
{

    cout << "\nWelcome to my Linear Linked List Program" << endl;

    Node<int> *N1 = new Node<int>(1);
    LSLL<int> L1(N1);

    cout << "Original ";
    L1.printList();

    int choice = 0;
    do
    {
        cout << "\nMenu" << endl;
        cout << "1. Insert at Head" << endl;
        cout << "2. Insert at Tail" << endl;
        cout << "3. Delete at Head" << endl;
        cout << "4. Delete at Tail" << endl;
        cout << "5. Print List" << endl;
        cout << "6. Get specific Node" << endl;
        cout << "7. Get Size" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Inserting at head" << endl;
            int data;
            cout << "Enter data: ";
            cin >> data;
            L1.insertAtHead(data);

            L1.printList();

            break;
        }
        case 2:
        {
            cout << "Inserting at tail" << endl;
            int data1;
            cout << "Enter data: ";
            cin >> data1;
            L1.insertAtTail(data1);
            L1.printList();
            break;
        }
        case 3:
        {
            cout << "Deleting at head" << endl;
            L1.deleteAtHead();
            L1.printList();
            break;
        }
        case 4:
            cout << "Deleting at tail" << endl;
            L1.deleteAtTail();
            L1.printList();
            break;
        case 5:
            cout << "Printing list" << endl;
            L1.printList();
            break;
        case 6:
        {
            cout << "Getting specific node" << endl;
            int index;
            cout << "Enter index: ";
            cin >> index;
            Node<int> *N = L1.getNode(index);
            cout << "Node at index " << index << " is: " << N->data << endl;
            break;
        }
        case 7:
        {
            cout << "Size of the list is: " << L1.getSize() << endl;
            break;
        }
        case 8:
            cout << "Exiting..." << endl;
            choice = -1;
            L1.~LSLL();
            break;
        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != -1);

    cout << "\n Goodbye!" << endl;

    return 0;
}