#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Rubric
{
public:
    int regno;
    float clarity;
    float completeness;
    float accuracy;
    float time;
    float total_marks;

    // Default constructor
    Rubric()
    {
        regno = 0;
        clarity = 0;
        completeness = 0;
        accuracy = 0;
        time = 0;
        total_marks = 0;
    }

    // Parameterized constructor
    Rubric(int r, float c, float comp, float acc, float t)
    {
        if (c < 0 || c > 2 || comp < 0 || comp > 3 || acc < 0 || acc > 3 || t < 0 || t > 2)
        {
            throw invalid_argument("Invalid input values.");
        }
        regno = r;
        clarity = c;
        completeness = comp;
        accuracy = acc;
        time = t;
        total_marks = clarity + completeness + accuracy + time;
    }

    // Method to write Rubric data to a file
    void writeToFile(ofstream &outfile)
    {
        outfile << regno << " " << clarity << " " << completeness << " " << accuracy << " " << time << " " << total_marks << endl;
    }

    // Method to read Rubric data from a file
    void readFromFile(ifstream &infile)
    {
        infile >> regno >> clarity >> completeness >> accuracy >> time >> total_marks;
    }

    // Method to display Rubric data
    void display()
    {
        cout << "Regno: " << regno << endl;
        cout << "Clarity: " << clarity << endl;
        cout << "Completeness: " << completeness << endl;
        cout << "Accuracy: " << accuracy << endl;
        cout << "Time: " << time << endl;
        cout << "Total Marks: " << total_marks << endl;
        cout << endl;}
};

int main()
{
    Rubric r1(101, 1.5, 2.5, 3.0, 1.0);
    Rubric r2(102, 2.0, 3.0, 2.5, 2.0);
    Rubric r3(103, 1.0, 2.0, 1.5, 1.5);

    // Write Rubric objects to a file
    ofstream outfile("Rubrics.txt", ios::out);
    if (!outfile)
    {
        cerr << "Error creating file!" << endl;
        return 1;
    }
    r1.writeToFile(outfile);
    r2.writeToFile(outfile);
    r3.writeToFile(outfile);
    outfile.close();

    // Read Rubric objects from the file and create new objects
    ifstream infile("Rubrics.txt", ios::in);
    if (!infile)
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    vector<Rubric> rubrics;
    Rubric temp;
    for (int i = 0; i < 3; ++i)
    {
        temp.readFromFile(infile);
        rubrics.push_back(temp);
    }
    infile.close();

    // Display the Rubric objects read from the file
    for (Rubric &r : rubrics)
    {
        r.display();
    }

    return 0;
}