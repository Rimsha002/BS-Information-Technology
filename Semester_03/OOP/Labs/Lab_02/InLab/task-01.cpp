#include <iostream>
using namespace std;

/*
class Player with the following attributes:
int ID;
string Name;
int HealthPoints;
int damagePoints;
bool isDead;
The following functionality is required. Two players must be able to engage in a battle. When fight starts, display message:
“New Battle: {Player one} vs {Player two}”
When they fight, ask the user for number of hits for both players. Each player will do
damage to other according to the his damage points.Damage points will subtract
health points of the other player. If health points of a player go below zero, the player
is dead. Display relative message, and show the Message:
“Winner By Knockout: {Player name}”
*/

class Player
{
private:
    string Name;
    int HealthPoints1;
    int damagePoints1;

    int HealthPoints2;
    int damagePoints2;
    bool isDead;

    int totalHit1;
    int totalHit2;

public:
    Player()
    {
        HealthPoints1 = 100;
        damagePoints1 = 0;

        HealthPoints2 = 100;
        damagePoints2 = 0;
    }

    void player1(string playName1)
    {
        cout << playName1 << " How many time you hit ? ";
        cin >> totalHit1;

        for (int i = 0; i < totalHit1; i++)
        {

            damagePoints1 = damagePoints1 + 5;
            if (HealthPoints1 != 0)
            {
                HealthPoints1 = HealthPoints1 - 5;
            }
        }
    }
    void player2(string playName2)
    {
        cout << playName2 << " How many time you hit ? ";
        cin >> totalHit2;

        for (int i = 0; i < totalHit2; i++)
        {
            damagePoints2 += 5;
            if (HealthPoints2 != 0)
            {
                HealthPoints2 -= 5;
            }
        }
    }

    void displayResult(string playName1, string playName2)
    {
        if (damagePoints1 < damagePoints2 || HealthPoints1 > HealthPoints2)
        {
            cout << "Winner By Knockout : " << playName1;
        }
        else if (damagePoints1 > damagePoints2 || HealthPoints1 < HealthPoints2)
        {
            cout << "Winner By Knockout : " << playName2;
        }
        else
        {
            cout << "Both have same Score";
        }
    }
};

int main()
{
    cout << "\n ---- Welcome to TEKKEN ----" << endl;
    string playName1;
    string playName2;

    cout << "Enter name of 1st player: ";
    getline(cin, playName1);
    cout << "Enter name of 2nd player: ";
    getline(cin, playName2);

    cout << "----- New Battle: " << playName1 << " vs " << playName2 << "-----" << endl;

    Player game;
    game.player1(playName1);
    game.player1(playName2);
    game.displayResult(playName1, playName2);
}