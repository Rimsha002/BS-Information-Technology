#include <iostream>
using namespace std;
class Person{
   string name;
   int age;
   char gender;
public:
   Person(){
     
      name = "";
      age = 0;
      gender = 'M';
   }
   Person(int a, string n, char g){
      name = n;
      age = a;
      gender = g;
   }
   void readInput(){
      cout << "Enter name , age , gender: ";
      cin >> name >> age >> gender;
   }
     void writeOutput(){
      cout << "Name: " << name << "  Age: " << age << "  Gender: " << gender << endl;

   }
};

int main()
{
   string name;
   int age;
   char gender;

   Person p1;
   p1.readInput();
   p1.writeOutput();

   return 0;
}