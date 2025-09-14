#include <iostream>
using namespace std;

#include "LSLL.h"

template <class T>
Node<T> *reverseLinkedList(Node<T> *head, int k)
{
    Node<T> *prev = nullptr;
    Node<T> *curr = head;
    Node<T> *next = nullptr;
    int count = 0;

    while (curr != nullptr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    return prev;
}

template <class T>
Node<T> *reverseKGroup(Node<T> *head, int k)
{
    Node<T> *temp = head;

    for (int i = 0; i < k; ++i)
    {
        if (temp == nullptr)
        {
            return head;
        }
        temp = temp->next;
    }

    Node<T> *newHead = reverseLinkedList(head, k);

    head->next = reverseKGroup(temp, k);

    return newHead;
}

template <class T>
void reverseInGroups(LSLL<T> &list, int k)
{
    list.head = reverseKGroup(list.head, k);
}

int main()
{
    LSLL<int> list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    // list.insertAtTail(5);
    // list.insertAtTail(6);
    // list.insertAtTail(7);
    // list.insertAtTail(8);

    int k;
    cout << "Enter value for reversing chunk: ";
    cin >> k;
    if (k <= 0 || k > list.getSize())
    {
        cout << "Chunk value is invalid." << endl;
        return 0;
    }
    cout << "Original List: ";
    list.printList();

    reverseInGroups(list, k);
    cout << "Reversed with group of " << k << " values: ";
    list.printList();

    cout << endl;
    return 0;
}
