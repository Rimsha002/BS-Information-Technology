#include <iostream>
#include <stdexcept>

using namespace std;
class Customer
{
    int customerId;
    static int id;
    static int count;
    string name;
    int phone;
    string gender;

public:
    Customer(string n, int p, string g)
    {
        name = n;
        phone = p;
        gender = g;
        customerId = id;

        id++;

        if (count > 0)
        {
            count = count - 1;
        }
        else
        {
            throw invalid_argument("Invalid Count.");
        }
    }
    // static int getCount()
    // {
    //     cout << "Number of Objects are: " << count << endl;
    // }
    void display()
    {
        cout << "ID: " << customerId << endl;
        cout << "Count no : " << count << endl;
        cout << "Name : " << name << endl;
        cout << "Phone : " << phone << endl;
        cout << "Gender : " << gender << endl;
        cout << endl
             << endl;
    }
};

int Customer ::id = 0;
int Customer ::count = 5;

int main()
{
    string name;
    string gender;
    int phone;

    cout << "Enter Name : ";
    getline(cin, name);
    cout << "Enter Phone: ";
    cin >> phone;
    cout << "Enter Gender (F for female, M for Male): ";
    cin >> gender;

    try
    {
        Customer custom1(name, phone, gender);
        custom1.display();
        Customer custom2(name, phone, gender);
        Customer custom3(name, phone, gender);
        Customer custom4(name, phone, gender);
        Customer custom5(name, phone, gender);

        custom2.display();
        custom3.display();
        custom4.display();
        custom5.display();
    }
    catch (const exception &e)
    {
        cerr << "Error! " << e.what() << endl;
    }

    return 0;
}