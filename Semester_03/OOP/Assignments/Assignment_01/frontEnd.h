#include <iostream>
#include <string>
#include "car.h"
#include "Person.h"
using namespace std;

// Declaraction of Function
int displayList();
int carMini();
int truck();
int electrify();
void buyerForm(string vehicleName);
void displayData();

int displayList()
{
    cout << "\n\n <-------- Welcome to TOYOTA Showroom -------->\n\n";

    cout << "What you are looking for? \n"
         << endl;
    cout << "1) Cars & Minivan" << endl;
    cout << "2) Trucks" << endl;
    cout << "3) Electrified" << endl;

    string vehicleName;
    int price;

    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        price = carMini();
        vehicleName = "Car-Mini";
        break;
    }
    case 2:
    {
        price = truck();
        vehicleName = "Truck";
        break;
    }
    case 3:
    {
        price = electrify();
        vehicleName = "Eletrified Car";
        break;
    }
    default:
    {
        cout << "Error: Select right option";
    }
    }
    
    // Buyer Data
    cout << "\n---Please Fill Buyer Form---\n"
         << endl;
    buyerForm(vehicleName);

    return price;
}

int carMini()
{
    string *name = new string[3];
    int *price = new int[3];

    cout << "--- Civi & Mini --- \n";

    cout << "\nSelect one you want to buy: \nRemember Price Detail also\n"
         << endl;
    cout << "1) Toyota Crown (red)\n $40, 350\n"
         << endl;
    cout << "2) Prius Prime (Black)\n $27,950\n"
         << endl;
    cout << "3) Corolla Hybrid (Grey)\n $23,500\n"
         << endl;
    int choice;

    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        name[0] = "Toyota Crown";
        price[0] = 40350;
        break;
    }
    case 2:
    {
        name[1] = "Pirus Prime";
        price[1] = 27950;
        break;
    }
    case3:
    {
        name[2] = "Corolla Hybrid";
        price[2] = 23500;
        break;
    }
    default:
    {
        cout << "You Choose wrong option";
    }
    }

    return price[choice - 1];
}

int truck()
{
    string *name = new string[3];
    int *price = new int[3];

    cout << "--- Truck --- \n";

    cout << "\nSelect one you want to buy: \nRemember Price Detail also\n"
         << endl;
    cout << "1) Tacoma (red)\n $40,350\n" << endl;
    cout << "2) Tundra (Black)\n $27,950\n" << endl;
    cout << "3) Tundra i-FORCE MAX (Grey)\n $23,500\n" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        name[0] = "Toyota Crown";
        price[0] = 40350;
        break;
    }
    case 2:
    {
        name[1] = "Pirus Prime";
        price[1] = 27950;
        break;
    }
    case 3:
    {
        name[2] = "Corolla Hybrid";
        price[2] = 23500;
        break;
    }
    default:
    {
        cout << "You Choose wrong option";
    }
    }
    return price[choice - 1];
}

int electrify()
{
    string *name = new string[3];
    int *price = new int[3];

    cout << "--- Electrify --- \n";

    cout << "\nSelect one you want to buy: \nRemember Price Detail also\n"
         << endl;
    cout << "1) BZ4X (red)\n $40, 350" << endl;
    cout << "2) Highlander Hybrid (Black)\n $27,950" << endl;
    cout << "3) Sequoia (Grey)\n $23,500" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        name[0] = "Toyota Crown";
        price[0] = 40350;
        break;
    }
    case 2:
    {
        name[1] = "Pirus Prime";
        price[1] = 27950;
        break;
    }
    case 3:
    {
        name[2] = "Corolla Hybrid";
        price[2] = 23500;
        break;
    }
    default:
    {
        cout << "You Choose wrong option";
    }
    }
    return price[choice - 1];
}

void buyerForm(string vehicleName)
{
    int cnic;
    string personName;
    string fatherName;
    int phoneNo;
    string address;

    int iD;
    int noOfTyre;
    int noOfDoor;
    string color;
    string runOn;
    string manufacturer;
    string model;
    int maxSpeed;
    int coverDistance;
    string carType;

    // Personal Data
    cout << "~ Your Personal Data ~\n" << endl;
    cout << "Buyer Name:";
    cin >> personName;
    cout << "CNIC no:";
    cin >> cnic;
    cout << "Father's Name:";
    cin >> fatherName;
    cout << "Phone No:";
    cin >> phoneNo;
    cout << "Buyer Address:";
    cin >> address;

    Person person(cnic, personName, fatherName, phoneNo, address);

    // Vehicle Data
    cout << "\n~ Your Vehicle Data ~\n" << endl;
    cout << "Enter ID :";
    cin >> iD;
    cout << "Enter Number of tyre :";
    cin >> noOfTyre;
    cout << "Enter Number of Doors :";
    cin >> noOfDoor;
    cout << "Enter Color :";
    cin >> color;
    cout << "Run on (disel or petrol) :";
    cin >> runOn;
    cout << "Enter Manufacturer name :";
    cin >> manufacturer;
    cout << "Enter Model :";
    cin >> model;
    cout << "Enter Maximum speed:";
    cin >> maxSpeed;

    cout << "Covered Distance?";
    cin >> coverDistance;
    cout << "Enter Car type :";
    cin >> carType;

    Car car(vehicleName, iD, noOfTyre, noOfDoor, color, runOn, manufacturer, model, maxSpeed, coverDistance, carType);
}

void displayData()
{
    Person person;
    Car car;
    person.displayPerson();
    car.displayCar();
}