#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    int age;
    string program;

    void displayDetail()
    {
        cout << "Student Name = " <<name << endl;
        cout << "Student Age = " << age << endl;
        cout << "Student Program = " << program << endl;
    }
};

int main()
{
    Student p;
    cout << "Enter Student name : ";
    getline(cin, p.name);
    cout << "Enter Student age : ";
    cin >> p.age;
    cout << "Enter Student Program : ";
    cin >> p.program;


    cout << "Student Details " << endl;
    p.displayDetail();

    return 0;
}
