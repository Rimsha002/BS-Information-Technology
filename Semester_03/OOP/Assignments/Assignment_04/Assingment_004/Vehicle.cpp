#include <iostream>
#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle()
{
	make = "";
	model = "";
	year = 0;
	price = 0.0;
}

Vehicle::Vehicle(string make, string model, int year, double price)
	{
		this->make = make;
		this->model = model;
		this->year = year;
		this->price = price;
	}

// void Vehicle::display_info()
// {
// 	cout << "Make: " << make << endl;
// 	cout << "Model: " << model << endl;
// 	cout << "Year: " << year << endl;
// 	cout << "Price: " << price << endl;
// }



