#include<iostream>

using namespace std;

int main() {

	int arr[5] = { 1,2,3,4,5 };
	cout << "Enter the number to check the occurence : ";
	int num;
	cin >> num;

	for (int i = 0; i < 5; i++){
		if (arr[i] == num)
		{
			cout << "Number " << num << " found at index  " << i << endl;
			return 0;
		}
	}
	cout << "Number " << num << " not found" << endl;

}
