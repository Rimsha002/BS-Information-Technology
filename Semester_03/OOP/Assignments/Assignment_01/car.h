
// #ifndef CAR_H
// #define CAR_H

#include <iostream>
#include <string>
#include "Vehicle.h"
using namespace std;

class Car
{
private:
    Vehicle vehicle;
    string name;
    string manufacturer;
    string model;
    int maxSpeed;
    int coverDistance;
    string carType;

public:
    Car(string name = "",
        int iD = 0,
        int noOfTyre = 4,
        int noOfDoor = 0,
        string color = "",
        string runOn = "",
        string manufacturer = "",
        string model = "",
        int maxSpeed = 0,
        int coverDistance = 0,
        string carType = "")
    {
        this->name = name;
        vehicle.setID(iD);
        vehicle.setTyres(noOfTyre);
        vehicle.setDoors(noOfDoor);
        vehicle.setColor(color);
        vehicle.setRunOn(runOn);
        this->manufacturer = manufacturer;
        this->model = model;
        this->maxSpeed = maxSpeed;
        this->coverDistance = coverDistance;
        this->carType = carType;
    }

    // Setters
    void setName(string name)
    {
        this->name = name;
    }
    void setmanuf(string manufacturer)
    {
        this->manufacturer = manufacturer;
    }
    void setmodel(string model)
    {
        this->model = model;
    }
    void setMaxSpeed(int maxSpeed)
    {
        this->maxSpeed = maxSpeed;
    }
    void setCoverDistance(int coverDistance)
    {
        this->coverDistance = coverDistance;
       
    }
    void setCarType(string carType)
    {
        this->carType = carType;
    }

    // Getters
    string getName()
    {
        return name;
    }
    string getmanuf()
    {
        return manufacturer;
    }
    string getModel()
    {
        return model;
    }
    int getMaxSpeed()
    {
        return maxSpeed;
    }
    int getCoverDistance()
    {
        return coverDistance;
    }
    string getCarType()
    {
        return carType;
    }

    // Display Function
    void displayCar()
    {
     
        cout << "\nVehicle Name: " << name << endl;
        cout << "\nID: " << vehicle.getID() << endl;
        cout << "Number of Tyres: " << vehicle.getTyres() << endl;
        cout << "Numberof Doors: " << vehicle.getDoors() << endl;
        cout << "Color: " << vehicle.getColor() << endl;
        cout << "Run On: " << vehicle.getRunOn() << endl;

        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Max-Speed: " << maxSpeed << endl;
        cout << "Distance Covered: " << coverDistance << endl;
        cout << "Car Type: " << carType << endl;
    }
};

// #endif