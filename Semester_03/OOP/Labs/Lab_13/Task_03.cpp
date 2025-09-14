#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class StudentRecord
{
private:
    string name;
    int id;
    float gpa;
    vector<string> courses;

public:
    StudentRecord()
    {
        name = "";
        id = 0;
        gpa = 0;
    };

    StudentRecord(string n, int id, float gpa, vector<string> course)
    {
        name = "";
        this->id = 0;
        this->gpa = 0;
        for (int i = 0; i < course.size(); i++)
        {
            courses[i] = course[i];
        }
    };

    ~StudentRecord(){};

    void setStudentData()
    {
        int num;

        cout << "Enter the name of student: ";
        cin >> name;
        cout << "Enter the id of student: ";
        cin >> id;
        cout << "Enter the GPA of student: ";
        cin >> gpa;
        cout << "How many courses student study? ";
        cin >> num;

        for (int i = 0; i < num; i++)
        {
            string cname;
            cout << "Enter the name of course: ";
            cin >> cname;
            courses.push_back(cname);
        }
    }

    void printStudentData()
    {
        cout << "Student name: " << name << endl;
        cout << "Student ID: " << id << endl;
        cout << "Student GPA: " << gpa << endl;

        for (int i = 0; i < courses.size(); i++)
        {
            cout << courses[i] << " " << endl;
        }
    }

    void writeToFile(ofstream &out) // to write on file
    {
        out << "Student name: " << name << endl;
        out << "Student ID: " << id << endl;
        out << "Student GPA: " << gpa << endl;

        for (int i = 0; i < courses.size(); i++)
        {
            out << courses[i] << ", " << endl;
        }
    }

    //To read form file
    

    void ReadFromFile(ifstream &in) // to read from file
    {
        string nam;
        int ID;
        float GPA;
        vector<string> studcourse;

        getline(in, nam);
        in >> ID;
        in >> GPA;

        for (int i = 0; i < courses.size(); i++)
        {
            in >> studcourse[i];
        }

        cout << "Student name: " << name << endl;
        cout << "Student ID: " << id << endl;
        cout << "Student GPA: " << gpa << endl;
        cout << "Student courses: " << gpa << endl;

        for (int i = 0; i < courses.size(); i++)
        {
            cout << courses[i] << "  " << endl;
        }
    }
};

int main()
{

    StudentRecord stud[5];
    ofstream out("studentRecord.txt");
    ifstream in("studentRecord.txt");

    cout << "  Enter the data for 5 student  " << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << "\t---Student no " << i + 1 << "---" << endl;
        stud[i].setStudentData();

        cout << "Write to file " << endl;
        stud[i].writeToFile(out);

        cout << "Read from file " << endl;
        stud[i].ReadFromFile(in);
    }

    return 0;
}