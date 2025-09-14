#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    string str;
    str = "Hello Rimsha!";

    ofstream out("file-Sample.txt"); // Create file and give it name out.
    out << str;                      // To write on file(assume it screen)
    out.close();

    ifstream in("file-Sample.txt");
    string str2;
    if (in.fail()) // if file not found
    {
        cout << "File not found!";
        return 0;
    }
    else
    {
        cout << "File found!";
    }
    
    getline(in, str2); // read and store in str2;
    cout << str2;
    in.close();
    // console str2

    return 0;
}
