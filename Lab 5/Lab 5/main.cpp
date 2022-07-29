/* Lab 5 - Mortgage
 Natalie Poist
 npoistcollege@gmail.com
 CWID #20405106
 Calculates monthly cost of a house given the selling price, annual rate of interest, and number of years for the loan
 */

#include <iostream>
#include <iomanip>
#include <string.h>
#include <math.h>

using namespace std;

//definitions
#define PROPERTY_TAX_RATE 0.0125
#define INSURANCE 2750.00

//prototypes
void input(double& sellingPrice, double& interestRate, double& loanDuration);

void calcMonthlyCosts(double sellingPrice, double interestRate, double loanDuration, double& loanAmount, double& downPayment, double& yearlyTaxRate, double& total, double& monthlyTax, double& monthlyInsurance, double& mortgagePayment, double& durationTotal);

void calcDownLoanMortgage(double sellingPrice, double interestRate, double loanDuration, double& loanAmount, double& downPayment, double& yearlyTaxRate);

void output(double sellingPrice, double interestRate, double loanDuration, double loanAmount, double downPayment, double yearlyTaxRate, double total, double monthlyTax, double monthlyInsurance, double mortgagePayment, double durationTotal);

void signature();

int main() {
    
    double sellingPrice, interestRate, loanDuration, durationTotal;
    double loanAmount, downPayment, yearlyTaxRate, total, monthlyTax, monthlyInsurance, mortgagePayment;
    
    //calls input function to get user input on house values
    input (sellingPrice, interestRate, loanDuration);
    
    //calls calculation function
    calcMonthlyCosts(sellingPrice, interestRate, loanDuration, loanAmount, downPayment, yearlyTaxRate, total, monthlyTax, monthlyInsurance, mortgagePayment, durationTotal);
    
    //calls output to print values
    output(sellingPrice, interestRate, loanDuration, loanAmount, downPayment, yearlyTaxRate, total, monthlyTax, monthlyInsurance, mortgagePayment, durationTotal);
    
    //calls signature function to print programmer info
    signature();
    
    return 0;
}


//Takes in the user information to be used to calculate payment
void input(double& sellingPrice, double& interestRate, double& loanDuration) {
    /* Pre: sellingPrice - reference to price the house is sold at
     downPayment - reference to down payment placed for house
     loanAmount - refernce to amount of loan
     interestRate - reference to interest rate on loan
     loanDuration - reference to duration of loan in years
     Post: nothing
     Purpose: takes in user input for numerical values pertaining to house cost and charges */

    //user input prompts
    cout << "Selling price: ";
    cin >> sellingPrice;
    
    cout << "Interest rate: ";
    cin >> interestRate;
    
    cout << "Duration of loan: ";
    cin >> loanDuration;
}


void calcMonthlyCosts(double sellingPrice, double interestRate, double loanDuration, double& loanAmount, double& downPayment, double& yearlyTaxRate, double& total, double& monthlyTax, double& monthlyInsurance, double& mortgagePayment, double& durationTotal) {
    /* Pre: sellingPrice - user input price house was sold at
     interestRate - annual rate of interest
     loanDuration - duration of loan in years
     loanAmount - reference to loan amount
     downPayment - reference to down payment
     yearlyTaxRate - reference to yearly tax rate
     total - reference to total monthly payment
     monthlyTax - referece to monthly tax value
     monthlyInsurance - reference to monthly insurance payment value
     mortgagePayment - reference to monthly morthgage payment value
     durationTotal - reference to total loan payment over loan duration
     Post: nothing
     Purpose: calculates the monthly payments needed as well as monthly tax and insurance costs
     calls inner function to calculate loan, mortgage, and down payment
     */
    
    //declare local variables
    double monthPaymentTopCalc;
    double compoundingInterest, compoundingPeriods;
    
    //calculate monthly instances/rates
    monthlyInsurance = INSURANCE / 12;
    monthlyTax = (PROPERTY_TAX_RATE * sellingPrice) / 12;
    compoundingInterest = (interestRate / 100) / 12;
    compoundingPeriods = loanDuration * 12;
    
    //calls second function to calculate loan, mortgage, down payment
    calcDownLoanMortgage(sellingPrice, interestRate, loanDuration, loanAmount, downPayment, yearlyTaxRate);
    
    //calculates monthly mortgage payment
    monthPaymentTopCalc = (loanAmount * (compoundingInterest * (pow(1 + compoundingInterest, compoundingPeriods))));
    mortgagePayment = monthPaymentTopCalc / ((pow(1 + compoundingInterest, compoundingPeriods)) - 1);

    //calculates total payment (mortgage + insurance + property tax)
    total = mortgagePayment + monthlyTax + monthlyInsurance;
    
    //calulates payment total on loan over loan duration
    durationTotal = (mortgagePayment * 12) * loanDuration;
    return;
}

