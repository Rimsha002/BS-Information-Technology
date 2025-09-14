#include <iostream>
#include "DLL.h"
using namespace std;

int main()
{

    cout << "Welcome to Doubly Linked List Program\n";

    int choice = 0;

    DSLL<int> ll;

    do
    {
        cout << "\nMenu: " << endl;
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert After\n";
        cout << "4. Insert Before\n";
        cout << "5. Delete at Head\n";
        cout << "6. Delete at Tail\n";
        cout << "7. Delete Node\n";
        cout << "8. Delete After\n";
        cout << "9. Delete Before\n";
        cout << "10. Get Node\n";
        cout << "11. Get Size\n";
        cout << "12. Search\n";
        cout << "13. Print\n";
        cout << "14. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Insert at Head: \n";
            int val;
            cout << "Enter value: ";
            cin >> val;
            ll.insertAtHead(val);
            break;
        }
        case 2:
        {
            cout << "Insert at Tail: \n";
            int val;
            cout << "Enter value: ";
            cin >> val;
            ll.insertAtTail(val);
            break;
        }
        case 3:
        {
            cout << "Insert After: \n";
            int val;
            cout << "Enter value: ";
            cin >> val;
            int index;
            cout << "Enter index: ";
            cin >> index;
            ll.insertAfter(index, val);
            break;
        }
        case 4:
        {
            cout << "Insert Before: \n";
            int val;
            cout << "Enter value: ";
            cin >> val;
            int index;
            cout << "Enter index: ";
            cin >> index;
            ll.insertBefore(index, val);
            break;
        }
        case 5:
        {
            cout << "Delete at Head: \n";
            ll.deleteAtHead();
            break;
        }
        case 6:
        {
            cout << "Delete at Tail: \n";
            ll.deleteAtTail();
            break;
        }
        case 7:
        {
            cout << "Delete Node: \n";
            int index;
            cout << "Enter index: ";
            cin >> index;
            dNode<int> *node = ll.getNode(index);
            ll.deleteNode(node);
            break;
        }
        case 8:
        {
            cout << "Delete After: \n";
            int val;
            cout << "Enter value: ";
            cin >> val;
            ll.deleteAfter(val);
            break;
        }
        case 9:
        {
            cout << "Delete Before: \n";
            int val;
            cout << "Enter value: ";
            cin >> val;
            ll.deleteBefore(val);
            break;
        }
        case 10:
        {
            cout << "Get Node: \n";
            int index;
            cout << "Enter index: ";
            cin >> index;
            dNode<int> *node = ll.getNode(index);
            cout << "Node: " << node->getData() << endl;
            break;
        }
        case 11:
        {
            cout << "Size: " << ll.getSize() << endl;
            break;
        }
        case 12:
        {
            cout << "Search: \n";
            int val;
            cout << "Enter value: ";
            cin >> val;
            dNode<int> *node = ll.search(val);
            if (node)
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;
        }
        case 13:
        {
            cout << "Print: \n";
            ll.printDSLL();
            break;
        }
        case 14:
        {
            cout << "Exiting Program\n";
            choice = -1;
            break;
        }
        default:
        {
            cout << "Invalid Choice\n";
            break;
        }
        }
    } while (choice != -1);
    return 0;
}