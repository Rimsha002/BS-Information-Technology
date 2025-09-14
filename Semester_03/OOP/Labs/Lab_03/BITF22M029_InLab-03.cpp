#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

int sortSaleman(vector<Salesman> &salesman);

class Salesman
{
private:
    string name;
    int salary;
    int sales_made;

public:

Salesman(string name= "", int salary = 0, int sales_made = 0)
{
    this->name = name;
    this->salary = salary;
    this->sales_made= sales_made;
}
void display()
{
    cout << "Name:" << name << endl;
    cout << "Salary:" << salary<< endl;
    cout << "Sales-Made:" << sales_made << endl;
}
};



int main()
{
    int salemanNo;
    cout << "How many number of Salesman?" << endl;
    cin >> salemanNo;

    // vector<int> FireSalesman(salemanNo);

    vector<Salesman> salesman;

    for (int i = 0; i < salemanNo; ++i)
    {
        string name;
        int salary;
        int sales_made;

        cout << "Enter details for Salesman " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> name;
        cout << "Salary: ";
        cin >> salary;
        cout << "Sales Made: ";
        cin >> sales_made;

        Salesman(name, salary, sales_made);
    }

    //Display Salesman data

    for(auto &n : salesman)
    {
        n.display();
    }

    return 0;
}


//Incomplete
// int sortSaleman(vector<Salesman> &salesman)
// {
//     sort(salesman.begin(), salesman.end(), greater<int>);

//     if(salesman.sales_made < 10)
//     {
//          search()
//     }

// }

//Try to solve but incomplete
//Unable to understand the remaining portion