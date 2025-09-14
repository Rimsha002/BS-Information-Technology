#include <iostream>
#include <fstream>
using namespace std;

// Patient Record system by random Access file
class Patient
{
private:
    int patient_ID;
    string name;
    string illness;
    string admitDay;

public:
    Patient()
    {
        patient_ID = 0;
        name = "";
        illness = "";
        admitDay = "";
    }

    Patient(int id, string n, string illness, string day)
    {
        patient_ID = id;
        name = n;
        this->illness = illness;
        admitDay = day;
    }

    // Write
    void writeRecord(ofstream &outFile)
    {
        outFile.write(reinterpret_cast<char *>(this), sizeof(*this));
    }

    void readRecord(ifstream &inFile)
    {
        Patient p;
       inFile.read(reinterpret_cast<char *>(&p), sizeof(p));
        p.display();
    }

    // Delete the record
    void deleteRecord(ofstream &writeFile, int id)
    {
        ifstream inFile;
        inFile.open("Patient.txt", ios::binary);
        if (!inFile)
        {
            cout << "File could not be opened" << endl;
            return;
        }
        // ofstream writeFile;
        writeFile.open("Temp.dat", ios::binary);
        inFile.seekg(0, ios::beg);
        while (inFile.read(reinterpret_cast<char *>(this), sizeof(*this)))
        {
            if (patient_ID != id)
            {
                writeFile.write(reinterpret_cast<char *>(this), sizeof(*this));
            }
        }
        inFile.close();
        writeFile.close();
        remove("Patient.dat");
        rename("Temp.dat", "Patient.dat");
    }
    //  Updater the record
    void updateRecord(ofstream &outFile, int id)
    {
        ifstream inFile;
        inFile.open("Patient.dat", ios::binary);
        if (!inFile)
        {
            cout << "File could not be opened" << endl;
            return;
        }
        ofstream ouFile;
        ouFile.open("Temp.dat", ios::binary);
        inFile.seekg(0, ios::beg);
        Patient p;
        while (inFile.read(reinterpret_cast<char *>(&p), sizeof(p)))
        {
            if (patient_ID == id)
            {
                cout << "Enter new patient ID: ";
                cin >> patient_ID;
                cout << "Enter new name: ";
                cin >> name;
                cout << "Enter new illness: ";
                cin >> illness;
                cout << "Enter new admit day: ";
                cin >> admitDay;
                ouFile.write(reinterpret_cast<char *>(&p), sizeof(p));
            }
            else
            {
                outFile.write(reinterpret_cast<char *>(&p), sizeof(p));
            }
        }
        inFile.close();
        ouFile.close();
        remove("Patient.dat");
        rename("Temp.dat", "Patient.dat");
    }


    void display()
    {
        cout << "Patient Id: "  << patient_ID <<endl;
        cout << "Patient Name: "  << name <<endl;
        cout << "Patient illness: "  << illness <<endl;
        cout << "Patient Admiting Day: "  << admitDay <<endl;
    }
    // Patient &operator=(Patient patient)
    // {

    // }
};

int main()
{
    cout << "\nWelcome to patient Record System" << endl;
    int patient_ID = 0;
    string name = "";
    string illness = "";
    string admitDay = "";
    int choice;

    cout << "Enter the Patient ID: ";
    cin >> patient_ID;
    cin.ignore();
    cout << "Enter the patient name: ";
    getline(cin, name);
    cout << "Enter the patient illness type: ";
    getline(cin, illness);
    cout << "Enter the patient AdmitDay: ";
    getline(cin, admitDay);

    Patient patient(patient_ID, name, illness, admitDay);

    do
    {
        cout << "\nSelect the option \n 1-Add Record to File\n 2-Update Record \n 3-Read Record from file\n 4-Delete Record from file\n Enter option or -1 to quite: " << endl;
        cin >> choice;

        if (choice == -1)
        {
            return 0;
        }
        switch (choice)
        {
        case 1:
        {
            cout << "\n---Add Record---" << endl;
            ofstream outFile;
            outFile.open("Patient.txt", ios::binary);
            if (!outFile)
            {
                cout << "File could not be opened" << endl;
                return 0;
            }
            patient.writeRecord(outFile);
            outFile.close();
            cout << "Data write succefully" << endl;
            break;
        }
        case 2:
        {
            cout << "\n---Update Record---" << endl;
            ofstream outFile;
            outFile.open("Patient.txt", ios::binary);
            if (!outFile)
            {
                cout << "File could not be opened" << endl;
                return 0;
            }
            cout << "Enter the id whose record you want to Update: ";
            int id;
            cin >> id;
            patient.updateRecord(outFile, id);
            outFile.close();
            cout << "Data Updated succefully" << endl;
            break;
        }
           case 3:
        {
            cout << "\n---Read the Record---" << endl;
            ifstream inFile;
            inFile.open("Patient.txt", ios::binary);
            if (!inFile)
            {
                cout << "File could not be opened" << endl;
                return 0;
            }
            patient.readRecord(inFile);
            break;
        }
           case 4:
        {
            cout << "\n---Delete Record---" << endl;
           ofstream outFile;
            outFile.open("Patient.txt", ios::binary);
            if (!outFile)
            {
                cout << "File could not be opened" << endl;
                return 0;
            }
            cout << "Enter the id whose record you want to delete: ";
            int id;
            cin >> id;

          patient.deleteRecord(outFile, id);
            break;
        }
        default:
        {
            cout << "Invalid choice" <<endl;
        }
        }

    } while (choice != -1);


    cout << "\n---GoodBye---" << endl;
    return 0;
}
