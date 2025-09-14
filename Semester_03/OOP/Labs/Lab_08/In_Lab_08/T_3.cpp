#include <iostream>
using namespace std;
int main()
{
    //Find occurance of characters in ascending order
    int count;
    const int size = 265;
    char arr[size];
    string str;
    cout <<"Enter a string: ";
    getline(cin, str);

    for(int i = 0; i < str.length() ;i++)
    {
     arr[i] = str[i];
    }

    for(int i = 0; i < str.length(); i++)
    {
        if(arr[i] == '\0')
        {
            break;
        }
        count = 0;
        for(int j = 0; j < str.length(); j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }
        cout.put(arr[i]) << ": ";
        cout<< count << endl;
    }

   return 0;
}