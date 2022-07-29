/* Natalie Poist
 Lab 2 - Mary's Bike
 Monthly Business Sales Tax Calc
 user inputs month, year, and amount
 program calculateds total of all stores and the amount of sales*/

#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

//Creates a preprocessor directive for given tax rate
#define TAX_RATE 0.0725 //preprocessor directive, must be all caps + use #define

int main()
{
    //Declares relevant variables and given county tax rate constant
    double totalLosAltos, totalCupertino, totalSunnyvale, totalCollected, totalSales;
    double countySalesTax, stateSalesTax, totalSalesTax;
    const double countyTaxRate = 0.01875; //sets this value to the variable as a constant w/ decimal places
    string monthYear;
    
    //Takes in Month, Year, and Totals of Each Store (Cupertino, Los Altos, and Sunnyvale)
    cout << "Enter Month and Year: "; //don't need endl bc i want user input to be on the same line
    getline(cin, monthYear); //getline allows for a string to be saved
    
    cout << "Enter Total Collected - Cupertino Store: ";
    cin >> totalCupertino;
    
    cout << "Enter Total Collected - Los Altos Store: ";
    cin >> totalLosAltos;
    
    cout << "Enter Total Collected - Sunnyvale Store: ";
    cin >> totalSunnyvale;
    
    //Calculates Total Collected from all 3 locations and the Total Sales once tax has been accounted for
    totalCollected = totalSunnyvale + totalLosAltos + totalCupertino; //sums each of the user input values
    totalSales = totalCollected / (1 + TAX_RATE + countyTaxRate);
    countySalesTax = countyTaxRate * totalSales;
    stateSalesTax = TAX_RATE * totalSales;
    totalSalesTax = countySalesTax + stateSalesTax;
    
    //Prints Month, Total Collected, Total Sales, and County, State, and Total Sales Tax to 2 decimal places
    cout << setprecision(2) << fixed; //every value from here after is shown to two decimal places
    cout << "Month: " << setw(10) << monthYear << endl; //setw sets the width of the varibale that comes NEXT //in this case monthYear
    cout << "Total Collected:   " << setw(10) << totalCollected << endl; //lining all of the spaces up allows user to skip using left and right align
    cout << "Total Sales:       " << setw(10) << totalSales << endl; //setw allows me to line up all the decimal points by ensuring that even values with more digits are aligned in the same size "box"
    cout << "County Sales Tax:  " << setw(10) << countySalesTax << endl;
    cout << "State Sales Tax:   " << setw(10) << stateSalesTax << endl;
    cout << "Total Sales Tax:   " << setw(10) << totalSalesTax << endl;
    
    //Prints Programmer Credits
    cout << "Programmed by Natalie Poist" << endl;
    
    return 0;
}

/* Execution Results
 Test Data: July 2022 and totals collected of 24,300 (Cupertino store), 34,876 (Los Altos),
 and 21,999 (Sunnyvale).
 
 Enter Month and Year: July 2022
 Enter Total Collected - Cupertino Store: 24300
 Enter Total Collected - Los Altos Store: 34876
 Enter Total Collected - Sunnyvale Store: 21999
 Month:  July 2022
 Total Collected:     81175.00
 Total Sales:         74387.17
 County Sales Tax:     1394.76
 State Sales Tax:      5393.07
 Total Sales Tax:      6787.83
 Programmed by Natalie Poist
 
 */
