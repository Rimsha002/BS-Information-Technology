#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int binomial(int n, int m);
int squares_sum(int n);
int gcd(int num1, int num2);
void func(string s, int n);
void rectangularPattern(int rows);


int main()
{
    
//Task 01
cout << binomial(8, 4);

//Task -2
// cout << "Enter the number : ";
// int num;
// cin >> num;
// cout << "Output: " << squares_sum(num);

//Task 03
// int result = gcd(-20 , -30);
// cout << result;

//Task 04
//  func("", 3);
// cout << result;



//Task 05
// cout << "Enter number of rows for pattern: ";
// int rows;
// cin >> rows;
// rectangularPattern(rows);


   return 0;
}


//Task 01
int binomial(int n, int m)
{
if (n == m || m == 0)
return 1;
else
return binomial(n - 1, m) + binomial(n - 1, m - 1);
}

//Task02
static int result = 0;
int squares_sum(int num)
{
    if(num <= 0)
    {
        return -1;
    }
    int p = num * num;
    result = result + p;
    squares_sum(num - 1);
    return result;

}

//Task 03
int gcd(int num1, int num2)
{
    if(num2 == 0)
    {
        return num1;
    }
    return gcd(num2, num1 % num2);

}

//Task 04
void func(string s, int n)
{
    if(n == 0)
    {
        cout << s;
    }
    func(s + "0", n - 1);
    func(s + "1", n - 1);
    return;
}

//Task_05
void rectangularPattern(int rows )
{
    if(rows <= 0)
    {
        return;
    }
   for (int i = 1; i <= rows; i++ )
   {
    cout << "*";
   }
   cout << endl;

    rectangularPattern(rows - 1);
}