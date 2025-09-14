#include "UnsortedList.h"
#include <iostream>

using namespace std;

int main() 
{
    int size;
    cout << "Enter the maximum size for the unsorted list: ";
    cin >> size;

    UnsortedList<int> list(size);

    int choice, value, index;

    do 
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert element\n";
        cout << "2. Remove element by index\n";
        cout << "3. Display list\n";
        cout << "4. Check if list is full\n";
        cout << "5. Check if list is empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                if (list.insert(value)) 
                {
                    cout << "Value inserted successfully.\n";
                }
                break;

            case 2:
                cout << "Enter the index of the element to remove: ";
                cin >> index;
                if (list.remove(index)) 
                {
                    cout << "Element removed successfully.\n";
                }
                break;

            case 3:
                list.display();
                break;

            case 4:
                if (list.isFull()) 
                {
                    cout << "The list is full.\n";
                } 
                else 
                {
                    cout << "The list is not full.\n";
                }
                break;

            case 5:
                if (list.isEmpty()) 
                {
                    cout << "The list is empty.\n";
                } 
                else 
                {
                    cout << "The list is not empty.\n";
                }
                break;

            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice, try again.\n";
        }

    } while (choice != 6);

    return 0;
}
