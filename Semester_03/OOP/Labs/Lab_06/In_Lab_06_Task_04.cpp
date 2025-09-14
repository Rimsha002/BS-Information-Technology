#include <iostream>
#include <vector>

using namespace std;
int menu();

class Date
{
   int day;
   int month;
   int year;

public:
   Date(int d = 0, int m = 0, int y = 0)
   {
      while (d < 0 || d > 31)
      {
         cout << "Invalid day. Enter Again" << endl;
         cin >> d;
      }
      this->day = d;
      while (m < 0 || m > 12)
      {
         cout << "Invalid month. Enter Again" << endl;
         cin >> m;
      }

      this->month = m;
      while (y < 0 || y > 2023)
      {
         cout << "Invalid year. Enter Again" << endl;
         cin >> y;
      }
      this->year = y;
   }
   // Setter
   void setDay(int d)
   {
      while (d < 0 || d > 31)
      {
         cout << "Invalid day. Enter Again" << endl;
         cin >> d;
      }
      this->day = d;
   }
   void setMonth(int m)
   {
      while (m < 0 || m > 12)
      {
         cout << "Invalid month. Enter Again" << endl;
         cin >> m;
      }
      this->month = m;
   }
   void setYear(int y)
   {
      while (y < 0 || y > 2024)
      {
         cout << "Invalid year. Enter Again" << endl;
         cin >> y;
      }
      this->year = y;
   }
   // Getter
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
   // Display Function
   void displayDate()
   {
      cout << "The date is: " << day << "-" << month << "-" << year << endl;
   }
};

// Class Member
class Member
{
   static int id;
   int memberID;
   string name;
   char gender;
   Date dateOfBirth;

public:
   Member(int mid, string n, char g, Date dob) : dateOfBirth(dob)
   {
      memberID = mid;
      name = n;
      gender = g;
      id++;
   }
   // setter
   void setMemeberID(int mid)
   {
      memberID = mid;
   }
   void setName(string n)
   {
      name = n;
   }
   void setGender(char g)
   {
      gender = g;
   }
   // Getter
   int getmemberId()
   {
      return memberID;
   }
   string getName()
   {
      return name;
   }
   char getGender()
   {
      return gender;
   }
   // Get Age
   int getAge()
   {
      int age = 2024 - dateOfBirth.getYear();
      return age;
   }
   // Display Function
   void displayMember()
   {
      cout << "\n--Member no: " << id << "---" << endl;
      cout << "Member ID: " << memberID << endl;
      cout << "Name: " << name << endl;
      cout << "Gender: " << gender << endl;
      cout << "Age: " << getAge() << " years " << endl;
      cout << "\n";
   }
};
int Member::id = 0;

// class Family
class Family
{
   static int fid;
   int familyID;
   int noOfMember;
   Member mem;

public:
   vector<vector<Member>> v;

   Family(int id, Member m) : mem(m)
   {
      familyID = id;
      v.push_back({m});
      noOfMember = v.size();
      fid++;
   }

   void addMember(Member m)
   {
      v.push_back(vector<Member>{m});
      noOfMember = v.size();
   }
   void removeMember(int id)
   {
      for (int i = 0; i < v.size(); i++)
      {
         if (v[i][0].getmemberId() == id)
         {
            v.erase(v.begin() + i);
            noOfMember = v.size();
         }
      }
   }
   void updateMemberData(int id)
   {
      for (int i = 0; i < v.size(); i++)
      {
         if (v[i][0].getmemberId() == id)
         {
            cout << "Enter the new name: ";
            string name;
            getline(cin,name);
            v[i][0].setName(name);
            cout << "Enter the gender: ";
            char g;
            cin >> g;
            v[i][0].setGender(g);

            int d, m, y;
            cout << "Enter DOB : ";
            cin >> d >> m >> y;

            Date dob1(d, m, y);
            
         }
      }
   }

   void displayFamily()
   {
      cout << "\nFamily ID: " << familyID << endl;
      cout << "No of Member: " << noOfMember << endl;
      for (int i = 0; i < v.size(); i++)
      {
         cout << "Member ID: " << v[i][0].getmemberId() << endl;
         cout << "Name: " << v[i][0].getName() << endl;
         cout << "Gender: " << v[i][0].getGender() << endl;
         cout << "Age: " << v[i][0].getAge() << " years " << endl;
         cout << "\n";
      }
   }
};
int Family::fid = 0;

int main()
{
   // Date
   int day, month, year;
   cout << "Enter the day in counting (DD) : ";
   cin >> day;
   cout << "Enter the month in counting (MM) : ";
   cin >> month;
   cout << "Enter the year (YYYY) : ";
   cin >> year;

   Date date(day, month, year);
   date.displayDate();

   // Member
   int memberID;
   string name;
   char gender;

   cout << "\n--- Member Data ---\n";
   cout << "Enter the member ID: ";
   cin >> memberID;
   cout << "Enter name of member: ";
   getline(cin,name);
   cout << "Enter gender (F for female; M for Male): ";
   cin >> gender;

   Member member(memberID, name, gender, date);
   member.getAge();
   member.displayMember();

   // Family
   int familyID;
   cout << "\n--- Family Data ---\n";
   cout << "Enter the family ID: ";
   cin >> familyID;

   Family family(familyID, member);

   int choice;
   do
   {
      choice = menu();

      switch (choice)
      {
      case 1:
      {
         int memberID;
         string name;
         char gender;
         cout << "\n--Add New Member--\n";

         cout << "Enter the member ID: ";
         cin >> memberID;
         cout << "Enter name of member: ";
         getline(cin,name);
         cout << "Enter gender (F for female; M for Male): ";
         cin >> gender;

         Member m(memberID, name, gender, date);
         family.addMember(m);
         break;
      }
      case 2:
      {
         cout << "\n--Remove Member--\n";
         int id;
         cout << "Enter id of Member: ";
         cin >> id;

         family.removeMember(id);
         break;
      }
      case 3:
      {
         cout << "\n--Update Member Data--\n";
         int id;
         cout << "Enter id of Member: ";
         cin >> id;
         family.updateMemberData(id);
         break;
      }
      case 4:
      {
         family.displayFamily();
         break;
      }
      }

   } while (choice != -1);

   return 0;
}

int menu()
{

   int choice;
   cout << "\n\nSelect one option: \n1. Add Member\n2. Remove Member\n3. Update Member Data\n4. Display Family\nPress -1 to exit" << endl;
   cin >> choice;
   return choice;
}