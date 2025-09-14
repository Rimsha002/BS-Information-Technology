#ifndef CIRCULARQUEUE_H
#include <iostream>
using namespace std;

template <class T>
class CircularQueue
{

private:
    int front;
    int rear;
    int capacity;
    int count;
    T *queueArray;

public:
    CircularQueue(); //space complexity O(1); time complexity O(1)
    CircularQueue(int size); //space complexity O(size); time complexity O(1)
    ~CircularQueue(); //space complexity O(1); time complexity O(1)
    CircularQueue(CircularQueue <T> &); 
    CircularQueue &operator=(CircularQueue <T> &);
    void enqueue(const T &data);
    T dequeue();
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    T peek() const;
    // void resize();
    void display() const;
};

template <class T>
CircularQueue<T>::CircularQueue()
{
    front = rear = 0;
    capacity = 0;
    count = 0;
    queueArray = nullptr;
}

template <class T>
CircularQueue<T>::CircularQueue(int size)
{
    front = rear = 0;
    count = 0;
    capacity = size;
    queueArray = new T[capacity];
}

template <class T>
CircularQueue<T>::~CircularQueue()
{
    delete[] queueArray;
}

template <class T>
CircularQueue<T>::CircularQueue(CircularQueue <T> &Q1)
//Space complexity O(size); Time complexity O(size)
{
    front = Q1.front;
    rear = Q1.rear;
    capacity = Q1.capacity;
    count = Q1.count;
    queueArray = new T[capacity];
    for (int i = 0; i < capacity; i++)
    {
        queueArray[i] = Q1.queueArray[i];
    }
}

template <class T>
CircularQueue<T> &CircularQueue<T>::operator=(CircularQueue <T> &Q1)
//Space complexity O(size); Time complexity O(size)
{
    if (this != &Q1)
    {
        delete[] queueArray;
        front = Q1.front;
        rear = Q1.rear;
        capacity = Q1.capacity;
        count = Q1.count;
        queueArray = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            queueArray[i] = Q1.queueArray[i];
        }
    }
    return *this;
}

template <class T>
void CircularQueue<T>::enqueue(const T &data)
//Space complexity O(1); Time complexity O(1)
{
    if (!isFull())
    {
        queueArray[rear] = data;
        rear = (rear + 1) % capacity;
        count++;
    }
    else
    {
        cout << "Queue is full" << endl;
    }
}

template <class T>
T CircularQueue<T>::dequeue()
//Space complexity O(1); Time complexity O(1)
{
    if (!isEmpty())
    {
        T temp = queueArray[front];
        front = (front + 1) % capacity;
        count--;
        return temp;
    }
    else
    {
        cout << "Queue is empty" << endl;
        return T();
    }
}

template <class T>
bool CircularQueue<T>::isEmpty() const
//Space complexity O(1); Time complexity O(1)
{
    if (rear == 0 && front == 0 && count == 0)
    {
        return true;
    }
    return false;
}

template <class T>
bool CircularQueue<T>::isFull() const
//Space complexity O(1); Time complexity O(1)
{
    if (count == capacity)
    {
        return true;
    }
    return false;
}

template <class T>
int CircularQueue<T>::size() const
{
    return count;
}

template <class T>
T CircularQueue<T>::peek() const
//Space complexity O(1); Time complexity O(1)
{
    if (!isEmpty())
    {
        return queueArray[front];
    }
    else
    {
        cout << "Sorry! Queue is empty. So," << endl;
        return 0;
    }
}

template <class T>
void CircularQueue<T>::display() const
//Space complexity O(1); Time complexity O(n)
{
    cout << "\nDisplay Circular Queue: ";
    if (!isEmpty())
    {
        int i = front;
        for (int k = 0; k < count; k++)
        {
            cout << queueArray[i] << " ";
            i = (i + 1) % capacity;
        }
    }
    cout << endl;
}

#endif