#include <iostream>
#include <string>

using namespace std;


void calculateAndDisplayLength(const string& sentence) {
    cout << "Length of the sentence: " << sentence.length() << " characters\n";
}


void reverseAndDisplay(const string& sentence) {
    string reversedString;


    for (int i = sentence.length() - 1; i >= 0; --i) {
        reversedString.push_back(sentence[i]);
    }

    cout << "Reversed sentence: " << reversedString << "\n";
}

int main() {

    cout << "Enter a sentence: ";
    string input;
    getline(cin, input);


    calculateAndDisplayLength(input);

   
    reverseAndDisplay(input);

    return 0;
}
