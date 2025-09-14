#ifndef DLL_H
#define DLL_H
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class DSLL;

template <class T>
class dNode
{
    friend DSLL<T>;
    T data;
    dNode<T> *next;
    dNode<T> *pre;

public:
    dNode(T d)
    {
        data = d;
        next = NULL;
        pre = NULL;
    }
    dNode(T d, dNode<T> *n, dNode<T> *p)
    {
        data = d;
        next = n;
        pre = p;
    }
    T getData()
    {
        return data;
    }
    ~dNode()
    {
        delete next;
        delete pre;
        next = NULL;
        pre = NULL;
    }
};

template <class T>
class DSLL
{

    int size;

public:
    dNode<int> *head;
    dNode<int> *tail;
    // CONSTRUCTOR
    DSLL();
    DSLL(dNode<T> *h);
    ~DSLL();
    DSLL(const DSLL<T> &other);
    // INSERTION
    void insertAtHead(T val);
    void insertAtTail(T val);
    bool insertAfter(int index, T val);
    bool insertBefore(int index, T val);
    // DELETION
    void deleteAtHead();
    void deleteAtTail();
    // bool deleteNode(dNode<T> *node);
    void deleteNode(dNode<T> *node);
    bool deleteAfter(T key);
    bool deleteBefore(T key);
    // OTHER FUNCTIONS
    dNode<T> *getNode(int index);
    int getSize();
    dNode<T> *search(T val);
    void printDSLL();

    // INLAB
    void PairSum(dNode<T> *head, int k);
    void doubleIt(dNode<T> *head);
    dNode<T>* rotateRight(dNode<T> *head, int k);
    vector<T> DLLToArray(dNode<T> *head);
};

template <class T>
DSLL<T>::DSLL()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

template <class T>
DSLL<T>::DSLL(dNode<T> *h)
{
    head = h;
    tail = h;
    size++;
}

template <class T>
DSLL<T>::~DSLL()
{
    delete head;
    delete tail;
    head = NULL;
    tail = NULL;
}

template <class T>
DSLL<T>::DSLL(const DSLL<T> &other)
{
    head = other.head;
    tail = other.tail;
    size = other.size;
}

template <class T>
void DSLL<T>::insertAtHead(T val)
{
    dNode<T> *temp = new dNode<T>(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
    size++;
}

template <class T>
void DSLL<T>::insertAtTail(T val)
{
    dNode<T> *temp = new dNode<T>(val);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->pre = tail;
        tail = temp;
    }
    size++;
}

template <class T>
bool DSLL<T>::insertAfter(int index, T val)
{
    if (index < 0 || index >= size)
    {
        cout << "Invalid Index\n";
        return false;
    }
    dNode<T> *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    dNode<T> *newNode = new dNode<T>(val);
    newNode->next = temp->next;
    temp->next->pre = newNode;
    temp->next = newNode;
    newNode->pre = temp;
    size++;
    return true;
}

template <class T>
bool DSLL<T>::insertBefore(int index, T val)
{
    if (index < 0 || index >= size)
    {
        cout << "Invalid Index\n";
        return false;
    }
    dNode<T> *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    dNode<T> *newNode = new dNode<T>(val);
    newNode->next = temp;
    newNode->pre = temp->pre;
    temp->pre->next = newNode;
    temp->pre = newNode;
    size++;
    return true;
}

// DELETION
template <class T>
void DSLL<T>::deleteAtHead()
{
    dNode<T> *temp = head;
    if (head == NULL)
    {
        cout << "List is Empty";
    }
    if (head->next == NULL)
    {
        head == NULL;
        delete temp;
    }
    else
    {
        temp->next = head->next;
        temp->pre = NULL;
        head->next = NULL;
        temp = head;
    }

    size--;
}

// template <class T>
// void DSLL<T>::deleteAtTail()
// {
//     if (head == NULL)
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
//         Node<T> *temp = head;
//         while (temp->next->next != NULL)
//         {
//             temp = temp->next;
//         }
//         Node<T> *N = temp->next;
//         temp->next = NULL;
//         delete N;
//         size--;
//     }
// }

template <class T>
void DSLL<T>::deleteAtTail()
{
    dNode<T> *temp = tail;
    if (head == NULL)
    {
        cout << "List is Empty";
    }
    if (head->next == NULL)
    {
        head == NULL;
        delete temp;
    }
    else
    {
        temp->pre = tail->pre;
        temp->next = NULL;
        tail->pre = NULL;
        temp = tail;
    }

    size--;
}

template <class T>
void DSLL<T>::deleteNode(dNode<T> *node)
{
    if (node == NULL)
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
        dNode<T> *pre = head;
        dNode<T> *curr = head->next;
        dNode<T> *nextp = head->next->next;

        while (curr != node)
        {
            pre = pre->next;
            curr = curr->next;
            nextp = nextp->next;
        }
        pre->next = curr->next;
        delete curr;
        size--;
    }
}


// template <class T>
// bool DSLL<T>::deleteNode(dNode<T> *node)
// {
//     if (head == NULL)
//     {
//         cout << "List is Empty\n";
//         return false;
//     }
//     if (node == head)
//     {
//         deleteAtHead();
//         return true;
//     }
//     if (node == tail)
//     {
//         deleteAtTail();
//         return true;
//     }
//     node->pre->next = node->next;
//     node->next->pre = node->pre;
//     node->next = NULL;
//     node->pre = NULL;
//     delete node;
//     size--;
//     return true;
// }

template <class T>
bool DSLL<T>::deleteAfter(T key)
{
    dNode<T> *temp = head;
    while (temp->next != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "We Reached Last Node\n";
        return false;
    }
    dNode<T> *delNode = temp->next;
    temp->next = delNode->next;
    if (delNode->next)
        delNode->next->pre = temp;
    delNode->next = NULL;
    delNode->pre = NULL;
    delete delNode;
    size--;
    return true;
}

template <class T>
bool DSLL<T>::deleteBefore(T key)
{
    dNode<T> *temp = head;
    while (temp->next != NULL && temp->data != key)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "We Reached Last Node\n";
        return false;
    }
    dNode<T> *delNode = temp->pre;
    temp->pre = delNode->pre;
    if (delNode->pre)
        delNode->pre->next = temp;
    delNode->next = NULL;
    delNode->pre = NULL;
    delete delNode;
    size--;
    return true;
}

// OTHERS
template <class T>
dNode<T> *DSLL<T>::getNode(int index)
{
    if (index < 0 || index >= size)
    {
        cout << "Invalid Index\n";
        return NULL;
    }
    dNode<T> *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp;
}

template <class T>
int DSLL<T>::getSize()
{
    return size;
}

template <class T>
dNode<T> *DSLL<T>::search(T val)
{
    dNode<T> *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

template <class T>
void DSLL<T>::printDSLL()
{
    dNode<T> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

#endif