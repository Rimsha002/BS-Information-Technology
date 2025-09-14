#ifndef DATE_H

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
    Date(int d = 0, int mon = 0, int y = 0)
    {

        if (d < 0 || d > 31 || mon < 0 || mon > 12 || y < 0 || y > 3000)
        {
            while (d < 0 || d > 31)
            {
                cout << "Invalid day" << endl;
                cout << "Enter day(0 to 31): ";
                cin >> d;
            }

            while (mon < 0 || mon > 12)
            {
                cout << "Invalid month" << endl;
                cout << "Enter month(0 to 12): ";
                cin >> mon;
            }
            while (y < 0 || y > 3000)
            {
                cout << "Invalid year" << endl;
                cout << "Enter year(0 to 3000): ";
                cin >> y;
            }
        }

        if (d >= 0 && d <= 31 && mon >= 0 && mon <= 12 && y >= 0)
        {
            this->day = d;
            this->month = mon;
            this->year = y;
        }
    }

    // Copy Constructor
    Date(Date &date)
    {
        day = date.day;
        month = date.month;
        year = date.year;
    }

    ~Date()
    {
    }

    void setDay(int d)
    {
        if (d >= 0 && d <= 31)
        {
            this->day = d;
        }
        else
        {
            cout << "Invalid day" << endl;
        }
    }
    void setMonth(int mon)
    {
        if (mon >= 0 && mon <= 12)
        {
            this->month = mon;
        }
        else
        {
            cout << "Invalid month" << endl;
        }
    }
    void setYear(int y)
    {
        if (y >= 0)
        {
            this->year = y;
        }
        else
        {
            cout << "Invalid year" << endl;
        }
    }
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }

    void setDate(int d, int m, int y)
    {
        this->day = d;
        this->month = m;
        this->year = y;
    }

    Date getDate()
    {
        Date d1;
        return d1;
    }

    // Display
    void display()
    {
        cout
            << day << " : " << month << " : " << year << "\nTime: ";
    }

    // Overload Assignment Operator
    Date &operator=(const Date &date)
    {
        day = date.day;
        month = date.month;
        year = date.year;
        return *this;
    }

    // Equality Operator Overloading
    bool operator==(const Date &date)
    {
        if (day == date.day && month == date.month && year == date.year)
        {
            return true;
        }
        return false;
    }
};

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
ostream &operator<<(ostream &o, const Date &date)
{
    o << date.day << " : " << date.month << " : " << date.year;
    return o;
}

#endif
