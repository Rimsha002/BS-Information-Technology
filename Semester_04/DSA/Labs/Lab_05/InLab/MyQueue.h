#ifndef MYQUEUE_H
#include <iostream>
using namespace std;

template <typename T>
class MyQueue
{
    int rear;
    int front;
    int queueCapacity;
    int numberOfElements;
    T *queueData;
    void resize();

public:
    MyQueue();
    MyQueue(int);
    ~MyQueue();
    MyQueue(const MyQueue<T> &);
    MyQueue<T> &operator=(const MyQueue<T> &);
    void enqueue(const T element);
    T dequeue();
    T getFront() const;
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    int getCapacity() const;
    void display() const;
};

template <class T>
MyQueue<T>::MyQueue() // Space complexity O(1); Time complexity O(1)
{
    rear = front = 0;
    numberOfElements = queueCapacity = 0;
    queueData = nullptr;
}

template <class T>
MyQueue<T>::MyQueue(int size) // Space complexity O(size); Time complexity O(1)
{
    rear = front = 0;
    numberOfElements = 0;
    queueCapacity = size;
    queueData = new T[size];
}

template <class T>
MyQueue<T>::~MyQueue() // Space complexity O(1); Time complexity O(1)
{
    delete[] queueData;
}

template <class T>
MyQueue<T>::MyQueue(const MyQueue<T> &Q1)
// Space complexity O(size); Time complexity O(size)
{
    rear = Q1.rear;
    front = Q1.front;
    numberOfElements = Q1.numberOfElements;
    queueCapacity = Q1.queueCapacity;
    queueData = new T[queueCapacity];
    for (int i = 0; i < queueCapacity; i++)
    {
        queueData[i] = Q1.queueData[i];
    }
}

template <class T>
MyQueue<T> &MyQueue<T>::operator=(const MyQueue<T> &Q1)
// Space complexity O(size); Time complexity O(size)
{
    if (this != &Q1)
    {
        delete[] queueData;
        rear = Q1.rear;
        front = Q1.front;
        numberOfElements = Q1.numberOfElements;
        queueCapacity = Q1.queueCapacity;
        queueData = new T[queueCapacity];
        for (int i = 0; i < queueCapacity; i++)
        {
            queueData[i] = Q1.queueData[i];
        }
    }
    return *this;
}

template <class T>
void MyQueue<T>::enqueue(const T element)
// Space complexity O(1); Time complexity O(1)
{
    if (!isFull()){
        queueData[rear] = element;
        rear = rear + 1;
        numberOfElements++;
    }
    else
    {
        cout << "Queue is full, resizing..." << endl;
        resize();
        queueData[rear] = element;
        rear = rear + 1;
        numberOfElements++;
    }
}

template <class T>
T MyQueue<T>::dequeue()
// Space complexity O(1); Time complexity O(1)
{
    if (!isEmpty() && front < rear)
    {
        T temp = queueData[front];
        front = front + 1;
        numberOfElements--;

        if (numberOfElements == 0)
        {
            front = rear = 0;
        }

        return temp;
    }
    else
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
}

template <class T>
T MyQueue<T>::getFront() const
// Space complexity O(1); Time complexity O(1)
{
    if (!isEmpty() && front < rear)
    {
        return queueData[front];
    }
    else
    {
        cout << "\nQueue is empty, So" << endl;
        return 0;
    }
}

template <class T>
bool MyQueue<T>::isEmpty() const
// Space complexity O(1); Time complexity O(1)
{
    if (rear == 0 && front == 0 && numberOfElements == 0)
    {
        return true;
    }
    return false;
}

template <class T>
bool MyQueue<T>::isFull() const // Space complexity O(1); Time complexity O(1)
{
    if (numberOfElements == queueCapacity && rear == queueCapacity && front == 0)
    {
        return true;
    }
    return false;
}

template <class T>
int MyQueue<T>::size() const // Space complexity O(1); Time complexity O(1)
{
    return numberOfElements;
}

template <class T>
int MyQueue<T>::getCapacity() const
{
    return queueCapacity;
}

template <class T>
void MyQueue<T>::resize() // Space complexity O(size); Time complexity O(size)
{
    if (rear == queueCapacity)
    {
        T *temp = new T[2 * queueCapacity];
        for (int i = 0; i < queueCapacity; i++)
        {
            temp[i] = queueData[i];
        }
        delete[] queueData;
        queueData = temp;
        queueCapacity = 2 * queueCapacity;
    }

    cout << "Queue resized successfully!" << endl;
}

template <class T>
void MyQueue<T>::display() const // Space complexity O(1); Time complexity O(n)
{
    for (int i = front; i < rear; i++)
    {
        cout << queueData[i] << " ";
    }
    cout << endl;
}
#endif