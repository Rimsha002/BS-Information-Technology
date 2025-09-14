#include <iostream>
using namespace std;

template<typename T>
class DNode {
public:
    T data;
    DNode* next;
    DNode* prev;
    DNode(T val) : data(val), next(nullptr), prev(nullptr) {}
};

template<typename T>
class DoublyLinkedList {
private:
    DNode<T>* head;
    DNode<T>* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}
    
    // Task 1.1: Get Nth Node
    DNode<T>* getNode(int n) {
        DNode<T>* current = head;
        int count = 0;
        while (current && count < n) {
            current = current->next;
            count++;
        }
        return current ? current : tail;
    }

    // Task 1.2: Insert After
    bool insertAfter(T value, T key) {
        DNode<T>* current = head;
        while (current && current->data != key) {
            current = current->next;
        }
        if (current) {
            DNode<T>* newNode = new DNode<T>(value);
            newNode->next = current->next;
            if (current->next) current->next->prev = newNode;
            newNode->prev = current;
            current->next = newNode;
            if (current == tail) tail = newNode;
            return true;
        }
        return false;
    }

    // Task 1.3: Insert Before
    bool insertBefore(T value, T key) {
        DNode<T>* current = head;
        while (current && current->data != key) {
            current = current->next;
        }
        if (current) {
            DNode<T>* newNode = new DNode<T>(value);
            newNode->prev = current->prev;
            if (current->prev) current->prev->next = newNode;
            newNode->next = current;
            current->prev = newNode;
            if (current == head) head = newNode;
            return true;
        }
        return false;
    }

    // Task 1.4: Delete Before
    bool deleteBefore(T key) {
        DNode<T>* current = head;
        while (current && current->data != key) {
            current = current->next;
        }
        if (current && current->prev) {
            DNode<T>* nodeToDelete = current->prev;
            if (nodeToDelete == head) {
                head = head->next;
                head->prev = nullptr;
            } else {
                nodeToDelete->prev->next = current;
                current->prev = nodeToDelete->prev;
            }
            delete nodeToDelete;
            return true;
        }
        return false;
    }

    // Task 1.5: Delete After
    bool deleteAfter(T key) {
        DNode<T>* current = head;
        while (current && current->data != key) {
            current = current->next;
        }
        if (current && current->next) {
            DNode<T>* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            if (nodeToDelete->next) nodeToDelete->next->prev = current;
            if (nodeToDelete == tail) tail = current;
            delete nodeToDelete;
            return true;
        }
        return false;
    }

    // Task 1.6: Get Length
    int getLength() {
        int length = 0;
        DNode<T>* current = head;
        while (current) {
            length++;
            current = current->next;
        }
        return length;
    }

    // Task 1.7: Search for a node with value 'x'
    DNode<T>* search(T x) {
        DNode<T>* current = head;
        while (current && current->data != x) {
            current = current->next;
        }
        return current;
    }

    // Additional utility functions (for display, insertion at head/tail) for testing
    void insertAtHead(T value) {
        DNode<T>* newNode = new DNode<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtTail(T value) {
        DNode<T>* newNode = new DNode<T>(value);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        DNode<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
