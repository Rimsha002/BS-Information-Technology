#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include "Vehicle.h"
using namespace std;

class Truck : public Vehicle
{
	string bedSize;
public:
	Truck() : Vehicle() {};
	//Truck(string make, string model, int year, double price, string size);
	Truck(string make, string model, int year, double price, string size) : Vehicle(make, model, year, price), bedSize(size) {}
	void display_info() override{}

};

#endif

