#ifndef PHARMACY_H
#include <iostream>
// #include "Medication.h"
// #include "Customer.h"
#include "Staff.h"
// #include "Salesman.h"
#include "Order.h"

using namespace std;

class Pharmacy
{
    static int Pharmacy_ID;
   string Pharmacy_Name;
   string pharmacy_owner;
   Medication *med;
   int max_size;
   int current_size;
   int *quantity;
   Staff *staff;
   int max_size_staff;
   int current_size_staff;
   Salesman *salesman;
   int max_size_salesman;
   int current_size_salesman;
   Order *order;
   int max_size_order;
   int current_size_order;
   int total_sales;
   int total_purchase;
   int total_profit;

   Order Or;

public:
   Pharmacy()
   {
      Pharmacy_ID++;
      Pharmacy_Name = "";
      pharmacy_owner = "";
      med = new Medication[10];
      max_size = 10;
      current_size = 0;

      quantity = new int[10];
      staff = new Staff[10];
      max_size_staff = 10;
      current_size_staff = 0;

      salesman = new Salesman[10];
      max_size_salesman = 10;
      current_size_salesman = 0;

      order = new Order[10];
      max_size_order = 10;
      current_size_order = 0;
      
      total_sales = 0;
      total_purchase = 0;
      total_profit = 0;
   }

   // Parametrize Constructor
   Pharmacy(string name, string owner)
   {
      Pharmacy_ID++;
      Pharmacy_Name = name;
      pharmacy_owner = owner;
      med = new Medication[10];
      max_size = 10;
      current_size = 0;
      quantity = new int[10];
      staff = new Staff[10];
      max_size_staff = 10;
      current_size_staff = 0;
      salesman = new Salesman[10];
      max_size_salesman = 10;
      current_size_salesman = 0;
      order = new Order[10];
      max_size_order = 10;
      current_size_order = 0;
      total_sales = 0;
      total_purchase = 0;
      total_profit = 0;
   }

   // Copy Constructor
   Pharmacy(const Pharmacy &obj)
   {
      Pharmacy_ID = obj.Pharmacy_ID;
      Pharmacy_Name = obj.Pharmacy_Name;
      pharmacy_owner = obj.pharmacy_owner;
      med = obj.med;
      max_size = obj.max_size;
      current_size = obj.current_size;
      quantity = obj.quantity;
      staff = obj.staff;
      max_size_staff = obj.max_size_staff;
      current_size_staff = obj.current_size_staff;
      salesman = obj.salesman;
      max_size_salesman = obj.max_size_salesman;
      current_size_salesman = obj.current_size_salesman;
      order = obj.order;
      max_size_order = obj.max_size_order;
      current_size_order = obj.current_size_order;
      total_sales = obj.total_sales;
      total_purchase = obj.total_purchase;
      total_profit = obj.total_profit;
   }

   // Destructor
   ~Pharmacy()
   {
      delete[] med;
      delete[] quantity;
      delete[] staff;
      delete[] salesman;
      delete[] order;
   }

   // Setter   
   void setPharmacy_Name(string name)
   {
      Pharmacy_Name = name;
   }
   void setPharmacy_Owner(string owner)
   {
      pharmacy_owner = owner;
   }

   // Getter
   int getPharmacy_ID()
   {
      return Pharmacy_ID;
   }
   string getPharmacy_Name()
   {
      return Pharmacy_Name;
   }
   string getPharmacy_Owner()
   {
      return pharmacy_owner;
   }

   

   // Add new Medication
   void add_new_Medication(Medication &medi)
   {
      if (current_size < max_size)
      {
         med[current_size] = medi;
         current_size++;
      }
      else
      {
         max_size = max_size * 2;
         Medication *temp = new Medication[max_size];
         for (int i = 0; i < current_size; i++)
         {
            temp[i] = med[i];
         }
         temp[current_size] = medi;
         current_size++;
         delete[] med;
         med = temp;
      }
   }

   // Remove Medication
   void remove_Medication(int id)
   {
      if (id < 0 || id >= current_size)
      {
         cout << "Invalid ID" << endl;
         while (id < 0 || id >= current_size)
         {
            cout << "Enter valid ID: ";
            cin >> id;
         }
      }
      for (int i = id; i < current_size; i++)
      {
         med[i] = med[i + 1];
      }
      current_size--;
   }

   // Add new order
   void add_new_order(Order &ord)
   {
      if (current_size_order < max_size_order)
      {
         order[current_size_order] = ord;
         current_size_order++;
      }
      else
      {
         max_size_order = max_size_order * 2;
         Order *temp = new Order[max_size_order];
         for (int i = 0; i < current_size_order; i++)
         {
            temp[i] = order[i];
         }
         temp[current_size_order] = ord;
         current_size_order++;
         delete[] order;
         order = temp;
      }
   }

