#include <iostream>
#include "CSLL.h"
using namespace std;

int main()
{
    cout << "\n\tWelcome to Circular Singly Linked List" << endl;
    csNode<int> *node = new csNode<int>(0);
    CSLL<int> list(node);

    int choice = 0;

    do
    {
        cout << "\nMenu: " << endl;
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at tail" << endl;
        cout << "3. Insert at position" << endl;
        cout << "4. Delete at head" << endl;
        cout << "5. Delete at tail" << endl;
        cout << "6. Delete at position" << endl;
        cout << "7. Delete Before" << endl;
        cout << "8. Delete After" << endl;
        cout << "9. Display" << endl;
        cout << "10. Size" << endl;
        cout << "11. Is Empty" << endl;
        cout << "12. Exit" << endl;
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter data: ";
            cin >> data;
            list.insertAtHead(data);
            list.printcsList();
            break;
        case 2:
        {
            cout << "Insert at tail: " << endl;
            int data1;
            cout << "Enter data: ";
            cin >> data1;
            list.insertAtTail(data1);
            list.printcsList();
            break;
        }
        case 3:
        {
            cout << "Insert at position: " << endl;
            int data2, pos;
            cout << "Enter data: ";
            cin >> data2;
            cout << "Enter position: ";
            cin >> pos;
            list.insertAtPos(data2, pos);
            list.printcsList();
            break;
        }
        case 4:
        {
            cout << "Delete at head: " << endl;
            list.deleteAtHead();
            list.printcsList();
            break;
        }
        case 5:
        {
            cout << "Delete at tail: " << endl;
            list.deleteAtTail();
            list.printcsList();
            break;
        }
        case 6:
        {
            cout << "Delete specific node: " << endl;
            cout << "Original List: ";
            list.printcsList();
            int data;
            cout << "Enter data: ";
            cin >> data;
            csNode<int> *node = list.head;
            while (node != list.tail && node->data != data) {
                node = node->next;
            }
            if (node->data == data) {
                list.deleteNode(node);
            } else {
                cout << "Node not found." << endl;
            }
            list.printcsList();
            break;
        }
        case 7:
        {
            cout << "Delete before: " << endl;
            cout << "Original List: ";
            list.printcsList();
            int data;
            cout << "Enter data: ";
            cin >> data;
            csNode<int> *node = list.head;
            while (node != list.tail && node->data != data) {
                node = node->next;
            }
            if (node->data == data) {
                list.deleteBefore(node);
            } else {
                cout << "Node not found." << endl;
            }
            list.printcsList();
            break;
        }
        case 8:
        {
            cout << "Delete after: " << endl;
            cout << "Original List: ";
            list.printcsList();
            int data;
            cout << "Enter data: ";
            cin >> data;
            csNode<int> *node = list.head;
            while (node != list.tail && node->data != data) {
                node = node->next;
            }
            if (node->data == data) {
                list.deleteAfter(node);
            } else {
                cout << "Node not found." << endl;
            }
            list.printcsList();
            break;
        }
        case 9:
        {
            cout << "Display: " << endl;
            list.printcsList();
            break;
        }
        case 10:
        {
            cout << "Size: " << list.getSize() << endl;
            break;
        }
        case 11:
            cout << "Is Empty: " << list.isEmpty() << endl;
            break;
        case 12:
            cout << "Exiting..." << endl;
            choice = -1;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != -1);

    cout << "\nBye!" << endl;
    return 0;
}
