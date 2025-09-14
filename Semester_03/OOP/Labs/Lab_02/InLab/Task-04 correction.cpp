#include <iostream>
#include<string>
using namespace std;

// Task No 04
/*
Create a class Student with attributes:
 Roll number
 Name
 Address
 Degree Program
 Courses Array
 Number of courses
Methods:
 Provide Parameterized Constructor with default values
 Provide function to add a new course
 Provide function to Display all data for a student
*/

class Student
{
private:
    string rollNo;
    string name;
    string degree;
    string *course;
    int noOfCourse;

public:

    // additional argument totalCourse
    Student(string roll, string mName, string mDegree, string *mCourse,int totalCourse, int nOfCourse)
    {
        rollNo = roll;
        name = mName;
        degree = mDegree;
        noOfCourse = nOfCourse;
        // course = mCourse;    // it will point to the same array as it is in the main function so it has to reserved new space for itself and copy data
        course = new string[totalCourse];
        for(int i = 0; i < totalCourse; i++)
        {
            course[i] = mCourse[i];
        }
    }
    // destructor  [it will free the space reserved by the course pointer]
    ~Student()
    {
        if(course)
        {
             delete[] course;
             course = nullptr;
        }
    }	

    void addNewCourse(string newCourse)
    {
        course[noOfCourse] = newCourse;
        noOfCourse++;
    }

    void displayAll()
    {
        cout << "\n ------ Display All Student data ----- \n";

        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Degree Name: " << degree << endl;
        for (int i = 0; i < noOfCourse; i++)
        {
            cout << "Course no " << i + 1 << " :" << course[i] << endl;
        }
        cout << "No of Course: " << noOfCourse << endl;
    }
};

int main()
{

    string *mCourse = new string[10];

    Student student("bitf22m029", "Rimsha", "BSIT", mCourse,10, 0);

    int check = 0;

    cout << " if you want to Add course press 1 therwise 0 :";
    cin >> check;
    cin.sync();

    while (check == 1)
    {
        string newCourse;
        cout << "Enter new course name: ";
        getline(cin, newCourse);
        cin.sync();

        student.addNewCourse(newCourse);
        cout << " Press 1 to countinue add ; therwise 0 :";
        cin >> check;
        cin.sync();
    }

    student.displayAll();


    delete[] mCourse;
    mCourse = nullptr;

    return 0;
}
