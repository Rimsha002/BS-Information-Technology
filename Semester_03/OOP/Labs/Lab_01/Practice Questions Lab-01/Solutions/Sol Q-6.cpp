#include<iostream>
#include<string>
using namespace std;


struct Student
{
   string name;
   int age;
   string program;
};

int main()
{
    struct Student p;
    cout << "Enter Student name : ";
    getline(cin,p.name);
    cout << "Enter Student age : ";
    cin >> p.age;
    cout << "Enter Student Program : ";
    cin >> p.program;


    cout << "Student Name = " << p.name << endl;
    cout << "Student Age = " << p.age << endl;
    cout << "Student Program = " << p.program << endl;
    return 0;
}
