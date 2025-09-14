#ifndef CAR_H
#define CAR_H

#include <string>
#include "Vehicle.h"
using namespace std;

class Car : public Vehicle
{
    int numDoors;
public:
	Car() = default;
    //Car(string make, string model, int year, double price, int numDoors);
    Car(string make, string model, int year, double price, int numDoors) : Vehicle(make, model, year, price), numDoors(numDoors) {}


    void display_info() override;
};

#endif 