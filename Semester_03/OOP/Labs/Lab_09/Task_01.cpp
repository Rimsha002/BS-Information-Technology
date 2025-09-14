#include <iostream>
#include <vector>
using namespace std;
class Date
{
    int day = 0;
    int month = 0;
    int year = 0;

    friend istream &operator>>(istream &i, Date &date);
    friend ostream &operator<<(ostream &o, const Date &date);
    friend Date operator+(Date date, Date date1);
    friend Date operator-(Date date, Date date1);

public:
    // Default + Parameterize Constructor
    Date(int d = 0, int mon = 0, int y = 0, int h = 0, int m = 0, int s = 0)
    {

        if (d < 0 || d > 31 || mon < 0 || mon > 12 || y < 0 || y > 3000)
        {
            while (d < 0 || d > 31)
            {
                cout << "Invalid day" << endl;
                cout << "Enter day(0 to 31): ";
                cin >> d;
            }

            while (mon < 0 || mon > 12)
            {
                cout << "Invalid month" << endl;
                cout << "Enter month(0 to 12): ";
                cin >> mon;
            }
            while (y < 0 || y > 3000)
            {
                cout << "Invalid year" << endl;
                cout << "Enter year(0 to 3000): ";
                cin >> y;
            }
        }

        if (d >= 0 && d <= 31 && mon >= 0 && mon <= 12 && y >= 0)
        {
            this->day = d;
            this->month = mon;
            this->year = y;
        }
    }

    // Copy Constructor
    Date(Date &date)
    {
        day = date.day;
        month = date.month;
        year = date.year;
    }

    ~Date()
    {
    }

    void setDay(int d)
    {
        if (d >= 0 && d <= 31)
        {
            this->day = d;
        }
        else
        {
            cout << "Invalid day" << endl;
        }
    }
    void setMonth(int mon)
    {
        if (mon >= 0 && mon <= 12)
        {
            this->month = mon;
        }
        else
        {
            cout << "Invalid month" << endl;
        }
    }
    void setYear(int y)
    {
        if (y >= 0)
        {
            this->year = y;
        }
        else
        {
            cout << "Invalid year" << endl;
        }
    }
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }

    void setDate(int d, int m, int y)
    {
        this->day = d;
        this->month = m;
        this->year = y;
    }

    Date getDate()
    {
        Date d1;
        return d1;
    }

    // Display
    void display()
    {
        cout << "\nDate: ";
        cout << endl
             << day << " : " << month << " : " << year << "\nTime: ";
    }
};

istream &operator>>(istream &i, Date &date)
{
    cout << "Enter day: ";
    i >> date.day;
    cout << "Enter month: ";
    i >> date.month;
    cout << "Enter year: ";
    i >> date.year;
    return i;
}
ostream &operator<<(ostream &o, const Date &date)
{
    o << "Date: " << date.day << " : " << date.month << " : " << date.year;
    return o;
}

Date operator+(Date date, Date date1)
{
    Date date2;
    date2.day = date.day + date1.day;
    date2.month = date.month + date1.month;
    date2.year = date.year + date1.year;

    if ((date2.day) > 31)
    {
        date2.month += date2.day / 31;
        date2.day %= 31;
    }
    if ((date2.month) > 12)
    {
        date2.year += date2.month / 12;
        date2.month %= 12;
    }
    return date2;
}

Date operator-(Date date, Date date1)
{
    Date date2;
    date2.day = date.day - date1.day;
    date2.month = date.month - date1.month;
    date2.year = date.year - date1.year;

    if ((date2.day) < 0)
    {
        date2.month -= 1;
        date2.day += 31;
    }
    if ((date2.month) < 0)
    {
        date2.year -= 1;
        date2.month += 12;
    }
    return date2;
}

/// Department Class
class Dept
{
    int depId;
    string dname;
    string location;

public:
    Dept()
    {
        depId = 0;
        dname = " ";
        location = " ";
    }

