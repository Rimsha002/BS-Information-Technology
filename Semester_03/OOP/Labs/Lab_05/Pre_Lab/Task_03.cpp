#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Recursion meet Vector
void insertSnt(vector<string> &snt, int);
void display(vector<string> &snt);

int main()
{
    int size;
    cout << "How many sentence you want to inserted? ";
    cin >> size;
    cout << "Enter " << size << " sentences in vector: ";

    vector<string> snt;

    insertSnt(snt, size);
    display(snt);

    return 0;
}

void insertSnt(vector<string> &snt, int size)
{

    if (size < 0)
    {
        return;
    }
    else
    {
        string sentence;

        getline(cin, sentence);
        snt.push_back(sentence);
        size--;
        insertSnt(snt, size);
    }
}
void display(vector<string> &snt)
{
    for (int i = 0; i <= snt.size(); i++)
    {
        cout << snt[i] << endl;
    }
}
