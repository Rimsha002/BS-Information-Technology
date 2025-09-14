#include <iostream>
#include <exception>
#include <string>
#include <vector>
using namespace std;
class Course
{
    int course_id;
    string name;
    float credit_hours;

public:
    Course(int course_id, string name, float credit_hours) : course_id(course_id), name(name), credit_hours(credit_hours) {}
    int get_course_id() const { return course_id; }
    string get_name() const { return name; }
    float get_credit_hours() const { return credit_hours; }
    void display()
    {
        cout << "Course ID: " << course_id << endl;
        cout << "Course title: " << name << endl;
        cout << "Course Credit Hours: " << credit_hours << endl;
    }
};

class OfferedCourses
{

public:
    vector<Course> courses;
    void addCourse()
    {
        try
        {
            int course_id = 0;
            string course_name = "";
            float credit_hours = 0.0;
            cout << "Enter course Id: ";
            cin >> course_id;
            for (int i = 0; i < courses.size(); i++)
            {
                if (courses[i].get_course_id() == course_id)
                {
                    throw invalid_argument("Course with this ID already exists!");
                }
            }
            cin.ignore();
            cout << "Enter course name: ";
            getline(cin, course_name);
            if (course_name == "")
            {
                throw invalid_argument("Course Title cannot be empty!");
            }
            cout << "Enter course credit Hours: ";
            cin >> credit_hours;
            if (credit_hours <= 0)
            {
                throw invalid_argument("Course Credit hours must be greater than zero!");
            }
            Course course(course_id, course_name, credit_hours);
            courses.push_back(course);
            cout << "Course added to offered courses successfully!" << endl;
        }
        catch (exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }

    void removeCourse()
    {
        try
        {
            int course_id = 0;

            cout << "Enter course Id to remove: ";
            cin >> course_id;
            bool flag = false;
            vector<Course> temp;
            for (int i = 0; i < courses.size(); i++)
            {
                if (courses[i].get_course_id() != course_id)
                {
                    temp.push_back(courses[i]);
                }
                else
                {
                    flag = true;
                }
            }
            cin.ignore();
            if (!flag)
            {
                throw invalid_argument("Course with this ID does not exist!");
            }
            courses = temp;
            cout << "Course removed successfully!" << endl;
        }
        catch (exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }

    void DisplayAllCourses()
    {
        try
        {
            bool flag = false;
            for (int i = 0; i < courses.size(); i++)
            {
                flag = true;
                courses[i].display();
            }
            if (!flag)
            {
                throw invalid_argument("No Course to display!");
            }
        }
        catch (exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
};
class Student
{
    string rollnum;
    string name;
    vector<Course> courses;

public:
    Student(string rollnum, string name)
    {
        this->rollnum = rollnum;
        this->name = name;
    }
    string getRollnum()
    {
        return rollnum;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Rollnum: " << rollnum << endl;
        cout << "Enrolled Courses: " << endl;
        bool flag = false;
        for (int i = 0; i < courses.size(); i++)
        {
            flag = true;
            courses[i].display();
        }
        if (!flag)
        {
            cout << "Student is not enrolled in any Course!" << endl;
        }
    }
    void addCourse(OfferedCourses &offeredcourses)
    {
        int id;
        cout << "Following are the courses being offered to the student: \n"
             << endl;
        offeredcourses.DisplayAllCourses();
        if (offeredcourses.courses.size() == 0)
        {
            return;
        }
        cout << "Enter the ID of the course you want to enroll in: ";
        cin >> id;

        bool courseFound = false;
        for (const Course &course : offeredcourses.courses)
        {
            if (course.get_course_id() == id)
            {
                courseFound = true;
                for (const Course &enrolledCourse : courses)
                {
                    if (enrolledCourse.get_course_id() == id)
                    {
                        cout << "Student is already enrolled in this course!" << endl;
                        return;
                    }
                }
                courses.push_back(course);
                cout << "Course added successfully for the student!" << endl;
                break;
            }
        }

        if (!courseFound)
        {
            cout << "Please select one of the offered courses!" << endl;
        }
    }

    void DropStudent()
    {
        try
        {
            if (courses.empty())
            {
                throw invalid_argument("Student is not enrolled in any courses.");
            }

            cout << "Student is enrolled in the following courses: " << endl;
            for (Course &course : courses)
            {
                course.display();
            }

            cout << "Enter the ID of the course to drop: ";
            int id;
            cin >> id;

            bool courseFound = false;
            vector<Course> temp;
            for (const Course &course : courses)
            {
                if (course.get_course_id() != id)
                {
                    temp.push_back(course);
                }
                else
                {
                    courseFound = true;
                }
            }

            if (!courseFound)
            {
                throw invalid_argument("Course with this ID does not exist!");
            }

            courses = temp;
            cout << "Course dropped successfully for the student." << endl;
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }

    void displayAllEnrolledCourses()
    {
        if (courses.size() == 0)
        {
            cout << "Student is not enrolled in any courses." << endl;
        }
        else
        {
            cout << "Student is enrolled in following courses: ";
            for (int i = 0; i < courses.size(); i++)
            {

                courses[i].display();
            }
        }
    }
};
int main()
{

    OfferedCourses offeredcourses;
    vector<Student> students;

    bool flag = true;
    int choice = 0;
    while (flag)
    {
        cout << "\n**********     Welcome to Student Course Management System     ********\n"
             << endl;
        cout << "1)- Add a new Course to offered courses." << endl;
        cout << "2)- Remove a course from offered courses." << endl;
        cout << "3)- Display all offered courses." << endl;
        cout << "4)- Add a Student." << endl;
        cout << "5)- Remove a student." << endl;
        cout << "6)- Display all students." << endl;
        cout << "7)- Assign a student a course from one of the offered courses." << endl;
        cout << "8)- Drop a student from a course." << endl;
        cout << "9)- Display all courses in which a student is enrolled." << endl;
        cout << "10)- Exit." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            offeredcourses.addCourse();
            break;
        }
        case 2:
        {
            offeredcourses.removeCourse();
            break;
        }
        case 3:
        {
            offeredcourses.DisplayAllCourses();
            break;
        }
        case 4:
        {
            cin.ignore();
            string rollnum = "";
            string name = "";
            cout << "Enter Roll number: ";
            getline(cin, rollnum);
            cout << "Enter name: ";
            getline(cin, name);
            if (name == "" || rollnum == "")
            {
                cout << "Name and roll number cannot be empty!" << endl;
            }
            else
            {
                Student student(rollnum, name);
                bool is_roll_found = false;
                for (auto s : students)
                {
                    if (s.getRollnum() == student.getRollnum())
                    {
                        is_roll_found = true;
                    }
                }
                if (is_roll_found)
                {
                    cout << "Student with Roll No already exists!" << endl;
                }
                else
                {

                    students.push_back(student);
                }
            }
            break;
        }
        case 5:
        {
            string rollnum = "";
            cout << "Enter Student roll number to remove: ";
            cin.ignore();
            getline(cin, rollnum);
            bool flag = false;
            vector<Student> temp;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].getRollnum() != rollnum)
                {
                    temp.push_back(students[i]);
                }
                else
                {
                    flag = true;
                }
            }
            if (!flag)
            {
                cout << "Student with roll number " << rollnum << " does not exist!" << endl;
            }
            else
            {
                students = temp;
                cout << "Student with roll number " << rollnum << " removed successfully!" << endl;
            }
            break;
        }

        case 6:
        {
            int count = 1;
            cout << "All Students: " << endl;
            for (int i = 0; i < students.size(); i++)
            {
                cout << "\nStudent: " << count++ << " \n"
                     << endl;
                students[i].display();
            }
            break;
        }
        case 7:
        {
            string rollnum = "";
            cout << "Enter Student roll number: ";
            cin.ignore();
            getline(cin, rollnum);
            bool flag = false;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].getRollnum() == rollnum)
                {
                    flag = true;
                    students[i].addCourse(offeredcourses);
                }
            }
            if (!flag)
            {
                cout << "Student with roll number does not exist!" << endl;
            }
            break;
        }

        case 8:
        {
            string rollnum = "";
            cout << "Enter Student roll number to remove: ";
            cin.ignore();
            getline(cin, rollnum);

            bool studentFound = false;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].getRollnum() == rollnum)
                {
                    studentFound = true;
                    students[i].DropStudent();
                    break;
                }
            }

            if (!studentFound)
            {
                cout << "Student with roll number " << rollnum << " does not exist!" << endl;
            }
        }
        break;

        case 9:
        {
            cin.ignore();
            string rollnum = "";
            cout << "Enter Student roll number to display its all courses: ";
            getline(cin, rollnum);
            bool flag = false;
            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].getRollnum() == rollnum)
                {

                    flag = true;
                    students[i].displayAllEnrolledCourses();
                }
            }
            
            if (!flag)
            {
                cout << "Student with roll number does not exists!" << endl;
            }
        
            break;
        }
        case 10:
        {
            flag = false;
            cout << "Goodbye!!" << endl;
        }
        }
    }
    return 0;
}
