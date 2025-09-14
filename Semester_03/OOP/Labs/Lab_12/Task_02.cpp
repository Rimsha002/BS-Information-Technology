#include <iostream>
using namespace std;

// Student Record
class Student
{
protected:
    string name;
    string department;

public:
    Student(){};
    Student(string n, string d)
    {
        name = n;
        department = d;
    }
    virtual void get_data() = 0;
    virtual void show_data() = 0;
    virtual ~Student(){};
};

class Medical: public Student
{
    public:
    Medical(): Student(){};
    Medical(string n, string d): Student(n, d){};

    void get_data()
    {
        cout << "\n--Data for Medical Student--\n";
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter department: ";
        cin >> department;
    }

    void show_data()
    {
        cout << "\n\t--Medical Student--" << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
    }

    ~Medical(){    };
};

//Engineering
class Engineering :public Student
{
    public:
    Engineering(): Student(){};
    Engineering(string n, string d): Student(n, d){};

    void get_data()
    {
        cout << "\n--Data for Engineering Student--\n";
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter department: ";
        cin >> department;
    }

    void show_data()
    {
        cout << "\n\t--Engineering Student--" << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
    }

    ~Engineering(){    };
};

// Science
class Science : public Student
{
    public:
    Science(): Student(){};
    Science(string n, string d): Student(n, d){};

    void get_data()
    {
        cout << "\n--Data for Science Student--\n";
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter department: ";
        cin >> department;
    }

    void show_data()
    {
        cout << "\t--Science Student--" << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
    }

    ~Science(){};
};



int main()
{
    Medical medi;
    Engineering engi;
    Science sci;

    Student * std[3] = {&medi, &engi, &sci};

    for(int i = 0; i < 3; i++)
    {
        std[i]->get_data();
    }

    for(int i = 0; i < 3; i++)
    {
        std[i]->show_data();
    }
    

    return 0;
}