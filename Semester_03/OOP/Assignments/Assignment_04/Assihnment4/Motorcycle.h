#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include <iostream>
#include "Vehicle.h"
#include <string>
using namespace std;

class Motorcycle : public Vehicle
{
protected:
	int engineSize;
public:
	Motorcycle();
	Motorcycle(string make, string model, int year, double price, int enginesize);


	void display_info();

};

#endif

