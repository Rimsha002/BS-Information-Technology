#include <iostream>
#include <string>
using namespace std;

/*
ICC has currently written its players match stats in registers. But with hundreds of new
players coming to International arena, it is getting hard to maintain this system. Now they
have decided to have a Computer based system to manage player’s career stats. Make a class Player:
Attributes:
 ID
 Name
 Team name
 No of Matches
 Total runs scored
 Total wickets
 Total catches taken
Methods:
 Default Constructor
 Parameterized Constructor
 Setters/ Getters
 Display Career Function

Main Function:
 ask the user for number of Matches played.
 Make a team of 5 players,
 Input data for each player from user.
 Pass this team to a function, “Data Displayer”
 display the player with the Most runs scored,
 Player with the most wickets taken,
 player with most catches taken.
 Make a function to Display the whole team as well.
*/

class Player
{
private:
    int iD;
    string name;
    string teamName;
    int noOfMatches;
    int totalRuns;
    int totalWickets;
    int totalCatches;

public:
    // Default Constructor
    Player()
    {
        iD = 0;
        name = "";
        teamName = "";
        noOfMatches = 0;
        totalRuns = 0;
        totalWickets = 0;
        totalCatches = 0;
    }

    // Parametarized Constructor
    Player(int id, string name, string teamName, int noOfMatches, int totalRuns, int totalWickets, int totalCatches)
    {
        iD = id;
        this->name = name;
        this->teamName = teamName;
        this->noOfMatches = noOfMatches;
        this->totalRuns = totalRuns;
        this->totalWickets = totalWickets;
        this->totalCatches = totalCatches;
    }
    // Setters/Getters
    void SetID(int id)
    {
        this->iD = id;
    }
    int GetID()
    {
        return iD;
    }

    void SetName(string name)
    {
        this->name = name;
    }
    string GetName() { return name; }

    void SetTeamName(string teamName)
    {
        this->teamName = teamName;
    }
    string GetTeamName() { return teamName; }

    void SetNoOfMatches(int matches)
    {
        this->noOfMatches = matches;
    }
    int GetNoOfMatches()
    {
        return noOfMatches;
    }

    void SetTotalRuns(int totalRuns)
    {
        this->totalRuns = totalRuns;
    }
    int GetTotalRuns()
    {
        return totalRuns;
    }

    void SetTotalWickets(int totalWickets)
    {
        this->totalWickets = totalWickets;
    }
    int GetTotalWickets()
    {
        return totalWickets;
    }

    void SetTotalCatches(int totalCatches)
    {
        this->totalCatches = totalCatches;
    }
    int GetTotalCatches()
    {
        return totalCatches;
    }

    int dataDisplayer()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << iD << endl;
        cout << "No of Matches: " << noOfMatches << endl;
        cout << "Total Runs: " << totalRuns << endl;
        cout << "Total Wickets: " << totalWickets << endl;
        cout << "Total Catches: " << totalCatches << endl;
    }
    void wholeTeam(Player team[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Player data: " << i + 1 << endl;
            int data = team[i].dataDisplayer();
            cout << data << endl;
        }
    }

    void mostScoredata(Player team[], int size)
    {
        // Most Runs Scores
        int mostRuns = team[0].GetTotalRuns();

        for (int i = 1; i < size; i++)
        {
            if (team[i].GetTotalRuns() > mostRuns)
                mostRuns = team[i].GetTotalRuns();
        }
        cout << "Most Runs Scores: " << mostRuns << endl;

        // Most Wickets Scores

        int mostWickets = team[0].GetTotalWickets();
        for (int i = 1; i < size; i++)
        {
            if (team[i].GetTotalWickets() > mostWickets)
                mostWickets = team[i].GetTotalWickets();
        }
        cout << "Most Wicket Scores: " << mostWickets << endl;

        // Most Catches

        int mostCatches = team[0].GetTotalCatches();
        for (int i = 1; i < size; i++)
        {
            if (team[i].GetTotalCatches() > mostCatches)
                mostCatches = team[i].GetTotalCatches();
        }
        cout << "Most Catches : " << mostCatches << endl;
    }
};

int main()
{
    int teamSize = 5;
    Player team[teamSize];
    Player player;

    string name;
    string teamName;
    int id;
    int totalRuns;
    int totalWickets;
    int totalCatches;

    int noOfMatches;
    cout << "\nHow many no. of Matches will be play? ";
    cin >> noOfMatches;
    cin.ignore();

    for (int i = 0; i < teamSize; i++)
    {
        cout << "\n---Player " << i + 1 << " Data---" << endl;
        cout << "Name: ";
        cin >> name;
        team[i].SetName(name);
        cin.ignore();

        for (int j = 0; j < noOfMatches; j++)
        {
            cout << "\n For match no :" << j + 1 << endl;

            cout << "ID: ";
            cin >> id;
            team[i].SetID(id);

            cout << "Team Name: ";
            cin >> teamName;
            team[i].SetTeamName(teamName);

            cout << "Total Runs: ";
            cin >> totalRuns;
            team[i].SetTotalRuns(totalRuns);

            cout << "Total Wickets: ";
            cin >> totalWickets;
            team[i].SetTotalWickets(totalWickets);

            cout << "Total Catches: ";
            cin >> totalCatches;
            team[i].SetTotalCatches(totalCatches);
        }
    }

    player.mostScoredata(team, teamSize);
    player.wholeTeam(team, teamSize);

    return 0;
}