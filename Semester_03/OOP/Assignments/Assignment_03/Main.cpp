#include <iostream>
#include "Pharmacy.h"

using namespace std;
int main()
{
    cout << "\n\t~~~~~ Welcome to Your Pharmacy ~~~~~ \n"
         << endl;
    Pharmacy *pharmacies = new Pharmacy[10];
    int size = 0;
    int choice;
    do
    {
        cout << endl;
        cout << "1. Add Pharmacy" << endl;
        cout << "2. Add Medication" << endl;
        cout << "3. Display Medication" << endl;
        cout << "4. Add Salesman" << endl;
        cout << "5. Remove Salesman" << endl;
        cout << "6. Add Order" << endl;
        cout << "7. Add new Staff" << endl;
        cout << "8. Remove Staff" << endl;
        cout << "9. Display all pharmacies" << endl;
        cout << "10. Exit" << endl;
        cout << "\nSelect option no. : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\n === ADD new Pharmacy === \n " << endl;
            if (size < 10)
            {
                cin >> pharmacies[size];
                size++;
                cout << "\nPharmacy Added successfully!" << endl;
            }
            else
            {
                cout << "Pharmacy array is full" << endl;
            }
            break;
        }
        case 2:
        {
            cout << "\n === ADD Madication === \n " << endl;
            int pharmacy_index;
            cout << "Enter the index of pharmacy: ";
            cin >> pharmacy_index;
            cin.ignore();
            if (pharmacy_index >= size || pharmacy_index < 0)
            {
                cout << "Invalid Index, Firstly add pharmacy at that index";
            }
            else
            {
                string des;
                string company_name;

                cout << "\n````Enter Medication Details````" << endl;

                cout << "\nEnter company name for medicine: ";
                getline(cin, company_name);
                cout << "Enter description for medicine: ";
                getline(cin, des);

                Medication medi(company_name, des);

                pharmacies[pharmacy_index].add_new_Medication(medi);
                cout << "\nDone! Medication added! \n"
                     << endl;
            }

            break;
        }
        case 3:
        {
            cout << "\n === Display Madication === \n " << endl;
            int pharmacy_index1;
            cout << "Enter the index of pharmacy: ";
            cin >> pharmacy_index1;
            if (pharmacy_index1 < size)
            {
                pharmacies[pharmacy_index1].display_all_medication();
            }
            else
            {
                cout << "Invalid index" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "\n === Add Salesman === \n " << endl;
            int pharmacy_index2;
            cout << "Enter the index of pharmacy: ";
            cin >> pharmacy_index2;
            if (pharmacy_index2 < size)
            {
                Salesman salesman;
                cin >> salesman;
                pharmacies[pharmacy_index2].add_new_salesman(salesman);
            }
            else
            {
                cout << "Invalid index" << endl;
            }
            break;
        }
        case 5:
        {
            cout << "\n === Remove Salesman === \n " << endl;
            int pharmacy_index3;
            cout << "Enter the index of pharmacy: ";
            cin >> pharmacy_index3;
            if (pharmacy_index3 < size)
            {
                cout << "Enter id of saleman you want to remove: ";
                int id;
                cin >> id;
                pharmacies[pharmacy_index3].remove_salesman(id);
            }
            else
            {
                cout << "Invalid index" << endl;
            }
            break;
        }
        case 6:
        {
            cout << "\n === Add new Order === \n " << endl;
            int pharmacy_index4;
            cout << "Enter the index of pharmacy: ";
            cin >> pharmacy_index4;
            if (pharmacy_index4 <
                size)
            {
                cout << "\n````Enter Order Details````\n"
                     << endl;
                int total_amount;
                int cust_id;
                cout << "Enter total amount for Order: ";
                cin >> total_amount;
                cout << "Enter Customer ID: ";
                cin >> cust_id;

                Order order(total_amount, cust_id);

                pharmacies[pharmacy_index4].add_new_order(order);
            }
            else
            {
                cout << "Invalid index" << endl;
            }
            break;
        }
        case 7:

        {
            cout << "\n === Add new Staff === \n " << endl;
            int pharmacy_index5;
            cout << "Enter the index of pharmacy: ";
            cin >> pharmacy_index5;
            if (pharmacy_index5 < size)
            {
                cout << "\n````Enter Order Details````\n"
                     << endl;
                int salary;
                cout << "Enter Salary amount for Staff: ";
                cin >> salary;

                Staff staff(salary);

                pharmacies[pharmacy_index5].add_new_staff(staff);
            }
            else
            {
                cout << "Invalid index" << endl;
            }
            break;
        }
        case 8:
        {
            cout << "\n === Remove Staff === \n " << endl;
            int pharmacy_index5;
            cout << "Enter the index of pharmacy: ";
            cin >> pharmacy_index5;
            if (pharmacy_index5 < size)
            {

                cout << "Enter id of staff you want to remove: ";
                int id;
                cin >> id;

                pharmacies[pharmacy_index5].remove_staff(id);
            }
            else
            {
                cout << "Invalid index" << endl;
            }
            break;
        }
        case 9:
        {
            cout << "\n === Display all Pharmacies === \n " << endl;
            cout << "\nList of present Pharmacies is: " << endl;
            for (int i = 0; i < size; i++)
            {
                cout << "\tPharmacy no. " << i + 1 << pharmacies[i] << endl;
            }
            cout << endl;

            break;
        }

        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 10);
    delete[] pharmacies;

    return 0;
}
