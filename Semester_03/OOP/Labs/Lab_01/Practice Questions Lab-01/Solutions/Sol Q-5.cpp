#include <iostream>

using namespace std;

int findArraySum( int arr[], int size) {
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    return sum;
}

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the " << i + 1 << " element : ";
        cin >> arr[i];
    }
  
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = findArraySum(arr, size);

    cout << "Sum of the array: " << sum << endl;

    return 0;
}
//sample input:1 2 3 4 5 
//sample output :20