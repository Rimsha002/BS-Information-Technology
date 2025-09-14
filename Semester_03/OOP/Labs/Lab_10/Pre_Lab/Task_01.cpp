#include <iostream>
using namespace std;

class Vehicles
{
    int max_Speed;
    int no_of_Wheel;
    int no_Of_Doors;
    int no_Of_Seats;
    int price;
    string fuel_type;
    string model;
    string color;

public:
    // Defualt Constructor
    Vehicles()
    {
        max_Speed = 0;
        no_of_Wheel = 0;
        no_Of_Doors = 0;
        no_Of_Seats = 0;
        price = 0;
        fuel_type = "";
        model = "";
        color = "";
    }

    // Parametrize Constructor
    Vehicles(int max_Speed, int no_of_Wheel, int no_Of_Doors, int no_Of_Seats, int price, string fuel_type, string model, string color)
    {
        setMax_Speed(max_Speed);
        setNo_of_Wheel(no_of_Wheel);
        setNo_Of_Doors(no_Of_Doors);

        this->no_Of_Seats = no_Of_Seats;
        this->price = price;
        this->fuel_type = fuel_type;
        this->model = model;
        this->color = color;
    }

    // Setter
    void setMax_Speed(int max_Speed)
    {
        if (max_Speed < 0)
        {
            while (max_Speed < 0)
            {
                cout << "Invalid max-Speed" << endl;
                cout << "Max Speed again: ";
                cin >> max_Speed;
            }
        }
        this->max_Speed = max_Speed;
    }

    void setNo_of_Wheel(int no_of_Wheel)
    {
        if (no_of_Wheel < 0)
        {
            while (no_of_Wheel < 0)
            {
                cout << "Invalid no_of_Wheel" << endl;
                cout << "No of Wheel again: ";
                cin >> no_of_Wheel;
            }
        }
        this->no_of_Wheel = no_of_Wheel;
    }

    void setNo_Of_Doors(int no_Of_Doors)
    {
        if (no_Of_Doors < 0)
        {
            while (no_Of_Doors < 0)
            {
                cout << "Invalid no_Of_Doors" << endl;
                cout << "No of Doors again: ";
                cin >> no_Of_Doors;
            }
        }
        this->no_Of_Doors = no_Of_Doors;
    }
    void setNo_Of_Seats(int no_Of_Seats)
    {
        this->no_Of_Seats = no_Of_Seats;
    }
    void setPrice(int price)
    {
        this->price = price;
    }
    void setFuel_type(string fuel_type)
    {
        this->fuel_type = fuel_type;
    }
    void setModel(string model)
    {
        this->model = model;
    }
    void setColor(string color)
    {
        this->color = color;
    }

    // Getters
    int getMax_Speed()
    {
        return max_Speed;
    }
    int getNo_of_Wheel()
    {
        return no_of_Wheel;
    }
    int getNo_Of_Doors()
    {
        return no_Of_Doors;
    }
    int getNo_Of_Seats()
    {
        return no_Of_Seats;
    }
    int getPrice()
    {
        return price;
    }
    string getFuel_type()
    {
        return fuel_type;
    }
    string getModel()
    {
        return model;
    }
    string getColor()
    {
        return color;
    }

    // Display
    void display()
    {
        cout << "Max Speed: " << max_Speed << endl;
        cout << "No of Wheel: " << no_of_Wheel << endl;
        cout << "No of Doors: " << no_Of_Doors << endl;
        cout << "No of Seats: " << no_Of_Seats << endl;
        cout << "Price: " << price << endl;
        cout << "Fuel Type: " << fuel_type << endl;
        cout << "Model: " << model << endl;
        cout << "Color: " << color << endl;
    }
};
class Truck : public Vehicles
{
public:
    int load_Capacity;

    // Default
    Truck()
    {
        load_Capacity = 0;
    }
    // Parametrize  Constructor
    Truck(int lood_c, int max_Speed, int no_of_Wheel, int no_Of_Doors, int no_Of_Seats, int price, string fuel_type, string model, string color)
    {
        load_Capacity = lood_c;
        setMax_Speed(max_Speed);
        setNo_of_Wheel(no_of_Wheel);
        setNo_Of_Doors(no_Of_Doors);
        setNo_Of_Seats(no_Of_Seats);
        setPrice(price);
        setFuel_type(fuel_type);
        setModel(model);
        setColor(color);
    }

    void setLoad_Capacity(int load_Capacity)
    {
        this->load_Capacity = load_Capacity;
    }
    int getLoad_Capacity()
    {
        return load_Capacity;
    }

    void displayTruck()
    {
        cout << "\n \tTruck data is: \n"
             << endl;
        display();
        cout << "Load Capacity: " << load_Capacity << endl;
    }
};

class Car : public Vehicles
{
public:
    string useType;
    Car()
    {
        useType = "";
    }
    Car(string useType, int max_Speed, int no_of_Wheel, int no_Of_Doors, int no_Of_Seats, int price, string fuel_type, string model, string color)
    {
        this->useType = useType;
        setMax_Speed(max_Speed);
        setNo_of_Wheel(no_of_Wheel);
        setNo_Of_Doors(no_Of_Doors);
        setNo_Of_Seats(no_Of_Seats);
        setPrice(price);
        setFuel_type(fuel_type);
        setModel(model);
        setColor(color);
    }