   // Add new staff
   void add_new_staff(Staff &st)
   {
      if (current_size_staff < max_size_staff)
      {
         staff[current_size_staff] = st;
         current_size_staff++;
      }
      else
      {
         max_size_staff = max_size_staff * 2;
         Staff *temp = new Staff[max_size_staff];
         for (int i = 0; i < current_size_staff; i++)
         {
            temp[i] = staff[i];
         }
         temp[current_size_staff] = st;
         current_size_staff++;
         delete[] staff;
         staff = temp;
      }
   }

   // Remove staff
   void remove_staff(int id)
   {
      if (id < 0 || id >= current_size_staff)
      {
         cout << "Invalid ID" << endl;
         while (id < 0 || id >= current_size_staff)
         {
            cout << "Enter valid ID: ";
            cin >> id;
         }
      }
      for (int i = id; i < current_size_staff; i++)
      {
         staff[i] = staff[i + 1];
      }
      current_size_staff--;
   }

   // Add new salesman
   void add_new_salesman(Salesman &sm)
   {
      if (current_size_salesman < max_size_salesman)
      {
         salesman[current_size_salesman] = sm;
         current_size_salesman++;
      }
      else
      {
         max_size_salesman = max_size_salesman * 2;
         Salesman *temp = new Salesman[max_size_salesman];
         for (int i = 0; i < current_size_salesman; i++)
         {
            temp[i] = salesman[i];
         }
         temp[current_size_salesman] = sm;
         current_size_salesman++;
         delete[] salesman;
         salesman = temp;
      }
   }

   // Remove salesman
   void remove_salesman(int id)
   {
      if (id < 0 || id >= current_size_salesman)
      {
         cout << "Invalid ID" << endl;
         while (id < 0 || id >= current_size_salesman)
         {
            cout << "Enter valid ID: ";
            cin >> id;
         }
      }
      for (int i = id; i < current_size_salesman; i++)
      {
         salesman[i] = salesman[i + 1];
      }
      current_size_salesman--;

      cout <<"\nNew salesman list is: " ;
        for (int i = 0; i < current_size_salesman; i++)
      {
         cout << salesman[i] << endl;
      }

   }

   // Display method to show all order
   void display_all_order()
   {
      for (int i = 0; i < current_size_order; i++)
      {
         order[i].display();
      }
   }

   // Display method to show all staff
   void display_all_staff()
   {
      for (int i = 0; i < current_size_staff; i++)
      {
         staff[i].display();
      }
   }

   // Display method to show all medication
   void display_all_medication()
   {
      for (int i = 0; i < current_size; i++)
      {
         med[i].display();
      }
   }

   // Total Purchase
   void total_Purchase()
   {
      for (int i = 0; i < current_size_order; i++)
      {
         total_purchase += order[i].getTotal_Amount();
      }
   }

   // Total sales(it will return total sales)
   void total_sale()
   {
      for (int i = 0; i < current_size_order; i++)
      {
         total_sales += order[i].getTotal_Amount();
      }
   }

   // total profit
   void total_Profit()
   {
      total_profit = total_sales - total_purchase;
   }

   // Display Method to display everything
   void display()
   {
      cout << "\n---Pharmacy Information---\n"
           << endl;
      cout << "Pharmacy ID: " << Pharmacy_ID << endl;
      cout << "Pharmacy Name: " << Pharmacy_Name << endl;
      cout << "Pharmacy Owner: " << pharmacy_owner << endl;
      cout << "Total Sales: " << total_sales << endl;
      cout << "Total Purchase: " << total_purchase << endl;
      cout << "Total Profit: " << total_profit << endl;
      cout << "Medication: " << endl;
      for (int i = 0; i < current_size; i++)
      {
         med[i].display();
      }
      cout << "Staff: " << endl;
      for (int i = 0; i < current_size_staff; i++)
      {
         staff[i].display();
      }
      cout << "Salesman: " << endl;
      for (int i = 0; i < current_size_salesman; i++)
      {
         salesman[i].display();
      }
      cout << "Order: " << endl;
      for (int i = 0; i < current_size_order; i++)
      {
         order[i].display();
      }
   }

   // Update medicine detail by it's ID
   void update_medicine_detail(int id)
   {
      if (id < 0 || id >= current_size)
      {
         cout << "Invalid ID" << endl;
         while (id < 0 || id >= current_size)
         {
            cout << "Enter valid ID: ";
            cin >> id;
         }
      }

      cout << "\n Previous Medicine Details\n"
           << endl;
      med[id].display();

      cout << "Enter new Medicine Name: ";
      string name;
      cin >> name;
      med[id].setMedicine_Name(name);

      cout << "Enter new description: ";
      string des;
      cin >> des;
      med[id].setMedicine_Name(des);

      cout << "Enter new company name: ";
      string company_name;
      cin >> company_name;
      med[id].setMedicine_Company_Name(company_name);

      cout << "Enter new price: ";
      float price;
      cin >> price;
      med[id].setPrice(price);

      cout << "Enter new expiry date: ";
      Date date;
      cin >> date;
      med[id].setExpiry_Date(date);

      cout << "Enter new quantity: ";
      int q;
      cin >> q;
      med[id].setQuantity_in_Stock(q);

      cout << "\nMedicine updated successfully\n"
           << endl;
   }


