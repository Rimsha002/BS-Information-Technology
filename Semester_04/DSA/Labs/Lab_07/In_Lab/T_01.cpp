#include <iostream>
#include "DLL.h"
using namespace std;

template <class T>
void DSLL<T>::PairSum(dNode<T> *head, int k)
{
    if (head == NULL)
    {
        cout << "List is empty";
        return;
    }
    if (head == tail)
    {
        if (head->data == k)
        {
            cout << "( " << head->data << " )";
        }
        else
        {
            cout << "Target pair not found";
        }
    }

    int s = getSize();
    dNode<T> *temp1;
    if (s % 2 != 0)
    {
        temp1 = head;
    }
    if (s % 2 == 0)
    {
        temp1 = head->next;

    }

    // dNode<T> *temp1 = head;
    dNode<T> *temp2 = tail;
    int sum = 0;

    while (temp1 != temp2)
    {
        sum = temp1->data + temp2->data;
        if (sum == k)
        {
            cout << "( " << temp1->data << " , " << temp2->data << " )";
        }
        temp1 = temp1->next;
        temp2 = temp2->pre;
    }
}

int main()
{
    DSLL<int> L1;
    L1.insertAtTail(1);
    L1.insertAtTail(2);
    L1.insertAtTail(3);
    L1.insertAtTail(4);
    L1.insertAtTail(5);
    L1.insertAtTail(6);
    L1.insertAtTail(7);
    L1.insertAtTail(8);
    L1.insertAtTail(9);

    dNode<int> *h = L1.head;
    cout << "Original: ";
    L1.printDSLL();
    cout << "Pair: ";
    L1.PairSum(L1.head, 10);

    return 0;
}