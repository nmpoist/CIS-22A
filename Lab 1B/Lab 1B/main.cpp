/*
 Natalie Poist
 Lab 1B - Change
 06/28/2022
 */

#include <iostream>

using namespace std; //shortens commands by adding std to the start of each line

int main() //creates the function
{
    //declare variables as doubles, so that each can have decimal point values
    int pennies, nickels, dimes, quarters;
    double dollars;
    
    //input the # of pennies, nickels, dimes, and quarters
    cout << "Enter number of pennies: "; //prints a prompt line
    cin >> pennies; //allows for user input and assigns input to variable
    
    cout << "Enter number of nickels: ";
    cin >> nickels;
    
    cout << "Enter number of dimes: ";
    cin >> dimes;
    
    cout << "Enter number of quarters: ";
    cin >> quarters;
    
    //calculate total dollars
    dollars = 0.01*(pennies) + 0.05*(nickels) + 0.10*(dimes) + 0.25*(quarters); //must use * sign or get an error
    //multiply eaach whole # values by decimal value and sum to find total dollars
    
    //output dollar amount
    cout << "Total Dollars in Change: $" << dollars << endl; //prints statement, dollar variable value, and a new line
    cout << "Lab 1B - Change" << endl;
    cout << "Programmed by Natalie Poist" << endl;

    
    return 0; //ensures the program ran successfully
}

/* Execution Results
 Enter number of pennies: 23
 Enter number of nickels: 5
 Enter number of dimes: 0
 Enter number of quarters: 3
 Total Dollars in Change: $1.23
 Lab 1B - Change
 Programmed by Natalie Poist
*/
