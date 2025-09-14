#ifndef DLL_H
#define DLL_H
#include <iostream>

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
    dNode<int> *head;
    dNode<int> *tail;
    int size;

public:
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
    bool deleteNode(dNode<T> *node);
    bool deleteAfter(T key);
    bool deleteBefore(T key);
    // OTHER FUNCTIONS
    dNode<T> *getNode(int index);
    int getSize();
    dNode<T> *search(T val);
    void printDSLL();
};

// template <class T>
// DSLL<T>::DSLL()
// {
//     head = NULL;
//     tail = NULL;
//     size = 0;
// }

// template <class T>
// DSLL<T>::DSLL(dNode<T> *h)
// {
//     head = h;
//     tail = h;
//     size++;
// }

// template <class T>
// DSLL<T>::~DSLL()
// {
//     delete head;
//     delete tail;
//     head = NULL;
//     tail = NULL;
// }

// template <class T>
// DSLL<T>::DSLL(const DSLL<T> &other)
// {
//     head = other.head;
//     tail = other.tail;
//     size = other.size;
// }

// template <class T>
// void DSLL<T>::insertAtHead(T val)
// {
//     dNode<T> *temp = new dNode<T>(val);
//     if (head == NULL)
//     {
//         head = temp;
//         tail = temp;
//     }
//     else
//     {
//         temp->next = head;
//         head->pre = temp;
//         head = temp;
//     }
//     size++;
// }

// template <class T>
// void DSLL<T>::insertAtTail(T val)
// {
//     dNode<T> *temp = new dNode<T>(val);
//     if (head == NULL)
//     {
//         head = temp;
//         tail = temp;
//     }
//     else
//     {
//         temp->next = NULL;
//         tail->next = temp;
//         temp->pre = tail;
//         tail = temp;
//     }
//     size++;
// }

// template <class T>
// void DSLL<T>::deleteAtHead()
// {

//     if (head == NULL)
//     {
//         cout << "List is Empty";
//         return;
//     }
//     dNode<T> *temp = head;
//     if (head->next == NULL)
//     {
//         head = NULL;
//         tail = NULL;
//         delete temp;
//     }
//     else
//     {
//         head = head->next;
//         head->pre = NULL;
//         delete temp;
//     }

//     size--;
// }

// template <class T>
// void DSLL<T>::deleteAtTail()
// {

//     if (tail == NULL)
//     {
//         cout << "List is Empty";
//         return;
//     }

//     dNode<T> *temp = tail;
//     if (tail->pre == NULL)
//     {
//         head = NULL;
//         tail = NULL;
//         delete temp;
//     }
//     else
//     {
//         // temp->pre->next = NULL;
//         // tail = temp->pre;
//         // temp->pre = NULL;
//         tail = tail->pre;
//         tail->next = NULL;
//         delete temp;
//     }

//     size--;
// }


// template <class T>
// bool DSLL<T>::deleteNode(dNode<T> *node)
// {
//      if (node == NULL || head == NULL)
//     {
//         cout << "Node not found or list empty." << endl;
//         return false;
//     }
//     if (node == head)
//     {
//         deleteAtHead();
//         return true ;
//     }
//     if (node == tail)
//     {
//         deleteAtTail();
//         return true;
//     }

//     dNode<T> *temp = node->next;
   
//     node->pre->next= node->next;
//     temp->pre = node->pre;
//     node->next = NULL;
//     node->pre = NULL;
//     delete node;
//    size --;
// return true;
// }

// template <class T>
// bool DSLL<T>::deleteAfter(T key)
// {
//     if (head == NULL)
//     {
//         cout << "List is empty." << endl;
//         return;
//     }
//     if (head->data == key)
//     {
//         deleteAtHead();
//         return;
//     }
//     if (node == tail)
//     {
//         deleteAtTail();
//         return;
//     }

//     dNode<T> *temp = node->next;
   
//     node->pre->next= node->next;
//     temp->pre = node->pre;
//     node->next = NULL;
//     node->pre = NULL;
//     delete node;
//    size --;
// return true;

// }

// template <class T>
// bool DSLL<T>::deleteBefore(T key)
// {
// }

// template <class T>
// void DSLL<T>::printDSLL() {}

// template <class T>
// dNode<T> *DSLL<T>::getNode(int index)
// {
// }

// template <class T>
// bool DSLL<T>::insertAfter(int index, T val)
// {
// }

// template <class T>
// bool DSLL<T>::insertBefore(int index, T val)
// {
// }


// template <class T>
// int DSLL<T>::getSize()
// {
// }

// template <class T>
// dNode<T> *DSLL<T>::search(T val)
// {
// }

#endif