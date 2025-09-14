#ifndef CUSTOMER_H

#include <iostream>
#include "General_Info.h"
using namespace std;
class Customer
{
   static int Customer_ID;
   char Membership_status;
   string payment_method;

public:
   General_Info general_info;
   // Default Constructor
   Customer()
   {
      general_info = General_Info();
      Membership_status = 'N';
      Customer_ID++;
   }

   // Parameterized Constructor
   Customer( char m)
   {
      Customer_ID++; 

      cin >> general_info;
      
      //Membership Status
      try
      {
         if (m != 'Y' && m != 'N' && m != 'y' && m != 'n')
         {
            throw "Invalid Membership Status";
         }
      }
      catch (const char *msg)
      {
         cout << msg << endl;
         while (m != 'Y' && m != 'N' && m != 'y' && m != 'n')
         {
            cout << "Enter Valid status again ( Y for yes , N for no): ";
            cin >> m;
         }
      }
      Membership_status = m;

      //Payment
      cin >> *this;  
      
   }

   // Copy Constructor
   Customer(const Customer &obj)
   {
      general_info = obj.general_info;
      Membership_status = obj.Membership_status;
      Customer_ID++;
   }

   // Destructor
   ~Customer()
   {
   }

   // Setter
   void setMembership(char m)
   {
      Membership_status = m;
   }
   void setGeneral_Info(General_Info g)
   {
      general_info = g;
   }

   int getCustomer_ID()
   {
      return Customer_ID;
   }
   char getMembership()
   {
      return Membership_status;
   }

   // Payment Method
   string getPayment()
   {
      return payment_method;
   }

   void display()
   {
      cout << "\n\t---Customer Information---\n"
           << endl;
      cout << "Customer ID: " << Customer_ID << endl;
      cout << "Membership Status: " << Membership_status << endl;
      cout << "Payment Method: " << payment_method << endl;
      cout << general_info;
   }

   friend istream &operator>>(istream &i, Customer &customer);
   friend ostream &operator<<(ostream &o, const Customer &customer);
};

// Decalaration of static variable
int Customer::Customer_ID = 0;

// Extraction
istream &operator>>(istream &i, Customer &customer)
{
   cout << "\nPayment Methods: " << endl;
   cout << "1. Cash" << endl;
   cout << "2. Credit Card" << endl;
   cout << "3. Debit Card" << endl;
   cout << "Select option: ";

   int choice;
   i >> choice;

   switch (choice)
   {
   case 1:
      customer.payment_method = "Cash";
      break;
   case 2:
      customer.payment_method = "Credit Card";
      break;
   case 3:
      customer.payment_method = "Debit Card";
      break;
   default:
      cout << "Invalid Choice" << endl;
   }
   return i;
}

// Insertion
ostream &operator<<(ostream &o, const Customer &customer)
{
   o << "Customer ID: " << customer.Customer_ID << endl;
   o << "Membership Status: " << customer.Membership_status << endl;
   // o << customer.general_info;
   o << "Payment Method: " << customer.payment_method << endl;

   return o;
}

#endif