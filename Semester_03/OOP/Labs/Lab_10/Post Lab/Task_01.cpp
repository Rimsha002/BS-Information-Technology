#include <iostream>
#include <vector>
#include <algorithm>
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

class Course
{
protected:
    string courseName;
    int capacity;
    int creditHours;
    int enrolled;
    int courseID;

public:
    Course()
    {
        courseName = "";
        capacity = 0;
        creditHours = 0;
        courseID++;
        
    }
    Course(string courseName, int capacity, int creditHours)
    {
        this->courseName = courseName;
        this->capacity = capacity;
        this->creditHours = creditHours;
        enrolled = 0;
        courseID = Person::id;
    }
    int getID() const
    {
        return courseID;
    }
    int getCapacity() const
    {
        return capacity;
    }
    int getEnrolled() const
    {
        return enrolled;
    }
    void incrementEnrolled()
    {
        enrolled++;
    }
    void decrementEnrolled()
    {
        enrolled--;
    }
    string getCourseName() const
    {
        return courseName;
    }

};

class Student : public Person
{
    vector<Course *> courses; 
public:
    void addCourse(Course *c)
    {
        courses.push_back(c);
    }
    void dropCourse(int courseID)
    {
        auto it = find_if(courses.begin(), courses.end(), [&](const Course *c)
                          { return c->getID() == courseID; });
        if (it != courses.end())
        {
            courses.erase(it);
            (*it)->decrementEnrolled(); 
        }
        else
        {
            cout << "Error: Student is not enrolled in this course." << endl;
        }
    }
    void viewCourses() const
    {
        cout << "Courses enrolled by student: " << endl;
        for (const Course *c : courses)
        {
            cout << "- " << c->getID() << ": " << c->getCourseName() << endl;
        }
    }
    void display() override
    {
        cout << "Student ID: " << getID() << endl;
        cout << "Name: " << getName() << endl;
    }

// overload () operator
    string operator()(string name)
    {
        return name;
    }

};

// Main function

int main()
{
    vector<Student> students;
    vector<Course> courses;

    Student std1;
    while (true)
    {
        cout << "1. Create new student" << endl;
        cout << "2. Create new course" << endl;
        cout << "3. Enroll student in a course" << endl;
        cout << "4. Drop student from a course" << endl;
        cout << "5. View courses of a student" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string name;
            cout << "Enter student name: ";
            getline(cin, name);
            students.push_back(Student());
            sort(students.begin(), students.end(), [](Student &a, Student &b)
                 { return a.getID() < b.getID(); });
        }
        else if (choice == 2)
        {
            string name;
            int capacity, creditHours;
            cout << "Enter course name: ";
            cin >> name;
            cout << "Enter capacity: ";
            cin >> capacity;
            cout << "Enter credit hours: ";
            cin >> creditHours;
            courses.push_back(Course(name, capacity, creditHours));
        }
        else if (choice == 3)
        {
            int studentID, courseID;
            cout << "Enter student ID: ";
            cin >> studentID;
            cout << "Enter course ID: ";
            cin >> courseID;

            auto student = find_if(students.begin(), students.end(), [&](const Student &s)
                                           { return s.getID() == studentID; });
            auto course = find_if(courses.begin(), courses.end(), [&](const Course &c)
                                          { return c.getID() == courseID; });

            if (student != students.end() && course != courses.end())
            {
                
                if ((*course).getCapacity() == (*course).getEnrolled())
                {
                    cout << "Error: Course is full." << endl;
                }
                else
                {
                    (*student).addCourse(&(*course)); 
                    (*course).incrementEnrolled();    
                }
            }
            else
            {
                cout << "Error: Student or Course not found." << endl;
            }
        }
        else if (choice == 4)
        {
            int studentID, courseID;
            cout << "Enter student ID: ";
            cin >> studentID;
            cout << "Enter course ID: ";
            cin >> courseID;

            auto student = find_if(students.begin(), students.end(), [studentID](const Student &s)
                                   { return s.getID() == studentID; });
            if (student != students.end())
            {
                (*student).dropCourse(courseID);
            }
            else
            {
                cout << "Error: Student not found." << endl;
            }
        }
        else if (choice == 5)
        {
            int studentID;
            cout << "Enter student ID: ";
            cin >> studentID;

            auto student = find_if(students.begin(), students.end(), [&](Student &s)
                                   { return s.getID() == studentID; });
            if (student != students.end())
            {
                (*student).viewCourses();
            }
            else
            {
                cout << "Error: Student not found." << endl;
            }
        }
        else if (choice == 6)
        {
            break;
        }
    }

    return 0;
}