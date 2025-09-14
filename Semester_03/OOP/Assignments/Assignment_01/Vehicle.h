// #ifndef VEHICLE_H
// #define VEHICLE_H

#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    int iD;
    int noOfTyre;
    int noOfDoor;
    string color;
    string runOn;

public:
    Vehicle(int iD = 0,
            int noOfTyre = 0,
            int noOfDoor = 0,
            string color = "",
            string runOn = "")
    {
        this->iD = iD;
        this->noOfTyre = noOfTyre;
        this->noOfDoor = noOfDoor;
        this->color = color;
        this->runOn = runOn;
    }
    // Setters
    void setID(int iD)
    {
        this->iD = iD;
    }
    void setTyres(int noOfTyre)
    {
        this->noOfTyre = noOfTyre;
    }
    void setDoors(int noOfDoor)
    {
        this->noOfDoor = noOfDoor;
    }
    void setColor(string color)
    {
        this->color = color;
    }
    void setRunOn(string runOn)
    {
        this->runOn = runOn;
    }
    // Getters
    int getID()
    {
        return iD;
    }
    int getTyres()
    {
        return noOfTyre;
    }
    int getDoors()
    {
        return noOfDoor;
    }
    string getColor()
    {
        return color;
    }
    string getRunOn()
    {
        return runOn;
    }

    // Display Function
    void displayVehicle()
    {
        cout << "ID: " << iD << endl;
        cout << "Number of Tyres: " << noOfTyre << endl;
        cout << "Numberof Doors: " << noOfDoor << endl;
        cout << "Color: " << color << endl;
        cout << "Run On: " << runOn << endl;
    }
};
