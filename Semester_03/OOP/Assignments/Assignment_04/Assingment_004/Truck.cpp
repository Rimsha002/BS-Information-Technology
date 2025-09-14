#include <iostream>
//#include "Vehicle.h"
#include "Truck.h"
using namespace std;


//Truck::Truck(string make, string model, int year, double price, string size) : Vehicle(make, model, year, price), bedSize(size){}

void Truck::display_info()
{
	cout << "Make: " << make << endl;		
	cout << "Model: " << model << endl;
	cout << "Year: " << year << endl;
	cout << "Price: " << price << endl;
	cout << "Bed size: " << bedSize << endl;
}	

