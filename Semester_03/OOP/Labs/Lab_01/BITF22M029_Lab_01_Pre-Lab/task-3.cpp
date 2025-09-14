#include <iostream>
#include <string>

using namespace std;
/*
Task 03: Student Class

1- Create following data members:
 Roll number (string)
 Name (string)
 Section (string)
 Cgpa (float)
All the data members should not be directly accessible outside the class.

2- Create following Data members:
 Default constructor
 Setters for all data members
 Getters for all members
 Display all Data
 */
class student
{
private:
    string rollNmuber; // Data members
    string name;
    string section;
    float cgpa;

public:
    student() // Constructor
    {
        string rollNmuber = "0";
        string name = "0";
        string section = "0";
        float cgpa = 0.0;
    }

    //Roll No
    void setterRollNo(string studentRollNo)
    {
        rollNmuber = studentRollNo;
    }
    string getterRollNo()
    { 
        return rollNmuber;
    }
    
    //Name
     void setterName(string studentName)
    {
        name = studentName;
    }
    string getterName()
    { 
        return name;
    }

    //Section
     void setterSection(string studentSection)
    {
        section = studentSection;
    }
    string getterSection()
    { 
        return section;
    }
    
    //CGPA
     void setterCgpa(float studentCgpa)
    {
        cgpa = studentCgpa;
    }
    float getterCgpa()
    { 
        return cgpa;
    }



    void display()
    {
        cout << "Data from display is: " << endl ; 
        cout << "Roll Nmber: " << rollNmuber << endl;
        cout << "Name: " << name << endl;
        cout << "Section: " << section << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

//Main 
int main()
{
    student obj;
   
    obj.setterRollNo("bitf22m029");
    obj.setterName("Rimsha");
    obj.setterSection("BSIT");
    obj.setterCgpa(3.3);
    

    obj.getterRollNo();
    obj.getterName();
    obj.getterSection();
    obj.getterCgpa();

    obj.display();
    return 0;
}
