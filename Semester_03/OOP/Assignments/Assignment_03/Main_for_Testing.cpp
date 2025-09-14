#include <iostream>

#include "Address.h"
// #include "General_Info.h"
// #include "Customer.h"
// #include "Staff.h"
// #include "Medication.h"
// #include "Pharma_Company.h"
// #include "Salesman.h"
// #include "Order.h"
// #include "Pharmacy.h"

using namespace std;

int main()
{
   // ----------Address Class

   string street;
   string city;

   cout << "Enter City Name: ";
   cin >> city;
   cout << "Enter Street Name: ";
   cin >> street;

   Address address(city, street);

   //       -----------Or other Method of Calling
   // Address address;

   // cin >> address;
   // cout << address;
   // address.display();

   // -----------General Information Class

   // General_Info general_info;
   // cin >> general_info;

   // general_info.display();

   /*
      string first_Name;
      string last_Name;
      string cnic;
      char gender;


      cout << "First Name: ";
      cin >> first_Name;
      cout << "Last Name: ";
      cin >> last_Name;
      cout << "CNIC: ";
      cin >> cnic;
      cout << "Gender: ";
      cin >> gender;

      General_Info general_info(first_Name, last_Name, cnic, gender, address);
      */

   // ----------- Customer Class

   // cout << "\n````Enter Customer Details````" << endl
   //      << endl;
   // char membership;
   // cout << "Enter Membership status ( Y for yes , N for no): ";
   // cin >> membership;

   // Customer customer(membership);
   // customer.display();

   // -----------Staff Class

   // int salary;
   // cout << "Enter Salary amount for Staff: ";
   // cin >> salary;
   // // By Prametrize Constructor 2
   // Staff staff(salary);

   // staff.display();

   // -----------Medication

   // string des;
   // string company_name;

   // cout << "\n````Enter Medication Details````" << endl;

   // cout << "\nEnter company name for medicine: ";
   // getline(cin, company_name);
   // cout << "Enter description for medicine: ";
   // getline(cin, des);

   // Medication medication(company_name, des);

   // medication.display();

   // -----------Pharma Company

   // string company_name;
   // string company_location;

   // cout << "\n````Enter Pharma-Company Details````\n"
   //      << endl;
   // cout << "Enter Pharma Company name: ";
   // getline(cin, company_name);
   // cout << "Enter Pharma Company Location: ";
   // getline(cin, company_location);

   // Pharma_Company pharma_comp(company_name, company_location);

   // Pharma_Company pharma_comp(pharma_comp);   //Constructor 2
   // pharma_comp.display();

   // ------------Saleman Class

   // int set_commi;
   // int obtain_commi;

   // cout << "\n````Enter Salesman Details````\n"
   //      << endl;
   // cout << "Enter Set Commision amount: ";
   // cin >> set_commi;
   // cout << "Enter obtained commission amount: ";
   // cin >> obtain_commi;
   // Salesman salesman(set_commi, obtain_commi);

   //-----  OR ----
   // Salesman salesman;
   // cin >> salesman;

   // salesman.display();

   // ------------Order Class

   // cout << "\n````Enter Order Details````\n"
   //      << endl;
   // int total_amount;
   // int cust_id;
   // cout << "Enter total amount for Order: ";
   // cin >> total_amount;
   // cout << "Enter Customer ID: ";
   // cin >> cust_id;

   // Order order(total_amount,cust_id );

   // order.display();

   // ------------Pharmacy Class
// cout << "\n````Enter Pharmacy Details````\n"
//         << endl;
//    string pharmacy_name;
//    string owner;
//    cout << "Enter Pharmacy Name: ";
//    getline(cin,pharmacy_name);
//    cout << "Enter Pharmacy owner Name: ";
//    getline(cin,owner);

//    Pharmacy pharmacy(pharmacy_name, owner);

//    pharmacy.display();



   return 0;
}
