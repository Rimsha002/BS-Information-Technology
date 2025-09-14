#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;


class Date
{
    int day = 0;
    int month = 0;
    int year = 0;

    friend istream &operator>>(istream &i, Date &date);
    friend ostream &operator<<(ostream &o, const Date &date);

public:
    // Default + Parameterize Constructor
    Date(int d = 0, int mon = 0, int y = 0);
    
    // Copy Constructor
    Date(const Date &date);

    ~Date();

    //Setter
    void setDay(int d);
    void setMonth(int mon);
    void setYear(int y);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    void setDate(int d, int m, int y);

    //Getter
    Date getDate()const;
    // Display
    void display() const;

    // Overload Assignment Operator
    Date &operator=(const Date &date);

    // Equality Operator Overloading
    bool operator==(const Date &date) const;
};

istream &operator>>(istream &i, Date &date);
ostream &operator<<(ostream &o, const Date &date);



#endif