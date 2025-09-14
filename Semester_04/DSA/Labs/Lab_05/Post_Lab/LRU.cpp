#include <iostream>
#include "MyQueue.h"

using namespace std;

class LRUCache
{
    MyQueue<int> cache;
    int capacity;

public:
    LRUCache(int cap) : cache(cap)
    {
        capacity = cap;
    }

    void accessPage(int page)
    {
        if (cache.size() == 0 || cache.size() < capacity)
        {
            if (!isPageInCache(page))
            {
                cout << "Page Fault: " << page << endl;
                cache.enqueue(page);
            }
            else
            {
                cout << "Page Hit: " << page << endl;
                moveToFront(page);
            }
        }
        else if (cache.size() == capacity)
        {
            if (!isPageInCache(page))
            {
                int removedPage = cache.dequeue();
                cout << "Page Fault: " << page << endl;
                cout << "Removing least recently used page: " << removedPage << endl;
                cache.enqueue(page);
            }
            else
            {
                cout << "Page Hit: " << page << endl;
                moveToFront(page);
            }
        }
        displayCache();
    }

    bool isPageInCache(int page)
    {
        for (int i = 0; i < cache.size(); i++)
        {
            if (cache.getElementAt(i) == page)
            {
                return true;
            }
        }
        return false;
    }

    void moveToFront(int page)
    {
        MyQueue<int> tempQueue(cache.getCapacity());
        while (cache.size() > 0)
        {
            int currentPage = cache.dequeue();
            if (currentPage != page)
            {
                tempQueue.enqueue(currentPage);
            }
        }
        cache.enqueue(page);
        while (tempQueue.size() > 0)
        {
            cache.enqueue(tempQueue.dequeue());
        }
    }

    void displayCache() const
    {
        cout << "Cache State: ";
        cache.display();
    }
};

int main()
{
    int cacheSize, pageRequest;
    cout << "Enter cache size: ";
    cin >> cacheSize;

    LRUCache lru(cacheSize);

    cout << "Enter page requests (enter -1 to quit): " << endl;
    while (true)
    {
        cin >> pageRequest;
        if (pageRequest == -1)
            break;
        lru.accessPage(pageRequest);
    }

    return 0;
}
