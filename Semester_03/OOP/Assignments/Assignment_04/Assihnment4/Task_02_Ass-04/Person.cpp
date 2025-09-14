#include <iostream>
#include "Person.h"
using namespace std;

Person::Person()
{
    firstName = "";
    lastName = "";
    cnic = 0;
    Address = " ";
    dateOfBirth = Date();
    Father = nullptr;
    Mother = nullptr;
}

// Parametrize Constructor
Person::Person(string firstName, string lastName, long long int cnic, string address, Date dateOfBirth, string fatherName, string motherName)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->cnic = cnic;
    this->Address = address;
    this->dateOfBirth = dateOfBirth;
    // Assign memory by dynamic array to father and mother
    Father = new Person();
    Mother = new Person();

    Person::setFatherName(fatherName);
    Person::setMotherName(motherName);
}

// Copy Constructor
Person::Person(const Person &person)
{
    firstName = person.firstName;
    lastName = person.lastName;
    cnic = person.cnic;
    Address = person.Address;
    dateOfBirth = person.dateOfBirth;
    Father = person.Father ? new Person(*person.Father) : nullptr;  
    Mother = person.Mother ? new Person(*person.Mother) : nullptr;  
}

// Destructor
Person::~Person() {
    delete Father;
    delete Mother;
}

// Setter
void Person::setFirstName(string firstName)
{
    this->firstName = firstName;
}
void Person::setLastName(string lastName)
{
    this->lastName = lastName;
}
void Person::setCNIC(long long int cnic)
{
    this->cnic = cnic;
}
void Person::setAddress(string address)
{
    this->Address = address;
}
void Person::setDateOfBirth(Date dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}

void Person::setFatherName(string Father)
{
    this->Father->setFirstName(Father);
}
void Person::setMotherName(string Mother)
{
    this->Mother->setFirstName(Mother);
}

// Getter
string Person::getFirstName()
{
    return firstName;
}
string Person::getLastName()
{
    return lastName;
}
long long int Person::getCNIC()
{
    return cnic;
}
string Person::getAddressObject()
{
    return Address;
}
Date Person::getDateOfBirth()
{
    return dateOfBirth;
}

string Person::getFatherName()
{
    return Father ? Father->getFirstName() : "";
}
string Person::getMotherName()
{
    return Mother ? Mother->getFirstName() : "";
}

// Display
void Person::displayPerson()
{
    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "CNIC: " << cnic << endl;
    cout << "Address: " << Address << endl;
    cout << "Date of Birth: " << dateOfBirth << endl;
    cout << "Father: " << (Father ? Father->getFirstName() + " " + Father->getLastName() : "N/A") << endl;
    cout << "Mother: " << (Mother ? Mother->getFirstName() + " " + Mother->getLastName() : "N/A") << endl;
}
