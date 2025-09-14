#ifndef CAR_H
#define CAR_H
#include <iostream>
#include "Vehicle.h"
#include <string>
using namespace std;

class Car : public Vehicle
{
protected:
	int numDoors;
public:
	Car();
	Car(string make, string model, int year, double price, int numDoors);


	void display_info();

};

#endif