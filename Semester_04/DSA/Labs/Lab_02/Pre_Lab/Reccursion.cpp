#include <iostream>
#include <string>
using namespace std;

// Functions Declaration
int search(int *arr, int element, int array_size);
int pow(int number, int power);
int number_of_digits(int number);
string reverse(string s, int len);
int binary_search(int *arr, int left, int right, int target);
int binary_search(int *arr, int size, int target);

int main()
{
   int check = 1;
   do
   {
      // Menu
      cout << endl;
      cout << "1. Search an element in an array" << endl;
      cout << "2. Power of a number" << endl;
      cout << "3. Number of digits in a number" << endl;
      cout << "4. Reverse a string" << endl;
      cout << "5. Binary Search" << endl;
      cout << "6. Binary Search by triming array" << endl;
      cout << "7. Exit" << endl;

      cout << "Enter your choice: ";
      int choice;
      cin >> choice;
      switch (choice)
      {
      case 1:
      { // Search an element in an array
         int arr[] = {2, 4, 6, 8, 10};
         int size = sizeof(arr) / sizeof(arr[0]);
         cout << "Array is: ";
         for (int i = 0; i < size; i++)
         {
            cout << arr[i] << " ";
         }
         cout << endl;
         cout << "Enter the element to search: ";
         int element;
         cin >> element;
         int result = search(arr, element, size);
         if (result == -1)
         {
            cout << "Element not found" << endl;
         }
         else
         {
            cout << "Element found at index: " << result << endl;
         }
         break;
      }

      case 2:
      { // Power of a number
         int number;
         int power;
         cout << "Enter the number: ";
         cin >> number;
         cout << "Enter the power: ";
         cin >> power;
         int result = pow(number, power);
         cout << "Result: " << result << endl;
         break;
      }

      case 3:
      { // Number of digits in a number
         int number;
         cout << "Enter the number: ";
         cin >> number;
         int result = number_of_digits(number);
         cout << "Number of digits: " << result << endl;
         break;
      }

      case 4:
      { // Reverse a string
         string s;
         cout << "Enter the string: ";
         cin.ignore();
         getline(cin, s);
         int len = s.length();
         string result = reverse(s, len);
         cout << "Reversed string: " << result << endl;
         break;
      }

      case 5:
      { // Binary Search
         int arr[] = {2, 4, 6, 8, 10};
        cout << "Array is: ";
         for (int i = 0; i < 5; i++)
         {
            cout << arr[i] << " ";
         }
         cout << endl;
         int size = sizeof(arr) / sizeof(arr[0]);
         int target;
         cout << "Enter the element to search: ";
         cin >> target;
         int result = binary_search(arr, 0, size - 1, target);
         if (result == -1)
         {
            cout << "Element not found" << endl;
         }
         else
         {
            cout << "Element found at index: " << result << endl;
         }
         break;
      }

      case 6:
      { // Binary Search by triming array
         int arr[] = {1, 2, 3, 4, 5};
         int size = sizeof(arr) / sizeof(arr[0]);
         cout << "Array is: ";
         for (int i = 0; i < size; i++)
         {
            cout << arr[i] << " ";
         } cout << endl;

         int target;
         cout << "Enter the element to search: ";
         cin >> target;

         int result = binary_search(arr, size, target);

         if (result == -1)
         {
            cout << "Element not found" << endl;
         }
         else
         {
            cout << "Element found at index: " << result << endl;
         }
         break;
      }

      case 7:
      { // Exit
         cout << "Exiting..." << endl;
         check = 0;
         break;
      }

      default:
      {
         cout << "Invalid choice" << endl;
         break;
      }
         return 0;
      }
   } while (check == 1);

   return 0;
}

// Functions Definition
int search(int *arr, int element, int size)
{
   if (size == 0)
   {
      return -1;
   }
   else if (arr[size - 1] == element)
   {
      return size - 1;
   }
   else
      return search(arr, element, size - 1);
}

// Power Function
int pow(int number, int power)
{
   if (power == 0)
   {
      return 1;
   }
   else
   {
      return number * pow(number, power - 1);
   }
}

// Number of Digits Function
static int counts = 0;
int number_of_digits(int number)
{
   counts = 0;
   if (number <= 0)
      return -1;
   else
   {
      number = number / 10;
      counts++;
      number_of_digits(number);
   }
   return counts;
}

// Reverse a String Function
string reverse(string s, int len)
{
   if (len == 0)
   {
      return string(1, s[0]);
   }
   else
   {
   return s[len] + reverse(s, len-1);
   }
}

int binary_search(int *arr, int left, int right, int target)
{
   int index = left + (right - left) / 2;
   if (left >= right)
   {
      return -1;
   }
   else if (arr[index] == target)
   {
      return index;
   }
   else
   {
      if (arr[index] > target)
         return binary_search(arr, left, index - 1, target);

      else
      {
         return binary_search(arr, index + 1, right, target);
      }
   }
}

int binary_search(int *arr, int size, int target)
{
   int index = size / 2;
   if (size <= 0)
   {
      return -1;
   }
   else if (arr[index] == target)
   {
      return index;
   }
   else
   {
      if (arr[index] > target)
      {
         size = index;
         return binary_search(arr, size, target);
      }
      else
      {
         // arr = &arr[index];
         // return binary_search(arr, size, target);
         return binary_search(arr + index + 1, size - index - 1, target);
      }

   }
}