#ifndef SALESMAN_H

#include <iostream>
// #include "General_Info.h"
#include "Pharma_Company.h"
using namespace std;

class Salesman
{
   static int Saleman_ID;

   int set_Commission;
   int obtained_Commission;
   General_Info general_info;
   Pharma_Company company;
   string *selected_medicine;
   int selected_medicine_size = 10;

   int select_range;

   friend istream &operator>>(istream &i, Salesman &salesman);
   friend ostream &operator<<(ostream &o, const Salesman &salesman);

public:
   Salesman()
   {
      Saleman_ID++;
      general_info = General_Info();
      company = Pharma_Company();
      set_Commission = 0;
      obtained_Commission = 0;

      selected_medicine_size = 10;
      selected_medicine = new string[selected_medicine_size];
   }

   // Parametrize
   Salesman(General_Info &general, Pharma_Company &comp, int set, int obtain)
   {

      general_info = general;
      company = comp;

      set_Commission = set;
      obtained_Commission = obtain;
      Saleman_ID++;
      selected_medicine_size = 10;
      selected_medicine = new string[selected_medicine_size];

      show_Purchase_Medicines();
   }

   // Parametrize Constructor 2
   Salesman(int set, int obtain)
   {
      Saleman_ID++;

      cin >> general_info;

      Pharma_Company comp(comp);
      company = comp;

      set_Commission = set;
      obtained_Commission = obtain;

      selected_medicine_size = 10;
      selected_medicine = new string[selected_medicine_size];

      show_Purchase_Medicines();
   }

   // setter
   void setSaleman_ID(int id)
   {
      Saleman_ID = id;
   }
   void setGeneral_Info(General_Info general)
   {
      general_info = general;
   }
   void setCompany(Pharma_Company c)
   {
      company = c;
   }
   void setSet_Commission(int set)
   {
      set_Commission = set;
   }
   void setObtained_Commission(int obtain)
   {
      obtained_Commission = obtain;
   }

   // getter
   int getSaleman_ID()
   {
      return Saleman_ID;
   }
   General_Info getGeneral_Info()
   {
      return general_info;
   }
   Pharma_Company getCompany()
   {
      return company;
   }
   int getSet_Commission()
   {
      return set_Commission;
   }
   int getObtained_Commission()
   {
      return obtained_Commission;
   }
   // Get selected Medicine
   string *getSelected_Medicine()
   {
      return selected_medicine;
   }
   // Get selected Medicine size
   int getSelectedSize()
   {
      return select_range;
   }

   // Function to show and selected the medicines
   void show_Purchase_Medicines()
   {
      cout << "\nAvailable Medicines of the company are: " << endl;

      vector<Medication> show_medicine = company.getList_of_Medicine();

      for (int i = 0; i < 10; i++)
      {

         cout << "Medicine id. " << i << " = " << show_medicine[i].getMedicine_Name() << endl;
      }
      cout << endl;

      int id;
      cout << "How many medicines you want to purchase: ";
      cin >> select_range;

      cout << "Enter the id of " << select_range << " medicines you want to purchase: ";

      for (int i = 0; i < select_range; i++)
      {
         cin >> id;
         selected_medicine[i] = show_medicine[id].getMedicine_Name();
         cout << i + 1 << " . " << show_medicine[id].getMedicine_Name() << endl;
      }

      cout << "Above Medicines are added to your pharmacy" << endl;
   }
   // Destructor
   ~Salesman()
   {
      delete[] selected_medicine;
   }
   // Display
   void display()
   {
      cout << "\n\t-----Salesman Detail-----\n"
           << endl;
      cout << "Saleman ID: " << Saleman_ID << endl;
      cout << "Set Commission: Rs. " << set_Commission << endl;
      cout << "Obtained Commission: Rs. " << obtained_Commission << endl;
      cout << general_info;
      cout << company;
      cout << "Selected Medicines are: " << endl;
      for (int i = 0; i < select_range; i++)
      {
         cout << i + 1 << ". " << selected_medicine[i] << endl;
      }
      cout << endl;
   }

   // Overload Assignment Operator
   Salesman &operator=(const Salesman &salesman)
   {
      general_info = salesman.general_info;
      company = salesman.company;
      set_Commission = salesman.set_Commission;
      obtained_Commission = salesman.obtained_Commission;
      for (int i = 0; i < select_range; i++)
      {
         selected_medicine[i] = salesman.selected_medicine[i];
      }

      Saleman_ID++;

      return *this;
   }
};

int Salesman::Saleman_ID = 0;

// Extraction Operator
istream &operator>>(istream &i, Salesman &salesman)
{
   cout << "\n````Enter Salesman Details````\n"
        << endl;
   cout << "Set Commission amount: Rs. ";
   i >> salesman.set_Commission;
   cout << "Enter Obtained Commission: Rs. ";
   i >> salesman.obtained_Commission;

   i >> salesman.general_info;

   Pharma_Company comp(comp);
   salesman.company = comp;

   salesman.company.List_of_Medicine(); // to get list form company
   salesman.show_Purchase_Medicines();

   return i;
}

// Insertion
ostream &operator<<(ostream &o, const Salesman &salesman)
{
   o << "\n-----Salesman Detail-----\n"
     << endl;
   o << "Saleman ID: " << salesman.Saleman_ID << endl;
   o << "Set Commission: Rs. " << salesman.set_Commission << endl;
   o << "Obtained Commission: Rs. " << salesman.obtained_Commission << endl;
   o << salesman.general_info;
   o << salesman.company;
   o << "Selected Medicines are: " << endl;
   for (int i = 0; i < salesman.select_range; i++)
   {
      o << i + 1 << ". " << salesman.selected_medicine[i] << endl;
   }

   return o;
}

#endif
