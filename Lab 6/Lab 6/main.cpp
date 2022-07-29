/* Lab 6 - NBA Stats
 Natalie Poist
 CWID #20405106
 npoistcollege@gmail.com
 Analyze the win-loss statistics for NBA teams for 2021-22 and count the teams
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//prototype
void winPercentage(float wins, float losses, string teamName, float& winPercent);

int main() {
    int count = 0; //initializes count variable
    float wins, losses, winPercent;
    string teamName;
    
    ifstream fileIn ("NBA_Lab6.txt"); //opens the file
    
    //checks if the file exists and was found in the directory
    if (fileIn.fail()) {
        cout << "file does not exist" << endl;
        exit (100);
    }
    
    //Declare file pointer
    ofstream fileOut;
    
    fileOut.open("Poist_lab6.txt");
    
    if (fileOut.fail()) {
        cout << "file does not exist" << endl;
        exit (100);
    }
    
    fileOut << setw(10) << "TEAMS" << setw(31) << "% WINS" << endl;
    
    while(!fileIn.eof()) {
        fileIn >> wins;
        fileIn >> losses;
        getline (fileIn, teamName);
        
        string tempString = teamName.substr(teamName.length()-1, 1);
        
        if(tempString == "\n" || tempString == "\r")        {
             teamName = teamName.erase(teamName.length()-1);
        }
        
        teamName.erase(0,1); // removes the first character of the string (the extra tab)
        
        winPercentage(wins, losses, teamName, winPercent); //calls calculation function with file and count
        
        count ++;
        
        fileOut << setw(36) << left << teamName << fixed << setprecision(1) << winPercent << endl;
        
    }
    
    fileOut << "\n";
    fileOut << setw(27) << left << "TOTAL NUMBER OF TEAMS " << count << endl; //outputs count of teams in file
    
    //signature
    fileOut << "\n";
    fileOut << "Programmed By: Natalie Poist" << endl;
    fileOut << "Lab 6 - NBA Stats" << endl;
    fileOut << "npoistcollege@gmail.com" << endl;
    
    //Close output file
    fileOut.close();
    
    //closes the input file
    fileIn.close();
    
    
    return 0;
}

void winPercentage(float wins, float losses, string teamName, float& winPercent) {
    /* Pre: wins - number of wins from file input
     losses - number of losses from file input
     teamName - full name of team
     winPercent - reference to precentage of wins for the team
     Post: nothing
     Purpose: calculaute the percentage of wins for a team given number of wins and losses in a season
     */
    
    winPercent = (wins / (wins + losses)) * 100;
    
    return;
}


