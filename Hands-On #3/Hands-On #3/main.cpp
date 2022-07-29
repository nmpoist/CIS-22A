/* Hands-On #3 - Tuition
 Natalie Poist
 CWID #20405106
 A program that calculates the costs of attending De Anza based on units taken in a quarter*/

#include <iostream>
#include <iomanip>
#include <string>

//defines cost per unit
#define UNIT_COST 31

using namespace std;

double calcTuition(double units, double studentFees);
void output(double Total);

//main function calling previously defined functions
int main() {
    //define variables
    double unitsTaken, studentFeesPaid, totalTuitionCalc;
    
    //prompt user for number of units taken
    cout << "Units taken this quarter: ";
    cin >> unitsTaken;
    
    //prompt user for amount of student fees paid
    cout << "Amount paid for student fees: ";
    cin >> studentFeesPaid;
    
    //calls the calcTuition function to calculate the tuition paid
    totalTuitionCalc = calcTuition(unitsTaken, studentFeesPaid);
    
    //calls output function to print statement of tuition paid and signature
    output(totalTuitionCalc);
}

//function calculating the total tuition paid based on user input of number of units and base student fees
double calcTuition(double units, double studentFees) {
    //define variables
    double tuitionTotal, unitTotal;
    
    //calculate cost of units taken and total tuition costs
    unitTotal = units * UNIT_COST;
    tuitionTotal = unitTotal + studentFees;
    
    //returns value of total tuition when called
    return tuitionTotal;
}

//void function returns no value, but outputs statements with calculated tuition and signature
void output(double Total) {
    
    cout << "Your total costs for attending De Anza College this quarter were: $" << Total << endl;
    cout << "Programmed By: Natalie Poist" << endl;
    cout << "CWID # 20405106" << endl;
    
    return;
}

/* Execution Results
 Units taken this quarter: 9.5
 Amount paid for student fees: 52.75
 Your total costs for attending De Anza College this quarter were: $347.25
 Programmed By: Natalie Poist
 CWID # 20405106
 */
