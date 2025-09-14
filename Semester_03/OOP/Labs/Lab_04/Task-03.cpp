#include <iostream>
#include <vector>
using namespace std;

class Course
{
private:
    int iD;
    string name;
    int creditHr;

public:
    Course(int id = 0, string name,
           int hr)
    {
        this->iD = id;
        this->name = name;
        this->creditHr = hr;
    }
};

class OfferedCourse
{

    vector<Course> course;
    int noOfCourses;

public:
    int getNumberOfCourses()
    {
        return noOfCourses = course.size();
    }
};

class Student
{
private:
    string rollNo;
    string name;
    vector<Course> course;

public:
    void setrollNo(int roll)
    {
        this->rollNo = roll;
    }
    void setName(int name)
    {
        this->name = name;
    }
    string getRoll()
    {
        return rollNo;
    }
    string getName()
    {
        return name;
    }
    void addNew()
    {
        cout << "Enter new course name:";
        string newC;
        // course.push_back(newC);
    }
};
int main()
{

    return 0;
};
