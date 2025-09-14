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

    csNode(T data = T(), csNode *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
    ~csNode()
    {
        next = nullptr;
    }

};

template <class T>
class CSLL
{
private:
   
    csNode<T> *tail;
    int size;

public:
 csNode<T> *head;
    CSLL();
    CSLL(T data);
    CSLL(csNode<T> *node);
    ~CSLL();

    void insertAtHead(T data);
    void insertAtTail(T data);
    void insertAtPos(T data, int pos);
    void deleteAtHead();
    void deleteAtTail();
    void deleteNode(csNode<T> *node);
    void deleteBefore(csNode<T> *node);
    void deleteAfter(csNode<T> *node);
    void printcsList() const;
    csNode<T> *getNode(int index) const;
    int getSize() const;
    bool isEmpty() const;
};

template <class T>
CSLL<T>::CSLL() : head(nullptr), tail(nullptr), size(0) {}

template <class T>
CSLL<T>::CSLL(T data)
{
    head = new csNode<T>(data);
    tail = head;
    tail->next = head;
    size = 1;
}

template <class T>
CSLL<T>::CSLL(csNode<T> *node)
{
    head = node;
    tail = node;
    tail->next = head;
    size = 1;
}

template <class T>
CSLL<T>::~CSLL()
{
    if (!head)
        return;
    csNode<T> *current = head;
    do
    {
        csNode<T> *nextNode = current->next;
        delete current;
        current = nextNode;
    } while (current != head);
    head = tail = nullptr;
    size = 0;
}

template <class T>
void CSLL<T>::insertAtHead(T data)
{
    csNode<T> *newNode = new csNode<T>(data);
    if (!head)
    {
        head = tail = newNode;
        tail->next = head;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    size++;
}

template <class T>
void CSLL<T>::insertAtTail(T data)
{
    csNode<T> *newNode = new csNode<T>(data);
    if (!head)
    {
        head = tail = newNode;
        tail->next = head;
    }
    else
    {
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
    size++;
}

template <class T>
void CSLL<T>::insertAtPos(T data, int pos)
{
    if (pos < 0 || pos > size)
    {
        cout << "Index out of bounds" << endl;
        return;
    }
    if (pos == 0)
    {
        insertAtHead(data);
    }
    else if (pos == size)
    {
        insertAtTail(data);
    }
    else
    {
        csNode<T> *newNode = new csNode<T>(data);
        csNode<T> *current = head;
        for (int i = 1; i < pos; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
}

template <class T>
void CSLL<T>::deleteAtHead()
{
    if (!head)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        csNode<T> *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }
    size--;
}

template <class T>
void CSLL<T>::deleteAtTail()
{
    if (!head)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        csNode<T> *current = head;
        while (current->next != tail)
        {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = head;
    }
    size--;
}

template <class T>
void CSLL<T>::deleteNode(csNode<T> *node)
{
    if (!node || !head)
    {
        cout << "Node not found or list empty." << endl;
        return;
    }
    if (node == head)
    {
        deleteAtHead();
        return;
    }
    if (node == tail)
    {
        deleteAtTail();
        return;
    }
    csNode<T> *temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    delete temp;
    if (temp == tail)
        tail = node;
    size--;
}

template <class T>
void CSLL<T>::deleteBefore(csNode<T> *node)
{
    if (!node || head == tail)
    {
        cout << "Invalid operation or insufficient nodes." << endl;
        return;
    }
    csNode<T> *prev = head, *curr = head;
    while (curr->next != node && curr->next != head)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr->next == node)
    {
        prev->next = node;
        delete curr;
        size--;
    }
    else
    {
        cout << "Node not found." << endl;
    }
}

template <class T>
void CSLL<T>::deleteAfter(csNode<T> *node)
{
    if (!node || head == tail)
    {
        cout << "Invalid operation or insufficient nodes." << endl;
        return;
    }
    csNode<T> *temp = node->next;
    if (temp == head)
    {
        cout << "Cannot delete head using deleteAfter." << endl;
        return;
    }
    node->next = temp->next;
    delete temp;
    if (temp == tail)
        tail = node;
    size--;
}

template <class T>
csNode<T> *CSLL<T>::getNode(int index) const
{
    if (index < 0 || index >= size)
    {
        cout << "Index out of bounds" << endl;
        return nullptr;
    }
    csNode<T> *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp;
}

template <class T>
int CSLL<T>::getSize() const
{
    return size;
}

template <class T>
bool CSLL<T>::isEmpty() const
{
    return size == 0;
}

template <class T>
void CSLL<T>::printcsList() const
{
    if (!head)
    {
        cout << "List is empty." << endl;
        return;
    }
    csNode<T> *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

#endif
