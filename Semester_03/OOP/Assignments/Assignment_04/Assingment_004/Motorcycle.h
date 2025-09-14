#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include <string>
#include "Vehicle.h"
using namespace std;

class Motorcycle : public Vehicle
{
	double engineSize;
public:
	
	Motorcycle() : Vehicle() {}
	//Motorcycle(string make, string model, int year, double price, double enginesize);
	Motorcycle(string make, string model, int year, double price, double enginesize) : Vehicle(make, model, year, price), engineSize(enginesize){}

	void display_info() override {}

};

#endif

