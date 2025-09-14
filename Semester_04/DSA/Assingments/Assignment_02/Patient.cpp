#include <iostream>
#include "Patient.h"

using namespace std;

PatientQueue::PatientQueue() : front(nullptr) {}

PatientQueue::~PatientQueue()
{
    while (front)
    {
        PatientNode *temp = front;
        front = front->next;
        delete temp;
    }
}

void PatientQueue::enqueuePatient(const string &patientID, const string &name, int severity, string arrivalTime)
{
    PatientNode *newPatient = new PatientNode(patientID, name, severity, arrivalTime);

    if (!front ||
        severity > front->severity ||
        (severity == front->severity &&
         arrivalTime < front->arrivalTime))
    {
        newPatient->next = front;
        front = newPatient;
    }
    else
    {
        PatientNode *current = front;
        while (current->next &&
               (current->next->severity > severity ||
                (current->next->severity == severity && current->next->arrivalTime <= arrivalTime)))
        {
            current = current->next;
        }
        newPatient->next = current->next;
        current->next = newPatient;
    }
    cout << "Patient added to queue.\n";
}

void PatientQueue::servePatient()
{
    if (!front)
    {
        cout << "No patients in the queue.\n";
        return;
    }
    PatientNode *temp = front;
    cout << "Serving Patient ID: " << temp->patientID << ", Name: " << temp->name << endl;
    cout << ", Severity: " << temp->severity << endl;
    cout << "Arrival Time: " << temp->arrivalTime << endl;
    front = front->next;
    delete temp;
}

void PatientQueue::viewPatients()
{
    if (!front)
    {
        cout << "No patients in queue.\n";
        return;
    }
    PatientNode *current = front;
    while (current)
    {
        cout << "Patient ID: " << current->patientID
             << ", Name: " << current->name
             << ", Severity: " << current->severity << endl;
        cout << "Arrival Time: " << current->arrivalTime << endl;
        current = current->next;
    }
}

int main()
{
    PatientQueue patientQueue;
    int choice;
    string patientID, name;
    int severity;
    string arrivalTime;

    do
    {
        cout << "\nPatient Management System\n";
        cout << "1. Enqueue Patient\n2. Serve Patient\n3. View Patients\n0. Exit\n";
        cout << "Enter choice: ";
        cin.clear();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Patient ID: ";
            cin >> patientID;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Severity: ";
            cin >> severity;
            cout << "Enter Arrival Time: ";
            cin.ignore();
            getline(cin, arrivalTime);

            patientQueue.enqueuePatient(patientID, name, severity, arrivalTime);
            break;
        case 2:
            patientQueue.servePatient();
            break;
        case 3:
            patientQueue.viewPatients();
            break;
        case 0:
            cout << "Exiting Patient Management System.\n";
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    } while (choice != 0);

    cout << "Good Bye!" << endl;
    return 0;
}
