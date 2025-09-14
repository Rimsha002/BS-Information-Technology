#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

struct PatientNode
{
    string patientID;
    string name;
    int severity;
    string arrivalTime;
    PatientNode *next;

    PatientNode(const string &id, const string &pname, int sev, string arrTime)
    {
        patientID = id;
        this->name = name;
        severity = sev;
        arrivalTime = arrTime;
        next = NULL;
    }
};

class PatientQueue
{
private:
    PatientNode *front;

public:
    PatientQueue();
    ~PatientQueue();
    void enqueuePatient(const string &patientID, const string &name, int severity, string arrivalTime);
    void servePatient();
    void viewPatients();
};

#endif
