#include <iostream>
#include "Date.h"
using namespace std;

// Default + Parameterized Constructor
Date::Date(int d = 0, int mon = 0, int y = 0)
{
    if (d < 0 || d > 31 || mon < 0 || mon > 12 || y < 0 || y > 3000)
    {
        cout << "Invalid date provided. Setting to default date (1/1/2000)." << endl;
        day = 1;
        month = 1;
        year = 2000;
    }
    else
    {
        day = d;
        month = mon;
        year = y;
    }
}

// Copy Constructor
Date::Date(const Date &date)
{
    day = date.day;
    month = date.month;
    year = date.year;
}

Date::Date::~Date() {}

// Setter methods
void Date::setDay(int d)
{
    if (d >= 0 && d <= 31)
    {
        day = d;
    }
    else
    {
        cout << "Invalid day" << endl;
    }
}
void Date::setMonth(int mon)
{
    if (mon >= 0 && mon <= 12)
    {
        month = mon;
    }
    else
    {
        cout << "Invalid month" << endl;
    }
}
void Date::setYear(int y)
{
    if (y >= 0)
    {
        year = y;
    }
    else
    {
        cout << "Invalid year" << endl;
    }
}

// Getter methods
int Date::getDay() const
{
    return day;
}
int Date::getMonth() const
{
    return month;
}
int Date::getYear() const
{
    return year;
}

// Set date method
void Date::setDate(int d, int m, int y)
{
    if (d >= 0 && d <= 31)
        day = d;
    if (m >= 0 && m <= 12)
        month = m;
    if (y >= 0)
        year = y;
}

// Get date method
Date Date::getDate() const
{
    return *this;
}

// Display method
void Date::display() const
{
    cout << day << "/" << month << "/" << year;
}

// Overload Assignment Operator
Date &Date::operator=(const Date &date)
{
    if (this != &date)
    {
        day = date.day;
        month = date.month;
        year = date.year;
    }
    return *this;
}

// Equality Operator Overloading
bool Date::operator==(const Date &date) const
{
    return (day == date.day && month == date.month && year == date.year);
}

// Overload >> operator
istream &operator>>(istream &i, Date &date)
{
    cout << "Enter day: ";
    i >> date.day;
    cout << "Enter month: ";
    i >> date.month;
    cout << "Enter year: ";
    i >> date.year;
    return i;
}

// Overload << operator
ostream &operator<<(ostream &o, const Date &date)
{
    o << date.day << "/" << date.month << "/" << date.year;
    return o;
}
