#include <iostream>
//#include "Vehicle.h"
#include "Motorcycle.h"
using namespace std;


//Motorcycle::Motorcycle(string make, string model, int year, double price, double enginesize) : Vehicle(make, model, year, price), engineSize(enginesize){}

void Motorcycle::display_info()
	{
		cout << "Make: " << make << endl;
		cout << "Model: " << model << endl;
		cout << "Year: " << year << endl;
		cout << "Price: " << price << endl;
		cout << "Engine size: " << engineSize << endl;
	}	

