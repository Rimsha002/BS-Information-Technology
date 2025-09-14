#include <iostream>
using namespace std;

void rowMajorND(int dimensions)
{
    cout << "Row major index mapping: ";
    for (int i = 1; i <= dimensions; i++)
    {
        cout << "i" << i;
        for (int j = i + 1; j <= dimensions; j++)
        {
            cout << " D" << j;
        }
        if (i < dimensions)
            cout << " + ";
    }
    cout << endl;
}

int main()
{
    rowMajorND(3);
    return 0;
}
