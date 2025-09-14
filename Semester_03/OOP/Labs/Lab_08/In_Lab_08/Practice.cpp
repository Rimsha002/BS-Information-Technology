#include <iostream>
using namespace std;

int main() {
    ////Peak : read but still pointing on same stream in mamory
    // char nextChar = cin.peek(); // Peeks at the next character in the input stream
    // cout << "Next character in the input stream: " << nextChar << endl;


/////Putback : put back the character in back of the stream
    //  char firstChar, secondChar;
    // cin >> firstChar; // Read a character from input stream
    // cin.putback(firstChar); // Put the character back into input stream
    // cin >> secondChar; // Read the character again
    // cout << "First character read: " << firstChar << endl;
    // cout << "Second character read: " << secondChar << endl;

 // get, put and eof member functions. #include <iostream> using namespace std;


     int character; // use int, because char cannot represent EOF

     // prompt user to enter line of text
     cout << "Before input eof() is " << cin.eof() << "\nEnter a sentence followed by Enter and end-of-file:\n";

     // use get to read each character; use put to display it
     while ((character = cin.get()) != EOF) {
         cout.put(character);
     }
    // For EOF enter ctrl+z + Enter in windows
     // display end-of-file character
     cout << "\nEOF in this system is: " << character
          << "\nAfter input of EOF, cin.eof() is " << cin.eof() << endl;
 
    return 0;
}