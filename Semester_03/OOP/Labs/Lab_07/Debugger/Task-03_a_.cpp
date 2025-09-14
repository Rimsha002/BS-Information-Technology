#include <iostream>
using namespace std;
int main()
{
    int x = 0;
    int ans =0 ;
    int product = 1;
    while( x <= 2)
    {
        if (ans % 2 == 0)
        {
            cout << "Answer: " << ans << endl;
        }
        product *= ans;
        ans += 3;
        x++;
        cout << "Iteration complete "<< endl;
    }
   return 0;
}