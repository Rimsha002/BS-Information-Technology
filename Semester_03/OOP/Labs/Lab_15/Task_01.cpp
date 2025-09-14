#include <iostream>
#include <exception>
#include <stdexcept>
#include <cstring>
#include <fstream>
using namespace std;

// Database Employee Record using random access file
class Employee
{
    int id;
    char name[50];
    char designation[50];
    float salary;

public:
    Employee()
    {
        id = 0;
        name[0] = '\0';
        designation[0] = '\0';
        salary = 0.0;
    }
    Employee(int id, char name[], char designation[], float salary)
    {
        this->id = id;
        strcpy(this->name, name);
        strcpy(this->designation, designation);

        this->salary = salary;
    }

    // Add data to file 
    void addData(int id)
    {
        ifstream infile;
        infile.open("Employees.dat", ios::binary);
        while (infile.read((char *)this, sizeof(*this)))
        {
            if (this->id == id)
            {
                throw invalid_argument("Employee with same ID already exists");
                return;
            }
        }
        infile.close();

        ofstream file;
        file.open("Employees.dat", ios::binary | ios::app);
        file.write((char *)this, sizeof(*this));
        file.close();

        cout << "Employee Data Added Successfully" << endl;
    }

    // Delete data from file
    void deleteData(int id)
    {
        ifstream file;
        ofstream temp;
        file.open("Employees.dat", ios::binary);
        temp.open("temp.dat", ios::binary);
        while (file.read((char *)this, sizeof(*this)))
        {
            if (this->id != id)
            {
                temp.write((char *)this, sizeof(*this));
            }
        }
        file.close();
        temp.close();
        remove("Employees.dat");
        rename("temp.dat", "Employees.dat");

        cout << "Employee Data Deleted Successfully" << endl;
    }

    // Update data in file
    void updateData(int id)
    {
        fstream file;
        file.open("Employees.dat", ios::binary | ios::in | ios::out);
        while (file.read((char *)this, sizeof(*this)))
        {
            if (this->id == id)
            {
                cout << "Enter new name: ";
                cin >> this->name;
                cout << "Enter new designation: ";
                cin >> this->designation;
                cout << "Enter new salary: ";
                cin >> this->salary;
                file.seekp(ios::app);
                file.write((char *)this, sizeof(*this));
                break;
            }
        }
        file.close();

        cout << "Employee Data Updated Successfully" << endl;
    }

    // Display data from file
    void displayData()
    {
        ifstream file;
        if (file.fail())
        {
            cout << "File not found" << endl;
            return;
        }
        else
        {
            file.open("Employees.dat", ios::binary);
            while (file.read((char *)this, sizeof(*this)))
            {
                cout << "ID: " << id << endl;
                cout << "Name: " << name << endl;
                cout << "Designation: " << designation << endl;
                cout << "Salary: " << salary << endl;
            }
            file.close();
        }
    }
};

int main()
{

    cout << "---Employee Database---" << endl;

    cout << "Enter Employee Details: " << endl;
    int id;
    char name[50];
    char designation[50];
    float salary;

    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Name: ";
    while (cin.get() != '\n')
        ;
    
    cout << "Enter Designation: ";
    cin.getline(designation, 50);

    cout << "Enter Salary: ";
    cin >> salary;

    Employee emp(id, name, designation, salary);

    int choice;

    do
    {
        cout << "\n Select one of the following or -1 to quite: \n";
        cout << "1. Add Data" << endl;
        cout << "2. Delete Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Display Data" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "--Add Employee-- " << endl;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            while (cin.get() != '\n');
            cout << "Enter Designation: ";
            cin.getline(designation, 50);

            cout << "Enter Salary: ";
            cin >> salary;

            try
            {
                Employee emp1(id, name, designation, salary);
                emp1.addData(id);
            }
            catch (invalid_argument &e)
            {
                cout << e.what() << endl;
            }

            break;
        }

        case 2:
        {
            cout << "--Delete Employee-- " << endl;
            cout << "Enter ID to delete: ";
            cin >> id;
            emp.deleteData(id);
            break;
        }
        case 3:
        {
            cout << "--Update Employee-- " << endl;
            cout << "Enter ID to update: ";
            cin >> id;
            emp.updateData(id);
            break;
        }
        case 4:
        {
            cout << "--Display Employee-- " << endl;
            emp.displayData();
            break;
        }
        case 5:
        {
            cout << "Exiting..." << endl;
            choice = -1;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }

    } while (choice != -1);

    return 0;
}