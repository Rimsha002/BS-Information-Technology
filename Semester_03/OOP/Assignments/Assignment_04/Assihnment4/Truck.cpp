#include <iostream>
#include "Truck.h"
using namespace std;

Truck::Truck()
{
	bedSize = 0;
}

Truck::Truck(string make, string model, int year, double price, int bedsize)
{
	this->make = make;
	this->model = model;
	this->year = year;
	this->price = price;
	this->bedSize = bedsize;
}

void Truck::display_info()
{
	cout << "Vehicle Type: Truck" << endl;
	cout << "Make: " << make << endl;
	cout << "Model: " << model << endl;
	cout << "Year: " << year << endl;
	cout << "Price: " << price << endl;
	cout << "Num of Doors: " << bedSize << endl;
	cout << endl;
}
