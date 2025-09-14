#include <iostream>
using namespace std;
void printFrequency( int arr[],  int size) {
     int MAX_SIZE = 1000;  

   
    int frequency[MAX_SIZE] = {0};

    
    for (int i = 0; i < size; ++i) {
        frequency[arr[i]]++;
    }

    
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (frequency[i] > 0) {
            cout << i << " has occurred " << frequency[i] << " times\n";
        }
    }
}

int main() {
    int inputArray[] = {15, 0, 5, 20, 5, 1, 0, 2, 5, 15};
    int arraySize = sizeof(inputArray) / sizeof(inputArray[0]);

    
    printFrequency(inputArray, arraySize);

    return 0;
}
