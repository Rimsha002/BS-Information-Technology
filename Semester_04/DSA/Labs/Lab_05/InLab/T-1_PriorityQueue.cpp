#include <iostream>

using namespace std;
template <class T>
class PriorityQueue
{
private:
    int capacity;
    int noOfElements;
    T *queue;
    int *priorityArray;

public:
    PriorityQueue()
    {
        capacity = 5;
        queue = new T[capacity];
        priorityArray = new int[capacity];
        noOfElements = 0;
    }

    PriorityQueue(int maxSize)
    {
        capacity = maxSize;
        queue = new T[capacity];
        priorityArray = new int[capacity];
        noOfElements = 0;
    }

    ~PriorityQueue()
    {
        delete[] queue;
        delete[] priorityArray;
    }

    void enqueue(const T &data, int priority)
    {
        if (isFull())
        {
            cout << "Queue is full, cannot enqueue." << endl;
            return;
        }
        int i = noOfElements;
        for (; i >= 0; i--)
        {
            if (priorityArray[i] > priority)
            {
                queue[i + 1] = queue[i];
                priorityArray[i + 1] = priorityArray[i];
            }
            else
            {
                break;
            }
        }

        queue[i + 1] = data;
        priorityArray[i + 1] = priority;
        noOfElements++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cerr << "Queue is empty, cannot dequeue." << endl;
            return 0;
        }

        T highestPrior = queue[0];

        for (int i = 0; i < (noOfElements - 1); i++)
        {
            queue[i] = queue[i + 1];
            priorityArray[i] = priorityArray[i + 1];
        }

        noOfElements--;
        return highestPrior;
    }

    bool isEmpty() const
    {
        if (noOfElements == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull() const
    {
        if (noOfElements == capacity)
        {
            return true;
        }
        return false;
    }

    int size() const
    {
        return noOfElements;
    }

    void display()
    {
        // cout << "Display Queue: ";
        for (int i = 0; i < noOfElements; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    PriorityQueue<int> intQueue;
    intQueue.enqueue(42, 2);
    intQueue.enqueue(36, 1);
    intQueue.enqueue(17, 3);
    cout << "\nBefore dequeue: ";
    intQueue.display();
    int h = intQueue.dequeue();
    cout << "\nDequeued highest priority: " << h << endl;
    cout << "After dequeue: ";
    intQueue.display();

    PriorityQueue<string> stringQueue;
    stringQueue.enqueue("apple", 5);
    stringQueue.enqueue("banana", 3);
    stringQueue.enqueue("cherry", 7);
    cout << "Before dequeue: ";
    stringQueue.display();

    string highestPriorityStr = stringQueue.dequeue();
    cout << "\nDequeued highest priority: " << highestPriorityStr << endl;
    cout << "After dequeue: ";
    stringQueue.display();

    cout << endl;
    return 0;
}
