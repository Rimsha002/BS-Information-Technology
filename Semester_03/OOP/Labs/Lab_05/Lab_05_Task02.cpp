#include <iostream>
#include <vector>
using namespace std;
int display();

class Voter
{
private:
    int cnic;
    string nameV;
    bool hasVooted;

public:
    Voter(int cnic = 0, string name = " ", bool hasvooted = false)
    {
        this->cnic = cnic;
        this->nameV = name;
        this->hasVooted = hasvooted;
    }

    void setcnic(int cnic)
    {
        this->cnic = cnic;
    }
    void setName(string name)
    {
        this->nameV = name;
    }
    void sethasVooted(bool hasvooted)
    {
        this->hasVooted = hasvooted;
    }

    int getcnic()
    {
        return cnic;
    }
    string getName()
    {
        return nameV;
    }
    bool gethasVooted()
    {
        return hasVooted;
    }
    void display()
    {
        cout << "CNIC : " << cnic << endl;
        cout << "Name : " << nameV << endl;
        cout << "Has Vooted : " << hasVooted << endl;
        cout << endl << endl;
    }
};

class Candidate
{
private:
    int id;
    string name;
    string party;
    string symbol;
    int votes;

public:
    Candidate(int id,
              string name,
              string party,
              string symbol,
              int votes)
    {
        this->id = id;
        this->name = name;
        this->party = party;
        this->symbol = symbol;
        this->votes = votes;
    }

    void setid(int id)
    {
        this->id = id;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setparty(string party)
    {
        this->party = party;
    }
    void setSymbol(string symbol)
    {
        this->symbol = symbol;
    }
     void setVote(int votes)
    {
        this->votes = votes;
    }

    // Getter
    int getid()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    string getparty()
    {
        return party;
    }
    string getSymbol()
    {
        return symbol;
    }
    int getvote()
    {
        return votes;
    }
    void display()
    {
        cout << "ID : " << id  << endl;
        cout << "Name : " << name  << endl;
        cout << "Party : " << party  << endl;
        cout << "Symbol : " << symbol  << endl;
        cout << "Votes : " << votes  << endl;
        cout << endl << endl;
    }
};

class VotingMachine
{
    int id;
    string nameC;
    string party;
    string symbol;
    int votes;
    int cnic;
    string nameV;
    bool hasVooted;

public:
    vector<Candidate> candidate;
    vector<Voter> voter;

    void addCandidate(int id, string nameC, string party, string symbol, int votes)
    {
        Candidate objcand(id, nameC, party, symbol, votes);
        candidate.push_back(objcand);

    }
    void removeCandidate(int id)
    {
        Candidate objcand(id, nameC, party, symbol, votes);
        candidate.erase(objcand);
    }

    void displayCandidate()
    {        
        Candidate objcand(id, nameC, party, symbol, votes);

        for (Candidate &objcand : candidate)
        {
            objcand.display();
        }
    }

    // Voter
    void addVoter(int cnic, string nameV, bool hasVooted)
    {
        Voter objvote(cnic, nameV, hasVooted);
        voter.push_back(objvote);
    }
    void removeVoter(int cnic)
    {
        Voter objvote(cnic);
        // voter.remove(objvote);
    }

    void displayVoter()
    {
        Voter objvote(cnic, nameV, hasVooted);
        objvote.display();
        
        for (Voter &objvote : voter)
        {
            objvote.display();
        }
    }    
  
};

int main()
{
    vector<VotingMachine> voteMachine;
    VotingMachine voteM;
    int choice;
    int id;
    string nameV;
    string party;
    string symbol;
    int votes;
    int cnic;
    string nameC;
    bool hasVooted;

    do
    {
        choice = display();
    

    switch (choice)
    {
    case 1:
    {
        cout << "---Add Candidate---" << endl;
        cout << "Enter id of candidate: " << endl;
        cin >> id;
        cout << "Enter Name of candidate: " << endl;
        getline(cin,nameC);
        cout << "Enter Party of candidate: " << endl;
        getline(cin,party);
        cout << "Enter Symbol of candidate: " << endl;
        getline(cin,symbol);
        cout << "Enter vote of candidate: " << endl;
        cin >> votes;
        voteM.addCandidate(id, nameC, party, symbol, votes);
        break;
    }
    case 2:
    {
        cout << "---Remove Candidate---" << endl;
        cout << "Enter id of candidate: " << endl;
        cin >> id;
        voteM.removeCandidate(id);
        break;
    }

    case 3:
    {
        cout << "---Display All Candidate---" << endl;

        voteM.displayCandidate();
        break;
    }
    case 4:
    {
        cout << "---Add Voter---" << endl;
        cout << "Enter CNIC of Voter: " << endl;
        cin >> id;
        cout << "Enter Name of Voter: " << endl;
        getline(cin,nameV);
        cout << "Have you votted [1] for Yes or [0] for No: " << endl;
        cin >> hasVooted;

        voteM.addVoter(cnic, nameV, hasVooted);
        break;
    }
    case 5:
    {
        cout << "---Remove Voter---" << endl;
        cout << "Enter CNIC of candidate: " << endl;
        cin >> cnic;
        voteM.removeVoter(id);
        break;
    }
        case 6:
    {
        cout << "---Display All Vooter---" << endl;

        voteM.displayVoter();
        break;
    }
    }
    } while (choice != -1);
    return 0;
}

int display()
{

    int choice;
    cout << "\nSelect the one option: " << endl;
    cout << "1- Add Candidate" << endl;
    cout << "2- Remove Candidate" << endl;
    cout << "3- Display all Candidate" << endl;
    cout << "4- Add Voter" << endl;
    cout << "5- Remove voter" << endl;
    cout << "6- Display all Voters" << endl;
    cout << "or Press -1 to exit" << endl;
    cin >> choice;
    while (choice < 1 || choice > 6)
    {
        cout << "Invalid Choice, Enter again";
        cin >> choice;
    };

    return choice;
}