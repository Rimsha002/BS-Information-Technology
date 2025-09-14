#include "UnsortedList.h"

// Constructor
template <typename T>
UnsortedList<T>::UnsortedList(int size) : maxSize(size), currSize(0) 
{
    if (size <= 0) 
    {
        throw std::invalid_argument("Size must be positive.");
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
bool UnsortedList<T>::insert(const T& val) 
{
    if (isFull()) 
    {
        std::cerr << "Error: List is full!" << std::endl;
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
        std::cerr << "Error: List is empty!" << std::endl;
        return;
    }

    for (int i = 0; i < currSize; ++i) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Remove Element by Index
template <typename T>
bool UnsortedList<T>::remove(int index) 
{
    if (isEmpty()) 
    {
        std::cerr << "Error: List is empty!" << std::endl;
        return false;
    }
    if (index < 0 || index >= currSize) 
    {
        std::cerr << "Error: Invalid index!" << std::endl;
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
