#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include "Vehicle.h"
#include <string>
using namespace std;

class Truck : public Vehicle
{
protected:
	int bedSize;
public:
	Truck();
	Truck(string make, string model, int year, double price, int bedsize);


	void display_info();

};

#endif

