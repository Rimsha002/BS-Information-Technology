#include <iostream>

using namespace std;

int* reverseArray(int arr[], int size) {
    int* reversedArray = new int[size];
    int j = size-1;
    for (int i = 0; i < size; ++i) {

        reversedArray[i] = arr[j];
        j--;
    }

    return reversedArray;
}

int main() {
    
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int* reversedArr = reverseArray(arr, size);

    cout << "Reversed Array: ";
    for (int i = 0; i < size; i++) {
        cout << reversedArr[i] << " ";
    }
    cout << endl;

   
    delete[] reversedArr;

    return 0;
}