#include <iostream>
using namespace std;

static int counts = 0;

int fnLinearSearch(int Array[], unsigned int Size, int SearchKey);
int fnBinarySearch(int Array[], unsigned int Size, int SearchKey);
void fnBubbleSort(int Array[], unsigned int Size, int SortKey);
void fnSelectionSort(int arr[], unsigned int Size, int key);

int main()
{
    int arr[] = {1,7,9,5,3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Array is : ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";}
    cout << endl;

    //Function Calling
    fnSelectionSort(arr, size, 1);

    cout << "Instructions Executed: " << counts << endl;
    cout << "Sorted Array is : ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";}
    cout << endl;

    return 0;
}

// Functions
void fnSelectionSort(int arr[], unsigned int Size, int key)
{ 
    counts++;
    for (int i = 0; i < Size - 1; i++) 
    {
        int extremeIndex = i;
        counts+=3;
        // Ascending order (key == 0)
        if (key == 0) 
        {
            counts+=3;
            for (int j = i + 1; j < Size; j++) {
                counts+=2;
                if (arr[j] < arr[extremeIndex]) {
                    counts+=2;
                    extremeIndex = j;
                    counts++;
                }
                counts++;
            }
        }
        // Descending order (key == 1)
        else if (key == 1) {
            counts+=3;
            for (int j = i + 1; j < Size; j++) {
                counts+=2;
                if (arr[j] > arr[extremeIndex]) {
                    counts+=2;
                    extremeIndex = j;
                    counts++;
                }
                counts++;
            }
        }
        swap(arr[i], arr[extremeIndex]);
        counts+=3;
    }
}

