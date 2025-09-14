#include <iostream>
#include <vector>

using namespace std;
class Person
{
    int cnic;
    string name;
    string address;
    char gender;

public:
    Person()
    {
        cnic = 0;
        name = "";
        address = " ";
        gender = 'M';
    }
    Person(int c, string name, string address, char gender)
    {
        cnic = c;
        this->name = name;
        this->address = address;
        this->gender = gender;
    }

    void setPerson()
    {
        cout << "Enter CNIC: " << cnic << endl;
        cout << "Enter Name : " << name << endl;
        cout << "Enter Address : " << address << endl;
        cout << "Enter Gender(M or F) : " << gender << endl;
    }

    // Display
    virtual void display()
    {
        cout << "CNIC: " << cnic << endl;
        cout << "Name: " << name << endl;
        cout << "Adress: " << address << endl;
        cout << "Gender: " << gender << endl;
    }
};

class Item
{
public:
    // static int iD;
    int iD;
    string title;
    string author;
    int numpages;
    bool isBorrowed;

    Item()
    {
        iD = 0;
        title = "";
        author = " ";
        numpages = 0;
        isBorrowed = false;
        // setborrow();
    }

    void setID(int id)
    {
        this->iD = id;
    }
    void setTitle(string title)
    {
        this->title = title;
    }
    void setAuthor(string a)
    {
        this->author = a;
    }
    void setnumPages(int numpage)
    {
        this->numpages = numpage;
    }

    // Getter
    int getID()
    {
        return iD;
    }
    string getAuther()
    {
        return author;
    }
    string getTitle()
    {
        return title;
    }
    int getNumpages()
    {
        return numpages;
    }

    void setborrow()
    {
        cout << "Is this book borrow? 1) Yes or 2) No";

        int choice;
        switch (choice)
        {
        case 1:
        {
            isBorrowed = true;
        }
        case 2:
        {
            isBorrowed = false;
        }

        default:
            cout << "Invalid choice";
            break;
        }
    }

    void getborrow()
    {
        if (isBorrowed == true)
        {
            cout << "Yes" << endl;
        }
        if (isBorrowed == false)
        {
            cout << "No" << endl;
        }
    }


    void setItem()     //function
    {
        cout << "Item ID: " << iD << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "No of Pages: " << numpages << endl;
        setborrow();
    }

    // Display
    virtual void display()
    {
        cout << "ID: " << iD << endl;
        cout << "Title: " << title << endl;
        cout << "Auther: " << author << endl;
        cout << "Number of pages: " << numpages << endl;
        cout << "Borrow: ";
        getborrow();
    }
};

// Book Class
class Book : public Item
{
public:
    string isbn;

    Book() : Item()
    {
        isbn = " ";
    }; // Default Constructor

    void setISBN(int isbn)
    {
        this->isbn = isbn;
    }

    string getISBN()
    {
        return isbn;
    }


    Book setBook()
    {
        setItem();
       cout << "Enter ISBN of book: " << isbn ;
       return *this;
    }

    void display() override
    {
        Item::display();
        cout << "ISBN: " << isbn << endl;
    }

    // void operator = (Book b)
    // {
    //     isbn = b.isbn;

    // }


};

// Class Thesis
class Thesis : public Item
{
public:
    int thesisID;
    string writer;

    Thesis() : Item()
    {
        thesisID = 0;
        writer = "";
    }; // Default Constructor

    void setThesisId(int id)
    {
        this->thesisID = id;
    }

    int getThesisId()
    {
        return thesisID;
    }

    void display() override
    {
        Item::display();
        cout << "Thesis ID: " << thesisID << endl;
        cout << "Writer of Thesis: " << writer << endl;
    }
};

// class Student
class Student : public Person
{
public:
    int rollNo;
    string degree;
    string department;

    Student() : Person()
    {
        rollNo = 0;
        degree = "";
        department = "";
    }; // Default Constructor

    void setRollNo(int roll)
    {
        this->rollNo = roll;
    }
    void setDegree(string degree)
    {
        this->degree = degree;
    }
    void setDepartment(string d)
    {
        this->department = d;
    }

    // Getter
    int getRollNo()
    {
        return rollNo;
    }
    string getDegree()
    {
        return degree;
    }
    string getDepartment()
    {
        return department;
    }

    void setStudent()
    {
        setPerson();
        cout << "Enter Roll No: " << rollNo << endl;
        cout << "Enter Degree : " << degree << endl;
        cout << "Enter Department: " << department << endl;
    }

    void display() override
    {
        Person::display();
        cout << "Roll No: " << rollNo << endl;
        cout << "Degree: " << degree << endl;
        cout << "Department: " << department << endl;
    }
};

class BorrowItem
{
public:
    string nameOfBorrowItem;
    string borrowDate;
    string returnDate;
    Student lendingTo;

    BorrowItem()
    {
        nameOfBorrowItem = "";
        borrowDate = " ";
        returnDate = " ";
    }

    void lend()
    {
        cout << "Enter Data for lending the Book or Thesis:" << endl;
        lendingTo.setStudent();
        cout << "Name of Book or Thesis: " << nameOfBorrowItem << endl;
        cout << "Borrow date : " << borrowDate << endl;
        cout << "Return Date : " << returnDate << endl;
    }

    void display()
    {
        cout << "\n Data of Lending Book is: " << endl;
        lendingTo.display();
        cout << "Name of Book or Thesis: " <<nameOfBorrowItem << endl;
        cout << "Borrow Date: " << borrowDate<< endl;
        cout << "Return Date : " << returnDate << endl;
    }
};

//class Library
class Library: public Book {
public:
string libraryName;
Person admin;
vector <Book> book;
vector <Thesis> thesis;
vector <BorrowItem> borrowed;

Library()
{
    libraryName = ""; 
}

~Library()
{
    cout << "Destructor is called" << endl;
}

void addBook()
{
    book.push_back(setBook());
}

void deleteBook()
{
    cout << "Enter index at which you want to delete book: ";
    int num;
    cin >> num;
    for (int i = num; i < book.size(); i++)
    {
        book[num] = book[num+1];
    }

    cout << "After deleting books are: " << endl;
    for (int i = 0; i < book.size(); i++)
    {

       book[i].display();
    }
   
}

};

int main()
{
    Library library;
    cout << "\n ````` Welcome to Library ``````\n" << endl;
        int choice;
        do
        {
            cout << "\n\n\tSelect the option or -1 to terminate" << endl;
            cout << "1. Add Book" << endl;
            cout << "2. Delete Book" << endl;
            cout << "3. update Book" << endl;
            cout << "4. Add borrow" << endl;
            cout << "5. Show Borrow Content" << endl;
            cout << "6. Display Library" << endl;
            cout << "7. Return Book" << endl;
            cout << "8. Total books or total borrow" << endl;
           
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
                cout << "\n---Add Book---" << endl;
                library.addBook();
                break;
            }
            case 2:
            {
                cout << "\n---Delete Book---" << endl;
                library.deleteBook();
                break;
            }

            case 3:
            {
                cout << "\n---Resize by Push Back---" << endl;
                
                break;
            }
            case 4:
            {
                

                break;
            }
            case 5:
            {
                
                break;
            }
            case 6:
            {
               
                break;
            }
            case 7:
            {
               
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

