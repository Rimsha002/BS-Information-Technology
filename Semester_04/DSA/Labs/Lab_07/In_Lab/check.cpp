#include <iostream>
#include "DLL.h"
using namespace std;

template <class T>
dNode<T> *DSLL<T>::rotateRight(dNode<T> *head, int k)
{
    if (!head || k <= 0) return head;  // Check for an empty list or invalid k

    dNode<T> *tail = head;
    // Find the last node to get initial tail
    while (tail->next) {
        tail = tail->next;
    }

    int count = 0;
    while (count < k) {
        // Link tail to head to rotate right
        tail->next = head;
        head->pre = tail;
        
        // Update head to be the last element
        head = tail;

        // Move tail to the previous node, which will be the new tail
        tail = tail->pre;
        tail->next = nullptr;  // Mark new tail's next as null
        head->pre = nullptr;   // Mark new head's pre as null

        count++;
    }
    return head;
}


int main()
{
    DSLL<int> L1;
    L1.insertAtTail(1);
    L1.insertAtTail(2);
    L1.insertAtTail(3);
    L1.insertAtTail(4);
    L1.insertAtTail(5);
    // L1.insertAtTail(6);

    dNode<int> *h = L1.head;
    cout << "Original: ";
    L1.printDSLL();

    cout << "After Right Rotation: ";
    L1.rotateRight(h, 1);
    L1.printDSLL();

    return 0;
}