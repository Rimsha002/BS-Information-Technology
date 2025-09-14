#ifndef ADDRESS_H
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// To keep address of customer and staff

class Address
{
   unsigned long long int mobile_no;
   static vector<unsigned long long int> vmobile_no;

   string email;
   static vector<string> vemail;

   string street_name;
   string city_name;

   friend istream &operator>>(istream &i, Address &address);
   friend ostream &operator<<(ostream &o, const Address &address);
   friend void mobile(Address &address, unsigned long long int mobileNo);
   friend void e_Mail(Address &address, string mail);

public:
   Address()
   {
      this->mobile_no = 0;
      this->email = "";
      this->street_name = "";
      this->city_name = "";
   }

   Address(string city, string street)
   {
      // Mobile
      int m_no;
      cout << "How many mobile no you want to enter?";
      cin >> m_no;

      for (int i = 0; i < m_no; i++)
      {
         unsigned long long int mobileNo;
         cout << "Enter Mobile No: ";
         cin >> mobileNo;

         mobile(*this, mobileNo);
      }

      // Email

      int e_no;
      cout << "How many emails you want to enter?";
      cin >> e_no;

      for (int i = 0; i < e_no; i++)
      {
         string e;
         cout << "Enter Email: ";
         getline(cin, e);

         e_Mail(*this, e);
      }

      this->street_name = street;
      this->city_name = city;
   }

   // Copy Constructor
   Address(Address &address)
   {
      for (int i = 0; i < address.vmobile_no.size(); i++)
      {
         vmobile_no[i] = address.vmobile_no[i];
      }
      for (int i = 0; i < address.vemail.size(); i++)
      {
         vemail[i] = address.vemail[i];
      }

      street_name = address.street_name;
      city_name = address.city_name;
   }

   // Destructor
   ~Address()
   {
   }

   // Getter and Setter
   void setMobile(unsigned long long int m)
   {
      mobile(*this, m);
   }

   void setEmail(string e)
   {

      e_Mail(*this, e);
   }

   void setStreet(string street)
   {
      this->street_name = street;
   }

   void setCity(string city)
   {
      this->city_name = city;
   }

   vector<unsigned long long int> getMobile()
   {
      return vmobile_no;
   }

   string getEmail()
   {
      return email;
   }
   string getStreet()
   {
      return street_name;
   }
   string getCity()
   {
      return city_name;
   }

   // Display
   void display()
   {
      cout << "\n\t---Address Details---\n";
      cout << "City Name: " << city_name << endl;
      cout << "Street Name: " << street_name << endl;

      cout << "Mobile ";

      int m_size = vmobile_no.size();
      
      for (int i = 0; i < m_size; i++)
      {
         cout << "\n No. " << i + 1 << ": ";
         cout << vmobile_no[i] << "  ";
      }

      cout << endl;

      cout << "Email ";
      int e_size = vemail.size();
      for (int j = 0; j < e_size; j++)
      {
         cout << "\n No. " << j + 1 << ": ";
         cout << vemail[j] << "  ";
      }

      cout << endl;
   }

   // [Index] Operator Overloading
   int operator[](int index)
   {
      int size = vmobile_no.size();

      while (index < 0 || index >= size)
      {
         cout << "Index out of range" << endl;
         cout << "Enter a valid index: ";
         cin >> index;
      }
      if (index >= 0 && index < size)
      {
         return vmobile_no[index];
      }
   }
};

// Extraction operator
istream &operator>>(istream &i, Address &address)
{
      cout << "\n````Enter Address Details````" << endl
        << endl;
   // Mobile
   int m_no;
   cout << "How many mobile no you want to enter?";
   i >> m_no;
   i.get();

   for (int j = 0; j < m_no; j++)
   {
      unsigned long long int mobileNo;
      cout << "Enter Mobile No: ";
      i >> mobileNo;
      i.get();

      mobile(address, mobileNo);
   }

   // Email
   int e_no;
   cout << "How many emails you want to enter?";
   i >> e_no;
   i.get();

   for (int j = 0; j < e_no; j++)
   {
      string e;
      cout << "Enter Email: ";
      getline(i, e);
     
      e_Mail(address, e);
   }

   cout << "Enter Street Name: ";
   getline(i, address.street_name);
 
   cout << "Enter City Name: ";
   getline(i, address.city_name);
   

   return i;
}

// Insertion Operator
ostream &operator<<(ostream &o, const Address &address)
{
   o << "\n---Address Details---\n";
   o << "City Name: " << address.city_name << endl;
   o << "Street Name: " << address.street_name << endl;

   o << "Mobile ";
   int m_size = address.vmobile_no.size();

   for (int i = 0; i < m_size; i++)
   {
      o << "\n No. " << i + 1 << ": ";
      o << address.vmobile_no[i] << "  ";
   }

   o << endl;

   o << "Email ";
   int e_size = address.vemail.size();
   for (int j = 0; j < e_size; j++)
   {
      o << "\n No. " << j + 1 << ": ";
      o << address.vemail[j] << "  ";
   }

   o << endl;

   return o;
}

vector<unsigned long long int> Address::vmobile_no;
vector<string> Address::vemail;

// Function for Mobile no
void mobile(Address &address, unsigned long long int mobileNo)
{

   try
   {
      if (find(address.vmobile_no.begin(), address.vmobile_no.end(), mobileNo) != address.vmobile_no.end())
      {
         throw "Mobile number already exists";
      }

      if (mobileNo < 0)
      {
         throw("Invalid Mobile No! ");
      }
   }
   catch (const char *msg)
   {
      cout << msg << endl;
      while (mobileNo < 0)
      {
         cout << "Enter valid Mobile no again: ";
         cin >> mobileNo;
      }
   }

   address.mobile_no = mobileNo;
   address.vmobile_no.push_back(address.mobile_no);
}

// Email Function
void e_Mail(Address &address, string mail)
{
   try
   {
      if (find(address.vemail.begin(), address.vemail.end(), mail) != address.vemail.end())
      {
         throw "Email already exists";
      }

      bool isValid = false;
      int e_length = mail.length();

      for (int i = 0; i < e_length; i++)
      {
         if (mail[i] == '@')
         {
            isValid = true;
            break;
         }
      }
      if (!isValid)
      {
         throw "Invalid Email";
      }
   }
   catch (const char *msg)
   {
      cout << msg << endl;

      bool isValid = false;

      do
      {
         cout << "Please enter valid email. ";
         // cin.ignore();
         getline(cin, mail);

         int e_length = mail.length();

         for (int i = 0; i < e_length; i++)
         {
            if (mail[i] == '@')
            {
               isValid = true;
               break;
            }
         }

      } while (!isValid);
   }

   address.email = mail;
   address.vemail.push_back(address.email);
}

#endif