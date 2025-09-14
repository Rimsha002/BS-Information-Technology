#include <iostream>
using namespace std;
// prime mania
void printPrime(int);

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    printPrime(n);
    return 0;
}


void printPrime(int n)
{
    static int i = 2;
    int count = 0;
    for (int j = 2; j < i; j++)
    {
        if (i % j == 0)
        {
            count++;
        }
    }
    if (count == 0)
    {
        cout << i << " ";
        n--;
    }
    i++;
    if (n > 0)
    {
        printPrime(n);
    }
}