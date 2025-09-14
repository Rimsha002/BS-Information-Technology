#include <iostream>
#include <vector>

//Error: Unable to run invalid input
using namespace std;

class Time
{
    int hour;
    int minute;
    int second;

public:
    Time(int h = 0, int m = 0, int s = 0)
    {
        if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60)
        {
            this->hour = h;
            this->minute = m;
            this->second = s;
        }
        else
        {
            cout << "Invalid time" << endl;
        }
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
};

class Date
{
    int day;
    int month;
    int year;

public:
    Date(int d = 0, int m = 0, int y = 0)
    {
        if (d >= 0 && d <= 31 && m >= 0 && m <= 12 && y >= 0)
        {
            this->day = d;
            this->month = m;
            this->year = y;
        }
        else
        {
            cout << "Invalid date" << endl;
        }
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
    void setMonth(int m)
    {
        if (m >= 0 && m <= 12)
        {
            this->month = m;
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
};

class Event
{
private:
    string title;
    int hour; // Time
    int min;
    int second;
    int day; // Date
    int month;
    int year;
    Time time;
    Date date;

public:
    Event(string title,
          int hour,
          int min,
          int second,
          int day,
          int month,
          int year)
           : time(hour, min, second), date(day, month, year)
    {
        this->title = title;
        this->hour = hour;
        this->min = min;
        this->second = second;
        this->day = day;
        this->month = month;
        this->year = year;
    }
    ~Event()
    {

    }

    void setTitle(string title)
    {
        this->title = title;
    }
    string getTitle()
    {
        return this->title;
    }
    void setTime(int h, int min, int s)
    {
        time.setHour(h);
        time.setMinute(min);
        time.setSecond(s);
    }
    void setDate(int d, int mon, int y)
    {
        date.setDay(d);
        date.setMonth(mon);
        date.setYear(y);
    }

    void printEventData()
    {
        cout << title << " occures on " << date.getDay() << "/" << date.getMonth() << "/" << date.getYear() << " at " << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond() << endl;
    }
};

int main()
{

    string title;
    int day = 0;
    int month = 0;
    int year = 0;
    int hour = 0;
    int minute = 0;
    int second = 0;

    vector<Event> events;

    cout << "Enter Event title: ";
    cin >> title;
    // event.setTitle(title);
    cout << "Enter Event date (i.e dd/mm/yyyy): ";
    cin >> day >> month >> year;
    cout << "Enter Event time (i.e hh:mm:ss): ";
    cin >> hour >> minute >> second;

    // event.setTime(hour, minute, second);
    // event.setDate(day, month, year);
    Event event(title, hour, minute, second, day, month, year);
    events.push_back(event);

    for (int i = 0; i < events.size(); i++)
    {
        events[i].printEventData();
    }

    return 0;
}