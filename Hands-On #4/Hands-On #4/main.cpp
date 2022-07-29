/* Hands-On #4 - Need for Reference Variable
 Natalie Poist
 npoistcollege@gmail.com
 CWID #20405106
 Takes in the amount owed and calculates the discount
*/

#include <iostream>
#include <iomanip>
using namespace std;
#define DISC_RATE 0.1

//Function prototypes
void signature(void);
double calcDiscount(double&);

int main()
{
    // Declare variaables
    double amtOwing, discount;
    
    //Input amouont owed
    cout << "Enter amount owed: " ;
    cin >> amtOwing;
    
    //Calculate discount and update amount owing
    discount = calcDiscount(amtOwing);
    
    //Output discount and undated amount owed
    cout << setprecision(2) << fixed;
    cout << "Amount of Discount: " << discount << endl;
    cout << "Amount Owed: " << amtOwing << endl;
    
    signature();
    return 0;
}

//calculates discount and returns discounted owed value
double calcDiscount(double& owe)
{
    /*Pre: reference to owe
     Post: Amount of discount
     Purpose: calculate discount and update amount owed to reflect discount
     */
    
    double disc;
    disc = DISC_RATE * owe;
    
    //Update amount owed
    owe = owe - disc;
    
    return disc;
}

//signature function -- prints who it was programmed by
void signature()
{
    cout << "Programmed by: " << "Natalie Poist" << endl;
}

/* Execution Results
 Enter amount owed: 100.00
 Amount of Discount: 10.00
 Amount Owed: 90.00
 Programmed by: Natalie Poist
 */
