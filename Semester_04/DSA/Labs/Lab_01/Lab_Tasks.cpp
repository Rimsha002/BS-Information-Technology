#include <iostream>
using namespace std;

static int counts = 0;

int fnLinearSearch(int Array[], unsigned int Size, int SearchKey);
int fnBinarySearch(int Array[], unsigned int Size, int SearchKey);
void fnBubbleSort(int Array[], unsigned int Size, int SortKey);
void fnSelectionSort(int arr[], unsigned int Size, int key);

int main()
{
    int arr[] = {4, 6, 2, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key = 10;
    cout << "Array is : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Functions
    // Linear Search
    // int index = fnLinearSearch(arr, size, key);
    // cout << "Key present at index: " << index << endl;
    // cout << "Instructions Executed: " << counts << endl;

    // int index = fnBinarySearch(arr, size, key);
    // cout << "Key present at index: " << index << endl;
    // cout << "Instructions Executed in Binary Search: " << counts << endl;

    // fnBubbleSort(arr, size, 0);
    // cout << "Instructions Executed: " << counts << endl;
    // cout << "Sorted Array is : ";
    // for (int i = 0; i < size; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    return 0;
}

// Functions

int fnLinearSearch(int arr[], unsigned int Size, int key)
{
    counts = 0;

    counts += 1;
    for (int i = 0; i < Size; i++)
    {
        counts = counts + 2;
        if (arr[i] == key)
        {
            counts++;
            return i;
        }
        counts += 2; // 1 for if and 1 for moving to next ireration
    }

    counts++;
    return -1;
}

int fnBinarySearch(int arr[], unsigned int Size, int key)
{
    counts = 0;
    // Sort the array
    counts += 1;
    for (int i = 0; i < Size - 1; i++)
    {
        counts += 2;
        counts++;
        for (int j = 0; j < Size - i - 1; j++)
        {
            counts += 2;
            if (arr[j] > arr[j + 1])
            {
                counts++; // taking decision
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                counts += 3;
            }
            counts += 2;
        }
    }

    int min = 0;
    int max = Size - 1;
    counts += 2;

    while (min <= max)
    {
        counts++;
        int index = (max + min) / 2;
        counts += 1; // 1 for index
        if (key == arr[index])
        {
            counts += 3; // 1 for comparison and 1 for return 1 for decision
            return index;
        }
        else if (key < arr[index])
        {
            counts += 3; // 2 for if and 2 for elseif 1 for max ass.
            max = index - 1;
        }
        else
        {
            counts += 2;
            min = index + 1;
        }
        counts++; // 1 for while
    }

    counts++;
    return -1;
}

void fnBubbleSort(int arr[], unsigned int Size, int key)
{
    counts = 0;

    if (key == 0)
    {
        counts += 2;
        for (int i = 0; i < Size - 1; i++)
        {
            counts += 2;
            counts++;
            for (int j = 0; j < Size - i - 1; j++)
            {
                counts += 2;
                if (arr[j] > arr[j + 1])
                {
                    counts++; // 1 for branching = taking decision
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    counts += 3;
                }
                counts += 2; // 1 for if and 1 for next iter.
            }
        }
    }

    if (key == 1)
    {
        counts += 2;
        for (int i = 0; i < Size - 1; i++)
        {
            counts += 2;
            counts++;
            for (int j = 0; j < Size - i - 1; j++)
            {
                counts += 2;
                if (arr[j] < arr[j + 1])
                {
                    counts++; // 1 for branching = taking decision
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    counts += 3;
                }
                counts += 2;
            }
        }
    }
}

void fnSelectionSort(int arr[], unsigned int Size, int key)
{ for (unsigned int i = 0; i < Size - 1; i++) {
        int extremeIndex = i;

        // Ascending order (key == 0)
        if (key == 0) {
            for (unsigned int j = i + 1; j < Size; j++) {
                if (arr[j] < arr[extremeIndex]) {
                    extremeIndex = j;
                }
            }
        }
        // Descending order (key == 1)
        else if (key == 1) {
            for (unsigned int j = i + 1; j < Size; j++) {
                if (arr[j] > arr[extremeIndex]) {
                    extremeIndex = j;
                }
            }
        }
        swap(arr[i], arr[extremeIndex]);
    }
}

