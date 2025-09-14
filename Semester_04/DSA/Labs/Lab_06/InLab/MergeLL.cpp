#include <iostream>
#include "LSLL.h"
using namespace std;

void printList(Node<int> *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// void mergeSorted(Node<int> *head1, Node<int> *head2)
// {
//     LSLL<int> L3;

//     if (head1 == NULL)
//     {
//         printList(head2);
//     }
//     if (head2 == NULL)
//     {
//         printList(head1);
//     }
//     else
//     {

//         while (head1 != NULL)
//         {
//             L3.insertAtTail(head1->data);
//             head1 = head1->next;
//         }
//         while (head2 != NULL)
//         {
//             L3.insertAtTail(head2->data);
//             head2 = head2->next;
//         }

//         Node<int> *N = L3.head;
//         Node<int> *M;

//         for (N; N != NULL; N = N->next)
//         {
//             for (M = N->next; M != NULL; M = M->next)
//             {
//                 if (N->data > M->data)
//                 {
//                     int temp = N->data;
//                     N->data = M->data;
//                     M->data = temp;
//                 }
//             }
//         }
//         L3.printList();
        
//     }
// }


Node<int> *mergeSorted(Node<int> *head1, Node<int> *head2)
//Optimized time = O(N + N)   space = o(1)
{
    Node<int> *t1 = head1;
    Node<int> *t2 = head2;
    Node<int> *dummey = new Node<int>(-1);
    Node<int>*temp = dummey;
    if(head1==NULL) return head2;
    if(head2 ==NULL) return head1;
    while(t1 != NULL && t2!= NULL)
    {
        if(t1->data< t2->data)
        {temp->next = t1;
            temp = t1;
        t1 = t1->next;
  
        }
        else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        
        }

        if(t1){temp->next = t1;}
        if(t2){temp->next = t2;}
    }

    return dummey->next;   

}


int main()
{
    LSLL<int> L;
    L.insertAtHead(4);
    L.insertAtHead(2);
    L.insertAtHead(0);

    LSLL<int> L1;
    L1.insertAtHead(5);
    L1.insertAtHead(3);
    L1.insertAtHead(1);
    L1.insertAtHead(0);
    L1.insertAtHead(-2);

    L.printList();
    L1.printList();


   Node <int>*N = mergeSorted(L.head, L1.head);
   printList(N);


    return 0;
}