#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void getTeams(vector<string>& teams, vector<string>& winners);
void Winner(const vector<string>& teams, const vector<string>& winners);

int main()
{
    vector<string> teams;
    vector<string> winners;

    getTeams(teams, winners);
    Winner(teams, winners);

    return 0;
}


void getTeams(vector<string>& teams, vector<string>& winners)
{
    string team, winner;
    ifstream inputfile;

    inputfile.open("Teams.txt");
    if (!inputfile)
    {
        cerr << "Failed to open Teams.txt file.\n";
        exit(1);
    }
    while (getline(inputfile, team))
    {
        teams.push_back(team);
    }
    inputfile.close();

    inputfile.open("Winners.txt");
    if (!inputfile)
    {
        cerr << "Failed to open Winners.txt file.\n";
        exit(1);
    }
    while (getline(inputfile, winner))
    {
        winners.push_back(winner);
    }
    inputfile.close();
}


void Winner(const vector<string>& teams, const vector<string>& winners)
{
    string choice;
    int Wins = 0;

    cout << "Here are the teams that have won the World Series:\n";
    for (const string& name : teams)
    {
        cout << name << endl;
    }

    cout << "\nPlease enter the name of the team you would like to know the number of wins for (or enter 'Q' to quit): " << endl;

    getline(cin, choice);

    while (choice != "Q" && choice != "q")
    {
        Wins = 0;

        for (const string& winner : winners)
        {
            if (choice == winner)
            {
                Wins++;
            }
        }

        cout << choice << " has won the World Series " << Wins << " times." << endl;

        cout << "\nEnter another team name, or 'Q' to quit: ";
        getline(cin, choice); 
    }

    cout << "Thank you for using the program." << endl;
    return;
}
