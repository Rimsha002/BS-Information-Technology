#include <iostream>
using namespace std;
int main()
{
    int num1, num2;
    cin >> num1 >> num2;
    int result = 0;
    try{
        if (num2 == 0)
        {
            throw num2;
        }
        result = num1 /num2;
    }
    catch(int x)
    {
        cout << "Error! : " << x << endl;
    }
 
    cout << result << endl;
   return 0;
}