#include <iostream>
using namespace std;
class Employee
{
    private:
    int id;
    static int count;

public:
    void setId()
    {
        cout << "Enter id :";
        cin >> id;

        count++;
    }
    int getId()
    {
        cout << "this is Data of Emploee no: " << count << endl;
        return id;
    }
    static void getCount(void) // Static Member Function to access Private Static Member
    {
        // cout << id // Throws Error as it is only for satatic member
        cout << "The value of count is: " << count << endl;
    }
};


// Declaring    Static Member
int Employee ::count = 100; // Be Default value 0
// Satatic Member :  It has one copy which retains and share by all object of class


int main()
{
    Employee empl1;
    Employee empl2;

    empl1.setId();
    empl1.getId();

    empl1.setId();
    empl2.getId();

  Employee::getCount();
    // cout << "Total Employee Registered: " <<   << endl;
    return 0;
}