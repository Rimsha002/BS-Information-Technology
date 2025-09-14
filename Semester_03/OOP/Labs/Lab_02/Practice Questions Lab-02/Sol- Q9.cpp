#include <iostream>
#include <cctype>
//The <cctype> header in C++ provides functions that are used for character classification.
// These functions are particularly useful for checking the type of characters,
// such as whether a character is a digit, lowercase letter, uppercase letter, etc.

void countCharacters(const string str) {
    int numbers = 0, lowerCase = 0, upperCase = 0, specialCharacters = 0;

    for (char ch : str) {
        if (isdigit(ch)) {
            numbers++;
        } else if (islower(ch)) {
            lowerCase++;
        } else if (isupper(ch)) {
            upperCase++;
        } else {
            specialCharacters++;
        }
    }


cout << "Numbers: " << numbers << "\n";
    cout << "Lowercase characters: " << lowerCase << "\n";
    cout << "Uppercase characters: " << upperCase << "\n";
    cout << "Special characters: " << specialCharacters << "\n";
}

int main() {
    string input;
    
    
    cout << "Enter a string: ";
    getline(cin, input);

  
    countCharacters(input);

    return 0;
}
