#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Addition
{
    vector<int> First_num;
    vector<int> Second_num;
    vector<int> binarySum;

public:
    Addition()
    {
        First_num.resize(32);
        Second_num.resize(32);
        binarySum.resize(32);
    }
    void input(int first, int second)
    {
        /// For First number
        int r1 = 0;
        int i = 31;
        while (first != 0)
        {
            r1 = first % 2;
            first = first / 2;

            First_num[i] = (r1);
            if (i >= 0)
            {
                i--;
            }
        }
        First_num[i] = first;

        cout << "First number is: \n";
        for (int j = 0; j <= 31; j++)
        {
            cout << First_num[j];
        }
        cout << endl;

        /// For Second Number

        int r2 = 0;
        int k = 31;

        while (second != 0)
        {
            r2 = second % 2;
            second = second / 2;

            Second_num[k] = r2;
            if (k >= 0)
            {
                k--;
            }
        }
        Second_num[k] = second;

        cout << "Second Number is: \n";
        for (int j = 0; j <= 31; j++)
        {
            cout << Second_num[j];
        }
        cout << endl;
    }

    // Get Sum
    vector<int> getSum()
    {
        int carry = 0;
        int sum = 0;

        for (int i = 31; i >= 0; i--)
        {
            sum = (First_num[i] ^ Second_num[i] ^ carry);
            binarySum[i] = sum;
            carry = (First_num[i] & Second_num[i]) | (Second_num[i] & carry) | (First_num[i] & carry);
        }

        return binarySum;
    }
};

int main()
{
    Addition addition;
    int first, second;
    cout << "Enter First number:";
    cin >> first;
    cout << "Enter second number:";
    cin >> second;
    addition.input(first, second);

    vector<int> sum;
    sum = addition.getSum();
    cout << "Binary Sum is: \n";
    for (int j = 0; j <= 31; j++)
    {
        cout << sum[j];
    }

    return 0;
}
