#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
class Book
{
public:
    string title;
    string author;
    string publisher;
    int year;
    int ISBN;
    static int isbnCounter;
    string status;

    Book()
    {
        ISBN = isbnCounter++;
    };
    Book(string t, string a, string p, int y, string s)
    {
        title = t;
        author = a;
        publisher = p;
        year = y;
        ISBN = isbnCounter++;
        status = s;
    }

    void setBookData(string t, string a, string p, int y, string s)
    {
        title = t;
        author = a;
        publisher = p;
        year = y;
        ISBN = isbnCounter++;
        status = s;
    }

    void printBookData()
    {
        cout << "Title: " << title << endl;
        cout << "Auther: " << author << endl;
        cout << "Publisher name: " << publisher << endl;
        cout << "Publication year: " << year << endl;
        cout << "Status: " << status << endl;
        cout << "ISBN: " << ISBN << endl;
    }

    void writetoFile(ofstream &outfile)
    {
        outfile << "Title: " << title << endl;
        outfile << "Auther: " << author << endl;
        outfile << "Publisher name: " << publisher << endl;
        outfile << "Publication year: " << year << endl;
        outfile << "Status: " << status << endl;
        outfile << "ISBN: " << ISBN << endl;
    }

    void readfromFile(ifstream &infile)
    {
        string line;
        string y;
        string isbn;

        getline(infile, line);
        title = line;
        getline(infile, line);
        author = line;
        getline(infile, line);
        publisher = line;
        getline(infile, line);
        y = line;
        getline(infile, line);
        status = line;
        getline(infile, line);
        isbn = line;

        cout << title << endl;
        cout << author << endl;
        cout << publisher << endl;
        cout << y << endl;
        cout << status << endl;
        cout << isbn << endl;
    }
};
// initialize the static variable
int Book::isbnCounter = 0;

class Library
{
    string LibraryName;
    string LibraryAddress;
    vector<Book> books;
    Book b;

public:
    Library()
    {
        LibraryName = " ";
        LibraryAddress = " ";
    }
    Library(string n, string a)
    {
        LibraryName = n;
        LibraryAddress = a;
    }

    // set library data
    void setLibraryData(string n, string address, string t, string a, string p, int y, string s)
    {
        LibraryName = n;
        LibraryAddress = address;
        b.setBookData(t, a, p, y, s);
        books.push_back(b);
    }

    void addBook(Book b)
    {
        books.push_back(b);
    }

    // remove specific book by isbn
    void removeBook(int isbn)
    {
        for (int i = 0; i < books.size(); i++)
        {
            if (books[i].ISBN == isbn)
            {
                books.erase(books.begin() + i);
                cout << "Book removed" << endl;
                return;
            }
        }
        cout << "Invalid ISBN! Book not found" << endl;
    }

    // Print Library data
    void printLibraryData()
    {
        cout << "Library Name: " << LibraryName << endl;
        cout << "Library Address: " << LibraryAddress << endl;
        cout << "Books: " << endl;
        for (int i = 0; i < books.size(); i++)
        {
            books[i].printBookData();
        }
    }

    // Write to file
    void writetoFile(ofstream &outfile)
    {
        outfile << endl;
        outfile << "Library Name: " << LibraryName << endl;
        outfile << "Library Address: " << LibraryAddress << endl;
        outfile << "\t~~~ Books ~~" << endl;
        for (int i = 0; i < books.size(); i++)
        {
            // outfile << endl;
            outfile << "Book no. " << i + 1 << endl;
            books[i].writetoFile(outfile);
        }
        cout << endl;
    }

    // Read from file
    void readfromFile(ifstream &infile)
    {
        string line;
        string space;

        getline(infile, line);
        space = line;
        getline(infile, line);
        LibraryName = line;
        getline(infile, line);
        LibraryAddress = line;
        getline(infile, line);
        cout << LibraryName << endl;
        cout << LibraryAddress << endl;

        cout << "~~~ Books ~~~" << endl
             << endl;
        while (!infile.eof())
        {
            Book b;
            b.readfromFile(infile);
        }
    }

    //Checkout 
    void checkOutBook(Book b)
    {
        b.status = "Checked-out";
    }

    //Return Book
    void returnBook(Book b)
    {
        b.status = "Available";
    }
};

int main()
{
    cout << "\n---Welcome to Library Management System---" << endl;
    Library library1;

    string name;
    string address;
    string title;
    string author;
    string publisher;
    int year;
    string status;

    cout << "\n--- Enter Library data--" << endl;
    cout << "Library Name: ";
    getline(cin, name);
    cout << "Library Address: ";
    getline(cin, address);
    cout << "Book Title: ";
    getline(cin, title);
    cout << "Author: ";
    getline(cin, author);
    cout << "Publisher: ";
    cin.ignore();
    getline(cin, publisher);
    cout << "Year: ";
    cin >> year;
    cout << "Status(1-Availabe or 2-Checked-out): ";
     cin.ignore();
    getline(cin, status);

   

    int choice;
    do
    {
        cout << "\n\n\tSelect the option or -1 to terminate" << endl;
        cout << "1. Add more book" << endl;
        cout << "2. Print Library Data" << endl;
        cout << "3. Remove the book" << endl;
        cout << "4. Read data from file" << endl;
        cout << "5. Exit" << endl;
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
            cout << "How many books you want to add: ";
            int num;
            cin >> num;
            for (int i = 1; i <= num; i++)
            {
                cout << "```Book no " << i + 1 << " data```" << endl;

                cout << "Book Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Author: ";
                getline(cin, author);
                cout << "Publisher: ";
                getline(cin, publisher);
                cout << "Year: ";
                cin >> year;
                cin.ignore();
                cout << "Status(Availabe or Checked-out): ";
                getline(cin, status);

                Book b1(title, author, publisher, year, status);
                library1.addBook(b1);
            }
            break;
        }
        case 2:
        {
            cout << "---Library data---" << endl;
            library1.printLibraryData();
            break;
        }
        case 3:
        {
            int isb;
            cout << "Enter the ISBN of the book you want to remove: ";
            cin >> isb;
            library1.removeBook(isb);
            cout << "Updated Library data: " << endl;
            library1.printLibraryData();
            break;
        }
        case 4:
        {
            // File in write mode
            ofstream file("Library.txt", ios::out);
            if (!file)
            {
                cout << "File not created" << endl;
                return 1;
            }
            {

                cout << "Write to file successful " << endl;
                library1.writetoFile(file);
            }
            file.close();
            // File in read mode
            ifstream infile("Library.txt", ios::in);
            if (!infile)
            {
                cout << "File not found" << endl;
                return 1;
            }
            else
            {
                cout << "Read from file: " << endl;
                library1.readfromFile(infile);
            }
            infile.close();
            break;
        }
        case 5:
        {
            cout << "Thank you" << endl;
            choice = -1;
            return 0;
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