    Dept(int id, string dname, string dloc)
    {
        this->depId = id;
        this->dname = dname;
        this->location = dloc;
    }

    friend istream &operator>>(istream &i, Dept &depart);
    friend ostream &operator<<(ostream &o, const Dept &depart);
    // Display
    void display()
    {
        cout << "Department Id: " << depId << endl;
        cout << "Department Name: " << dname << endl;
        cout << "Department Location: " << location << endl;
    }

    void setDepart(int id, string name, string loc)
    {
        this->depId = id;
        this->dname = name;
        this->location = loc;
    }

    Dept getDepart()
    {
        Dept department;
        return department;
    }
};

istream &operator>>(istream &i, Dept &depart)
{
    cout << "Enter department id: ";
    i >> depart.depId;
    cout << "Enter department name: ";
     cin.ignore();
     getline(i, depart.dname);
    cout << "Enter deparment location: ";
    i >> depart.location;
    return i;
}
ostream &operator<<(ostream &o, const Dept &depart)
{
    o << "Department Id: " << depart.depId << endl
      << "Department Name: " << depart.dname << endl
      << "Department Location: " << depart.location << endl;
    return o;
}

/// Employee Class
class Employee
{
    int empId;
    string ename;
    int salary;
    int workingHour;
    Date hiredate;
    Dept deptid;

    friend istream &operator>>(istream &i, Employee &emplo);
    friend ostream &operator<<(ostream &o, const Employee &emplo);

public:
    Employee()
    {
        empId = 0;
        ename = " ";
        salary = 0;
        workingHour = 0;
    }

    // Parametarize
    Employee(int eid, string ename, int salary, int workHr, int day, int mon, int year, int depid, string dname, string deplocation)
    {
        this->empId = eid;
        this->ename = ename;
        this->salary = salary;
        this->workingHour = workHr;
        hiredate.setDate(day, mon, year);
        deptid.setDepart(depid, dname, deplocation);
    }
    // Copy Constructor
    Employee(const Employee &emplo) // must be contant
    {
        this->empId = emplo.empId;
        this->ename = emplo.ename;
        this->salary = emplo.salary;
        this->workingHour = emplo.workingHour;
        this->hiredate = emplo.hiredate;
        this->deptid = emplo.deptid;
    }
    ~Employee()
    {
    }
    void setEmploID(int)
    {
        this->empId = empId;
    }
    void setName(string name)
    {
        this->ename = name;
    }
    int getEmploId()
    {
        return empId;
    }
    int getnoOfYear()
    {
        int noOfYears = 2024 - hiredate.getYear();
        return noOfYears;
    }

    // Display
    void display()
    {
        cout << "Employee Id: " << empId << endl;
        cout << "Employee Name: " << ename << endl;
        cout << "Employee salary: " << salary << endl;
        cout << "Working Hours: " << workingHour << endl;
        hiredate.display();
        deptid.display();
    }
};

istream &operator>>(istream &i, Employee &emplo)
{
    cout << "Enter Employee id: ";
    i >> emplo.empId;
    cout << "Enter Employee name: ";
    cin.ignore();
    getline(i, emplo.ename);
    cout << "Enter Employee Salary: ";
    i >> emplo.salary;
    cout << "Enter Working hours: ";
    i >> emplo.workingHour;
    i >> emplo.hiredate;
    cout << "Employee's deaprtmet details: \n";
    i >> emplo.deptid;
    return i;
}
ostream &operator<<(ostream &o, const Employee &emplo)
{
    o << "Employee Id: " << emplo.empId << endl
      << "Employee Name: " << emplo.ename << endl
      << "Employee salary: " << emplo.salary << endl
      << "Working Hours: " << emplo.workingHour << endl
      << emplo.hiredate << endl
      << emplo.deptid << endl;
    return o;
}

