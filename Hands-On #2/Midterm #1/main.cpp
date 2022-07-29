#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    const double dollarPound = 0.841848;
    const double dollarEuro = 0.997815;
    const double dollarYen = 137.545;
    double userDollars, userYen, userEuros, userPounds;
    
    cout << "Enter amount in dollars: ";
    cin >> userDollars;
    
    userPounds = userDollars * dollarPound;
    userEuros = userDollars * dollarEuro;
    userYen = userDollars * dollarYen;
    
    
    cout << fixed << setprecision(2);
    cout << right << setw(15) << userDollars << " dollars" << endl;
    cout << right << setw(15) << userPounds << " pounds" << endl;
    cout << right << setw(15) << userEuros << " euros" << endl;
    cout << right << setw(15) << userYen << " yen" << endl;
    
    cout << "Programmed By: Natalie Poist" << endl;
    
    return 0;
}

/* Execution Results
 Enter amount in dollars: 123.45
          123.45 dollars
          103.93 pounds
          123.18 euros
        16979.93 yen
 Programmed By: Natalie Poist
 */
