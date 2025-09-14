#include <iostream>
//#include "Vehicle.h"
#include "Car.h"
using namespace std;

//Car::Car(string make, string model, int year, double price, int numDoors): Vehicle(make, model, year, price), numDoors(numDoors){}

void Car::display_info()
{
    cout << "Make: " << make << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
    cout << "Price: " << price << endl;
    cout << "Number of doors: " << numDoors << endl;
}

