#include <iostream>
#include <string>
#include "frontEnd.h"
using namespace std;

int main()
{

int price = displayList();

int amount;
cout << "\n \n Now, Enter Amount in $ you paid: ";
cin >> amount;

if(amount < price )
{
    cout << "Your Price is low" << endl;
}
else if (amount > price)
{
    int returnAmount = amount - price;
    cout << "Your extra amount :" << returnAmount;
}
else{
    cout << "----Congtratualtion ! ";
    displayData();

    cout << "\n \n IS ALLOTED YOU ";
}


    return 0;
}

