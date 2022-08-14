/* Lab 7 - NBA Stats
 Natalie Poist
 CWID # 20405106
 nataliepoist@gmail.com
 Analyze the NBA season data for 2021-22 and output data to file and screen
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#define MAX 100

using namespace std;

//function prototypes
int getData(ifstream& inFile, double winPercentage[], double threePoint[], double averageFreeThrows[], string teamNames[]);
void output(ofstream& fileOut, string teamNames[], double threePoint[], double averageFreeThrows[], double winPercentage[], int num);
void percentAbove(ofstream& fileOut, double winPercentage[], double userPercent, int teamCount, double threePoint[], double averageFreeThrows[], string teamNames[]);
int highestFreeThrows(string teamNames[], double averageFreeThrows[], int num);
void locWinPer(string teamNames[], double winPercentage[], int num, string userTeam);
void sortSelect(string teamNames[], double threePoint[], double averageFreeThrows[], double winPercentage[], int num);
void signature();

int main() {
    ifstream inFile;
    ofstream fileOut;
    double winPercentage[MAX];
    double threePoint[MAX];
    double averageFreeThrows[MAX];
    string teamNames[MAX];
    int teamCount; int locFreeThrows = -1;
    double userPercent;
    string userTeam;
    
    //reads in data and counts number of teams in league
    teamCount = getData(inFile, winPercentage, threePoint, averageFreeThrows, teamNames);
    
    //opens output file
    fileOut.open("Poist_Lab7.txt");
    
    if (fileOut.fail()) {
        cout << "File does not exist" << endl;
        exit (100);
    }
    
    //outputs formatted data from file to output file
    output(fileOut, teamNames, threePoint, averageFreeThrows, winPercentage, teamCount);
    
    //percent between 1-100 and outputs to file amount of teams with win percent > input value
    cout << "Please enter a value between 1 and 100: ";
    cin >> userPercent;
    if ((userPercent >= 1) && (userPercent <= 100)) {
        percentAbove(fileOut, winPercentage, userPercent, teamCount, threePoint, averageFreeThrows, teamNames);
    }
    
    //prints error message and exits if number is invalid
    else {
        cout << "Please enter a valid number." << endl;
        exit (100);
    }
    
    //finds subscript of team with highest number of average free throws and prints team name and free throw average to screen (ASSUME NO TIES)
    locFreeThrows = highestFreeThrows(teamNames, averageFreeThrows, teamCount);
    
    //ensures that the subscript was updated from initialized value
    if (locFreeThrows > -1) {
        cout << fixed << setprecision(1);
        cout << setw(25) << left << teamNames[locFreeThrows] << setw(10) << right << averageFreeThrows[locFreeThrows] << endl;
    }
    
    //finds the % of wins for the team picked by user
    cout << "Input name of team you would like to see win % of: ";
    
    //ignore allows for getline to work by skipping the new line from previous cin
    cin.ignore();
    getline(cin, userTeam);
    locWinPer(teamNames, winPercentage, teamCount, userTeam);
    
    //sorts values from highest to lowest three point percentage
    sortSelect(teamNames, threePoint, averageFreeThrows, winPercentage, teamCount);
    
    //outputs sorted data from file to output file
    output(fileOut, teamNames, threePoint, averageFreeThrows, winPercentage, teamCount);
    
    //prints signature
    signature();
    
    //closes files
    fileOut.close();
    inFile.close();
    
    return 0;
}
// end of main

int getData(ifstream& inFile, double winPercentage[], double threePoint[], double averageFreeThrows[], string teamNames[]) {
    /* Pre: inFile - reference to data file
     winPercentage - array of percentage of wins
     threePoint -array of percents of 3-point field goals
     averageFreeThrows - array of average number of free throws per game
     teamNames - array of names of the teams
     Post: count - actual number of teams
     Purpose: opens data file, stores values in arrays, counts number of teams in league
     */
    
    int count = 0;
    double tempArray[MAX];
    double totalGames;
    
    //opens the file
    inFile.open("NBA_Lab7.txt");
    
    if (inFile.fail()) {
        cout << "No such file" << endl;
        exit (100);
    }
    
    while (count < MAX && !inFile.eof()) {
        //inputs wins and losses and calculates the win percentage of each team
        inFile >> winPercentage[count] >> tempArray[count];
        totalGames = winPercentage[count] + tempArray[count];
        winPercentage[count] = (winPercentage[count] / totalGames) * 100;
        
        //inputs values of 3 point counts and free throws
        inFile >> threePoint[count] >> averageFreeThrows[count];
        
        //gets team names without leading while spaces
        char temp;
        inFile.get(temp);
        getline(inFile, teamNames[count]);
        
        string tempString = teamNames[count].substr(teamNames[count].length()-1, 1);
        
        if(tempString == "\n" || tempString == "\r")        {
            teamNames[count] = teamNames[count].erase(teamNames[count].length()-1);
        }
    
        //increment the count of number of teams in the league
        count++;
    }
    
    return count;
}
//end of getData

