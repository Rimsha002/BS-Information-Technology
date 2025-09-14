#include <iostream>
#include "CircularQueue.h"
using namespace std;
int main()
{
    CircularQueue<int> intQueue(3);
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    intQueue.display();

    cout << "Peek element  : " << intQueue.peek() << endl;
    cout << "Dequeue element: " << intQueue.dequeue();   

    intQueue.enqueue(40); 
    intQueue.display();

    CircularQueue<string> stringQueue(2);
    stringQueue.enqueue("hello");
    stringQueue.enqueue("world");

    stringQueue.display();


    cout << "Dequeue element: " <<stringQueue.dequeue(); 
    stringQueue.enqueue("again");

    stringQueue.display();

    //Assignment operator
    CircularQueue<int> intQueue1(3);
    intQueue1 = intQueue;
    cout << "\nAfter Assignment operator";
    intQueue1.display();

    //Copy constructor
    CircularQueue<int> intQueue2(intQueue);
    cout << "\nCopy constructor";
    intQueue2.display();

    return 0;
}