#include <iostream>
#include <cctype> 

using namespace std;

bool areAnagrams(const string &str1, const string &str2) {
    if (str1.length() != str2.length()) {
        return false; 
    }

    int charCount[26] = {0}; 
        for (char c : str1) {
        charCount[tolower(c) - 'a']++; 
    }

    for (char c : str2) {
        charCount[tolower(c) - 'a']--; 
    }

    for (int count : charCount) {
        if (count != 0) {
            return false; 
        }
    }

    return true; 
}

int main() {
    string str1 = "Gram";
    string str2 = "mgra";

    if (areAnagrams(str1, str2)) {
        cout << "The given strings are anagrams." << endl;
    } else {
        cout << "The given strings are not anagrams." << endl;
    }

    return 0;
}
