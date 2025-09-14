#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Course
{
    int courseId;
    string name;
    int hour;

public:
    Course(int id = 0, string n = "", int h = 0)
    {
        this->courseId = id;
        this->name = n;
        this->hour = h;
    }
};
class Student
{
    static int rollNo;
    string s_name;
    string degree;
    vector<Course> courses;

public:
    Student() = default;

    Student(string n, string d, vector<Course> course)
    {
        rollNo = rollNo++;
        s_name = n;
        degree = d;
        courses = course;
    }

    void writeData(ofstream &outfile)
    {

    }
    void readData(ofstream &outfile)
    {

    }
    void updateData(ofstream &outfile, int id)
    {

    }
    void deleteData(ofstream &outfile, int id)
    {

    }
};

int Student::rollNo = 0;



//Main
int main()
{
    cout << "\nWelcome to Student Record System" << endl;

    int courseId;
    string name;
    int hour;
    static int rollNo;
    string s_name;
    string degree;
    vector<Course> courses;

    int choice;

    cout << "Enter the Student name: ";
    cin >> s_name;
    cin.ignore();
    cout << "Enter the Student degree: ";
    getline(cin, degree);
    cout << "How many courses student want to study? ";
    int num;
    cin >> num;
    cout << "Enter " << num << "courses detail" << endl;

    for (int i = 0; i < num; i++)
    {
        cout << "Course no " << i + 1 << endl;

        cout << "Enter the course id: ";
        cin >> courseId;
        cin.ignore();
        cout << "Enter the course name: ";
        getline(cin, name);
        cout << "Enter hour of course ";
        cin>> hour;

        Course course(courseId, name, hour);
        courses.push_back(course);
    }

    Student student(s_name, degree, courses);

    do
    {
        cout << "\nSelect the option \n 1-Add Record to File\n 2-Update Record \n 3-Read Record from file\n 4-Delete Record from file\n Enter option or -1 to quite: " << endl;
        cin >> choice;

        if (choice == -1)
        {
            return 0;
        }
        switch (choice)
        {
        case 1:
        {
            cout << "\n---Add Record---" << endl;
            ofstream outFile;
            outFile.open("Student.txt", ios::out);
            if (!outFile)
            {
                cout << "File could not be opened" << endl;
                return 0;
            }
            student.writeData(outFile);
            outFile.close();
            cout << "Data write succefully" << endl;
            break;
        }
        case 2:
        {
            cout << "\n---Update Record---" << endl;
            ofstream outFile;
            outFile.open("Student.txt", ios::out);
            if (!outFile)
            {
                cout << "File could not be opened" << endl;
                return 0;
            }
            cout << "Enter the roll_no whose record you want to Update: ";
            int id;
            cin >> id;
            student.updateData(outFile, id);
            outFile.close();
            cout << "Data Updated succefully" << endl;
            break;
        }
        case 3:
        {
            cout << "\n---Read the Record---" << endl;
            ifstream inFile;
            inFile.open("Student.txt", ios::binary);
            if (!inFile)
            {
                cout << "File could not be opened" << endl;
                return 0;
            }
            student.readData(inFile);
            break;
        }
        case 4:
        {
            cout << "\n---Delete Record---" << endl;
            ofstream outFile;
            outFile.open("Student.txt", ios::binary);
            if (!outFile)
            {
                cout << "File could not be opened" << endl;
                return 0;
            }
            cout << "Enter the student roll no whose record you want to delete: ";
            int id;
            cin >> id;

            student.deleteData(outFile, id);
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }

    } while (choice != -1);

    cout << "\n---GoodBye---" << endl;
    return 0;
}
