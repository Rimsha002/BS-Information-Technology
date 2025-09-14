#include <iostream>
using namespace std;

/*
Task 01: Little Humpty’s Pharmacy

Little Humpty wants to start a new business. He has heard there is great scope in Pharmacy stores
business. He wants to have Computerized system to handle all the medicines in a pharmacy. Being
your friend he asks you for help and lucky for Humpty, you are a great programmer. Develop a
system for Humpty’s Pharmacy. He wants to have following info about medicines:
 Medicine id
 Medicine name
 Manufacturer
 Sail Person he bought medicine from.
 Price at which he bought
 Price to sell at
 Quantity
Humpty says he does not know how much medicine he will have but he will add them as we go along. He wants a nice little menu based system where

he can add new medicine,
watch the data for a medicine,
watch the data of all the medicine,
watch all the medicine he bought of a particular manufacturer, watch all the medicine he bought from a particular Sail Person,
Total Quantity of each medicine he has at store.
*/

const int Max_Count = 100;

class Medicine // For Template
{
public:
    int id;
    string name;
    string manuf;
    string sailPerson;
    double buyPrice;
    double sellPrice;
    int quantity;
};

template <typename M>

class humptyPharmacy
{
private:
    M *medicine = new M[Max_Count];
    int id;
    string name;
    string manuf;
    string sailPerson;
    double buyPrice;
    double sellPrice;
    int quantity;
    int count = 0;
    int total = 0;

public:
    humptyPharmacy()
    {
        id = 0;
        name = "NaN";
        manuf = "NaN";
        sailPerson = "NaN";
        buyPrice = 0.0;
        sellPrice = 0.0;
        quantity = 0;
    }

    void addNewMedicine(int mID, string mName, string mManuf, string mSailPerson, double mBuyPrice, double mSellPrice, int mQuantity)
    {
        medicine[count].id = mID;
        medicine[count].name = mName;
        medicine[count].manuf = mManuf;
        medicine[count].sailPerson = mSailPerson;
        medicine[count].buyPrice = mBuyPrice;
        medicine[count].sellPrice = mSellPrice;
        medicine[count].quantity = mQuantity;

        count++;
    }

    void watchMedicineData(int mID)
    {
        for (int i = 0; i < count; i++)
        {
            if (mID == medicine[i].id)
            {
                cout << "Medicine data for this ID is :" << endl;
                cout << "ID: " << medicine[i].id << endl;
                cout << "Name: " << medicine[i].name << endl;
                cout << "Manufacturare: " << medicine[i].manuf << endl;
                cout << "Sail Person Name: " << medicine[i].sailPerson << endl;
                cout << "Buy Price: " << medicine[i].buyPrice << endl;
                cout << "Sell Price: " << medicine[i].sellPrice << endl;
                cout << "Quantity: " << medicine[i].quantity << endl;
            }
        }
        cout << " Medicine not found " << endl;
    }

    void allMedicineData()
    {
        if (count == 0)
        {
            cout << " No Medicine found ";
        }

        cout << "All Medicine data is :" << endl;
        for (int i = 0; i < count; i++)
        {
            {
                cout << "Medicine :" << i + 1 << endl;
                cout << "ID: " << medicine[i].id << endl;
                cout << "Name: " << medicine[i].name << endl;
                cout << "Manufacturare: " << medicine[i].manuf << endl;
                cout << "Sail Person: " << medicine[i].sailPerson << endl;
                cout << "Buy Price: " << medicine[i].buyPrice << endl;
                cout << "Sell Price: " << medicine[i].sellPrice << endl;
                cout << "Quantity: " << medicine[i].quantity << endl;
                cout << "---------------" << endl;
            }
        }
    }

    void perticularManuf(string mManuf)
    {
        for (int i = 0; i < count; i++)
        {
            if (mManuf == medicine[i].manuf)
            {
                cout << endl
                     << "All Medicins of this Manufacturare are :" << endl;
                cout << "-----" << i + 1 << "-----" << endl;
                cout << "Name: " << medicine[i].name << endl;
                cout << "ID: " << medicine[i].id << endl;
                cout << "Manufacturare: " << medicine[i].manuf << endl;
                cout << "Sail Person Name: " << medicine[i].sailPerson << endl;
                cout << "Buy Price: " << medicine[i].buyPrice << endl;
                cout << "Sell Price: " << medicine[i].sellPrice << endl;
                cout << "Quantity: " << medicine[i].quantity << endl;
            }
            else
            {
                cout << " Medicine of this Manufacture is not found " << endl;
            }
        }
    }

