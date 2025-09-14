#include <iostream>
#include <exception>
using namespace std;

template <class T>
class Stack
{
private:
    int *data;
    int capacity;
    int top;
    void resize(int);

public:
    Stack();
    Stack(const Stack<T> &);
    ~Stack();
    Stack &operator=(const Stack<T> &);
    void push(const T &);
    T pop();
    T stackTop();
    bool isEmpty() const;
    bool isFull() const;
    int getCapacity() const;
    int getNoOfElements() const;
};

template <class T>
Stack<T>::Stack()
{
    capacity = 1;
    data = new T[capacity];
    top = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T> &stk1)
{
    capacity = stk1.capacity;
    top = stk1.top;
    data = new T[capacity];
    for (int i = 0; i < top; i++)
    {
        data[i] = stk1.data[i];
    }
}

template <class T>
Stack<T>::~Stack()
{
    delete[] data;
}

template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &stk1)
{

    delete[] data;
    capacity = stk1.capacity;
    top = stk1.top;
    data = new T[capacity];
    for (int i = 0; i < top; i++)
    {
        data[i] = stk1.data[i];
    }
    return *this;
}

template <class T> 
void Stack <T> :: push(const T &x)
{
    if(isFull())
    {
        resize(2*capacity);
    }
    data[top] = x;
    top++;
}

template <class T>
T Stack<T>::pop()
{
    if(isEmpty())
    {
        // cout << "Stack is empty" << endl;
        cerr << "Stack is empty" << endl;
        return -1;
    }
    top--;
    return data[top];
}

template <class T>
T Stack<T>::stackTop()
{
    if(isEmpty())
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return data[top-1];
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return top == 0;
}

template <class T>
bool Stack<T>::isFull() const
{
    return top == capacity;
}

template <class T>
int Stack<T>::getCapacity() const
{
    return capacity;
}

template <class T>
int Stack<T>::getNoOfElements() const
{
    return top;
}

template <class T>
void Stack<T>::resize(int newCapacity)
{
    T *newData = new T[newCapacity];
    for (int i = 0; i < top; i++)
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}


