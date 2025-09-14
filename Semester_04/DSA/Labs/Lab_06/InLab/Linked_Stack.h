#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <iostream>
#include <exception>
using namespace std;

template <class T>
class Stack;

template <class T>
class StackNode
{
    T data;
    StackNode<T> *next;
    friend Stack<T>;

public:
    StackNode()
    {
        this->data = NULL;
        this->next = NULL;
    }
    StackNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
    StackNode(T data, StackNode<T> *next)
    {
        this->data = data;
        this->next = next;
    }

    ~StackNode()
    {
        next = nullptr;
    }
};

static int size = 0;

template <class T>
class Stack
{
    StackNode<T> *top;
    
public:
    Stack();
    Stack(StackNode<T> *N);
    Stack(const Stack<T> &);
    ~Stack();
    void push(T element);
    void pop();
    T getTop();
    int getSize();
    bool isEmpty();
    bool isFull();
    T Peek(int index);
    void printStack();
};

template <class T>
Stack<T>::Stack()
{
    top = NULL;
    size = 0;
}

template <class T>
Stack<T>::Stack(StackNode<T> *N)
{
    top = N;
    size++;
}

template <class T>
Stack<T>::Stack(const Stack<T> &S1)
{
    top = S1.top;
    size = S1.size;

    if(top == nullptr)
    {
        return;
    }

    if(S1.top->next == nullptr)
    {
        top = new StackNode<T>(S1.top->data);
        return;
    }

    StackNode<T> *temp = S1.top;
    while(temp != nullptr)
    {
        push(temp->data);
        temp = temp->next;
    }
    return;
}



template <class T>
Stack<T>::~Stack()
{
    StackNode<T> *current = top;
    StackNode<T> *nextNode = nullptr;
    while (current != nullptr)
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    top = nullptr;
    size = 0;
}

template <class T>
void Stack<T>::push(T element)
{
    StackNode<T> *temp = new StackNode<T>(element);
    if (top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
    size++;
}

template <class T>
void Stack<T>::pop()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        StackNode<T> *temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
}

template <class T>
T Stack<T>::getTop()
{
    if (top == NULL)
    {
        throw runtime_error("Stack is empty");
    }
    return top->data;
}


template <class T>
int Stack<T>::getSize()
{
    return size;
}

template <class T>
bool Stack<T>::isEmpty()
{
    if(size == 0)
    {
        return true;
    }
}

template <class T>
bool Stack<T>::isFull()
{
    try
    {
        StackNode<T>* N = new StackNode<T>(1);
        delete N; 
        return false;    
    }
    catch (bad_alloc& e)
    {
        return true;     
    }
}

template <class T>
T Stack<T>::Peek(int index)
{
    if (index >= size || index < 0)
    {
        throw out_of_range("Index out of bounds");
    }
    StackNode<T> *temp = top;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}


template <class T>
void Stack<T>::printStack()
{
    // cout << "Stack: ";
    StackNode<T> *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

#endif