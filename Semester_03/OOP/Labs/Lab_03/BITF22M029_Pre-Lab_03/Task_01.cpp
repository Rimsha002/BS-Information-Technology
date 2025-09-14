#include <iostream>

using namespace std;

void makeData( int [], int);
void display(int [], int);
void getElement(int [], int, int);
void countEven(int[], int);
void countOdd(int[], int);
bool removeFirst(int[], int, int);
int * dropSmallest(int[], int);

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];
    //Array Filled
    makeData(arr, size);

    //Display Array
    display(arr,size);
    //Find Index Element
    int index;
    cout << endl;
    cout << "Enter the index of the element you want to get: ";
    cin>>index;
    getElement(arr, size,index);

    //Count Even
    countEven(arr, size);

    //Count Odd
    countOdd(arr, size);

    //Remove First
     int key;
    cout << endl;
    cout << "Enter the key you want to remove: ";
    cin>>key;
    if(removeFirst(arr, size, key)) {
        cout << "Removal is Successful" << endl;
    } else {
        cout << "Key not Found" << endl;
    }

    //Drop Smallest
    dropSmallest(arr, size);



    return 0;
}


//Function Definitions and Declarations

//Enter Data in Array
void makeData(int arr[], int size) 
{
    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter the value for the " << i + 1 << " element: ";
        cin >> arr[i];
    }
}
//Display Data
void display(int arr[], int size) 
{
    cout << endl ;

    for (int i = 0; i < size; i++) {
        cout << "The value of the " << i + 1 << " element is: " << arr[i] << endl;
    }
}

void getElement(int arr[], int size, int index) 
{
    while(index > size) {
        cout << "Index out of range, Enter again" << endl;
        cin >> index;
        
    }
    cout << "The value at " << index << " index is: " << arr[index] << endl;
}

//Count Even
void countEven(int arr[], int size)
 {
    int count = 0;
    cout << endl;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    cout << "The number of even elements in the array is: " << count << endl;
}

//Count ODD
void countOdd(int arr[], int size) 
{
    int count = 0;
    cout << endl;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {
            count++;
        }
    }
    cout << "The number of odd elements in the array is: " << count << endl;
}

//Remove
bool removeFirst(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
        
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            return true;
        }
    }

    return false; 
}
    
//Drop Smallest

int * dropSmallest(int arr[], int size) {
    static int newArr[50]; 
    int size2 = 0; 
    int mini = 0; 

    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[mini]) {
            mini = i; 
        }
    }

    for (int i = 0; i < size; i++) {
        if (i != mini) {
            newArr[size2] = arr[i];
            size2++;
        }
    }

    
    cout << "\nNew array after dropping the smallest element is: " << endl;
    for (int i = 0; i < size2; i++) {
        cout << newArr[i] << endl;
    }

    return newArr; 
}
