#include <iostream>
using namespace std;

class Animal{
    string name;
    public:
    Animal()
    {   }
    Animal(string n)
    {
        this->name = n;
        cout << "Animal constructor called" <<endl;
    }
    ~Animal()
    { 
        cout << "Animal Destructor called" <<endl;
     }
};
class Mammal: public Animal{
    int numLegs;
    public:
    Mammal() :Animal()
    {   }
    Mammal(string n, int num) : Animal(n)
    {
        this->numLegs = num;
        cout << "Mammal constructor called" <<endl;
    }
    ~Mammal()
    { 
        cout << "Mammal destructor called" <<endl;
     }
};

class Bird: public Animal{
    int wingSpan;
    public:
    Bird() :Animal()
    {   }
    Bird(string n, int wing) : Animal(n)
    {
        this->wingSpan = wing;
        cout << "Bird constructor called" <<endl;
    }
    ~Bird()
    { 
        cout << "Bird destructor called" <<endl;
    }
};

class Dog: public Mammal{
    string breed;
    public:
    Dog() :Mammal()
    {   }
    Dog(string name, int num, string breed) : Mammal(name, num)
    {
        this->breed = breed;
        cout << "DOG constructor called" <<endl;
    }
    ~Dog()
    { 
        cout << "Dog destructor called" <<endl;
    }
};
class Cat: public Mammal{
    string color;
    public:
    Cat() :Mammal()
    {   }
    Cat(string name, int num, string color) : Mammal(name, num)
    {
        this->color = color;
        cout << "Cat constructor called" <<endl;
    }
    ~Cat()
    { 
        cout << "Cat destructor called" <<endl;
    }

};



int main()
{
    cout << "\n-----Animal----" << endl;
    Animal animal("Cow");

    cout << "\n-----Mammal----" << endl;
    Mammal mammal("Maria", 2);

    cout << "\n-----Bird----" << endl;
    Bird bird("Sparrow", 2);

    cout << "\n----Dog----" << endl;
    Dog dog("Sharlok", 4, "breed");

    cout << "\n-----Cat----" << endl;
    Cat cat("Bello", 4, "White");

    return 0;
}