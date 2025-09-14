#include <iostream>
#include <algorithm>

using namespace std;
// Integar Class

class Integer
{
private:
    int *arr;
    int size;

public:
    Integer(int s, int *arr)
    {
        this->size = s;
        for (int i = 0; i < size; i++)
        {
            this->arr[i] = arr[i];
        }
    }

    friend int largest(Integer largest);
    friend int Smallest(Integer samllest);
    friend int Sort(Integer sor);
    friend int Repeat(Integer repeat);

    ~Integer()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
};

int largest(Integer largest)
{
    int large = largest.arr[0];
    for (int i = 0; i < largest.size; i++)
    {
        if (largest.arr[i] > large)
        {
            large = largest.arr[i];
        }
    }
    cout << "Largest integer in Array is : " << large << endl;
}

int Smallest(Integer smallest)
{
    int small = smallest.arr[0];
    for (int i = 0; i < smallest.size; i++)
    {
        if (smallest.arr[i] < small)
        {
            small = smallest.arr[i];
        }
    }
    cout << "Smallest integer in Array is : " << small << endl;
}
int Repeat(Integer repeat)
{
    int s = repeat.size;
    int r;
    for (int i = 0; i < repeat.size; i++)
    {
        for (int j = i+1; j < repeat.size; j++)
        {
            if (repeat.arr[i] == repeat.arr[j])
            {
                r = repeat.arr[i];
                cout << r << " is repeated." << endl;
            }
        }
    }
}
int Sort(Integer sor)
{
    // int *arr2 = new int(sor.size);
    //sort arrat


    sort.sor.arr(sor.arr.begin(), sor.arr.end());


    // cout << "Sorted Array is: " << endl;
    // for (int i = 0; i < sort.size; i++)
    // {
    //     cout << arr2[i] << endl;
    // }
}
int main()
{
    int size;
    int element;
    int *arr = new int(size);

    cout << "Enter the size of Array: ";
    cin >> size;
    cout << "Enter the Elements of Array: ";
    
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i] ;
    }

    Integer integer(size, arr);
    largest(integer);
    Smallest(integer);

   // Sort(integer);
   Repeat(integer);

    return 0;
}