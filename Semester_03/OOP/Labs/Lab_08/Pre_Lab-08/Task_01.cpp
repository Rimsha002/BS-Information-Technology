#include <iostream>
using namespace std;
class Student
{
    int subject;
    int *marks;

public:
    Student() // Default Constructor
    {
        subject = 0;
        marks = nullptr;
    }
    Student(int sub) // Parameterize Constructor
    {
        subject = sub;
        marks = new int[subject];
        cout << "Enter marks for each subject: ";
        for (int i = 0; i < subject; i++)
        {
            cin >> marks[i];
        }
    }

    // copy constructor
    Student(const Student &s1)
    {
        this->subject = s1.subject;
        marks = new int[subject];
        for (int i = 0; i < subject; i++)
        {
            this->marks[i] = s1.marks[i];
        }
    }
    ~Student() { // Destructor
        delete[] marks;
    }

    void setSubject(int sub)
    {
        subject = sub;
    }
    int getSubject() const
    {
        return subject;
    }
    void setMarks(int m[], int s)
    {
        subject = s;
        delete [] marks;
        for (int i = 0; i < s; i++)
        {
            this->marks[i] = m[i];
        }
    }
    const int *getMarks() const
    {
        return marks;
    }
    void inputMarks(int subj, int m[])
    {
        delete [] marks;
        subject = subj;
        marks = new int [subject];
        for (int i = 0; i < subj; i++)
        {
            marks[i] = m[i];
        }
    }
    void outputMarks()
    {
        cout << "Subjects: " << subject << endl;
        cout << "Marks are: ";
        for (int i = 0; i < subject; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int subject;
    // Student s1;

    cout << "\n---Parameterize Constructor---" << endl; // Parameterize Constructor
    cout << "Enter no of Subjects: ";
    cin >> subject;
    Student s1(subject);
    s1.outputMarks();

    cout << "\n---Copy Constructor---" << endl; // Copy constructor called
    Student s2(s1);
    s2.outputMarks();

    cout << "\n---Input Marks Method---" << endl; // Input Marks Method called
    int m[3] = {0};
    cout << "Enter Subjects: ";
    cin.ignore();
    cin >> subject;
    cout << "Enter marks: ";
    for (int i = 0; i < subject; i++)
    {
        cin >> m[i];
    }
    s1.inputMarks(subject, m);
    s1.outputMarks(); // Output Marks Method called

    return 0;
}