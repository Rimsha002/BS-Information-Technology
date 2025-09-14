#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "Date.h"
using namespace std;

class Person
{
protected:
	static int id;
	string firstName;
	string lastName;
	long long int cnic; 
	Date dateOfBirth;
	string Address;
	Person* Father;
	Person* Mother;


public:
	Person();

	//Parametrize Constructor
	Person(string firstName, string lastName, long long int cnic,string address, Date dateOfBirth, string fatherName, string motherName);
	
	//Copy Constructor
	Person(const Person& person);

	//Setter
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setCNIC(long long int cnic);
	void setAddress(string address);
	void setDateOfBirth(Date dateOfBirth);
	void setFatherName(string Father);
	void setMotherName(string Mother);

	//Getter
	string getFirstName();
	string getLastName();
	long long int getCNIC();
	string getAddressObject();
	Date getDateOfBirth();
	string getFatherName();
	string getMotherName();

	~Person();

	void displayPerson();

};

int Person::id = 0;

#endif 

