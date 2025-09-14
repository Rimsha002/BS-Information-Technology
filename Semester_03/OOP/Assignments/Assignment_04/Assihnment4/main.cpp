#include <iostream>
#include <vector>
#include <algorithm>
#include "Vehicle.h"
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"

using namespace std;

void displayInventory(const vector<Vehicle*>& inventory);
void addVehicle(vector<Vehicle*>& inventory);
void removeVehicle(vector<Vehicle*>& inventory);
void searchVehicle(const vector<Vehicle*>& inventory);
void sortInventory(vector<Vehicle*>& inventory, const string& criteria);


int main() {
    vector<Vehicle*> inventory;

    Car car("Toyota", "Corolla", 2015, 25000, 4);
    Truck truck("Ford", "F-150", 2018, 30000, 8);
    Motorcycle motorcycle("Harley-Davidson", "Street 750", 2020, 7500, 750);

    inventory.push_back(&car);
    inventory.push_back(&truck);
    inventory.push_back(&motorcycle);

    int choice;
    string criteria;

    while (true) {
        cout << "\nVehicle Show Inventory Management System\n";
        cout << "1. Display inventory\n";
        cout << "2. Add a vehicle\n";
        cout << "3. Remove a vehicle\n";
        cout << "4. Search for a vehicle\n";
        cout << "5. Sort inventory\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayInventory(inventory);
            break;
        case 2:
            addVehicle(inventory);
            break;
        case 3:
            removeVehicle(inventory);
            break;
        case 4:
            searchVehicle(inventory);
            break;
        case 5:
            cout << "Enter sort criteria (make/model/year/price): ";
            cin >> criteria;
            sortInventory(inventory, criteria);
            break;
        case 6:
            for (auto& vehicle : inventory) {
                delete vehicle;
            }
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}



void displayInventory(const vector<Vehicle*>& inventory) {
    for (const auto& vehicle : inventory) {
        vehicle->display_info();
    }
}

void addVehicle(vector<Vehicle*>& inventory) {
    string type, make, model;
    int year;
    double price, spec;
    cout << "Enter vehicle type (Car/Truck/Motorcycle): ";
    cin >> type;
    cout << "Enter make: ";
    cin >> make;
    cout << "Enter model: ";
    cin >> model;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter price: ";
    cin >> price;

    if (type == "Car" || type == "car") {
        cout << "Enter number of doors: ";
        cin >> spec;
        inventory.push_back(new Car(make, model, year, price, spec));
    }
    else if (type == "truck" || type == "Truck") {
        cout << "Enter bed size in cubic feet: ";
        cin >> spec;
        inventory.push_back(new Truck(make, model, year, price, spec));
    }
    else if (type == "Motorcycle" || type == "motercycle") {
        cout << "Enter engine size in cc: ";
        cin >> spec;
        inventory.push_back(new Motorcycle(make, model, year, price, spec));
    }
    else {
        cout << "Invalid vehicle type!" << endl;
    }
}

void removeVehicle(vector<Vehicle*>& inventory) {
    string make, model;
    cout << "Enter make of vehicle to remove: ";
    cin >> make;
    cout << "Enter model of vehicle to remove: ";
    cin >> model;

    auto it = remove_if(inventory.begin(), inventory.end(), [&](Vehicle* vehicle) {
        return vehicle->getMake() == make && vehicle->getModel() == model;
        });

    if (it != inventory.end()) {
        delete* it;
        inventory.erase(it, inventory.end());
        cout << "Vehicle removed successfully." << endl;
    }
    else {
        cout << "Vehicle not found." << endl;
    }
}

void searchVehicle(const vector<Vehicle*>& inventory) {
    string make, model;
    int year;
    double price;
    cout << "Enter search criteria (make, model, year, price): ";
    cin >> make >> model >> year >> price;

    for (const auto& vehicle : inventory) {
        if ((make.empty() || vehicle->getMake() == make) &&
            (model.empty() || vehicle->getModel() == model) &&
            (year == 0 || vehicle->getYear() == year) &&
            (price == 0 || vehicle->getPrice() == price)) {
            vehicle->display_info();
        }
    }
}

void sortInventory(vector<Vehicle*>& inventory, const string& criteria) {
    if (criteria == "make") {
        sort(inventory.begin(), inventory.end(), [](Vehicle* a, Vehicle* b) {
            return a->getMake() < b->getMake();
            });
    }
    else if (criteria == "model") {
        sort(inventory.begin(), inventory.end(), [](Vehicle* a, Vehicle* b) {
            return a->getModel() < b->getModel();
            });
    }
    else if (criteria == "year") {
        sort(inventory.begin(), inventory.end(), [](Vehicle* a, Vehicle* b) {
            return a->getYear() < b->getYear();
            });
    }
    else if (criteria == "price") {
        sort(inventory.begin(), inventory.end(), [](Vehicle* a, Vehicle* b) {
            return a->getPrice() < b->getPrice();
            });
    }
    else {
        cout << "Invalid sort criteria!" << endl;
    }
}

