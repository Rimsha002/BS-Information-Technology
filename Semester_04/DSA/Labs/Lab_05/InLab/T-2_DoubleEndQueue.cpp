#include <iostream>
using namespace std;

template <class T>
class Deque {
private:
    int front, rear, size;
    T* arr;
    int capacity;

public:
    Deque(int capacity) {
        this->capacity = capacity;
        front = -1;
        rear = 0;
        size = 0;
        arr = new T[capacity];
    }

    ~Deque() {
        delete[] arr;
    }

    bool isFull() const {
        return (size == capacity);
    }

    bool isEmpty() const {
        return (size == 0);
    }

    void insertFront(T value) {
        if (isFull()) {
            cout << "Deque is full" << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = capacity - 1;
        } else {
            front--;
        }

        arr[front] = value;
        size++;
    }

    void insertRear(T value) {
        if (isFull()) {
            cout << "Deque is full" << endl;
            return;
        }

        if (front == -1) {
            front = rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = value;
        size++;
    }

    T removeFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1;
        }

        T value = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front++;
        }

        size--;
        return value;
    }

    T removeRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return -1;
        }

        T value = arr[rear];
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;
        } else {
            rear--;
        }

        size--;
        return value;
    }

    void display() const {
        cout << "Display Deque: ";
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    Deque<int> deque(5);
    deque.insertRear(5);
    deque.insertFront(10);
    deque.insertRear(15);
    deque.display(); 

    deque.removeFront();
    cout << "After front remove ";
    deque.display(); 

    deque.removeRear();
    cout << "After rear remove ";
    deque.display(); 

    return 0;
}
