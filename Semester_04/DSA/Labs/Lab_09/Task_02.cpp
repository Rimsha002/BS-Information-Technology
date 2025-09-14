#include <iostream>
#include "DLL.h"
using namespace std;

template <class T>
dNode<T>DSLL<T>::*getIntersectionNode(dNode<T> *headA, dNode<T> *headB)
{
if(!headA || !headB)
{
    return NULL;
}
dNode<T> *temp1 = headA;
dNode<T> *temp2 = headB;
cout << "Hello";
while( temp1 != temp2)
{
 temp1 = temp1->next;
 temp2 = temp2->next;   
}

return temp1->next;

}


int main()
{
dNode<int> *Node1 = new dNode<int>(1);
dNode<int> *Node2 = new dNode<int>(2);
dNode<int> *Node3 = new dNode<int>(3);
dNode<int> *Node4 = new dNode<int>(4);
dNode<int> *Node5 = new dNode<int>(5);
dNode<int> *Node6 = new dNode<int>(6);
dNode<int> *Node7 = new dNode<int>(7);
dNode<int> *Node8 = new dNode<int>(8);

Node1->next = Node2;


// &getIntersectionNode(dNode<T> *headA, dNode<T> *headB);
   return 0;
}