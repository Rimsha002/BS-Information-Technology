#include <iostream>
// #include "Vehicle.h"
#include "Car.h"
// #include "Truck.h"
// #include "Motorcycle.h"
using namespace std;

int main()
{
    Car car("Toyota", "Camry", 2020, 24000.0, 4);
	Vehicle* v = &car;
	v->display_info();
    return 0;
}

