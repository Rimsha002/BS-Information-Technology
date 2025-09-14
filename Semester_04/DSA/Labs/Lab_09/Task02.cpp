#include <iostream>
using namespace std;

class Node{
int data;
Node *next;
public:
Node(int d)
{
    data = d;
    next = NULL;
}
Node(int d, Node *n)
{
    data = d;
    next = n;
}
};

int main()
{
    Node *n1(1);

   return 0;
}