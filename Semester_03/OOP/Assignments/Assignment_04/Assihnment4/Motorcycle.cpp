#include <iostream>
#include "Motorcycle.h"
using namespace std;

Motorcycle::Motorcycle()
{
	engineSize = 0;
}

Motorcycle::Motorcycle(string make, string model, int year, double price, int enginesize)
{
	this->make = make;
	this->model = model;
	this->year = year;
	this->price = price;
	this->engineSize = enginesize;
}

void Motorcycle::display_info()
{
	cout << "Vehicle Type: Motorcycle" << endl;
	cout << "Make: " << make << endl;
	cout << "Model: " << model << endl;
	cout << "Year: " << year << endl;
	cout << "Price: " << price << endl;
	cout << "Num of Doors: " << engineSize << endl;
	cout << endl;
}

