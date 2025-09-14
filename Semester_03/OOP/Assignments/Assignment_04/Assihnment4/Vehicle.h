#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
	string make;
	string model;
	int year = 0;
	double price = 0;

public:
	Vehicle();
	Vehicle(string make, string model, int year, double price);
	
	string getMake() const;
	string getModel() const;
	int getYear() const;
	double getPrice() const;

	virtual void display_info() = 0;

};
#endif


