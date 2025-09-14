#include <iostream>
#include "MyQueue.h"
using namespace std;
int main()
{
    MyQueue<int> q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);

    q1.display();

    int noOfElements = q1.size();
    cout << "Number of elements in the queue: " << noOfElements << endl;
    int capacity = q1.getCapacity();
    cout << "Capacity of the queue: " << capacity << endl;


    cout << "Front element 1: " << q1.getFront() << endl;
    cout << "Dequeued element: " << q1.dequeue() << endl;
    cout << "Front element 2: " << q1.getFront() << endl;
    cout << "Dequeued element: " << q1.dequeue() << endl;
    cout << "Front element 3: " << q1.getFront() << endl;
    cout << "Dequeued element: " << q1.dequeue() << endl;
    cout << "Front element 4: " << q1.getFront() << endl;
    cout << "Dequeued element: " << q1.dequeue() << endl;
    cout << "Front element 5: " << q1.getFront() << endl;
    cout << "Dequeued element: " << q1.dequeue() << endl;
    cout << "Front element 6: " << q1.getFront() << endl;
    cout << "Dequeued element: " << q1.dequeue() << endl;


    //Assiging q1 to q2
    MyQueue<int> q2 = q1;
    cout << "After Assignment: " << endl;
    q2.display();

    //Copy Constructor
    MyQueue<int> q3(q1);
    cout << "After Copy Constructor: " << endl;
    q3.display();

   return 0;
}

