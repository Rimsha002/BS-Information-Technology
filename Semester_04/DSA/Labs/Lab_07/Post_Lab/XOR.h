#ifndef XORLIST_H
#define XORLIST_H

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *npx;
    Node(int val)
    {
        data = val;
        npx = nullptr;
    }
};

class XORList
{
private:
    Node *head;
    Node *tail;

    Node *XOR(Node *a, Node *b);

public:
    XORList();
    ~XORList();
    void insertAtHead(int val);
    void insertAtTail(int val);
    int deleteAtHead();
    int deleteAtTail();
    void printList();
};

Node *XORList::XOR(Node *a, Node *b)
{
    return (Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

XORList::XORList()
{
    head = nullptr;
    tail = nullptr;
}

XORList::~XORList()
{
    Node *current = head;
    Node *prev = nullptr;
    Node *next;

    while (current != nullptr)
    {
        next = XOR(prev, current->npx);
        delete current;
        prev = current;
        current = next;
    }
}

void XORList::insertAtHead(int val)
{
    Node *newNode = new Node(val);
    newNode->npx = XOR(nullptr, head);

    if (head == nullptr && tail == nullptr)
    {
        tail = newNode;
        head = newNode;
        return;
    }

    head->npx = XOR(newNode, XOR(nullptr, head->npx));

    // else
    // {
    //     tail = newNode;
    // }

    head = newNode;
}

void XORList::insertAtTail(int val)
{
    Node *newNode = new Node(val);
    newNode->npx = XOR(tail, nullptr);

    if (head == nullptr && tail == nullptr)
    {
        tail = newNode;
        head = newNode;
        return;
    }

        tail->npx = XOR(newNode, XOR(tail->npx, nullptr));
  

    tail = newNode;
}

int XORList::deleteAtHead()
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return -1;
    }

    int val = head->data;
    Node *next = XOR(nullptr, head->npx);

    if (next != nullptr)
    {
        next->npx = XOR(nullptr, XOR(head, next->npx));
    }
    else
    {
        tail = nullptr;
    }

    delete head;
    head = next;
    return val;
}

int XORList::deleteAtTail()
{
    if (tail == nullptr)
    {
        cout << "List is empty!" << endl;
        return -1;
    }

    int val = tail->data;
    Node *prev = XOR(tail->npx, nullptr);

    if (prev != nullptr)
    {
        prev->npx = XOR(XOR(prev->npx, tail), nullptr);
    }
    else
    {
        head = nullptr;
    }

    delete tail;
    tail = prev;
    return val;
}

void XORList::printList()
{
    Node *current = head;
    Node *prev = nullptr;
    Node *next;

    while (current != nullptr)
    {
        cout << current->data << " ";
        next = XOR(prev, current->npx);
        prev = current;
        current = next;
    }
    cout << endl;
}

#endif
