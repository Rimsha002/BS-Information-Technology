#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

struct ProjectNode
{
    string projectName;
    string projectCode;
    bool isCompleted;
    ProjectNode *next;

    ProjectNode(const string &pname, const string &pcode, bool completed)
        : projectName(pname), projectCode(pcode), isCompleted(completed), next(nullptr) {}
};

struct EmployeeData
{
    string name;
    string employeeID;
    ProjectNode *head;

    EmployeeData(const string &empName, const string &empID)
        : name(empName), employeeID(empID), head(nullptr) {}
};

class EmployeeNode
{
public:
    EmployeeData data;
    EmployeeNode *prev;
    EmployeeNode *next;

    EmployeeNode(const EmployeeData &empData)
        : data(empData), prev(nullptr), next(nullptr) {}
};

class EmployeeList
{
private:
    EmployeeNode *head;

public:
    EmployeeList();
    EmployeeList(const EmployeeList &other);
    ~EmployeeList();
    bool addEmployee(const string &employeeID, const string &name);
    bool checkEmployee(const string &employeeID);
    bool checkStatus(int);
    bool addProject(const string &employeeID, const string &projectName, const string &projectCode, bool isCompleted);
    bool removeEmployee(const string &employeeID);
    void updateEmployee(const string &employeeID, const string &newProjectName, bool isCompleted);
    void displayEmployee(const string &employeeID);
    void displayAllEmployees(int order);
};

#endif
