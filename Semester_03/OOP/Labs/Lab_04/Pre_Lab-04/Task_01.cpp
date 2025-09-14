#include <iostream>
#include <vector>

using namespace std;

//Array Updating
void updateArray();

int main()
{
    updateArray();
    return 0;
}

void updateArray()
{
    int size;
    int num;
    int index;

    cout << ("Enter the size of array: ");
    cin >> size;
    vector<int> arr(size);
    cout << "Enter " << size << " numbers in array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Original Array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    char terminate;

    do
    {
        cout << "\nEnter a number that you want to update: ";
        cin >> num;

        cout << "Enter index/position of the array: ";
        cin >> index;

        if (index < 0 || index >= size)
        {
            cout << "Invalid position" << endl;
        }
        else
        {
            arr[index] = num;
        }
        // cin.clear();
        // cin.ignore();
        cout << "Press * to terminate program" << endl;
        cin >> terminate;

    } while (terminate != '*');

    cout << "\nUpdated Array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
