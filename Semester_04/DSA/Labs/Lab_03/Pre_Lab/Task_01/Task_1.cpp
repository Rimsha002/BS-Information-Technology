#include <iostream>
using namespace std; 
template <typename T>
class UnsortedList
{
private:
    T* arr;
    int maxSize;
    int currSize;

public:
    UnsortedList(int size = 10); 
    ~UnsortedList();
    UnsortedList(const UnsortedList<T>&); // Copy constructor
    const UnsortedList<T>& operator=(const UnsortedList<T>&); // Assignment operator
    bool insert(const T& val); // Insert element
    bool isFull() const; // Check if list is full
    bool isEmpty() const; // Check if list is empty
    void display() const; // Display list
    bool remove(int index); // Remove element by index

    

};
// Constructor
template <typename T>
UnsortedList<T>::UnsortedList(int size) : maxSize(size), currSize(0) 
{
    if (size <= 0) 
    {
        throw invalid_argument("Size must be positive.");
    }
    arr = new T[maxSize];
}

// Destructor
template <typename T>
UnsortedList<T>::~UnsortedList() 
{
    delete[] arr;
}

// Copy Constructor
template <typename T>
UnsortedList<T>::UnsortedList(const UnsortedList<T>& other) 
{
    maxSize = other.maxSize;
    currSize = other.currSize;
    arr = new T[maxSize];
    for (int i = 0; i < currSize; ++i) 
    {
        arr[i] = other.arr[i];
    }
}

// Assignment Operator
template <typename T>
const UnsortedList<T>& UnsortedList<T>::operator=(const UnsortedList<T>& other) 
{
    if (this != &other) 
    {
        delete[] arr;
        maxSize = other.maxSize;
        currSize = other.currSize;
        arr = new T[maxSize];
        for (int i = 0; i < currSize; ++i) 
        {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

// Insert Element
template <typename T>
bool UnsortedList<T> :: insert(const T& val) 
{
    if (isFull()) 
    {
        cerr << "Error: List is full!" << endl;
        return false;
    }
    arr[currSize++] = val;
    return true;
}

// Check if List is Full
template <typename T>
bool UnsortedList<T>::isFull() const 
{
    return currSize == maxSize;
}

// Check if List is Empty
template <typename T>
bool UnsortedList<T>::isEmpty() const 
{
    return currSize == 0;
}

// Display List
template <typename T>
void UnsortedList<T>::display() const 
{
    if (isEmpty()) 
    {
        cerr << "Error: List is empty!" << endl;
        return;
    }

    for (int i = 0; i < currSize; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Remove Element by Index
template <typename T>
bool UnsortedList<T>::remove(int index) 
{
    if (isEmpty()) 
    {
        cerr << "Error: List is empty!" << endl;
        return false;
    }
    if (index < 0 || index >= currSize) 
    {
        cerr << "Error: Invalid index!" << endl;
        return false;
    }

    for (int i = index; i < currSize - 1; ++i) 
    {
        arr[i] = arr[i + 1];
    }

    currSize--;
    return true;
}

// Explicit template instantiation
template class UnsortedList<int>;



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