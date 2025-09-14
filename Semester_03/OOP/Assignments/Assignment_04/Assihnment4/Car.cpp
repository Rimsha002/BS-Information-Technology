#include <iostream>
#include "Car.h"
using namespace std;

Car::Car()
{
	numDoors = 0;
}

Car::Car(string make, string model, int year, double price, int numDoors)
{
	this->make = make;
	this->model = model;
	this->year = year;
	this->price = price;
	this->numDoors = numDoors;
}

void Car::display_info() 
{
	cout << "Vehicle Type: Car" << endl;
	cout << "Make: " << make << endl;
	cout << "Model: " << model << endl;
	cout << "Year: " << year << endl;
	cout << "Price: " << price << endl;
	cout << "Num of Doors: " << numDoors << endl;
	cout << endl;
}