#include <iostream>
using namespace std;

void countBill(int);

int main()
{
    int unit;
    cout << "Enter consumed units: ";
    cin >> unit;
    countBill(unit);
    return 0;
}

void countBill(int units)
{
    int rangeStart = 0;
    int rangeEnd = 100;

    int rate = 25;
    int bill = 0;
while (units > rangeEnd)
{
    bill = bill + (rangeEnd - rangeStart) * rate;
    rangeStart = rangeEnd;
    rangeEnd += 50;
    rate += 5;
}

bill = bill + ((units - rangeStart) * rate);

    cout << "Bill is: Rs. " << bill;
}