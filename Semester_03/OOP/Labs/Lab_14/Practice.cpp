#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Structure to represent a record
struct Record {
    int id;
    char name[50];
    float salary;
};

// Function to add a record to the file
void addRecord(fstream& file) {
    Record record;
    cout << "Enter ID: ";
    cin >> record.id;
    cin.ignore(); // Ignore the newline character in the input buffer
    cout << "Enter Name: ";
    cin.getline(record.name, 50);
    cout << "Enter Salary: ";
    cin >> record.salary;

    file.write(reinterpret_cast<char*>(&record), sizeof(Record));
}

// Function to display all records from the file
void displayRecords(fstream& file) {
    file.seekg(0, ios::beg); // Move file pointer to the beginning
    Record record;
    while (file.read(reinterpret_cast<char*>(&record), sizeof(Record))) {
        cout << "ID: " << record.id << ", Name: " << record.name << ", Salary: " << record.salary << endl;
    }
}

// Function to update a specific record
void updateRecord(fstream& file, int id) {
    Record record;
    bool found = false;
    file.seekg(0, ios::beg); // Move file pointer to the beginning
    while (file.read(reinterpret_cast<char*>(&record), sizeof(Record))) {
        if (record.id == id) {
            cout << "Enter new Name: ";
            cin.ignore(); // Ignore the newline character in the input buffer
            cin.getline(record.name, 50);
            cout << "Enter new Salary: ";
            cin >> record.salary;
            file.seekp(-sizeof(Record), ios::cur); // Move file pointer back
            file.write(reinterpret_cast<char*>(&record), sizeof(Record));
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Record with ID " << id << " not found." << endl;
    }
}

// Function to delete a specific record
void deleteRecord(fstream& file, int id) {
    Record record;
    bool found = false;
    fstream tempFile("temp.dat", ios::out | ios::binary);
    file.seekg(0, ios::beg); // Move file pointer to the beginning
    while (file.read(reinterpret_cast<char*>(&record), sizeof(Record))) {
        if (record.id == id) {
            found = true;
        } else {
            tempFile.write(reinterpret_cast<char*>(&record), sizeof(Record));
        }
    }
    file.close();
    tempFile.close();
    remove("records.dat");
    rename("temp.dat", "records.dat");
    if (!found) {
        cout << "Record with ID " << id << " not found." << endl;
    } else {
        cout << "Record with ID " << id << " deleted successfully." << endl;
    }
}

int main() {
    fstream file("records.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int choice;
    do {
        cout << "\n1. Add Record\n2. Display Records\n3. Update Record\n4. Delete Record\n5. Exit\nEnter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                addRecord(file);
                break;
            case 2:
                displayRecords(file);
                break;
            case 3:
                int idToUpdate;
                cout << "Enter ID of record to update: ";
                cin >> idToUpdate;
                updateRecord(file, idToUpdate);
                break;
            case 4:
                int idToDelete;
                cout << "Enter ID of record to delete: ";
                cin >> idToDelete;
                deleteRecord(file, idToDelete);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    file.close();
    return 0;
}
