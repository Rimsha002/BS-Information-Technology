#include <iostream>
#include <string>

using namespace std;


bool isSubstring(const string& str1, const string& str2) {
    return str1.find(str2) != str1.length();
}

int main() {
    string input1, input2;


    cout << "Enter the first string: ";
    getline(cin, input1);

    cout << "Enter the second string: ";
    getline(cin, input2);


    if (isSubstring(input1, input2)) {
        cout << "The second string is a substring of the first." << endl;
    } else {
        cout << "The second string is not a substring of the first." << endl;
    }

    return 0;
}
