#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class UnsortedList
{
private:
    T* arr;
    int maxSize;
    int currSize;

public:
    UnsortedList(int size = 10); // Default and parameterized constructor
    ~UnsortedList(); // Destructor
    UnsortedList(const UnsortedList<T>&); // Copy constructor
    const UnsortedList<T>& operator=(const UnsortedList<T>&); // Assignment operator
    bool insert(const T& val); // Insert element
    bool isFull() const; // Check if list is full
    bool isEmpty() const; // Check if list is empty
    void display() const; // Display list
    bool remove(int index); // Remove element by index
};

#endif // UNSORTEDLIST_H
