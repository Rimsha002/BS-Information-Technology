#include <iostream>
#include <vector>
using namespace std;

class Person
{
protected:
    string name;

public:
    static int id;

    Person()
    {
        name = "";
        id++;
    }
    Person(string name)
    {
        this->name = name;
        id++;
    }

    // Setter
    void setID(int id)
    {
        this->id = id;
    }
    void setName(string name)
    {
        this->name = name;
    }

    // Getter
    int getID()
    {
        return id;
    }
    string getName()
    {
        return name;
    }

    // Display
    virtual void display()
    {
        cout << "Person ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};
int Person::id = 0;

// Teacher
class Teacher : public Person
{
protected:
    int courseEnrolled;
    string department;

public:
    static int teacherID;

    Teacher() : Person()
    {
        courseEnrolled = 0;
        department = "";
        teacherID++;
    };

    Teacher(string name, int courseEnrolled, string department) : Person(name)
    {
        this->courseEnrolled = courseEnrolled;
        this->department = department;
        teacherID++;
    }

    void setCourseEnrolled(int courseEnrolled)
    {
        this->courseEnrolled = courseEnrolled;
    }
    void setDepartment(string department)
    {
        this->department = department;
    }

    // Getter
    int getCourseEnrolled()
    {
        return courseEnrolled;
    }
    string getDepartment()
    {
        return department;
    }
    int getTeacherID()
    {
        return teacherID;
    }

    // void setStudent()
    // {
    //     setPerson();
    //     cout << "Enter Roll No: " << rollNo << endl;
    //     cout << "Enter Degree : " << degree << endl;
    //     cout << "Enter Department: " << department << endl;
    // }

    void display() override
    {
        cout << "Teacher ID: " << teacherID << endl;
        cout << "Teacher Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Course Enrolled: " << courseEnrolled << endl;
    }
};
int Teacher::teacherID = 0;

// Courses
class Course
{
public:
    string courseName;
    int capcity;
    int creditHours;
    Teacher teacher;

public:
    static int courseID;

    Course()
    {
        courseName = "";
        capcity = 0;
        creditHours = 0;
        courseID++;
        teacher = Teacher();
    }

    Course(string courseName, int capcity, int creditHours, Teacher teacher)
    {
        this->courseName = courseName;
        this->capcity = capcity;
        this->creditHours = creditHours;
        this->teacher = teacher;
        courseID++;
    }
};

int Course::courseID = 0;

//Student
class Student : public Person
{
    Course c1;
public:
    vector <Course> courses;
    Student() : Person()
    {
        c1 = Course();
    }

    void addCourse(Course c1)
    {
        courses.push_back(c1);
    }

    void deleteCourse(int id)
    {
        if(id == c1.courseID)
        {
            courses.erase(courses.begin() + id);
        }
    }

    void upDateCourse(int id, Course c1)
    {
        if(id == c1.courseID)
        {
            courses[id] = c1;
        }
    }

    void display()
    {
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
        cout << "Courses: " ;
        for(int i = 0; i < courses.size(); i++)
        {
            cout << courses[i].courseName << endl;
        }
    }
        

        

    
};

main()
{
   vector <Course> coursesInUni;
   coursesInUni.push_back(Course("OOP", 50, 3, Teacher("Ali", 3, "CS")));
    return 0;
}
