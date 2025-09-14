#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <iostream>
#include <exception>
using namespace std;

template <class T>
class Queue;

template <class T>
class QNode
{
    T data;
    QNode<T> *next;
    friend Queue<T>;

public:
    QNode()
    {
        this->data = NULL;
        this->next = NULL;
    }
    QNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
    QNode(T data, QNode<T> *next)
    {
        this->data = data;
        this->next = next;
    }

    ~QNode()
    {
        next = nullptr;
    }
};

template <class T>
class Queue
{
    QNode<T> *front;
    QNode<T> *rear;
    int size;

public:
    Queue();
    Queue(QNode<T> *N);
    Queue(const Queue<T> &);
    ~Queue();
    void enqueue(T element);
    void dequeue();
    T FrontElement();
    T currSize();
    bool isEmpty();
    bool isFull();
    void displayQueue();
};

template <class T>
Queue<T>::Queue()
{
    front = rear = nullptr;
    size = 0;
}

template <class T>
Queue<T>::Queue(QNode<T> *N)
{
    front = rear = N;
    size = 1;
}

template <class T>
Queue<T>::Queue(const Queue<T> &Q)
{
    front = Q.front;
    rear = Q.rear;
    size = Q.size;

    if (Q.front == nullptr)
    {
        return;
    }

    if (Q.front == Q.rear)
    {
        front = rear = new QNode<T>(Q.front->data);
        return;
    }

    else
    {
        QNode<T> *temp = Q.front;

        while (temp != nullptr)
        {
            rear->next = new QNode<T>(temp->data);
            rear = rear->next;
            temp = temp->next;
        }
    }
}

template <class T>
Queue<T>::~Queue()
{
    while (front != nullptr)
    {
        QNode<T> *temp = front;
        front = front->next;
        temp->next = nullptr;
        delete temp;
    }
    rear = nullptr;
    size = 0;
}

template <class T>
void Queue<T>::enqueue(T element)
{
    QNode<T> *temp = new QNode<T>(element);

    if (rear == nullptr)
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
    size++;
}

template <class T>
void Queue<T>::dequeue()
{
    if (front == nullptr)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        QNode<T> *temp = front;
        front = front->next;
        temp->next = nullptr;
        delete temp;
        size--;
    }
}

template <class T>
T Queue<T>::FrontElement()
{
    if (front == nullptr)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return front->data;
}

template <class T>
T Queue<T>::currSize()
{
    if(front == nullptr)
    {
        return 0;
    }
    return size;
}

template <class T>
bool Queue<T>::isEmpty()
{
    if (front == nullptr)
    {
        return true;
    }
    return false;
}

template <class T>
bool Queue<T>::isFull()
{
    return false;
}

template <class T>
void Queue<T>::displayQueue()
{
    if (front == nullptr)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        QNode<T> *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}


#endif