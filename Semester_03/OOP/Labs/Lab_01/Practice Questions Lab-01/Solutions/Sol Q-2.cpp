#include<iostream>

using namespace std;

int main() {

	int arr[] = {1 ,4, 3,5,6,7,8,9,7,6,5};
	int size = sizeof(arr) / sizeof(arr[0]);
	
	int  sum = 0;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
		count++;
	}
	cout << "Total number of elements in array  is :  " << count << endl;

	cout << "Total sum of array is :  " << sum <<endl;

}
