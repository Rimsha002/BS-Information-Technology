#ifndef STAFF_H

#include <iostream>
#include "Date.h"
#include "General_Info.h"
using namespace std;

class Staff
{
   static int staff_ID;
   string role;
   Date employment_Date;
   General_Info general_info;
   int salary;

public:
   Staff()
   {
      role = "";
      salary = 0;
      employment_Date = Date();
      general_info = General_Info();
      staff_ID++;
   }

   // Prameterize Constructor
   Staff(string r, Date date, General_Info general, int s)
   {
      role = r;
      employment_Date = date;
      general_info = general;
      salary = s;
      staff_ID++;
   }

   // Prameterize Constructor 2
   Staff( int s)
   {
      cout << "Hello1";
      cin >> *this; // to set role and date
      cout << "Hello2";
      cin.ignore();
      cin >> general_info;
      salary = s;
      staff_ID++;
      cout << "Hello3";
   }

   // Destructor
   ~Staff()
   {
   }

   // Copy constructor

   Staff(const Staff &obj)
   {
      role = obj.role;
      employment_Date = obj.employment_Date;
      general_info = obj.general_info;
      salary = obj.salary;
   }

   // Setter
   void setRole(string r)
   {
      role = r;
   }
   void setEmployment_Date(Date date)
   {
      employment_Date = date;
   }
   void setGeneral_Info(General_Info general)
   {
      general_info = general;
   }
   void setSalary(int s)
   {
      salary = s;
   }

   // Getter
   int getStaff_ID()
   {
      return staff_ID;
   }
   string getRole()
   {
      return role;
   }
   Date getEmployment_Date()
   {
      return employment_Date;
   }
   General_Info getGeneral_Info()
   {
      return general_info;
   }
   int getSalary()
   {
      return salary;
   }

   // Display
   void display()
   {
      cout << "\n\t---Staff Information---\n"
           << endl;
      cout << "Staff ID: " << staff_ID << endl;
      cout << "Role: " << role << endl;
      cout << "Employment Date: " << employment_Date << endl;
      cout << general_info << endl;
      cout << "Salary: " << salary << endl;
   }

   friend istream &operator>>(istream &i, Staff &staff);
   friend ostream &operator<<(ostream &o, const Staff &staff);
};

int Staff::staff_ID = 0;

// Extraction
istream &operator>>(istream &i, Staff &staff)
{
   cout << "\n````Enter Staff Details````" << endl
        << endl;

   cout << "Enter Role: " << endl;
   int choice;
   string role;
   cout << "1. Pharmacist" << endl;
   cout << "2. Technician" << endl;
   cout << "3. Assistant" << endl;
   cout << "Select any option" << endl;
   i >> choice;

   switch (choice)
   {
   case 1:
      role = "Pharmacist";
      break;
   case 2:
      role = "Technician";
      break;
   case 3:

      role = "Assistant";
      break;
   default:

      cout << "Invalid Choice" << endl;
   }

   staff.setRole(role);

   cout << "Enter Employment Date: ";
   i >> staff.employment_Date;

   return i;
}

// Insertion
ostream &operator<<(ostream &o, const Staff &staff)
{
   o << "\n---Staff Information---\n";
   o << "Staff ID: " << staff.staff_ID << endl;
   o << "Role: " << staff.role << endl;
   o << "Employment Date: " << staff.employment_Date << endl;

   return o;
}

#endif