    void setUseType(string useType)
    {
        this->useType = useType;
    }
    string getUseType()
    {
        return useType;
    }

    void displayCar()
    {
        cout << "\n \tCar data is: \n"
             << endl;
        display();
        cout << "Use Type: " << useType << endl;
    }
};

// MoterCycle Class
class MoterCycle : public Vehicles
{
public:
    string engineOption;
    MoterCycle()
    {
        engineOption = "";
    }

    MoterCycle(string engine, int max_Speed, int no_of_Wheel, int no_Of_Doors, int no_Of_Seats, int price, string fuel_type, string model, string color)
    {
        this->engineOption = engine;
        setMax_Speed(max_Speed);
        setNo_of_Wheel(no_of_Wheel);
        setNo_Of_Doors(no_Of_Doors);
        setNo_Of_Seats(no_Of_Seats);
        setPrice(price);
        setFuel_type(fuel_type);
        setModel(model);
        setColor(color);
    }

    void setEngineOption(string engineOption)
    {
        this->engineOption = engineOption;
    }
    string getEngineOption()
    {
        return engineOption;
    }

    void displayMoterCycle()
    {
        cout << "\n \tMoterCycle data is: \n"
             << endl;
        display();
        cout << "Engine Option: " << engineOption << endl;
    }
};





void intput_Truck();
void input_Car();
void input_MoterCycle();

int main()
{
    int choice;

    cout << "For which Vehicle you want to enter data \n 1. Truck \n 2. Car \n 3. MoterCycle  \n Enter your choice: ";

    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        intput_Truck();
        break;
    }
    case 2:
    {
        input_Car();
        break;
    }
    case 3:
    {
        input_MoterCycle();
        break;
    }

    default:
        cout << "Invalid Choice" << endl;
        break;
    }



    return 0;
}



//Function for input
void intput_Truck()
{
    int max_Speed;
    int no_of_Wheel;
    int no_Of_Doors;
    int no_Of_Seats;
    int price;
    string fuel_type;
    string model;
    string color;
    int load_Capacity;
    string useType;
    string engineOption;

    cout << "Enter Max Speed: ";
    cin >> max_Speed;
    cout << "Enter No of Wheel: ";
    cin >> no_of_Wheel;
    cout << "Enter No of Doors: ";
    cin >> no_Of_Doors;
    cout << "Enter No of Seats: ";
    cin >> no_Of_Seats;
    cout << "Enter Price: ";
    cin >> price;

    cin.ignore();
    cout << "Enter Fuel Type: ";
    getline(cin, fuel_type);
    cout << "Enter Model: ";
    cin >> model;

    cin.ignore();
    cout << "Enter Color: ";
    getline(cin, color);
    cout << "Enter Load Capacity: ";
    cin >> load_Capacity;

   
    Truck t1(load_Capacity, max_Speed, no_of_Wheel, no_Of_Doors, no_Of_Seats, price, fuel_type, model, color);
    t1.displayTruck();
}

void input_Car()
{
    int max_Speed;
    int no_of_Wheel;
    int no_Of_Doors;
    int no_Of_Seats;
    int price;
    string fuel_type;
    string model;
    string color;
    int load_Capacity;
    string useType;
    string engineOption;

    cout << "Enter Max Speed: ";
    cin >> max_Speed;
    cout << "Enter No of Wheel: ";
    cin >> no_of_Wheel;
    cout << "Enter No of Doors: ";
    cin >> no_Of_Doors;
    cout << "Enter No of Seats: ";
    cin >> no_Of_Seats;
    cout << "Enter Price: ";
    cin >> price;

    cin.ignore();
    cout << "Enter Fuel Type: ";
    getline(cin, fuel_type);
    cout << "Enter Model: ";
    cin >> model;

    cin.ignore();
    cout << "Enter Color: ";
    getline(cin, color);
    
    cin.ignore();
    cout << "Enter Use Type(For Family or Personal or Commercial): ";
    getline(cin, useType);

  
    Car c1(useType, max_Speed, no_of_Wheel, no_Of_Doors, no_Of_Seats, price, fuel_type, model, color);

    c1.displayCar();
}


void input_MoterCycle()
{
    int max_Speed;
    int no_of_Wheel;
    int no_Of_Doors;
    int no_Of_Seats;
    int price;
    string fuel_type;
    string model;
    string color;
    int load_Capacity;
    string useType;
    string engineOption;

    cout << "Enter Max Speed: ";
    cin >> max_Speed;
    cout << "Enter No of Wheel: ";
    cin >> no_of_Wheel;
    cout << "Enter No of Doors: ";
    cin >> no_Of_Doors;
    cout << "Enter No of Seats: ";
    cin >> no_Of_Seats;
    cout << "Enter Price: ";
    cin >> price;

    cin.ignore();
    cout << "Enter Fuel Type: ";
    getline(cin, fuel_type);
    cout << "Enter Model: ";
    cin >> model;

    cin.ignore();
    cout << "Enter Color: ";
    getline(cin, color);
  
    cout << "Enter Engine Option(Petrolium or Electric): ";
    getline(cin, engineOption);


    MoterCycle m1(engineOption, max_Speed, no_of_Wheel, no_Of_Doors, no_Of_Seats, price, fuel_type, model, color);

    m1.displayMoterCycle();
}