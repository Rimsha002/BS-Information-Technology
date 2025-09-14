#include <iostream>
using namespace std;
int main()
{
    //Find occurance of characters in ascending order
    int count;
    int ascii;

    const int size = 265;
    char arr[size] = {0};
    string str;
    cout <<"Enter a string: ";
    getline(cin, str);

    for(int i = 0; i < str.length() ;i++)
    {
     arr[i] = str[i];
    }

    // count by using it's ascii and show only 1 character 1 time 


    for(int i = 0; i < str.length(); i++)
    {
    ascii = str[i];
    for(int j = 0; j < str.length(); j++)
    {
        if(ascii == arr[j])
        {
            count++;
        }
       arr[ascii] = count;
        
    }
    for(int i = 0; i < str.length(); i++)
    {
        if(arr[i] != 0)
        {
            cout << char(i) << ": " << arr[i] << endl;
        }
    }
    }


   return 0;
}