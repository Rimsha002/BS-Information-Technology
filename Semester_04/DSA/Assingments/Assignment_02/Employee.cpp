#include <iostream>
#include "Employee.h"

using namespace std;

EmployeeList::EmployeeList() : head(nullptr) {}

EmployeeList::~EmployeeList()
{
    EmployeeNode *current = head;

    while (current != nullptr)
    {
        ProjectNode *project = current->data.head;
        while (project)
        {
            ProjectNode *temp = project;
            project = project->next;
            delete temp;
        }
        EmployeeNode *temp = current;
        current = current->next;
        delete temp;
    }
}

EmployeeList::EmployeeList(const EmployeeList &other) : head(nullptr)
{
    EmployeeNode *current = other.head;
    while (current)
    {
        addEmployee(current->data.employeeID, current->data.name);
        ProjectNode *project = current->data.head;
        while (project)
        {
            addProject(current->data.employeeID, project->projectName, project->projectCode, project->isCompleted);
            project = project->next;
        }
        current = current->next;
    }
}

bool EmployeeList::addEmployee(const string &employeeID, const string &name)
{
    EmployeeNode *newEmployee = new EmployeeNode(EmployeeData(name, employeeID));

    if (!head)
    {
        head = newEmployee;
        return true;
    }

    EmployeeNode *current = head;
    EmployeeNode *prev = nullptr;
    while (current && current->data.employeeID < employeeID)
    {
        prev = current;
        current = current->next;
    }

    if (current && current->data.employeeID == employeeID)
    {
        cout << "Employee ID already exists.\n";
        delete newEmployee;
        return false;
    }

    if (prev)
    {
        prev->next = newEmployee;
        newEmployee->prev = prev;
    }
    else
    {
        head = newEmployee;
    }

    if (current)
    {
        newEmployee->next = current;
        current->prev = newEmployee;
    }

    return true;
}

bool EmployeeList::checkEmployee(const string &employeeID)
{
    EmployeeNode *current = head;
    while (current && current->data.employeeID != employeeID)
    {
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << "Employee not found.\n";
        return false;
    }
    return current != nullptr;
}

bool EmployeeList::checkStatus(int status) 
{
    if (status != 0 && status != 1)
    {
        cout << "Invalid status. Enter 0 or 1: ";
        return false;
    }
    return true;
}

bool EmployeeList::addProject(const string &employeeID, const string &projectName, const string &projectCode, bool isCompleted)
{
    EmployeeNode *current = head;
    while (current && current->data.employeeID != employeeID)
    {
        current = current->next;
    }

    if (!current)
    {
        cout << "Employee ID not found.\n";
        return false;
    }

    ProjectNode *newProject = new ProjectNode(projectName, projectCode, isCompleted);
    newProject->next = current->data.head;
    current->data.head = newProject;
    return true;
}

bool EmployeeList::removeEmployee(const string &employeeID)
{
    EmployeeNode *current = head;
    while (current && current->data.employeeID != employeeID)
    {
        current = current->next;
    }

    if (!current)
    {
        cout << "Employee not found.\n";
        return false;
    }

    if (current->prev)
        current->prev->next = current->next;
    if (current->next)
        current->next->prev = current->prev;
    if (current == head)
        head = current->next;

    delete current;
    return true;
}

void EmployeeList::updateEmployee(const string &employeeID, const string &newProjectName, bool isCompleted)
{
    addProject(employeeID, newProjectName, "", isCompleted);
}

void EmployeeList::displayEmployee(const string &employeeID)
{
    EmployeeNode *current = head;
    while (current && current->data.employeeID != employeeID)
    {
        current = current->next;
    }

    if (!current)
    {
        cout << "Employee not found.\n";
        return;
    }

    cout << "Employee ID: " << current->data.employeeID << endl;
    cout << "Name: " << current->data.name << endl;
    ProjectNode *project = current->data.head;
    while (project)
    {
        cout << "Project: " << project->projectName << " (" << "P-Code:" << project->projectCode << "), Completed: " << (project->isCompleted ? "Yes" : "No") << endl;
        project = project->next;
    }
}

void EmployeeList::displayAllEmployees(int order)
{
    if (!head)
    {
        cout << "No employees found.\n";
        return;
    }

    EmployeeNode *current = head;
    if (order == 1)
    {
        while (current->next)
            current = current->next;
        while (current)
        {
            displayEmployee(current->data.employeeID);
            current = current->prev;
        }
    }
    else
    {
        while (current)
        {
            displayEmployee(current->data.employeeID);
            current = current->next;
        }
    }
}

int main()
{
    EmployeeList employeeList;
    int choice = 0;
    string empID, empName, projectName, projectCode;
    bool projectStatus;

    do
    {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Employee\n2. Add Project\n3. Remove Employee\n4. Update Employee\n";
        cout << "5. Display Employee\n6. Display All Employees\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> empID;
            cout << "Enter the Employee naame: ";
            cin.ignore();
            getline(cin, empName);
            employeeList.addEmployee(empID, empName);
            break;
        case 2:
        {
            cout << "\n Add Project Details\n";
            cout << "Enter Employee ID: ";
            cin >> empID;
            // employeeList.checkEmployee(empID);

            if (employeeList.checkEmployee(empID) == true)
            {
                cout << "Enter Project Name: ";
                cin.ignore();
                getline(cin, projectName);
                cout << "Enter Project Code: ";
                cin >> projectCode;
                cout << "Enter Completion Status (0/1): ";
                 cin >> projectStatus;
                 
                if(employeeList.checkStatus(projectStatus))
               {
                employeeList.addProject(empID, projectName, projectCode, projectStatus);
               }
            }
            break;
        }
        case 3:
        {
            cout << "\nRemove Employee\n";
            cout << "Enter Employee ID to remove: ";
            cin >> empID;
            employeeList.removeEmployee(empID);
            break;
        }
        case 4:
        {
            cout << "Update Employee Project\n";
            cout << "Enter Employee ID to update: ";
            cin >> empID;
            if (employeeList.checkEmployee(empID) == true)
            {
                cout << "Enter Project Name: ";
                cin >> projectName;
                cout << "Enter Completion Status (0/1): ";
                cin >> projectStatus;

                employeeList.updateEmployee(empID, projectName, projectStatus);
            }
            break;
        }
        case 5:
        {
            cout << "Display Employee\n";
            cout << "Enter Employee ID to display: ";
            cin >> empID;
            employeeList.displayEmployee(empID);
            break;
        }
        case 6:
        {
            cout << "\nDisplay All Employees\n";
            int order;
            cout << "Enter display order (0 for ascending, 1 for descending): ";
            cin >> order;
            employeeList.displayAllEmployees(order);
            break;
        }
        case 0:
            cout << "Exiting Employee Management System.\n";
            choice = -1;
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    } while (choice != -1);

    cout << "Bye!!" << endl;
    return 0;
}
