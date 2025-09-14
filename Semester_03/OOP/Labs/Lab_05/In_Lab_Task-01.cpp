#include <iostream>
#include <queue>
#include <stack>

using namespace std;
// Queue ShowDown
void removeEven(queue<int> &q);

int main()
{
    queue<int> queue;

    int size;
    int element;

    cout << "Enter range of Queue: ";
    cin >> size;
    cout << "Enter " << size << " elements in Queue ";
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        queue.push(element);
    }
    removeEven(queue);

    return 0;
}
void removeEven(queue <int> & q)
{
    queue<int> q2;
    int size = q.size();

    for (int i = 0; i < size; i++)
    {
        int num = q.front();
       
        if (num % 2 == 0)
        {
            q.pop();
        }
        else
        {
            q2.push(num);
            q.pop();
        }
    }

    cout << "\nQueue with only Odd number is : \n";
    while (!q2.empty())
    {
        cout << q2.front() << " ";
        q2.pop();
    }

}