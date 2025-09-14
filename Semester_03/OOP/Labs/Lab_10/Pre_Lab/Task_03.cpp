#include <iostream>
using namespace std;

class Animals
{
    string name;
    int no_of_legs;

public:
    // Defualt Constructor
    Animals()
    {
        name = "";
        no_of_legs = 0;
    }

    // Parametrize Constructor
    Animals(string name, int no_of_legs)
    {
        setName(name);
        setNo_of_legs(no_of_legs);
    }

    // Setter
    void setName(string name)
    {
        this->name = name;
    }

    void setNo_of_legs(int no_of_legs)
    {
        if (no_of_legs < 0)
        {
            while (no_of_legs < 0)
            {
                cout << "Invalid no_of_legs" << endl;
                cout << "No of legs again: ";
                cin >> no_of_legs;
            }
        }
        this->no_of_legs = no_of_legs;
    }

    // Getter
    string getName()
    {
        return name;
    }

    int getNo_of_legs()
    {
        return no_of_legs;
    }

    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "No of legs: " << no_of_legs << endl;
    }
};

class Mammals : public Animals
{

    string blood_type;

public:
    Mammals() : Animals(){};

    // Parametrize Constructor
    Mammals(string name, int no_of_legs, string blood) : Animals(name, no_of_legs)
    {
        blood_type = blood;
    };

    void print()
    {
        cout << "I am Mammal." << endl;
    }

    void setBloodType(string blood)
    {
        blood_type = blood;
    }

    string getBlood()
    {
        return blood_type;
    }

    void display() override
    {
        Animals::display();
        cout << "Blood Type: " << blood_type << endl;
    }
};

class MarineAnimals : public Animals
{
    string habitate;

public:
    // defualt constructor
    MarineAnimals() : Animals(){};

    // parametrize constructor
    MarineAnimals(string name, int no_of_legs, string habitate) : Animals(name, no_of_legs)
    {
        this->habitate = habitate;
    }

    void setHabitate(string habitate)
    {
        this->habitate = habitate;
    }
    string getHabitate()
    {
        return habitate;
    }

    void print()
    {
        cout << "I am Mammal." << endl;
    }

    void display() override
    {
        Animals::display();
        cout << "Habitate: " << habitate << endl;
    }
};

// Lion
class Lion : public Mammals
{
    string sound;

public:
    Lion() : Mammals() {}

    Lion(string n, int a, string bt) : Mammals(n, a, bt) {}

    void makeSound()
    {
        sound = "Roar";
    }

    void display() override
    {
        Mammals::display();
        cout << "Sound: " << sound << endl;
    }
};

// Whale (both mammal and marine
class Whale : public Mammals, public MarineAnimals
{
    string sound;

public:
    Whale() : Mammals(), MarineAnimals() {}

    Whale(string n, int a, string bt, string h) : Mammals(n, a, bt), MarineAnimals(n, a, h)
    {
        sound = "";
    }

    void setName(string n)
    {
        Mammals::setName(n);
        MarineAnimals::setName(n);
    }
     void setNo_of_legs(int a)
    {
        Mammals::setNo_of_legs(a);
        MarineAnimals::setNo_of_legs(a);

    }

    void makeSound()
    {
        sound = "whistles, and pulsed calls";
    }

    void display() override
    {
        Mammals::display();
        MarineAnimals::display();
        cout << "Sound: " << sound << endl;
    }
};

// Cow
class Cow : public Mammals
{
    string sound;

public:
    Cow() : Mammals() {}

    Cow(string n, int a, string bt) : Mammals(n, a, bt)
    {
        sound = "";
    }

    void makeSound()
    {
        sound = "Cow Sound";
    }
    void display() override
    {
        Mammals::display();
        cout << "Sound: " << sound << endl;
    }
};

// Shark (marine)
class Shark : public MarineAnimals
{
    string sound;

public:
    void makeSound()
    {
        sound = "low-frequency, pulsing sounds";
    }
    void display() override
    {
        MarineAnimals::display();
        cout << "Sound: " << sound << endl;
    }
};

int main()
{
    Lion lion;
    lion.setName("Lion");
    lion.setNo_of_legs(4);
    lion.setBloodType("Warm Blooded");
    lion.makeSound();
    lion.display();
    cout << endl;

    Whale whale;
    whale.setName("Whale");
    whale.setNo_of_legs(0);
    whale.setBloodType("Warm Blooded");
    whale.setHabitate("Sea");
    whale.display();
    cout << endl;


    Cow cow;
    cow.setName("Cow");
    cow.setNo_of_legs(4);
    cow.setBloodType("Warm Blooded");
    cow.makeSound();
    cow.display();
    cout << endl;

    Shark shark;
    shark.setName("Shark");
    shark.setNo_of_legs(0);
    shark.setHabitate("Sea");
    shark.makeSound();
    shark.display();
    cout << endl;



    return 0;
}