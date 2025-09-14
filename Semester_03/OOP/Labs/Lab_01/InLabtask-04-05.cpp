#include <iostream>
using namespace std;

//Task no 04
class myClass
{
private:         // Access specifier
    int id;      // Add Semi Colon
    string name; // Add semi colon

public:
    myClass()
    {
        // id = "one"; // not define string in integar type variable
        id = 1;
        name = "Ali"; // String by inverted commas
    }

    void display() // Add data type of function
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};

/*
Task-5: Person Class
create a Employee class:
Attributes:
 CNIC
 Name
 Father’s name
 Address
 Phone

All data members will be hidden from class user.
 Methods:
 Default constructor
 Setters
 Getters
 Display all data
*/

class employeeClass
{
private:
    int cnic;
    string name;
    string fatherName;
    string address;
    int phone;

public:
    employeeClass() // Constractor
    {
        int cnic = 0;
        string name = "0";
        string fatherName = "0";
        string address = "0";
        int phone = 0;
    }

    void setCnic(int c)
    {
        cnic = c;
    }
    int getterCnic()
    {
        return cnic;
    }
    // Name
    void setName(string n)
    {
        name = n;
    }
    string getterName()
    {
        return name;
    }
    // Father Name
    void setfName(string fn)
    {
        fatherName = fn;
    }
    string getterfName()
    {
        return fatherName;
    }

    // Address
    void setAddress(string a)
    {
        address = a;
    }
    string getterAddress()
    {
        return address;
    }
    // Phone
    void setPhone(int pn)
    {
        phone = pn;
    }
    int getterPhone()
    {
        return phone;
    }

    int display()
    {
        cout << "CNIC: " << cnic << endl;
        cout << "Name: " << name << endl;
        cout << "Father's Name: " << fatherName << endl;
        cout << "Address: " << address << endl;
        cout << "Phone No.: " << phone << endl;
    }
};

int main()
{
    //     //Task 01
        // myClass obj;
        // obj.display(); // use obj.
    // Task 02

    employeeClass obj;
    obj.setCnic(12234556);
    obj.setName("Rimsha");
    obj.setfName("Majeed");
    obj.setAddress("Lahore");
    obj.setPhone(234568);
    

    obj.getterCnic();
    obj.getterName();
    obj.getterfName();
    obj.getterAddress();
    obj.getterPhone();

    obj.display();

    return 0;
}