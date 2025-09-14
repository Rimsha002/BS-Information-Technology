#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
using namespace std;

struct ProjectNode
{
    string projectName;
    string projectCode; // Unique project code, e.g., PRJ213
    bool isCompleted;
    ProjectNode *next; // Link to the next project node
};

struct EmployeeData
{
    string name;
    string employeeID;
    ProjectNode *head; // Pointer to the head of the projects/status list
};

class EmployeeNode
{
public:
    EmployeeData data;
    EmployeeNode *prev;
    EmployeeNode *next;
};

class EmployeeList
{
private:
    EmployeeNode *head;
    int size;

public:
    EmployeeList();
    EmployeeList(const EmployeeList &list);
    ~EmployeeList();
    bool addEmployee(const string &employeeID, const char *name);
    bool addProject(const string &employeeID, const string &projectName, const string &projectCode, bool isCompleted);
    bool removeEmployee(const string &employeeID);
    void updateEmployee(const string &employeeID, const string &newProjectName,
                        bool isCompleted);
    // Update an employee's record by adding a new project (along with its status) to their list of projects.
    // Insert the new project at the head of their project list.
    void displayEmployee(const string &employeeID);
    void displayAllEmployees(int order);
    // Display records of all employees. If `order=0`, display the employees  in ascending order of their employee IDs. If `order=1`, display them in descending order.
};

EmployeeList::EmployeeList()
{
    head = NULL;
    size = 0;
}

EmployeeList::EmployeeList(const EmployeeList &list)
{
    head = list.head;
}

EmployeeList::~EmployeeList()
{
    EmployeeNode *temp = head;
    while (temp != NULL)
    {
        EmployeeNode *next = temp->next;
        delete temp;
        temp = next;
    }
    size = 0;
}

bool EmployeeList::addEmployee(const string &employeeID, const char *name)
{
    EmployeeNode *newNode = new EmployeeNode;
    newNode->data.employeeID = employeeID;
    newNode->data.name = name;
    newNode->data.head = NULL;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        size++;
        return true;
    }

    EmployeeNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    size++;
    return true;
}

bool EmployeeList::addProject(const string &employeeID, const string &projectName, const string &projectCode, bool isCompleted)
{
    EmployeeNode *temp = head;
    while (temp != NULL)
    {
        if (temp->data.employeeID == employeeID)
        {
            ProjectNode *newProject = new ProjectNode;
            newProject->projectName = projectName;
            newProject->projectCode = projectCode;
            newProject->isCompleted = isCompleted;
            newProject->next = temp->data.head;
            temp->data.head = newProject;
            return true;
        }
        temp = temp->next;
    }
    return false;
}






#endif