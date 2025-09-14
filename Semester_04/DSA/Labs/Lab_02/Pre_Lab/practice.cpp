#include <iostream>
using namespace std;

int incAndDec(int n)
{
   if(n <= 0)
   return 0;
   cout << n << endl;
   incAndDec(n-1);
   cout << n << endl;
}

 void fun(int N)
{
    if(N  <= 1 )
    return;
    
    fun(N-1);
    
    fun(N-1);
    cout << N << " ";
}

string reverse(string s, int len)
{
   if (len == 0)
   {
      return string(1, s[0]);
   }
   else
   {
   return s[len] + reverse(s, len-1);
   }
}

int main()
{
    // fun(3);
   //  string s;
   //  cout << "Enter the string: ";
   //       getline(cin, s);
   //       int len = s.length();
   //       string result = reverse(s, len);
   //      cout << "Reversed string: " << result << endl;

   incAndDec(4);
   return 0;
}

