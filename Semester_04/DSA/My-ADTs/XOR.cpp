#include "XOR.h"

// XOR two pointers
Node* XORList::XOR(Node* a, Node* b) {
    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}


XORList::XORList() : head(nullptr), tail(nullptr) {}


XORList::~XORList() {
    Node* current = head;
    Node* prev = nullptr;
    Node* next;

    while (current) {
        next = XOR(prev, current->npx); 
        delete current;
        prev = current;
        current = next;
    }
}

void XORList::insertAtHead(int val) {
    Node* newNode = new Node(val);
    newNode->npx = XOR(nullptr, head);

    if (head) {
        head->npx = XOR(newNode, XOR(nullptr, head->npx));
    } else {
        tail = newNode;
    }

    head = newNode;
}

void XORList::insertAtTail(int val) {
    Node* newNode = new Node(val);
    newNode->npx = XOR(tail, nullptr);

    if (tail) {
        tail->npx = XOR(newNode, XOR(tail->npx, nullptr));
    } else {
        head = newNode;
    }

    tail = newNode;
}

int XORList::deleteAtHead() {
    if (!head) {
        cout << "List is empty!" << endl;
        return -1;
    }

    int val = head->data;
    Node* next = XOR(nullptr, head->npx);

    if (next) {
        next->npx = XOR(nullptr, XOR(head, next->npx));
    } else {
        tail = nullptr;
    }

    delete head;
    head = next;
    return val;
}

int XORList::deleteAtTail() {
    if (!tail) {
        cout << "List is empty!" << endl;
        return -1;
    }

    int val = tail->data;
    Node* prev = XOR(tail->npx, nullptr);

    if (prev) {
        prev->npx = XOR(XOR(prev->npx, tail), nullptr);
    } else {
        head = nullptr;
    }

    delete tail;
    tail = prev;
    return val;
}

void XORList::printList() {
    Node* current = head;
    Node* prev = nullptr;
    Node* next;

    // cout << "XOR Linked List: ";
    while (current) {
        cout << current->data << " ";
        next = XOR(prev, current->npx);
        prev = current;
        current = next;
    }
    cout << endl;
}


int main() {
    XORList list;

    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);

    cout <<endl;
    cout << "After inserting at head: ";
    list.printList();

    list.insertAtTail(40);
    list.insertAtTail(50);

    cout << "After inserting at tail: ";
    list.printList();

    cout << "Deleted from head: " << list.deleteAtHead() << endl;
    list.printList();

    cout << "Deleted from tail: " << list.deleteAtTail() << endl;
    list.printList();
    cout << endl;
    return 0;
}