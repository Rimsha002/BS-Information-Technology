#include <iostream>
// #inlcude "LSLL.h"
#include "Linked_Stack.h"
using namespace std;

// void reverseSLL(LSLL<int> &L1)
// {

//     cout << "Reverse LinkList: ";

//     Node<int> *temp = L1.tail;

//     while (temp != L1.head)
//     {
//        temp = head->next;
//        tail = temp;
//        temp = tail->next;
//        tail->next = NULL;
//        temp->next = tail;

//     }
//     cout << endl;
// }

// void reverseSLL(Stack<int> &S1)
// {

//     cout << "Reverse LinkList: ";

//     Node<int> *temp = L1.tail;

//     while (temp != L1.head)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

int main()
{
    // Node<int> *N1 = new Node<int>(1);
    // LSLL<int> L(N1);

    // L.insertAtHead(2);
    // L.insertAtHead(3);
    // L.insertAtHead(4);
    // L.insertAtHead(5);

    // L.printList();

    // reverseSLL(L);

    Stack<int> S1;
    S1.push(1);
    S1.push(2);
    S1.push(3);
    S1.push(4);
    S1.push(5);

    S1.printStack();

    Stack<int> S2;
   

    while (!S1.isEmpty())
    {
        cout << S1.getTop();
        S1.pop();
    }

    // S2.printStack();

    return 0;
}