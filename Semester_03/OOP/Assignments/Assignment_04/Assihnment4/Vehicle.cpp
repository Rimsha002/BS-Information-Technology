#include <iostream>
#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle()
{
	make = " ";
	model = " ";
	year = 0;
	price = 0;
}
	
Vehicle::Vehicle(string make, string model, int year, double price) {
	this->make = make;
	this->model = model;
	this->year = year;
	this->price = price;

};

string Vehicle::getMake() const 
{ return make; }
string Vehicle::getModel() const 
{ return model; }
int Vehicle::getYear() const
{ return year; }
double Vehicle::getPrice() const 
{ return price; }

