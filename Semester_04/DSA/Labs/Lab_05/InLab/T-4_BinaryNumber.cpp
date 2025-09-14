#include <iostream>
#include "MyQueue.h"

using namespace std;

void generateBinaryNumbers(int N)
{
    MyQueue<string> binaryQueue(50);
    binaryQueue.enqueue("1");

    for (int i = 0; i < N; i++)
    {
        string current = binaryQueue.getFront();
        cout << current << " ";
        binaryQueue.dequeue();

        binaryQueue.enqueue(current + "0");
        binaryQueue.enqueue(current + "1");
    }
    cout << endl;
}

int main()
{
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    generateBinaryNumbers(N);

    return 0;
}
