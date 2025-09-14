#include "XOR.h"
#include <iostream>
using namespace std;

void displayMenu() {
    cout << "\n~~~~ XOR Linked List Menu ~~~\n";
    cout << "1. Insert at Head\n";
    cout << "2. Insert at Tail\n";
    cout << "3. Delete from Head\n";
    cout << "4. Delete from Tail\n";
    cout << "5. Print List\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    XORList list;
    int choice, value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
            {
                cout << "Enter value to insert at head: ";
                cin >> value;
                list.insertAtHead(value);
                break;
            }
            case 2:
            {
                cout << "Enter value to insert at tail: ";
                cin >> value;
                list.insertAtTail(value);
                break;
            }
            case 3:
            {
                cout << "Deleted from head: " << list.deleteAtHead() << endl;
                break;
            }
            case 4:
            {
                cout << "Deleted from tail: " << list.deleteAtTail() << endl;
                break;
            }
            case 5:
            {
                cout << "List contents: ";
                list.printList();
                break;
            }
            case 6:
            {
                cout << "\tGoodbye!\n";
                choice = -1;
                break;
            }
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != -1);

    return 0;
}
