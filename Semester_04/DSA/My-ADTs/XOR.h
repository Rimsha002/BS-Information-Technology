#ifndef XORLIST_H
#define XORLIST_H

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* npx; 
    Node(int val){
        data = val;
        npx = nullptr;
    }
};

class XORList {
private:
    Node* head;
    Node* tail;

    Node* XOR(Node* a, Node* b);

public:
    XORList();
    ~XORList();
    void insertAtHead(int val);
    void insertAtTail(int val);
    int deleteAtHead();
    int deleteAtTail();
    void printList();
};

#endif
