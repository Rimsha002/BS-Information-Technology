#include <iostream>
#include <string>
using namespace std;

class BigInt
{
    int *arr;
    int size;
    int n;

public:
    BigInt(string num)
    {
        size = num.length();
        arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            n = num[i] - '0';
            arr[i] = n;
        }
    }
    
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << endl;
        }
    }
    ~BigInt()
    {
        delete[] arr;
    }

    BigInt &operator++()
    {
        for (int i = size - 1; i >= 0; i--)
        {

            if (arr[i] >= 10)
            {
                arr[i] %= 10;
                if (i > 0)
                    arr[i - 1]++;
                else
                {

                    for (int j = size; j > 0; j--)
                        arr[j] = arr[j - 1];
                    arr[0] = 1;
                    size++;
                    i++;
                }
            }
        }
    }

    BigInt &operator--()
    {
        return --num;

        for (int i = 0; i < size; i++)
        {
            if (arr[size - 1] == 9)
            {
                arr[size - 1] = 0;
                --arr[size - 2];
            }
            arr[i]--;
        }
        return *this;
    }
};
int main()
{
    string integer;
    cout << "Enter integer: ";
    cin >> integer;

    BigInt b1(integer);
    BigInt b2 = ++b1;
    BigInt b3 = --b1;

    cout << "Original : ";
    b1.display();
    cout << endl;

    cout << "Pre Increment : ";
    b2.display();
    cout << endl;

    cout << "Pre Decrement : ";
    b3.display();
    cout << endl;
    return 0;
}
