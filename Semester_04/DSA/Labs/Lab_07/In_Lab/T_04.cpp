#include <iostream>
#include "DLL.h"
#include <vector>
using namespace std;

template <class T>
vector<T> DSLL<T>::DLLToArray(dNode<T> *head)
{
    int s = getSize();
    int i = 0;
    vector<int> v;
    dNode<T> *temp = head;

    while(temp != NULL)
    {
        v.push_back(temp->data);
        temp = temp->next;
        i++;
    }
    return v;

}



int main()
{
     DSLL<int> L1;
    L1.insertAtTail(1);
    L1.insertAtTail(2);
    L1.insertAtTail(3);
    L1.insertAtTail(4);
    L1.insertAtTail(5);

    int s = L1.getSize();
    vector<int> v1;
    dNode<int> *h = L1.head;

    v1 = L1.DLLToArray(h);
    cout << "Array: ";
    for(int i =0; i < s; i++)
    {
        cout << v1[i] << " " ;
    }
    cout << endl;
   return 0;
}