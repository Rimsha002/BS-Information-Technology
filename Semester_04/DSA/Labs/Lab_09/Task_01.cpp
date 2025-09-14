#include <iostream>
#include <vector>
using namespace std;

/*
int search(vector<int> &arr, int target)
{
    int size = arr.size();
    if (size <= 0)
    {
        return -1;
    }

    int min = 0;
    int max = size - 1;
    int index = size / 2;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            max = i;
            break;
        }
    }

    while (min >= max)
    {
        if (target == arr[index])
        {
            cout << "Target found at index";
            return index;
        }
        if (target > arr[index])
        {
            min = index - 1;
        }
        if (target < arr[index])
        {
            min = index + 1;
        }
    }

    cout << "Target not found ";

    return -1;
}
*/

int search(vector<int> &arr, int target)
{
    
    int size = arr.size();
    if (size <= 0)
    {
        return -1;
    }

    int min = 0;
    int max = size - 1;
    int index = size / 2;

    if(target > arr[index])
    {
        
    }
}

int main()
{
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);

    int result = search(arr, 6);
    cout << result << endl;
    return 0;
}