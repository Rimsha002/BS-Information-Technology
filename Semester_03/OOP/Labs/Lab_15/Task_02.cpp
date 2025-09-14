#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <cstring>
#include <fstream>

using namespace std;

// Sort Name
class FileReader
{
protected:
    string name;

public:
    FileReader()
    {
        name = "";
    }
    FileReader(string name)
    {
        this->name = name;
    }

    // Write names to file
    void writeNames(ofstream &file)
    {
        file.open("Names.txt", ios::app);

        file.write((char *)this, sizeof(*this));
        file.close();
    }

    void addName(string name)
    {
        ofstream file;
        file.open("Names.txt", ios::app);
        file.write((char *)this, sizeof(*this));
        file.close();

        cout << "Name added successfully" << endl;
    }

    // Read names from file
    void readNames(ifstream &file)
    {
        file.open("Names.txt", ios::in);
        while (file.read((char *)this, sizeof(*this)))
        {
            cout << name << endl;
        }
        file.close();

        // check on non alphabetical characters
        for (int i = 0; i < name.length(); i++)
        {
            if (!isalpha(name[i]))
            {
                throw invalid_argument("Name should contain only alphabets");
            }
        }
    }

    // Display
    void display()
    {
        ifstream file;
        file.open("Names.txt", ios::in);

        cout << "Data in file is: ";
        while (file.read((char *)this, sizeof(*this)))
        {
            cout << name << endl;
        }
        file.close();
    }
};

class NameSorter : public FileReader
{
public:
    NameSorter() : FileReader()
    {
    }
    NameSorter(string name) : FileReader(name)
    {
    }

    // Sort list of names alphabetically
    void sortNames(ifstream &file)
    {
        file.open("Names.txt", ios::in);
        while (file.read((char *)this, sizeof(*this)))
        {
            cout << name << endl;
        }
        file.close();

        // sort name
        sort(name.begin(), name.end());


        if (name.length() > 15)
        {
            throw length_error("Name should not be greater than 15 characters");
        }

        cout << "\nSorted name: " << name << endl;
    }
};

int main()
{
    cout << "--- Sorted Names ---" << endl;

    string name;
    cout << "Enter name: ";
    cin >> name;

    FileReader filereader(name);
    int choice;

    ofstream file;
    ifstream infile;
    do
    {
        cout << "\nSelect an option or -1 to exit" << endl;
        cout << "1. Write names to file" << endl;
        cout << "2. Read names from file" << endl;
        cout << "3. Sort names" << endl;
        cout << "4. Display names" << endl;
        cout << "5. Add new name" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "\nWriting names to file" << endl;
            filereader.writeNames(file);
            break;
        case 2:

            cout << "\nReading names from file" << endl;
            try
            {
                filereader.readNames(infile);
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 3:

            cout << "\nSorting names" << endl;
            
            try
            {
                NameSorter namesorter(name);
                namesorter.sortNames(infile);
            }
            catch (const length_error &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 4:

            cout << "\nDisplaying names" << endl;
            filereader.display();
            break;

        case 5:
            cout << "\nAdding new name" << endl;
            
            cout << "Enter name: ";
            cin >> name;
            filereader.addName(name);
            break;

        case 6:
            cout << "Exiting program" << endl;
            choice = -1;
            break;

        default:

            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != -1);

    return 0;
}