#include <iostream>
#include "CSLL.h"
using namespace std;

int main() {
    CSLL<int> list;
    int choice, value, pos;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete Head\n";
        cout << "5. Delete Tail\n";
        cout << "6. Delete Node\n";
        cout << "7. Delete Before Node\n";
        cout << "8. Delete After Node\n";
        cout << "9. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                list.insertAtHead(value);
                cout << "Inserted " << value << " at the head.\n";
                break;
            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                list.insertAtTail(value);
                cout << "Inserted " << value << " at the tail.\n";
                break;
            case 3:
                cout << "Enter value and position to insert: ";
                cin >> value >> pos;
                list.insertAtPos(value, pos);
                cout << "Inserted " << value << " at position " << pos << ".\n";
                break;
            case 4:
                list.deleteAtHead();
                cout << "Deleted head node.\n";
                break;
            case 5:
                list.deleteAtTail();
                cout << "Deleted tail node.\n";
                break;
            case 6:
                cout << "Enter position of node to delete: ";
                cin >> pos;
                list.deleteNode(list.getNode(pos));
                cout << "Deleted node at position " << pos << ".\n";
                break;
            case 7:
                cout << "Enter position of node to delete before: ";
                cin >> pos;
                list.deleteBefore(list.getNode(pos));
                cout << "Deleted node before position " << pos << ".\n";
                break;
            case 8:
                cout << "Enter position of node to delete after: ";
                cin >> pos;
                list.deleteAfter(list.getNode(pos));
                cout << "Deleted node after position " << pos << ".\n";
                break;
            case 9:
                cout << "Current List: ";
                list.printcsList();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
