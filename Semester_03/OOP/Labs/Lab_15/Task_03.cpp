#include <iostream>
#include <exception>
#include <stdexcept>
#include <cstring>
#include <fstream>
using namespace std;

// Inventory Management System
class Inventory
{
    string name;
    int quantity;

public:
    Inventory()
    {
        name = "";
        quantity = 0;
    }
    Inventory(string name, int quantity)
    {
        this->name = name;
        this->quantity = quantity;
    }

    // Read data from file
    void readData(ifstream &file)
    {
        file.open("Inventory.dat", ios::in);
        while (file.read((char *)this, sizeof(*this)))
        {
            cout << "Name: " <<name << " " << "Qunatity: " << quantity << endl;
        }
        file.close();
    }

    // Add data to file
    void addData()
    {
        string name1;
        int quantity1;

        cout << "Enter Name: ";
        getline(cin, name1);
        cout << "Enter Quantity: ";
        cin >> quantity1;
        
        ifstream infile;
        infile.open("Inventory.dat", ios::binary);
        while (infile.read((char *)this, sizeof(*this)))
        {
            if (this->name == name1)
            {
                throw invalid_argument("Item with same name already exists");
                return;
            }
        }

        this->name = name1;
        this->quantity = quantity1;

        infile.close();

        ofstream file;
        file.open("Inventory.dat", ios::binary | ios::app);
        file.write((char *)this, sizeof(*this));
        file.close();

        cout << "Item Data Added Successfully" << endl;
    }

    // Remove data from file
    void removeData()
    {
        string n;
        cout << "Enter name of item to remove: ";
        cin >> n;

        ifstream file;
        ofstream temp;
        file.open("Inventory.dat", ios::binary);

        if (!file)
        {
            throw("File is empty");
            return;
        }
        temp.open("temp.dat", ios::binary);
        while (file.read((char *)this, sizeof(*this)))
        {
            if (this->name != n)
            {
                temp.write((char *)this, sizeof(*this));
            }
        }
        file.close();
        temp.close();
        remove("Inventory.dat");
        rename("temp.dat", "Inventory.dat");

        cout << "Item Removed Successfully" << endl;
    }

    // Update data in file
    void updateData()
    {
        string n;
        cout << "Enter name of item to update: ";
        cin >> n;

        fstream file;
        file.open("Inventory.dat", ios::binary | ios::in | ios::out);
        while (file.read((char *)this, sizeof(*this)))
        {
            if (this->name == n)
            {
                cout << "Enter new name: ";
                getline(cin, this->name);
                cout << "Enter new quantity: ";
                cin >> this->quantity;
                file.seekg(ios::app);
                file.write((char *)this, sizeof(*this));
                cout << "Item Data Updated Successfully" << endl;
                return;
            }
        }
        cout << "Item not found" << endl;
        file.close();
    }

    // Display
    void display()
    {
        ifstream file;
        file.open("Inventory.dat", ios::in);

        cout << "Data in file is: ";
        while (file.read((char *)this, sizeof(*this)))
        {
            cout << "Name: " << name << " " << "Quantity: " << quantity << endl;
        }
        file.close();
    }
};

int main()
{
    Inventory inventory;
    ifstream file;
    int choice;
    do
    {
        cout << "\n--- Inventory Management System ---" << endl;

        cout << "Select option or -1 to quite" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. Remove Item" << endl;
        cout << "3. Update Item" << endl;
        cout << "4. Display Items" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "--Adding data" << endl;
            try
            {
                inventory.addData();
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 2:
        {
            cout << "--Removing data" << endl;
            try
            {
                inventory.removeData();
            }
            catch (const char *e)
            {
                cout << e << endl;
            }
            break;
        }
        case 3:
        {
            cout << "--Updating data" << endl;
            inventory.updateData();
            break;
        }
        case 4:
        {
            cout << "--Displaying data" << endl;
            inventory.display();
            break;
        }
        case 5:

        {
            cout << "Exiting..." << endl;
            choice = -1;
            break;
        }
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != -1);
    return 0;
}