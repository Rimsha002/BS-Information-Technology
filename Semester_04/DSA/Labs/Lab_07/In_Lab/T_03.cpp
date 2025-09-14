#include <iostream>
#include "DLL.h"
using namespace std;

template <class T>
dNode<T> *DSLL<T>::rotateRight(dNode<T> *head, int k)
{
    int count = 0;
    while (count != k)
    {
        tail->next = head;
        head->pre = tail;
        head = tail;

        tail = tail->pre;


        tail->next = nullptr;  // Mark new tail's next as null
        head->pre = nullptr; 
        count++;
    }

    //     int count = 0;
    //     dNode<T> *N;
    //     dNode<T> *temp;
    //     int s = getSize();

    //     while(count != k)
    //     {
    //         temp = tail;
    //         N->data = tail->data;

    //         while(temp->pre != NULL)
    //         {
    //             temp->data = temp->pre->data;
    //             temp = temp->pre;
    //         }
    //         temp->data = N->data;
    //         count++;
    //     }
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