/// Firm Class
class Firm
{
    string fname;
    int noOfEmployee;
    Employee emplo;
    vector<Employee> vEmplo;
    friend class Attendance;

public:
    Firm()
    {
        fname = " ";
        noOfEmployee = 0;
    }
    Firm(string n, int num, vector<Employee> v)
    {
        this->fname = n;
        this->noOfEmployee = num;
        for (int i = 0; i < vEmplo.size(); i++)
        {
            this->vEmplo[i] = v[i];
        }
    }
    // Copy Constructor
    Firm(const Firm &firm)
    {
        this->fname = firm.fname;
        this->noOfEmployee = firm.noOfEmployee;

        for (int i = 0; i < vEmplo.size(); i++)
        {
            this->vEmplo[i] = firm.vEmplo[i];
        }
    }
    ~Firm()
    {
    }

    // Add Employee
    void addEmployee(Employee emplo)
    {
        vEmplo.push_back(emplo);
    }

    void removeEmployee(Employee emplo)
    {
        cin.ignore();
        cout << "Enter id of Employee: ";
        int id;
        for (int i = 0; i < vEmplo.size(); i++)
        {
            if (id == vEmplo[i].getEmploId())
            {
                vEmplo.erase(vEmplo.begin() + i);
                break;
            }
        }
    }

    void updateEmployee(Employee emplo)
    {
        cin.ignore();
        cout << "Enter id of Employee to which you update: ";
        int id;
        for (int i = 0; i < vEmplo.size(); i++)
        {
            if (id == vEmplo[i].getEmploId())
            {
                cin >> vEmplo[i];
                break;
            }
        }

        vEmplo.push_back(emplo);
    }
    void sortEmployee()
    {
    }

    void display()
    {
        cout << "Firm name: " << fname << endl;
        cout << "Number of Employee: " << noOfEmployee << endl;

        emplo.display();
    }

    friend istream &operator>>(istream &i, Firm &firm);
    friend ostream &operator<<(ostream &o, const Firm &firm);
};

istream &operator>>(istream &i, Firm &firm)
{
    cout << "Enter Firm name: ";
    getline(i, firm.fname);
    cout << "Enter No of Employee: ";
    i >> firm.noOfEmployee;
    cout << "--Employee Data--";
    for (int i = 0; i < firm.noOfEmployee; i++)
    {
        cout << "\n--For Employee no. " << i + 1 << endl;

        Employee emplo;
        cin >> emplo;
        firm.vEmplo.push_back(emplo);
    }

    return i;
}
ostream &operator<<(ostream &o, const Firm &firm)
{
    cout << "\n\n ---Firm Data is: ---\n";
    o << "Firm Name: " << firm.fname << endl
      << "No of Employee: " << firm.noOfEmployee << endl;
    for (int i = 0; i < firm.vEmplo.size(); i++)
    {
        cout << "\n\t--Employee no. " << i + 1 << endl;
        o << firm.vEmplo[i];
    }

    return o;
}

class Attendance
{
    vector<Date> vdate;
    vector<vector<Employee>> present_Employee;

public:
};

int main()

{

    cout << "---Firm data---" << endl;
    Firm firm;
    cin >> firm;
  
    int choice;
    do
    {
        cout << "Select the option or -1 to terminate" << endl;
        cout << "1. Display Firm data" << endl;
        cout << "2. Add Employee" << endl;
        cout << "3. Remove Employee" << endl;
        cout << "4. Update Employee" << endl;
        cout << "5. Sort Employee" << endl;
        cout << "6. Mark Attencance" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == -1)
        {
            break;
        }

        switch (choice)
        {
        case 1:
        {
            cout << "\n---Display Firm" << endl;
            cout << firm;
            break;
        }
        case 2:
        {
            Employee emplo;
            cin >> emplo;
            firm.addEmployee(emplo);
            break;
        }

        case 3:
        {
            Employee emplo;
            firm.removeEmployee(emplo);
            break;
        }
        case 4:
        {
            Employee emplo;
            firm.updateEmployee(emplo);
            break;
        }

        default:
        {
            cout << "Invalid choice" << endl;
            break;
        }
        }

    } while (choice != -1);

    return 0;
}