    void sailPersonMedicine(string mSailPerson)
    {
        for (int i = 0; i < count; i++)
        {
            if (mSailPerson == medicine[i].sailPerson)
            {
                cout << endl
                     << "All Medicins of this Sail Person is:" << endl;
                cout << "-----" << i + 1 << "-----" << endl;
                cout << "Name: " << medicine[i].name << endl;
                cout << "ID: " << medicine[i].id << endl;
                cout << "Manufacturare: " << medicine[i].manuf << endl;
                cout << "Sail Person Name: " << medicine[i].sailPerson << endl;
                cout << "Buy Price: " << medicine[i].buyPrice << endl;
                cout << "Sell Price: " << medicine[i].sellPrice << endl;
                cout << "Quantity: " << medicine[i].quantity << endl;
            }
            else
            {
                cout << "Medicine not found " << endl;
            }
        }
    }

    void totalQuantity(int mID)
    {
        for (int i = 0; i < count; i++)
        {
            if (mID == medicine[i].id)
            {
                cout << "Toatal Quantity of : " << medicine[i].name << " = " << medicine[i].quantity << endl;
            }
            else
            {
                cout << " Medicine not found " << endl;
            }
        }
    }
};

int main()
{
    humptyPharmacy<Medicine> pharmacy;

    cout << "Welcome to Little Humpty Pharmacy " << endl;

    int choice;

    do
    {
        cout << endl
             << "Pharmacy System Menu:" << endl;
        cout << "1. Add New Medicine" << endl;
        cout << "2. Display Medicine Information" << endl;
        cout << "3. Display All Medicines" << endl;
        cout << "4. Display Medicines by Manufacturer" << endl;
        cout << "5. Display Medicines by Sail Person" << endl;
        cout << "6. Total Quantity of a Medicine" << endl;
        cout << "7. Exit" << endl
             << endl;

        cout << "Enter your choice (1-7): ";

        cin >> choice;
        cin.sync(); // Here, Personnaly I don't know about this(sync) but I want to remove buffer overeflow

        string mName, mManuf, mSailPerson;
        double mBuyPrice, mSellPrice;
        int mID, mQuantity;

        switch (choice)
        {
        case 1:
        {

            cout << "Enter medicine ID: ";
            cin >> mID;
            cin.sync();
            cout << "Enter medicine Name: ";
            getline(cin, mName);
            cout << "Enter medicine Manufacturare: ";
            getline(cin, mManuf);
            cout << "Enter medicine Sail Person name: ";
            getline(cin, mSailPerson);
            cout << "Enter medicine Buy Price: ";
            cin >> mBuyPrice;
            cout << "Enter medicine Sell Price: ";
            cin >> mSellPrice;
            cout << "Enter medicine Quantity: ";
            cin >> mQuantity;

            pharmacy.addNewMedicine(mID, mName, mManuf, mSailPerson, mBuyPrice, mSellPrice, mQuantity);

            cout << "Your Medicine Enter successfully" << endl;
            break;
        }
        case 2:
        {
            cout << "Enter medicine ID: ";
            cin >> mID;
            pharmacy.watchMedicineData(mID);
            break;
        }
        case 3:
        {
            pharmacy.allMedicineData();
            break;
        }
        case 4:
        {
            cout << "Enter Manufacturare Name: ";
            getline(cin, mManuf);
            pharmacy.perticularManuf(mManuf);
            break;
        }
        case 5:
        {
            cout << "Enter Sail Person Name: ";
            getline(cin, mSailPerson);
            ;
            pharmacy.sailPersonMedicine(mSailPerson);
            break;
        }
        case 6:
        {
            cout << "Enter ID to find Total Quantity: ";
            cin >> mID;
            pharmacy.totalQuantity(mID);
            break;
        }
        case 7:
            cout << "Exiting Pharmacy Management System. Goodbye!" << endl;
            return 0;

        default:
            cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
        }
    } while (choice != 7);
    return 0;
}
