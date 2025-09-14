#include <iostream>
using namespace std;

template <typename T>

class Person
{
private:
    string ID;
    string name;
    string address;

public:
    Person(string Id, string name, string address)
    {
      
        ID = Id;
        name = name;
        address = address;
    }
    int setID(int id)
    {
        ID = id;
    }
    string setName(string name)
    {
        this.name = name;
    }

    int getName(string name)
    {
        name = name;
    }
    string setAddress(string address)
    {
        this.address = address;
    }

    string getAddress(string address)
    {
        address = address;
    }
    void displayAllData()
    {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
    }

    void add(T one, T two)
    {
        return one + two;
    }
    void add(T one, T two, T three)
    {
        return one + two;
    }

}; // Semi Colon

int main()
{
    Person<string> person("1", "M.Jafar Naqvi", "GRW");
    person.setID(1);
    person.setName("M.Jafar Naqvi");
    person.setAddress("GRW");
    person.displayAllData();
    return 0;
}