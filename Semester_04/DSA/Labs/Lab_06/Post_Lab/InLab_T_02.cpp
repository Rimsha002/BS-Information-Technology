#include <iostream>
#include "CSLL.h"
using namespace std;

csNode<int> *mergeCircularRoutes(csNode<int> *head1, csNode<int> *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    csNode<int> *tail1 = head1;
    while (tail1->next != head1)
    {
        tail1 = tail1->next;
    }

    csNode<int> *tail2 = head2;
    while (tail2->next != head2)
    {
        tail2 = tail2->next;
    }

    tail1->next = head2;
    tail2->next = head1;

    return head1;
}

void printCircular(csNode<int> *head)
{
    if (!head)
    {
        cout << "List is empty." << endl;
        return;
    }
    csNode<int> *temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to start: " << head->data << ")\n";
}

int main()
{
    csNode<int> *route1 = new csNode<int>(10);
    route1->next = new csNode<int>(20);
    route1->next->next = new csNode<int>(30);
    CSLL<int> c1(route1);

    csNode<int> *route2 = new csNode<int>(40);
    route2->next = new csNode<int>(50);
    route2->next->next = new csNode<int>(60);
    CSLL<int> c2(route2);

    cout << "Route 1: ";
    printCircular(route1);
    c1.printcsList();
    cout << "Route 2: ";
    printCircular(route2);

    csNode<int> *mergedRoute = mergeCircularRoutes(route1, route2);
    cout << "Merged Circular Route: ";
    printCircular(mergedRoute);
    // mergedRoute->printNodes(mergedRoute);
    return 0;
}