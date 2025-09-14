#include <iostream>
#include "MyQueue.h"

using namespace std;

void FIFOPageReplacement(int pages[], int n, int capacity)
{
    MyQueue<int> memoryQueue(capacity);
    int pageFaults = 0;
 

    for (int i = 0; i < n; i++)
    {
       bool check = false;

        for (int j = 0; j < memoryQueue.size(); j++)
        {
            if (memoryQueue.getFront() == pages[i])
            {
                check = true;
                break;
            }
            memoryQueue.enqueue(memoryQueue.dequeue());
        }

        if (!check)
        {
            if (memoryQueue.size() == capacity)
            {
                memoryQueue.dequeue();
            }
            memoryQueue.enqueue(pages[i]);
            pageFaults++;
        }

        memoryQueue.display();
    }

    cout << "Total Page Faults: " << pageFaults << endl;
}

int main()
{
    int pages[] = {1, 3, 0, 3, 5, 6};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3;

    FIFOPageReplacement(pages, n, capacity);

    cout << endl;

    return 0;
}
