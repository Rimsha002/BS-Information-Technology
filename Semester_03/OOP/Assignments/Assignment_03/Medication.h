#ifndef MEDICATION_H

#include <iostream>

using namespace std;

class Medication
{
   static int Medicine_ID;
   string Medicine_Name;
   string description;
   int price;
   int quantity_in_Stock;

   bool isExpired;
   string medicine_Company_Name;

   friend istream &operator>>(istream &i, Medication &medi);
   friend ostream &operator<<(ostream &o, const Medication &medi);

public:
   Date expiry_date;
   // Default Constructor
   Medication()
   {
      Medicine_Name = "";
      description = "";
      price = 0;
      quantity_in_Stock = 0;
      expiry_date = Date();
      isExpired = false;
      medicine_Company_Name = "";
      Medicine_ID++;
   }

   // Parametrize Constructor
   Medication(string name, string desc, int p, int q, Date date, string company_name)
   {
      Medicine_Name = name;
      description = desc;
      price = p;
      quantity_in_Stock = q;
      expiry_date = date;
      medicine_Company_Name = company_name;
      Medicine_ID++;
   }

   // Parametrize Constructor 2
   Medication( string company_name, string desc)
   {
      cin >> *this;

      medicine_Company_Name = company_name;
      description = desc;

      Medicine_ID++;
   }

   // Copy Constructor
   Medication(const Medication &medi)
   {
      Medicine_ID = medi.Medicine_ID;
      Medicine_Name = medi.Medicine_Name;
      description = medi.description;
      price = medi.price;
      quantity_in_Stock = medi.quantity_in_Stock;
      expiry_date = medi.expiry_date;
      isExpired = medi.isExpired;
      medicine_Company_Name = medi.medicine_Company_Name;
      Medicine_ID++;
   }

   // Destructor
   ~Medication()
   {
   }

   // Setter
   void setMedicine_ID(int id)
   {
      Medicine_ID = id;
   }
   void setMedicine_Name(string name)
   {
      Medicine_Name = name;
   }
   void setDescription(string desc)
   {
      description = desc;
   }
   void setPrice(int p)
   {
      price = p;
   }
   void setQuantity_in_Stock(int q)
   {
      quantity_in_Stock = q;
   }
   void setExpiry_Date(Date date)
   {
      expiry_date = date;
   }
   void setIsExpired(bool expired)
   {
      isExpired = expired;
   }
   void setMedicine_Company_Name(string company)
   {
      medicine_Company_Name = company;
   }

   // Getter
   int getMedicine_ID()
   {
      return Medicine_ID;
   }
   string getMedicine_Name()
   {
      return Medicine_Name;
   }
   string getDescription()
   {
      return description;
   }
   int getPrice()
   {
      return price;
   }
   int getQuantity_in_Stock()
   {
      return quantity_in_Stock;
   }
   Date getExpiry_Date()
   {
      return expiry_date;
   }
   bool getIsExpired()
   {
      return isExpired;
   }
   string getMedicine_Company_Name()
   {
      return medicine_Company_Name;
   }

   // IsExpired
   void isExpireOrNot()
   {
      if (expiry_date.getYear() < 2024)
      {
         isExpired = true;
      }

      isExpired = false;
   }

   // Display
   void display()
   {
      cout << endl <<endl;
      cout << "Medicine ID: " << Medicine_ID << endl;
      cout << "Medicine Name: " << Medicine_Name << endl;
      cout << "Medicine Company Name: " << medicine_Company_Name << endl;
      cout << "Description: " << description << endl;
      cout << "Price: Rs. " << price << endl;
      cout << "Quantity in Stock: " << quantity_in_Stock << endl;
      cout << "Expiry Date: " << expiry_date << endl;
      cout << "Is Expired: ";
      if (isExpired == true)
      {
         cout << "Yes" << endl;
      }
      else
      {
         cout << "No" << endl;
      }
      cout << endl;
      
   }

   // Overload Assignment operator
   Medication &operator=(const Medication &medi)
   {
      Medicine_ID = medi.Medicine_ID;
      Medicine_Name = medi.Medicine_Name;
      description = medi.description;
      price = medi.price;
      quantity_in_Stock = medi.quantity_in_Stock;
      expiry_date = medi.expiry_date;
      isExpired = medi.isExpired;
      medicine_Company_Name = medi.medicine_Company_Name;
      Medicine_ID++;

      return *this;
   }
};

int Medication::Medicine_ID = 0;

// Extraction Operator

istream &operator>>(istream &i, Medication &medi)
{
   
   cout << "Enter Medicine Name: ";
   i >> medi.Medicine_Name;
   cout << "Enter Price: ";
   i >> medi.price;
   cout << "Enter Quantity in Stock: ";
   i >> medi.quantity_in_Stock;
   cout << "Enter Expiry Date: ";
   i >> medi.expiry_date;

   medi.isExpireOrNot();

   return i;
}

// Insertion Operator
ostream &operator<<(ostream &o, const Medication &medi)
{
   o << "Medicine ID: " << medi.Medicine_ID << endl;
   o << "Medicine Name: " << medi.Medicine_Name << endl;
   o << "Price: " << medi.price << endl;
   o << "Quantity in Stock: " << medi.quantity_in_Stock << endl;
   o << "Expiry Date: " << medi.expiry_date << endl;

   return o;
}

#endif

