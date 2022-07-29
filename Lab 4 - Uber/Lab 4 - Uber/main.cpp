/*Lab 4 - Uber
 Natalie Poist
 CWID #20405106
 npoistcollege@gmail.com
 Program that calculates the cost of an Uber ride based on time, distance, and type of uber.
 Prints the rider's name and total cost of ride
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//prototype
double totalFare(char uberType, double rideMinutes, double rideMiles, double surgeMult);
void output(string riderName, double totalFare);

int main() {
    //declare variables
    string riderName;
    double rideMinutes, rideMiles;
    char uberType, surgeTrip;
    double surgeMult, total;
    
    //recieve user input
    cout << "Enter Name: ";
    getline(cin, riderName);
    
    cout << "Enter time in minutes: ";
    cin >> rideMinutes;
    
    cout << "Enter distance: ";
    cin >> rideMiles;
    
    cout << "Enter 'X' for uberX or 'S' for SUV or 'L' for luxury: ";
    cin >> uberType;
    uberType = toupper(uberType);
    
    cout << "Enter 'Y' if surge or 'N' if not: ";
    cin >> surgeTrip;
    surgeTrip = toupper(surgeTrip);
    
    //if during a surge, user inputs the multiplier
    if (surgeTrip == 'Y') {
        cout << "Enter surge multiplier: ";
        cin >> surgeMult;
    }
    //sets the surge multiplier to 1 if not during surge
    else if (surgeTrip == 'N') {
        surgeMult = 1.00;
    }
    else {
        cout << "Error please enter Y or N to indicate if there is a surge." << endl;
        exit(1);
    }
    
    //calculating trip cost
    total = totalFare(uberType, rideMinutes, rideMiles, surgeMult);
    
    //printing rider information and cost
    output(riderName, total);
    
    return 0;
}


double totalFare(char uberType, double rideMinutes, double rideMiles, double surgeMult) {
    /* Pre: uberType - Type of uber: uberX, SUV, luxury
     rideMinutes - time of ride in minutes
     rideMiles - distance of ride in miles
     surgeMult - multiplier based on if surge or not (defaults to 1 if not specified by user)
     Post: Total cost of trip
     Purpose: Compute the total cost of the uber trip
    */
    
    //given values for uber prices and declare variables
    const double uberXBaseFare = 2.00;
    const double suvBaseFare = 15.00;
    const double luxuryBaseFare = 5.00;
    const double uberXMinuteFare = 0.22;
    const double suvMinuteFare = 0.90;
    const double luxuryMinuteFare = 0.50;
    const double uberXMileFare = 1.15;
    const double suvMileFare = 3.75;
    const double luxuryMileFare = 2.75;
    const double uberXMinFare = 6.55;
    const double suvMinFare = 25.00;
    const double luxuryMinFare = 10.55;
    double totalFare;
    
    //calculate total cost based on type of ride
    if (uberType == 'X') {
        totalFare = (uberXBaseFare * surgeMult) + (rideMinutes * uberXMinuteFare) + (rideMiles * uberXMileFare);
        //ensures that the cost of the ride is greater than the minimum fee
        if (totalFare >= uberXMinFare) {
            totalFare = totalFare;
        }
        else if (totalFare < uberXMinFare) {
            totalFare = uberXMinFare;
        }
    }
    
    else if (uberType == 'S') {
        totalFare = (suvBaseFare * surgeMult) + (rideMinutes * suvMinuteFare) + (rideMiles * suvMileFare);
        if (totalFare >= suvMinFare) {
            totalFare = totalFare;
        }
        else if (totalFare < suvMinFare) {
            totalFare = suvMinFare;
        }
    }
    
    else if (uberType == 'L') {
        totalFare = (luxuryBaseFare * surgeMult) + (rideMinutes * luxuryMinuteFare) + (rideMiles * luxuryMileFare);
        if (totalFare >= luxuryMinFare) {
            totalFare = totalFare;
        }
        else if (totalFare < luxuryMinFare) {
            totalFare = luxuryMinFare;
        }
    }
    else {
        cout << "Error, please enter a valid Uber Type." << endl;
        exit(1);
    }
    
    //output of the function
    return totalFare;
}


void output(string riderName, double totalFare) {
    /* Pre: riderName - name of rider
     totalFare - calculated fare based on uber type and trip length/distance
     Post: nothing
     Purpose: print the total fare for the ride as well as the rider's name*/
    
    cout << "\n"; //prints a new line
    cout << "Rider Name: " << riderName << endl;
    cout << fixed << setprecision(2) << "Ride Total: $" << totalFare << endl;
    
    //signature
    cout << "Programmed By: Natalie Poist" << endl;
    
    return;
}

/* Execution Results
 1.
 Enter Name: Mary Pape
 Enter time in minutes: 70
 Enter distance: 55
 Enter 'X' for uberX or 'S' for SUV or 'L' for luxury: X
 Enter 'Y' if surge or 'N' if not: Y
 Enter surge multiplier: 1.9

 Rider Name: Mary Pape
 Ride Total: $82.45
 Programmed By: Natalie Poist
 
 2.
 Enter Name: Taylor Swift
 Enter time in minutes: 15
 Enter distance: 16.8
 Enter 'X' for uberX or 'S' for SUV or 'L' for luxury: L
 Enter 'Y' if surge or 'N' if not: N

 Rider Name: Taylor Swift
 Ride Total: $58.70
 Programmed By: Natalie Poist
 
 3.
 Enter Name: Jason Rider
 Enter time in minutes: 45
 Enter distance: 13.8
 Enter 'X' for uberX or 'S' for SUV or 'L' for luxury: C
 Enter 'Y' if surge or 'N' if not: N
 Error, please enter a valid Uber Type.
 */
