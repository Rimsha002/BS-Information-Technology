#include <iostream>
using namespace std;

int maxSubArraySumBruteForce(int arr[], int n);
int maxSubArraySumKadane(int arr[], int n);

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum subarray sum using Brute Force: " << maxSubArraySumBruteForce(arr, n) << endl;
    cout << "Maximum subarray sum using Kadane's Algorithm: " << maxSubArraySumKadane(arr, n) << endl;

    // Result:
    // Kadane's Algorithm is more efficient than Brute Force Algorithm

    return 0;
}

int maxSubArraySumBruteForce(int arr[], int n)
{
    int maxSum = -1000000;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int currentSum = 0;
            for (int k = i; k <= j; k++)
            {
                currentSum += arr[k];
            }
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
            }
        }
    }
    return maxSum;
}

int maxSubArraySumKadane(int arr[], int n)
{
    int maxSum = -1000000;
    int currentSum = 0;

    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
        }
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    return maxSum;
}