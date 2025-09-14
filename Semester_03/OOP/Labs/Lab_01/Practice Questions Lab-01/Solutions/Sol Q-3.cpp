#include <iostream>

using namespace std;



int main() {
      int arr[] = { 5, 2, 9, 1, 7, 3 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int largest, smallest;
    largest = smallest = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
        else if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    cout << "Largest number in the array: " << largest << endl;
    cout << "Smallest number in the array: " << smallest << endl;

    return 0;
}