#include <iostream>
using namespace std;

class Time
{
private:
    int second = 0;
    int minute = 0;
    int hour = 0;

    friend istream &operator>>(istream &i, Time &t);
    friend ostream &operator<<(ostream &o, Time &t);
    friend Time operator+(Time t, Time t1);
    friend Time operator-(Time t, Time t1);

public:
    // Default + Parameterize Constructor
    Time(int h = 0, int m = 0, int s = 0)
    {
        if (h < 0 || h > 24 || m < 0 || m > 60 || s < 0 || s > 60)
        {
            while (h < 0 || h > 24)
            {
                cout << "Invalid hour" << endl;
                cout << "Enter hour(0 to 24): ";
                cin >> h;
            }

            while (m < 0 || m > 60)
            {
                cout << "Invalid minute" << endl;
                cout << "Enter minute(0 to 60): ";
                cin >> m;
            }

            while (s < 0 || s > 60)
            {
                cout << "Invalid second" << endl;
                cout << "Enter second(0 to 60): ";
                cin >> s;
            }
        }

        if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60)
        {
            this->hour = h;
            this->minute = m;
            this->second = s;
        }
    }

    // Copy Constructor
    Time(Time &t)
    {
        second = t.second;
        minute = t.minute;
        hour = t.hour;
    }

    ~Time()
    {
    }

    void setHour(int h)
    {
        if (h >= 0 && h < 24)
        {
            this->hour = h;
        }
        else
        {
            cout << "Invalid hour" << endl;
        }
    }
    void setMinute(int m)
    {
        if (m >= 0 && m < 60)
        {
            this->minute = m;
        }
        else
        {
            cout << "Invalid minute" << endl;
        }
    }
    void setSecond(int s)
    {
        if (s >= 0 && s < 60)
        {
            this->second = s;
        }
        else
        {
            cout << "Invalid second" << endl;
        }
    }
    int getHour()
    {
        return this->hour;
    }
    int getMinute()
    {
        return this->minute;
    }
    int getSecond()
    {
        return this->second;
    }

    // Display
    void display()
    {
        cout << endl
             << hour << " : " << minute << " : " << second << endl;
    }
};

istream &operator>>(istream &i, Time &t)
{
    cout << "Enter hour: ";
    i >> t.hour;
    cout << "Enter minute: ";
    i >> t.minute;
    cout << "Enter second: ";
    i >> t.second;
    return i;
}
ostream &operator<<(ostream &o, Time &t)
{
    o << t.hour << " : " << t.minute << " : " << t.second << endl;
    return o;
}

Time operator+(Time t, Time t1)
{
    Time t3;

    t3.second = t.second + t1.second;
    t3.minute = t.minute + t1.minute;
    t3.hour = t.hour + t1.hour;

    if ((t3.second) > 60)
    {
        t3.minute += t3.second / 60;
        t3.second %= 60;
    }
    if ((t3.minute) > 60)
    {
        t3.hour += t3.minute / 60;
        t3.minute %= 60;
    }
    if ((t3.hour) > 24)
    {
        t3.hour = t3.hour % 24;
    }
    return t3;
}

Time operator-(Time t, Time t1)
{
    Time t3;
    t3.second = t.second - t1.second;
    t3.minute = t.minute - t1.minute;
    t3.hour = t.hour - t1.hour;

    if ((t3.second) < 0)
    {
        t3.minute -= 1;
        t3.second += 60;
    }
    if ((t3.minute) < 0)
    {
        t3.hour -= 1;
        t3.minute += 60;
    }
    if ((t3.hour) < 0)
    {
        t3.hour += 24;
    }
    return t3;
}

class Date
{
    Time t;
    int day = 0;
    int month = 0;
    int year = 0;

    friend istream &operator>>(istream &i, Date &date);
    friend ostream &operator<<(ostream &o, const Date &date);
    friend Date operator+(Date date, Date date1);
    friend Date operator-(Date date, Date date1);

public:
    // Default + Parameterize Constructor
    Date(int d = 0, int mon = 0, int y = 0, int h = 0, int m = 0, int s = 0 )  : t()
    {
        t = Time(h, m, s);

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
        t = date.t;
    }

    ~Date()
    {}

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

    // Display
    void display()
    {
        cout << "\nDate: ";
        cout << endl
             << day << " : " << month << " : " << year << "\nTime: ";
      t.display();
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
    cout << "Enter time (i.e hh:mm:ss): ";
    i >> date.t;
    return i;
}
ostream &operator << (ostream &o, const Date &date)
{
    o << "Date: " << date.day << " : " << date.month << " : " << date.year << endl;
    // o << "Time: " << date.t; // Use Time extraction operator
    return o;
}

Date operator+(Date date, Date date1)
{
    Date date2;
    date2.day = date.day + date1.day;
    date2.month = date.month + date1.month;
    date2.year = date.year + date1.year;

    if ((date2.day) > 31)
    {
        date2.month += date2.day / 31;
        date2.day %= 31;
    }
    if ((date2.month) > 12)
    {
        date2.year += date2.month / 12;
        date2.month %= 12;
    }
    return date2;
}

Date operator-(Date date, Date date1)
{
    Date date2;
    date2.day = date.day - date1.day;
    date2.month = date.month - date1.month;
    date2.year = date.year - date1.year;

    if ((date2.day) < 0)
    {
        date2.month -= 1;
        date2.day += 31;
    }
    if ((date2.month) < 0)
    {
        date2.year -= 1;
        date2.month += 12;
    }
    return date2;
}

int main()
{
    int hour = 0;
    int minute = 0;
    int second = 0;

    int day = 0;
    int month = 0;
    int year = 0;
    cout << "---Enter time (i.e hh:mm:ss): ";
    cin >> hour >> minute >> second;

    Time t1(hour, minute, second);
    t1.display();

    cout << "\n--Copy Constructor" << endl;
    Time t2(t1);
    t2.display(); // Display

    Time t3;

    t3 = t1 + t2;
    cout << "\n--Addition of two time: ";
    t3.display();

    t3 = t1 - t2;
    cout << "\n--Subtraction of two time: ";
    t3.display();

    cout << "\n---Enter date (i.e dd/mm/yyyy): ";
    cin >> day >> month >> year;


    Date d1(day, month, year, hour, minute, second);
    d1.display();
   
    cout << "\n--Copy Constructor" << endl;
    Date d2(d1);
    d2.display(); // Display

    Date d3;
    d3 = d1 + d2;
    cout << "\n--Addition of two date: ";
    d3.display();

    d3 = d1 - d2;
    cout << "\n--Subtraction of two date: ";
    d3.display();



    return 0;
}