void percentAbove(ofstream& fileOut, double winPercentage[], double userPercent, int teamCount, double threePoint[], double averageFreeThrows[], string teamNames[]) {
    /* Pre: fileOut - reference to output file
     winPercentage[] - array of win percentage values
     userPercent - user input percent value
     teamCount - number of teams in the league
     threePoint -array of percents of 3-point field goals
     averageFreeThrows - array of average number of free throws per game
     teamNames[] - array of team names
     Post: nothing
     Purpose: find teams with a higher win percentage than user input and print team data
     */
    int i;
    int percentAbove = 0;
    
    //header
    fileOut << "Groups with percentage of wins above " << userPercent << endl;
    
    //iterates through array until a value greater than the user input is found
    for (i = 0; i < teamCount; i++) {
        if (winPercentage[i] > userPercent) {
            fileOut << fixed << setprecision(1);
            fileOut << setw(25) << left << teamNames[i] << setw(10) << right << threePoint[i] << setw(20) << right << averageFreeThrows[i] << setw(25) << right << winPercentage[i] << endl;
            percentAbove++;
        }
    }
    //if initilized check is not changed, print error message
    if (percentAbove == 0) {
        fileOut << "No group with percentage of wins above " << userPercent << endl;
    }
    
}
//end of percentAbove

int highestFreeThrows(string teamNames[], double averageFreeThrows[], int num) {
    /* Pre: teamNames[] - array of team names
     averageFreeThrows - array of average number of free throws per game
     num - number of teams
     Post: subscript - subscript of team with highest average free throw value
     Purpose: find the subscript of the team with the highest average free throw value
     */
    
    //initilizes subscript to reflect first value of array
    int subscript = 0;
    
    //checks if current free throw value is greater than that of existing largest seen value
    for (int i = 1; i < num + 1; i++) {
        if (averageFreeThrows[i] > averageFreeThrows [subscript]) {
            subscript = i;
        }
    }
    
    return subscript;
}
//end of highestFreeThrows

void locWinPer(string teamNames[], double winPercentage[], int num, string userTeam) {
    /* Pre: teamNames[] - array of team names
     winPercentage - array of percentage of wins
     num - number of teams
     userTeam - user input of team name to check
     Post: nothing
     Purpose: find the team that matches user input and print the win percentage
     */
    
    //initializes to ensure team is found from user input
    bool teamFound = false;
    
    //iterate over teams until team is found, then print win percentage
    for (int i = 0; i < num; i++) {
        if (userTeam == teamNames[i]) {
            cout << winPercentage[i] << endl;
            teamFound = true;
        }
    }
    
    //if no team found, print error
    if (teamFound == false) {
        cout << "No statistics for " << userTeam << " team." << endl;
    }
}
//end of locWinPer

void sortSelect(string teamNames[], double threePoint[], double averageFreeThrows[], double winPercentage[], int num) {
    /* Pre: teamNames[] - array of team names
     threePoint -array of percents of 3-point field goals
     averageFreeThrows - array of average number of free throws per game
     winPercentage - array of percentage of wins
     num - number of teams
     Post: nothing
     Purpose: sorts values from highest to lowest three point percentage
     */
    
    int walker;
    int largestIndex;
    double tempDouble;
    int current;
    string tempString;
    
    //determines highest value subscript
    for (current = 0; current < num - 1; current++) {
        largestIndex = current;
        for (walker = current + 1; walker < num; walker++) {
            if(threePoint[walker] > threePoint[largestIndex]) {
                largestIndex = walker;
            }
        }
    //swap positions
        tempDouble = threePoint[current];
        threePoint[current] = threePoint[largestIndex];
        threePoint[largestIndex] = tempDouble;
        
        tempDouble = averageFreeThrows[current];
        averageFreeThrows[current] = averageFreeThrows[largestIndex];
        averageFreeThrows[largestIndex] = tempDouble;
        
        tempString = teamNames[current];
        teamNames[current] = teamNames[largestIndex];
        teamNames[largestIndex] = tempString;
        
        tempDouble = winPercentage[current];
        winPercentage[current] = winPercentage[largestIndex];
        winPercentage[largestIndex] = tempDouble;
    }
}
//end of sortSelect

void output(ofstream& fileOut, string teamNames[], double threePoint[], double averageFreeThrows[], double winPercentage[], int num) {
    /* Pre: fileOut - reference to output file
     teamNames[] - array of team names
     threePoint -array of percents of 3-point field goals
     averageFreeThrows - array of average number of free throws per game
     winPercentage - array of percentage of wins
     num - number of teams
     Post: nothing
     Purpose: output all data in format to file
     */

    fileOut << setw(25) << left << "TEAM" << setw(20) << left << "% 3-pt field goals" << setw(30) << left << "avg free throws/game" << setw(20) << left << "% wins" << endl;
    for (int i = 0; i < num; i++) {
        fileOut << fixed << setprecision(1);
        fileOut << setw(25) << left << teamNames[i] << setw(10) << right << threePoint[i] << setw(20) << right << averageFreeThrows[i] << setw(25) << right << winPercentage[i] << endl;
    }
    
}
//end of output

void signature() {
    
    //prints signature, ID#, and email address
    cout << "Programmed By: Natalie Poist" << endl;
    cout << "CWID #20405106" << endl;
    cout << "npoistcollege@gmail.com" << endl;
    
    return;
}
