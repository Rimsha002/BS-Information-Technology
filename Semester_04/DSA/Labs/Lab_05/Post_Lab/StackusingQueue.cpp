#include <iostream>
#include "MyQueue.h" 

using namespace std;

class StackUsingQueues {
    MyQueue<int> q1;  
    MyQueue<int> q2; 
    int capacity;

public:
    StackUsingQueues(int cap) : q1(cap) , q2(cap){
        capacity = cap;
    }

    void push(int x) {
        q2.enqueue(x);  

        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        MyQueue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if (!q1.isEmpty()) {
            cout << "Popped: " << q1.dequeue() << endl;
        } else {
            cout << "Stack is empty!" << endl;
        }
    }

    int top() {
        if (!q1.isEmpty()) {
            return q1.getFront();
        } else {
            cout << "Stack is empty!" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return q1.isEmpty();
    }
};

int main() {
    int capacity;
    cout << "Enter capacity of the stack: ";
    cin >> capacity;

    StackUsingQueues stack(capacity);
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl;
    stack.pop();

    cout << "Top element: " << stack.top() << endl;
    stack.pop();

    stack.push(40);
    cout << "Top element: " << stack.top() << endl;

    return 0;
}
