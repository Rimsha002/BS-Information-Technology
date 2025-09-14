#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void loadData(ifstream &in);

int main()
{

   ifstream infile("Data.txt");
   loadData(infile);

   return 0;
}

void loadData(ifstream &in)
{
   string str;
   vector<string> str2;

   while (!in == EOF)
   {
      getline(in, str);
      str2.push_back(str);
   }

   cout << "Your Data in file is ";

   for (int i = 0; i < str2.size(); i++)
   {
      cout << str2[i];
   }

   cout << "Enter new data " << endl;
   int currentsize = str2.size();

   while (! str2[currentsize] == '\n')
   {
      getline(cin, str2[currentsize]);
      currentsize++;
   }

   void NewData(ofstream & out, string str)
   {
      // out.app(str);
   }