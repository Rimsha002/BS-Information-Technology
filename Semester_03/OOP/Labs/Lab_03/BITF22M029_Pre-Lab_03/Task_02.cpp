#include <iostream>
#include <vector>
using namespace std;

class Job
{
private:
    int deadline;

public:
    Job(int deadline = 0)
    {
        this->deadline = deadline;
    }
    void toSetDeadline(int deadline)
    {
        this->deadline = deadline;
    }
    int getDeadline()
    {
        return deadline;
    }
};

int main()
{
    vector<Job> jobs;

    cout << "\nHow many values you want to enter? " << endl;
    int N;
    cin >> N;

    int deadline;

    for (int i = 0; i < N; ++i) // Create 10 objects of Vector
    {
        cout << "Deadline of job " << i + 1 << ": ";

        while (!(cin >> deadline) || (cin.get() != '\n') || (deadline < 0)) 
        {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            while (cin.get() != '\n')
            {
            }
        }
        jobs.push_back(Job(deadline));
    }

    int deadline1 = jobs[0].getDeadline();
    int deadline2 = jobs[1].getDeadline();

    for (int i = 1; i < jobs.size(); ++i)
    {
        if (jobs[i].getDeadline() < deadline1)
        {
            deadline2 = deadline1;
            deadline1 = jobs[i].getDeadline();
        }

    }

    cout << endl;
    cout << "Two Most Earlier Jobs are: "<< endl;
    cout << "1. Job with Deadline: " <<  deadline1 << endl;
    cout << "2. Job with Deadline: " <<  deadline2 << endl;
    cout << endl;
    
    return 0;
}
