#include <iostream>
using namespace std;
/*
Create a class Arrays, Attributes:
int * arrayOne;
int sizeOne;
int * arraysTwo;
int sizeTwo;
Pass values via parameterized constructor. It will have two functions:
 Intersection: Returns a new array which will have intersection of the member arrays;
 Union: Returns a new array which will have Union of the member arrays. Write Main function. Get result arrays, display them in main function
*/

class Arrays
{
private:
    int *arrOne;
    int size1;
    int *arrTwo;
    int size2;
    int *Result;
    int resultSize;

public:
    Arrays(int *arrayOne, int sizeOne, int *arrayTwo, int sizeTwo, int *result)
    {
        arrOne = arrayOne;
        arrTwo = arrayTwo;
        size1 = sizeOne;
        size2 = sizeTwo;
        Result = result;
        resultSize = 0;
    }

    void IntersectionArray(int rSize)
    {
        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                if (arrOne[i] == arrTwo[j])
                {
                    Result[rSize] = arrOne[i];
                    rSize++;
                }
            }
        }
        resultSize = rSize;
    }

    void UnionArray(int rSize)
    {
        for (int j = 0; j < size2; j++)
        {
            Result[rSize] = arrOne[i];
            rSize++;
        }

        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                if (arrOne[i] == arrTwo[j])
                {
                    Result[rSize] = arrOne[i];
                    rSize++;
                }
            }
        }
        resultSize = rSize;
    }

    int getterResultSize()
    {
        return resultSize;
    }
};

int main()
{
    // Dynamic 1st Array and its input
    int sizeOne;
    cout << " Enter size of 1st array: ";
    cin >> sizeOne;

    cout << " Enter array 1 elements: ";

    int *arrayOne = new int[sizeOne];
    for (int i = 0; i < sizeOne; i++)
    {
        cin >> arrayOne[i];
    }
    // Dynamic 2nd Array and it's input
    int sizeTwo;
    cout << " Enter size of 1st array: ";
    cin >> sizeTwo;

    cout << " Enter array 2 elements: ";

    int *arrayTwo = new int[sizeTwo];
    for (int i = 0; i < sizeTwo; i++)
    {
        cin >> arrayTwo[i];
    }

    // Result array size on heap
    int *resultSize = new int;
    *resultSize = 0;

    // Dynamic Result Array
    int *result = new int[*(resultSize)];

    // Parameterize Constructor
    Arrays array(arrayOne, sizeOne, arrayTwo, sizeTwo, result);

    // Intersection of arrays
    array.IntersectionArray(*resultSize);

    // To get final Result array Size
    int finalResultSize = array.getterResultSize();

    // Display Intersection Array
    cout << "\n Intersection Result Array is: { ";
    for (int i = 0; i < finalResultSize; i++)
    {
        cout << result[i] << " ";
    }
    cout << " }\n";

    return 0;
}