void calcDownLoanMortgage(double sellingPrice, double interestRate, double loanDuration, double& loanAmount, double& downPayment, double& yearlyTaxRate) {
    /* Pre: sellingPrice - user input price house was sold at
     interestRate - annual rate of interest
     loanDuration - duration of loan in years
     loanAmount - reference to amount of loan
     downPayment - reference to down payment amount
     yearlyTaxRate - reference to yearly tax rate
     Post: nothing
     Purpose: calculates down payment, loan amount, and mortgage amount of house
     */
    
    //declares non-global constant
    const double downPaymentPercent = 0.20;
    
    //calculates down payment, yearly tax rate, and loan amount
    downPayment = sellingPrice * downPaymentPercent;
    yearlyTaxRate = 0.0125 * sellingPrice;
    loanAmount = sellingPrice - downPayment;

    return;
}

void output(double sellingPrice, double interestRate, double loanDuration, double loanAmount, double downPayment, double yearlyTaxRate, double total, double monthlyTax, double monthlyInsurance, double mortgagePayment, double durationTotal) {
    /* Pre: sellingPrice - user input price house was sold at
     interestRate - annual rate of interest
     loanDuration - duration of loan in years
     loanAmount - loan amount
     downPayment - down payment
     yearlyTaxRate - yearly tax rate
     total - total monthly payment
     monthlyTax - monthly tax value
     monthlyInsurance - monthly insurance payment value
     mortgagePayment - monthly morthgage payment value
     durationTotal - total loan payment over loan duration
     Post: nothing
     Purpose: formats output correctly and prints
     */
    
    //formatted output of monthly cost values
    cout << "MONTHLY COST OF HOUSE" << endl;
    cout << fixed << setprecision(2);
    cout << setw(30) << left << "SELLING PRICE" << "$" << setw(12) << left << sellingPrice << endl;
    cout << setw(31) << left << "DOWN PAYMENT" << setw(12) << left << downPayment << endl;
    cout << setw(31) << left << "AMOUNT OF LOAN" << setw(12) << left << loanAmount << endl;
    cout << setw(35) << left << "INTEREST RATE" << setw(3) << left << interestRate << "%" << endl;
    cout << setw(35) << left << "TAX RATE" << setw(3) << left << PROPERTY_TAX_RATE << "%" << endl;
    cout << fixed << setprecision(0) << setw(38) << left << "DURATION OF LOAN (YEARS)" << setw(12) << left << loanDuration << endl;
    cout << "\n";
    
    //formatted output of monthly payment values
    cout << fixed << setprecision(2);
    cout << "MONTHLY PAYMENT" << endl;
    cout << setw(33) << left << "MORTGAGE" << setw(12) << left << mortgagePayment << endl;
    cout << setw(34) << left << "PROPERTY TAX" << setw(12) << left << monthlyTax << endl;
    cout << setw(34) << left << "INSURANCE" << setw(12) << left << monthlyInsurance << endl;
    cout << setw(40) << right << "--------" << endl;
    cout << setw(33) << right << "$" << setw(12) << left << total << endl;
    
    cout << setw(29) << left << "PAYMENT TOTAL ON LOAN" << setw(11) << right << durationTotal << endl;
    return;
}

void signature() {
    
    //prints signature, ID#, and email address
    cout << "Programmed By: Natalie Poist" << endl;
    cout << "CWID #20405106" << endl;
    cout << "npoistcollege@gmail.com" << endl;
    
    return;
}

/* Execution Results
 Test 1:
 Selling price: 700000
 Interest rate: 2.75
 Duration of loan: 30
 MONTHLY COST OF HOUSE
 SELLING PRICE                 $700000.00
 DOWN PAYMENT                   140000.00
 AMOUNT OF LOAN                 560000.00
 INTEREST RATE                      2.75%
 TAX RATE                           0.01%
 DURATION OF LOAN (YEARS)              30

 MONTHLY PAYMENT
 MORTGAGE                         2286.15
 PROPERTY TAX                      729.17
 INSURANCE                         229.17
                                 --------
                                 $3244.48
 PAYMENT TOTAL ON LOAN          823014.22
 Programmed By: Natalie Poist
 CWID #20405106
 npoistcollege@gmail.com
 Program ended with exit code: 0
 
 Selling price: 700000
 Interest rate: 6.734
 Duration of loan: 30
 MONTHLY COST OF HOUSE
 SELLING PRICE                 $700000.00
 DOWN PAYMENT                   140000.00
 AMOUNT OF LOAN                 560000.00
 INTEREST RATE                      6.73%
 TAX RATE                           0.01%
 DURATION OF LOAN (YEARS)              30

 MONTHLY PAYMENT
 MORTGAGE                         3626.20
 PROPERTY TAX                      729.17
 INSURANCE                         229.17
                                 --------
                                 $4584.53
 PAYMENT TOTAL ON LOAN         1305430.35
 Programmed By: Natalie Poist
 CWID #20405106
 npoistcollege@gmail.com
 Program ended with exit code: 0
 */
