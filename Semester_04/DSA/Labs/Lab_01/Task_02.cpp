#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

int fnLinearSearch(int arr[], unsigned int Size, int key)
{
    for (int i = 0; i < Size; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int fnBinarySearch(int arr[], unsigned int Size, int key)
{ for (int i = 0; i < Size - 1; i++) {
        for (int j = 0; j < Size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int min = 0;
    int max = Size - 1;

    while (min <= max)
    {
        int index = (max + min) / 2;
        if (key == arr[index])
        {
            return index;
        }
        else if (key < arr[index])
        {
            max = index - 1;
        }
        else
        {
            min = index + 1;
        }
    }

    return -1;
}

void fnBubbleSort(int arr[], unsigned int Size, int key)
{
    if (key == 0)
    {
        for (int i = 0; i < Size - 1; i++)
        {
            for (int j = 0; j < Size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    if (key == 1)
    {
        for (int i = 0; i < Size - 1; i++)
        {
            for (int j = 0; j < Size - i - 1; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
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

int main()
{
    // Your function to be measured
    int nums[] = {1, 4, 5, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);
    int key = 3;
    int index;

    // Get the current time  before execution
    auto start = high_resolution_clock::now();

    // Linear Function
    index = fnLinearSearch(nums, size, key);
    cout << key << " found at index " << index << endl;

    // Binary Function
    // index = fnBinarySearch(nums, size, key);
    // cout << key << " found at index " << index << endl;

    // Bubble Function
    // fnBubbleSort(nums, size, 0);

    // Selection Function
    // fnSelectionSort(nums, size, 0);

    // cout << "Sorted Array is: " << endl;
    // for (int i : nums)
    //     cout << i << " ";
    // cout << endl;

    // Get the current time  after execution
    auto end = high_resolution_clock::now();

    // Calculate the duration in microseconds
    auto duration = duration_cast<microseconds>(end - start).count();

    cout << "Time taken to execute function is: " << duration << " microsecond(s)" << endl;

    return 0;
}
