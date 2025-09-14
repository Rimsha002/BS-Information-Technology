#include <iostream>
#include <queue>
#include <stack>

using namespace std;
//Reverse Queue
int main()
{
    queue<int> queue;
    stack<int> stack;
    int size;
    int element;

    cout << "Input range of Queue: ";
    cin >> size;
    cout << "Enter " << size << " elements in Queue ";
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        queue.push(element);
    }

    while (!queue.empty())
    {
        stack.push(queue.front());
        queue.pop();
    }
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }

    return 0;
}