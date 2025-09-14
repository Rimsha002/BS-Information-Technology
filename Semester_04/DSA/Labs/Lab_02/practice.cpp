#include <iostream>
using namespace std;
int main()
{
    char s[10] = "BCSFall19";
    cout << (s + 3)[5] << endl;

    int *arr = new int[5]{1, 2, 3, 4, 5};
    cout << ((*(arr + 3)) + 2) << endl;

    int a = 10, b = ++a, c = b++;
    cout << a << " " << b << " " << c << endl;
    return 0;
}

int gcd(int num1, int num2)
{
    // int small = num1;
    // if(num2 < small)
    // {
    //     small = num2;
    // }
    // int comm = small / 2;
    // if(num1 % comm == 0 && num2 % comm == 0)
    // {
    //     return comm;
    // }
}
