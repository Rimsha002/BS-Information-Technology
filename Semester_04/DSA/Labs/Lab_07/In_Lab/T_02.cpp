#include <iostream>
#include "DLL.h"
using namespace std;

template <class T>
void DSLL<T>::doubleIt(dNode<T> *head)
{
    dNode<T> *temp1 = head;
    dNode<T> *temp2 = tail;
    T d;
    while (temp1 != NULL)
    {
        d = (d * 10) + temp1->data;
        temp1 = temp1->next;
    }

    d = d * 2;
    while (temp2 != NULL)
    {
        temp2->data = d % 10;
        d = d / 10;
        temp2 = temp2->pre;
    }
}
int main()
{
    DSLL<int> L1;
    L1.insertAtTail(1);
    L1.insertAtTail(8);
    L1.insertAtTail(9);

    dNode<int> *h = L1.head;
    cout << "Original: ";
    L1.printDSLL();

    cout << "Double: ";
    L1.doubleIt(h);
    L1.printDSLL();

    return 0;
}