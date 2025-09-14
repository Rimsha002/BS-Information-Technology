#ifndef LSLL_H
#define LSLL_H
#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(T data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
    Node() : data(T()), next(nullptr) {}
    ~Node()
    {
        next = nullptr;
    }
};

template <class T>
class LSLL
{
public:
    Node<T> *head;
    Node<T> *tail;
    int size;
    
    LSLL(); 
    LSLL(T data);
    LSLL(Node<T> *N);
    ~LSLL();
    void insertAtHead(T data);
    void insertAtTail(T data);
    void deleteAtHead();
    void deleteAtTail();
    void printList();
    Node<T> *getNode(int index);
    int getSize();
    bool isEmpty();
};

template <class T>
LSLL<T>::LSLL()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class T>
LSLL<T>::LSLL(T data)
{
    head = new Node<T>(data);
    tail = head;
    size = 1;
}

template <class T>
LSLL<T>::LSLL(Node<T> *N)
{
    head = N;
    tail = N;
    size = 1;
}

template <class T>
LSLL<T>::~LSLL()
{
    Node<T>* current = head;
    Node<T>* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class T>
void LSLL<T>::insertAtHead(T data)
{
    Node<T> *temp = new Node<T>(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    size++;
}

template <class T>
void LSLL<T>::insertAtTail(T data)
{
    Node<T> *temp = new Node<T>(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->next = NULL;
        tail = temp;
    }
    size++;
}

template <class T>
void LSLL<T>::deleteAtHead()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        if (head == NULL) 
        {
            tail = NULL;
        }
    }
}

template <class T>
void LSLL<T>::deleteAtTail()
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
        Node<T> * temp = head;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node<T> *N = temp->next;
        temp->next = NULL;
        delete N;
        tail = temp;
        size--;
    }
}

template <class T>
void LSLL<T>::printList()
{
    cout << "List: ";

    Node<T> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

template <class T>
int LSLL<T>::getSize()
{
    return size;
}

template <class T>
bool LSLL<T>::isEmpty()
{
    return (head == NULL && size == 0);
}

template <class T>
Node<T>* LSLL<T>::getNode(int index)
{
    if (index < 0 || index >= size)
    {
        cout << "Index out of bounds" << endl;
        return nullptr;
    }
    Node<T>* temp = head; 
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp;
}

#endif
