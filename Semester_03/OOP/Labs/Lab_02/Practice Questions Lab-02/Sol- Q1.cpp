#include <iostream>
using namespace std;

int main()
{
    const int size = 5;
    int array[size];
    cout << "Enter " << size << " Elements of array:";

    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }

    int firstMax = INT_MIN;
    int secondMax = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (array[i] > firstMax)
        {
            secondMax = firstMax;
            firstMax = array[i];
        }
        else if (array[i] < firstMax && array[i] > secondMax)
        {
            secondMax = array[i];
        }
    }
    if (secondMax == INT_MIN)
    {
        cout << "Second max Element = " << firstMax << endl;
    }
    else
    {

        cout << "Second max Element = " << secondMax << endl;
    }
    return 0;
}