   //Sell Medicine
   void sell_medicine()
   {
      Order ord;
      cout << "Enter Customer ID: ";
      int id;
      cin >> id;
      ord.setCustomer_ID(id);
      cout << "Enter Order Date: ";
      Date date;
      cin >> date;
      ord.setOrder_date(date);

      cout << "Enter Salesman ID: "; //imp
      int s_id;
      cin >> s_id;
      Or.getSalesman().setSaleman_ID(s_id);

      cout << "Enter Company Name: ";
      string company;
      cin >> company;
      Or.getCompany().setCompany_Name(company);

      ord.setPayment_Method();
      

      cout << "Enter Total Amount: ";
      float amount;
      cin >> amount;
      ord.setTotal_Amount(amount);
      cout << "Enter Quantity of Medicine: ";
      int q;
      cin >> q;
    Or.getMedication().setQuantity_in_Stock(q);

      cout << "Enter Medicine ID: ";
      int m_id;
      cin >> m_id;

      Or.getMedication().setMedicine_ID(m_id);

      add_new_order(ord);
   }

   
   

   //Show all Order made
   void show_all_order_made()
   {
      for (int i = 0; i < current_size_order; i++)
      {
         order[i].display();
      }
   }

   // All order made by perticular person
   void order_by_perticular_person(int id)
   {
      for (int i = 0; i < current_size_order; i++)
      {
         if (order[i].getCustomer_ID() == id)
         {
            order[i].display();
         }
      }
   }


   // All order on specific date
   void order_on_specific_date(Date date)
   {
      for (int i = 0; i < current_size_order; i++)
      {
         if (order[i].getOrder_date() == date)
         {
            order[i].display();
         }
      }
   }

   // Show all salesman
   void show_all_salesman()
   {
      for (int i = 0; i < current_size_salesman; i++)
      {
         salesman[i].display();
      }
   }

   // Method to pay salary to all staff(profit deducted)
   void pay_salary_to_all_staff()
   {
      for (int i = 0; i < current_size_staff; i++)
      {
         staff[i].setSalary(staff[i].getSalary() - total_profit);
      }
   }

   // Discard expiry medicine
   void discard_expiry_medicine()
   {
      for (int i = 0; i < current_size; i++)
      {
         if (med[i].getIsExpired() == true)
         {
            remove_Medication(i);
         }
      }
   }

friend istream &operator>>(istream &i, Pharmacy &pharmacy);
friend ostream &operator<<(ostream &o, const Pharmacy &pharmacy);



};

int Pharmacy::Pharmacy_ID = 0;

//Extraction 
  istream &operator>>(istream &i, Pharmacy &pharmacy)
   {
      cout << "\n````Enter Pharmacy Details````" << endl;

      cout << "Enter Pharmacy Name: ";
      i >> pharmacy.Pharmacy_Name;
      cout << "Enter Pharmacy Owner: ";
      i >> pharmacy.pharmacy_owner;

      return i;
   }

   //Insertion
   ostream &operator<<(ostream &o, const Pharmacy &pharmacy)
   {
      o << "\n---Pharmacy Information---\n"
        << endl;
      o << "Pharmacy ID: " << pharmacy.Pharmacy_ID << endl;
      o << "Pharmacy Name: " << pharmacy.Pharmacy_Name << endl;
      o << "Pharmacy Owner: " << pharmacy.pharmacy_owner << endl;
      o << "Total Sales: " << pharmacy.total_sales << endl;
      o << "Total Purchase: " << pharmacy.total_purchase << endl;
      o << "Total Profit: " << pharmacy.total_profit << endl;
      o << "Medication: " << endl;
      for (int i = 0; i < pharmacy.current_size; i++)
      {
         o << pharmacy.med[i];
      }
      o << "Staff: " << endl;
      for (int i = 0; i < pharmacy.current_size_staff; i++)
      {
         o << pharmacy.staff[i];
      }
      o << "Salesman: " << endl;
      for (int i = 0; i < pharmacy.current_size_salesman; i++)
      {
         o << pharmacy.salesman[i];
      }
      o << "Order: " << endl;
      for (int i = 0; i < pharmacy.current_size_order; i++)
      {
         o << pharmacy.order[i];
      }

      return o;
   }

#endif