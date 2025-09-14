#include <iostream>

using namespace std;
int main()
{

   int character; 

   cout << "eof character before is: " << cin.eof();

   cout << "\nEnter a sentence followed by Enter and EOF:\n";
   // EOF = ctrl+z + Enter (in windows)

   while ((character = cin.get()) != EOF)
   {
      cout.put(character);
   }

   cout << "\nEOF character after is: " << character;
   cout << "\neof character After is: " << cin.eof() << endl;
   return 0;
}