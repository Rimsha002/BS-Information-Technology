#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle
{
protected:
	string make;
	string model;
	int year;
	double price;
public:
	Vehicle(){}
	Vehicle(string make, string model, int year, double price) {};

	virtual void display_info() = 0;

};
#endif

