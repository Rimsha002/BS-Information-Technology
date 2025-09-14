#ifndef CSLL_H
#define CSLL_H

#include <iostream>
using namespace std;

template <class T>
class csNode
{
public:
    T data;
    csNode *next;

    csNode()
    {
        this->data = NULL;
        this->next = NULL;
    }

    csNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
    csNode(T data, csNode *next)
    {
        this->data = data;
        this->next = next;
    }

    ~csNode()
    {
        delete next;
        next = nullptr;
    }

    void printcsNodes(csNode<int> *head)
    {
        while (head)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
};

template <class T>
class CSLL
{
    
    
    int size = 0;

public:
csNode<T> *head;
csNode<T> *tail;
    CSLL();
    CSLL(T data);
    CSLL(csNode<T> *N);
    ~CSLL();
    void insertAtHead(T data);
    void insertAtTail(T data);
    void insertAtPos(T data, T pos);
    void deleteAtHead();
    void deleteAtTail();
    void deleteNode(csNode<T> *node);
    // void deleteSpecificNode(csNode<T>* node, int key);
    void deleteBefore(csNode<T> *node);
    void deleteAfter(csNode<T> *node);
    void printcsList();
    csNode<T> *getNode(int index);
    int getSize();
    bool isEmpty();
};

template <class T>
CSLL<T>::CSLL()
{
    next = NULL;
    tail = NULL;
    size = 0;
}

template <class T>
CSLL<T>::CSLL(T data)
{
    head = new csNode<T>(data);
    tail = head;
    tail->next = head;
    size = 1;
}

template <class T>
CSLL<T>::CSLL(csNode<T> *N)
{
    head = N;
    tail = N;
    tail->next = head;
    size++;
}

template <class T>
CSLL<T>::~CSLL()
{
    csNode<T> *current = head;
    csNode<T> *nextNode = nullptr;
    while (current->next != head)
    {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
void CSLL<T>::insertAtHead(T data)
{
    csNode<T> *temp = new csNode<T>(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        tail->next = head;
    }
    else
    {
        temp->next = head;
        head = temp;
        tail->next = head;
    }
    size++;
}

template <class T>
void CSLL<T>::insertAtPos(T data, T pos)
{
    if (pos < 0 || pos > size)
    {
        cout << "Index out of bounds" << endl;
    }
    else if (pos == 0)
    {
        insertAtHead(data);
    }
    else if (pos == size)
    {
        insertAtTail(data);
    }
    else
    {
        csNode<T> *temp = new csNode<T>(data);
        csNode<T> *pre = head;
        for (int i = 0; i < pos - 1; i++)
        {
            pre = pre->next;
        }
        temp->next = pre->next;
        pre->next = temp;
        size++;
    }
}

template <class T>
void CSLL<T>::insertAtTail(T data)
{
    csNode<T> *temp = new csNode<T>(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        tail->next = head;
    }
    else
    {
        tail->next = temp;
        temp->next = head;
        tail = temp;
    }
    size++;
}

template <class T>
void CSLL<T>::deleteAtHead()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        csNode<T> *temp = head;
        head = head->next;
        tail->next = head;
        temp->next = NULL;
        delete temp;
        size--;
    }
}

template <class T>
void CSLL<T>::deleteAtTail()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
    }
    else if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    else
    {
        csNode<T> *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }
        temp->next = head;
        delete tail;
        tail = temp;
        size--;
    }
}


template <class T>
void CSLL<T>::deleteNode(csNode<T> *node)
{
    if (node == NULL || head == NULL)
    {
        cout << "Node does not exist." << endl;
        return;
    }
    if (head == tail && node == head)
    { 
        delete head;
        head = tail = NULL;
        size = 0;
        return;
    }

    if (node == tail)
    {
        deleteAtTail();
        return;
    }

    if (node == head)
    {
        deleteAtHead();
        return;
    }

    csNode<T> *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;

    if (temp == tail)
    {
        tail = node;
    }

    delete temp;
    size--;
}

// template <class T>
// void CSLL<T>::deleteSpecificNode(csNode<T>* node, int key)
//  {
//     if (node == nullptr) {
//          cout << "List is empty, nothing to delete." << endl;
//         return;
//     }

//     csNode<T>* curr = node->next;
//     csNode<T>* prev = node;

//     if (curr == node && curr->data == key) {
//         delete curr;
//         node = nullptr;
//         }

//     // If the node to be deleted is the first node
//     if (curr->data == key) {
//         node->next = curr->next;
//         delete curr;
        
//     }

//     // Traverse the list to find the node to be deleted
//     while (curr != node && curr->data != key) {
//         prev = curr;
//         curr = curr->next;
//     }

//     // If the node to be deleted is found
//     if (curr->data == key) {
//         prev->next = curr->next;
//         if (curr == node) {
//             node = prev;
//         }
//         delete curr;
//     } else {
//         // If the node to be deleted is not found
//         cout << "Node with data " << key
//           << " not found." << endl;
//     }

// }


template <class T>
void CSLL<T>::deleteBefore(csNode<T> *node)
{
    if (node == NULL || head == NULL || head == tail)
    {
        cout << "Invalid operation or only one node in the list." << endl;
        return;
    }

    csNode<T> *temp = head;
    csNode<T> *prev = NULL;

    while (temp->next != node && temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp->next == node)
    {
        if (temp == head)
        {
            deleteAtTail();
        }
        else
        {
            prev->next = node;
            delete temp;
            size--;
        }
    }
    else
    {
        cout << "Node not found." << endl;
    }
}

template <class T>
void CSLL<T>::deleteAfter(csNode<T> *node)
{
    if (node == NULL || head == NULL || head == tail)
    {
        cout << "Invalid operation or only one node in the list." << endl;
        return;
    }

    csNode<T> *temp = node->next;
    if (temp == head)
    {
        cout << "Cannot delete head using deleteAfter." << endl;
        return;
    }

    node->next = temp->next;

    if (temp == tail)
    {
        tail = node;
    }

    delete temp;
    size--;
}


template <class T>
csNode<T> *CSLL<T>::getNode(int index)
{
    if (index < 0 || index >= size)
    {
        cout << "Index out of bounds" << endl;
        return NULL;
    }
    else
    {
        csNode<T> *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        return temp;
    }
}

template <class T>
int CSLL<T>::getSize()
{
    if (size == 0)
    {
        cout << "List is empty." << endl;
    }
    else
        return size;
}

template <class T>
bool CSLL<T>::isEmpty()
{
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void CSLL<T>::printcsList()
{
    csNode<T> *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

#endif