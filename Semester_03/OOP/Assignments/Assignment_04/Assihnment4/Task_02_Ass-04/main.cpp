#include <iostream>
#include "Person.h"
#include <string>

using namespace std;

int main()
{
	cout << "Hello World" << endl;	
	Date d1(12, 5, 1890);
	
	Person p1("Ali", "Ahmed", 123456789, "Karachi", d1, "Ahmed", "Sara");
	p1.displayPerson();



	return 0;
}
