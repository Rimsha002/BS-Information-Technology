#include <iostream>
#include <ctime>
#include<chrono>

using namespace std;

void bubbleSort(int arr[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false; 
        for (int j = 0; j < n - i - 1; j++)
        { 
            if (arr[j] > arr[j+1]) 
            {
                swap(arr[j], arr[j+1]);
                swapped = true; 
            }
        }
        
        if (!swapped) {
            break;
        }
    }
}

int main() {    

    // Get the current time, based on system
    time_t now = time(0);
    //This Structre will help you to use info like hours, minutes and seconds!!
    struct tm* First = localtime(&now);
    
    //Your Funcion Call Here
    int nums [] = {5, 4, 3, 1, 2};
    bubbleSort(nums, 5);
    for(int i:nums)
        cout<<i<<" ";
    cout<<endl;
    

    // Get the current time again after executing functions!
    now = time(0);
    struct tm* Second = localtime(&now);

    // Compute the difference and display as following
    cout << "The First time is: " << First-> tm_hour << ":" << First -> tm_min << ":" << First -> tm_sec << "." << First -> tm_sec << endl;
    cout << "The Second time is: " << Second -> tm_hour << ":" << Second -> tm_min << ":" << Second -> tm_sec << "." << Second -> tm_sec << endl;

    //Calucuating difference b/w time
    cout << "Time taken in executing function is: " << Second -> tm_sec - First -> tm_sec<< " Second(s)" <<endl <<endl;
    
    return 0;
}

