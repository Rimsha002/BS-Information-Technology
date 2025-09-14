#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    int cnic;
    string personName;
    string fatherName;
    int phoneNo;
    string address;

public:
    Person(int cnic = 0,
           string personName = "",
           string fatherName = "",
           int phoneNo = 0,
           string address = "")
    {
        this->cnic = cnic;
        this->personName = personName;
        this->fatherName = fatherName;
        this->phoneNo = phoneNo;
        this->address = address;
    }
    // Setters
    void setCNIC(int cnic)
    {
        this->cnic = cnic;
    }
    void setPName(string personName)
    {
        this->personName = personName;
    }
    void setFName(string fatherName)
    {
        this->fatherName = fatherName;
    }
    void setPhone(int phoneNo)
    {
        this->phoneNo = phoneNo;
    }
    void setAddress(string address)
    {
        this->address = address;
    }
    // Getters
    int getCnic()
    {
        return cnic;
    }
   string getPName()
    {
        return personName;
    }
    string getFName()
    {
        return fatherName;
    }
    int getPhone()
    {
        return phoneNo;
    }
    string getAddress()
    {
        return address;
    }

    // Display Function
    void displayPerson()
    {
        cout << "CNIC: " << cnic << endl;
        cout << "Buyer Name: " << personName << endl;
        cout << "Father Name: " << fatherName << endl;
        cout << "Phone No: " << phoneNo << endl;
        cout << "Address: " << address << endl;
    }
};