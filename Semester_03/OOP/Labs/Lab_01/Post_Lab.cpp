#include <iostream>
using namespace std;
/*
Post Lab_01
Create a C++ program that:
  Makes a car Class with data members:
o wheels
o doors
o currentSpeed
o maxSpeed
 And with Class Methods
o speed (Inside Class)
o break (Outside Class)
  Make two objects in the name of ferrari and mustang.
   Every time when you call speed function currentSpeed is increased by 5 while
break function decrease it by 5.
 Make sure the current Speed does not go below 0 or above max speed.
*/

class car
{
private:
    int wheels;
    int doors;
    int currentSpeed;
    int maxSpeed;

public:
    car(int mSpeed)
    {
        wheels = 0;
        doors = 0;
        currentSpeed = 0;
        maxSpeed = mSpeed;
    }

    void speed()
    {
        // if (currentSpeed < maxSpeed)
        // {
        //     currentSpeed = currentSpeed + 5;
        // }

       /// correction
        currentSpeed += 5 ;
     if (currentSpeed >  maxSpeed)
    {
        currentSpeed = maxSpeed ;
    }

    }

    int getSpeed()
    {
        return currentSpeed;
    }

    void Break();

    int getBreak()
    {
        return currentSpeed;
    }
};

// Outside defining of Method
void car::Break()
{
    // if (currentSpeed > 0)
    // {
    //     currentSpeed = currentSpeed - 5;
    // }

    ///correction
    currentSpeed -= 5 ;
     if (currentSpeed <  0)
    {
        currentSpeed = 0 ;
    }
};

int main()
{
    int mSpeed;
    cout << "Enter max speed of car: ";
    cin >> mSpeed;

    car ferrari(mSpeed);
    car mustang(mSpeed);

    // Ferrari
    ferrari.speed();
    
    int cSpeedOfFerrari = ferrari.getSpeed();
    cout << "Frerrari current speed is: " << cSpeedOfFerrari << " km/h" << endl;

    // Brake on Ferrari
    ferrari.Break();
    
    int bSpeedOfFerrari = ferrari.getBreak();
    cout << "Ferrari speed after break is: " << bSpeedOfFerrari << endl;

    // Mustang Speed
    mustang.speed();

    int cSpeedOfMustang = mustang.getSpeed();
    cout << "Mustang current speed is: " << cSpeedOfMustang << " km/h" << endl;

    // Brake on Mustang
    mustang.Break();

    int bSpeedOfMustang = mustang.getBreak();
    cout << "Mustang speed after break is: " << bSpeedOfMustang << endl;

    return 0;
}