#ifndef GENERAL_INFO_H
#include <iostream>
#include "Address.h"
#include <vector>
using namespace std;

class General_Info
{
   string first_Name;
   string last_Name;
   string cnic;
   static vector<string> vCNIC;
   char gender;

   friend istream &operator>>(istream &i, General_Info &general_info);
   friend ostream &operator<<(ostream &o, const General_Info &genaral_Info);
   friend void Cnic(General_Info &general_info, string c);
   friend void Gender(General_Info &general_info, char g);

public:
   Address address;
   General_Info()
   {
      first_Name = " ";
      last_Name = " ";
      cnic = "";
      gender = 'M';
      address = Address();
   }

   General_Info(string f, string l, string c, char g, Address a)
   {
      first_Name = f;
      last_Name = l;

      // CNIC
      Cnic(*this, c);

      // gender
      Gender(*this, g);

      // Adress
      address = a;
   }

   // Copy Constructor
   General_Info(const General_Info &obj)
   {
      first_Name = obj.first_Name;
      last_Name = obj.last_Name;
      cnic = obj.cnic;
      for (int i = 0; i < obj.vCNIC.size(); i++)
      {
         vCNIC.push_back(obj.vCNIC[i]);
      }
      gender = obj.gender;
      address = obj.address;
   }

   // Destructor
   ~General_Info()
   {
   }

   // Setter
   void setFirtName(string f)
   {
      first_Name = f;
   }
   void setLastName(string l)
   {
      last_Name = l;
   }
   void setGender(char g)
   {
      if (g != 'M' || g != 'F')
      {
         cout << "Invalid Gender" << endl;
         while (g != 'M' || g != 'F')
         {
            cout << "Enter valid Gender( M for male, F for female)" << endl;
            cin >> g;
         }
      }
      gender = g;
   }
   void setCnic(string cnic)
   {
      Cnic(*this, cnic);
   }

   // Getter
   string getFirstName()
   {
      return first_Name;
   }
   string getLastName()
   {
      return last_Name;
   }
   string getCnic()
   {
      return cnic;
   }
   char getGender()
   {
      return gender;
   }

   // Display
   void display()
   {
      cout << "\n\t--General Info Details--\n";
      cout << "First Name: " << first_Name << endl;
      cout << "Last Name: " << last_Name << endl;
      cout << "CNIC: ";
      for (int j = 0; j < vCNIC.size(); j++)
      {
         for (int i = 0; i < cnic.size(); i++)
         {
            cout << cnic[i];
            if (i == 4 || i == 11)
            {
               cout << "-";
            }
         }
      }
      cout << endl;

      cout << "Gender: " << gender << endl;
      cout << address;
   }

   // Overload Assigment operator
   General_Info &operator=(const General_Info &obj)
   {
      first_Name = obj.first_Name;
      last_Name = obj.last_Name;
      cnic = obj.cnic;
      for (int i = 0; i < obj.vCNIC.size(); i++)
      {
         vCNIC.push_back(obj.vCNIC[i]);
      }
      gender = obj.gender;
      address = obj.address;

      return *this;
   }
};

// Declaration of static variable
vector<string> General_Info::vCNIC;

// Extraction operator
istream &operator>>(istream &i, General_Info &general_info)
{
   cout << "\n````Enter General Info Details````\n" << endl;
        cin.ignore();
   cout << "Enter First Name: ";
   getline(i, general_info.first_Name);

   cout << "Enter Last Name: ";
   getline(i, general_info.last_Name);

   cout << "Enter CNIC: ";
   i >> general_info.cnic;
   Cnic(general_info, general_info.cnic);

   cout << "Enter Gender?(M for male, F for female): ";
   i >> general_info.gender;
   Gender(general_info, general_info.gender);

   i >> general_info.address;
   return i;
}

// Insertion Operator
ostream &operator<<(ostream &o, const General_Info &genaral_Info)
{
   o << "\n---General Info Details---\n";
   o << "First Name: " << genaral_Info.first_Name << endl;
   o << "Last Name: " << genaral_Info.last_Name << endl;
   o << "CNIC: ";
   for (int j = 0; j < genaral_Info.vCNIC.size(); j++)
   {
      for (int i = 0; i < genaral_Info.cnic.size(); i++)
      {
         cout << genaral_Info.cnic[i];
         if (i == 4 || i == 11)
         {
            cout << "-";
         }
      }
   }
   cout << endl;
   o << "Gender: " << genaral_Info.gender << endl;

   o << genaral_Info.address;
   return o;
}

// Function for CNIC
void Cnic(General_Info &general_info, string c)
{
   try
   {
      if (find(general_info.vCNIC.begin(), general_info.vCNIC.end(), c) != general_info.vCNIC.end())
      {
         throw("CNIC already exists");
      }
      if (general_info.cnic.size() == 0 || general_info.cnic.size() < 13 || general_info.cnic.size() > 13)
      {
         throw("Invalid CNIC");
      }
   }
   catch (const char *msg)
   {
      cout << msg << endl;
      while (general_info.cnic.size() != 13)
      {
         cout << "Enter valid CNIC (13-digits): ";
         cin >> general_info.cnic;
      }
   }

   general_info.vCNIC.push_back(general_info.cnic);
}

// Function for Gender
void Gender(General_Info &general_info, char g)
{

   if (g != 'M' && g != 'F')
   {
      cout << "Invalid Gender" << endl;
      while (g != 'M' && g != 'F')
      {
         cout << "Enter valid Gender( M for male, F for female)" << endl;
         cin >> g;
      }
   }
   general_info.gender = g;
}

#endif