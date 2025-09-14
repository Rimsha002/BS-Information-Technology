#ifndef PHARMA_COMPANY_H

#include <iostream>
#include "Medication.h"
#include <vector>
using namespace std;

class Pharma_Company
{
   static int company_ID;
   string company_Name;
   string location;
   string medicine_n[10] = {"Panadol", "Disprin", "Brufen", "Cataflam", "Augmentin", "Zithromax", "Ciproxin", "Flagyl", "Diflucan", "Nizoral"};

   vector<Medication> list_of_medicine;

   friend istream &operator>>(istream &i, Pharma_Company &pharma_company);
   friend ostream &operator<<(ostream &o, const Pharma_Company &pharma_company);

public:
   Medication medi;
   Pharma_Company()
   {
      company_ID++;
      company_Name = "";
      location = "";
      list_of_medicine.resize(10);

      for (int i = 0; i < 10; i++)
      {
         string name = medicine_n[i];
         medi.setMedicine_Name(name);
         list_of_medicine.push_back(medi);
      }
   }

   // Parametrize Constructor
   Pharma_Company(string c_name, string loc)
   {
      company_ID++;
      company_Name = c_name;
      location = loc;

      list_of_medicine.clear();

      for (int i = 0; i < 10; i++)
      {
         string name = medicine_n[i];
         medi.setMedicine_Name(name);
         list_of_medicine.push_back(medi);
      }
   }

   // Parametrize Constructor 2

   Pharma_Company(Pharma_Company &company)
   {
      company_ID++;

      cin >> *this; // to set CompanyName and location

      list_of_medicine.clear();

      for (int i = 0; i < 10; i++)
      {
         string name = medicine_n[i];
         medi.setMedicine_Name(name);
         list_of_medicine.push_back(medi);
      }
   }

   // Copy Constructor
   Pharma_Company(const Pharma_Company &obj)
   {
      company_Name = obj.company_Name;
      location = obj.location;
      list_of_medicine = obj.list_of_medicine;
      company_ID++;
   }

   // Setter
   void setCompany_Name(string c)
   {
      company_Name = c;
   }
   void setLocation(string l)
   {
      location = l;
   }
   void setList_of_Medicine(string medicine_names[10])
   {
      list_of_medicine.clear();

      for (int i = 0; i < 10; i++)
      {
         Medication medi;
         string name = medicine_names[i];
         medi.setMedicine_Name(name);
         list_of_medicine.push_back(medi);
      }
   }

   //Create list
   void List_of_Medicine()
   {
      list_of_medicine.clear();

      for (int i = 0; i < 10; i++)
      {
         string name = medicine_n[i];
         medi.setMedicine_Name(name);
         list_of_medicine.push_back(medi);
      }
   }

   // Getter
   int getCompany_ID()
   {
      return company_ID;
   }

   string getCompany_Name()
   {
      return company_Name;
   }
   string getLocation()
   {
      return location;
   }

   vector<Medication> getList_of_Medicine()
   {
      return list_of_medicine;
   }

   ~Pharma_Company()
   {
   }

   // Display
   void display()
   {
      cout << "\n\t---Pharma Company Information---\n"
           << endl;
      cout << "Company ID: " << company_ID << endl;
      cout << "Company Name: " << company_Name << endl;
      cout << "Location: " << location << endl;
      cout << "List of Availabe Medicines: " << endl;
      for (int i = 0; i < 10; i++)
      {
         cout << i + 1 << ". " << list_of_medicine[i].getMedicine_Name() << endl;
      }
      cout << endl;
   }

   // Overload Assignment Operator
   Pharma_Company &operator=(const Pharma_Company &obj)
   {
      company_Name = obj.company_Name;
      location = obj.location;
      list_of_medicine = obj.list_of_medicine;
      company_ID++;

      return *this;
   }
};

int Pharma_Company::company_ID = 0;

// Extraction
istream &operator>>(istream &i, Pharma_Company &pharma_company)
{
   cout << "\n````Enter Pharma Company Details````" << endl
        << endl;
   cout << "Enter Company Name: ";
   getline(i, pharma_company.company_Name);

   cout << "Enter Location: ";
   getline(i, pharma_company.location);

   return i;
}

// Insertion
ostream &operator<<(ostream &o, const Pharma_Company &pharma_company)
{
   o << "\n---Pharma Company Information---\n"
     << endl;
   o << "Company ID: " << pharma_company.company_ID << endl;
   o << "Company Name: " << pharma_company.company_Name << endl;
   o << "Location: " << pharma_company.location << endl;

   return o;
}

#endif
