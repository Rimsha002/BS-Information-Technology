#include <iostream>
#include "LSLL.h"
using namespace std;

// template <class T>
// void LSLL<T>::deleteNode(Node<int> * node)
// {
//      if (head == NULL)
//     {
//         cout << "List is empty." << endl;
//     }
//     else if (head == tail)  
//     {
//         delete head;       
//         head = nullptr;     
//         tail = nullptr;
//         size = 0;
//     }
//     else
//     {
//         Node <T> *pre = head;
//         Node <T> *curr = head->next;
//         Node <T> *nextp = head->next->next;
    
//         while(curr != node)
//         {
//             pre = pre->next;
//             curr = curr->next;
//             nextp = nextp->next;
//         }
//         pre->next = curr->next; 
//         delete curr;
//         size--;
//     }
// }

int main()
{
   
    LSLL<int> L;
    L.insertAtHead(1);
    L.insertAtHead(2);
    L.insertAtHead(3);
    L.insertAtHead(4);
    L.insertAtHead(5);

    L.printList();

    Node<int> *N1 = new Node<int>(3);
    L.deleteNode(N1);

    L.printList(); 

    return 0;
}