#include <iostream>
using namespace std;

class Animal
{
protected:
    string sound;

public:
    Animal(){};
    Animal(string s)
    {
        sound = s;
    }
    virtual void make_sound() = 0;
    virtual ~Animal(){};
};

// Cat
class Cat : public Animal
{
public:
    Cat() : Animal(){};
    Cat(string s) : Animal(s){};

    void make_sound()
    {
        cout << "Cat makes a " << sound << " sound." << endl;
    }
    ~Cat(){};
};

// Dog
class Dog : public Animal
{
    public:
    Dog() : Animal(){};
    Dog(string s) : Animal(s){};

    void make_sound()
    {
        cout << "Dog makes a " << sound << " sound." << endl;
    }

    ~Dog(){};

};

// Bird

class Bird : public Animal
{
    public:
    Bird() : Animal(){};
    Bird(string s) : Animal(s){};

    void make_sound()
    {
        cout << "Bird makes a " << sound << " sound." << endl;
    }

    ~Bird(){};

};

int main()
{
    Cat cat("Meow");
    Dog dog("Woof");
    Bird bird("Chirp");


    Animal *ani[3] = { &cat, &dog, &bird };

    for (int i = 0; i < 3; i++)
    {
        ani[i]->make_sound();
    }
    
    return 0;
}