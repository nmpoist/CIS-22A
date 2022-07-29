/* Lab 3 - Audio Visual Equipment
 Natalie Poist
 npoistcollege@gmail.com
 Creates a customer bill for a company */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//define sunnyvale tax rate
#define TAX_RATE 0.0913

int main()
{
    //declare variables for user input
    int numTV, numTheatreSys, numRemoteCont, numDVR, numBlueRay, numProjector;
    
    //declare variables with values of items
    const double TV = 379.00;
    const double theatreSystem = 429.99;
    const double remoteController = 35.20;
    const double DVR = 149.98;
    const double blueRayPlayer = 248.00;
    const double projector = 1300.00;
    
    //declare subtotal of each item, total bill, tax, and  subtotal + tax variables
    double subTV, subTheatreSys, subRemoteCont, subDVR, subBlueRay, subProjector;
    double subtotal, tax, total;
    
    //take in user input on number of each item sold and store to int variables
    cout << "How many TVs were sold? ";
    cin >> numTV;
    
    cout << "How many Theatre System units were sold? ";
    cin >> numTheatreSys;
    
    cout << "How many Remote Controller units were sold? ";
    cin >> numRemoteCont;
    
    cout << "How many DVRs were sold? ";
    cin >> numDVR;
    
    cout << "How many Blue-Ray Disc Players were sold? ";
    cin >> numBlueRay;
    
    cout << "How many Projectors were sold? ";
    cin >> numProjector;
    
    //calculate the subtotal for each item
    subTV = numTV * TV;
    subTheatreSys = numTheatreSys * theatreSystem;
    subRemoteCont = numRemoteCont * remoteController;
    subDVR = numDVR * DVR;
    subBlueRay = numBlueRay * blueRayPlayer;
    subProjector = numProjector * projector;
    
    //calculate subtotal
    subtotal = subTV + subTheatreSys + subRemoteCont + subDVR + subBlueRay + subProjector;
    
    //calculate tax
    tax = TAX_RATE * subtotal;
    
    //calculate total
    total = subtotal + tax;
    
    //output to 2 decimal places organized such that decimal points align
    cout << setprecision(2) << fixed;
    cout << setw(7) << left << "QTY" << setw(19) << left << "Description" << setw(15) << right << "Unit Price" << setw(15) << right << "Total Price" << endl;
    
    cout << setw(7) << left << numTV << setw(19) << left << "TV" << setw(14) << right << TV << setw(15) << right << subTV << endl;
    
    cout << setw(7) << left << numTheatreSys << setw(19) << left << "THEATRE SYSTEM" << setw(14) << right << theatreSystem << setw(15) << right << subTheatreSys << endl;
    
    cout << setw(7) << left << numRemoteCont << setw(19) << left << "REMOTE CONTROLLER" << setw(14) << right << remoteController << setw(15) << right << subRemoteCont << endl;
    
    cout << setw(7) << left << numDVR << setw(19) << left << "DVR" << setw(14) << right << DVR << setw(15) << right << subDVR << endl;
    
    cout << setw(7) << left << numBlueRay << setw(19) << left << "Blu-Ray Disc Player" << setw(14) << right << blueRayPlayer << setw(15) << right << subBlueRay << endl;
    
    cout << setw(7) << left << numProjector << setw(19) << left << "PROJECTOR" << setw(14) << right << projector << setw(15) << right << subProjector << endl;
    
    cout << endl;
    
    //output subtotal, tax, and total
    cout << setw(40) << right << "SUBTOTAL" << setw(12) << right << subtotal << endl;
    cout << setw(40) << right << "TAX" << setw(12) << right << tax << endl;
    cout << setw(40) << right << "TOTAL" << setw(12) << right << total << endl;
    
    
    //signature
    cout << "Programmed by Natalie Poist" << endl;
    cout << "July 11, 2022" << endl;
    cout << "Lab 3 - Audio Visual Equipment" << endl;
    
    return 0;
}

/* Excution Results
 
 Test Data 1:
 How many TVs were sold? 13
 How many Theatre System units were sold? 2
 How many Remote Controller units were sold? 0
 How many DVRs were sold? 1
 How many Blue-Ray Disc Players were sold? 2
 How many Projectors were sold? 21
 QTY    Description             Unit Price    Total Price
 13     TV                         379.00        4927.00
 2      THEATRE SYSTEM             429.99         859.98
 0      REMOTE CONTROLLER           35.20           0.00
 1      DVR                        149.98         149.98
 2      Blu-Ray Disc Player        248.00         496.00
 21     PROJECTOR                 1300.00       27300.00

                                 SUBTOTAL    33732.96
                                      TAX     3079.82
                                    TOTAL    36812.78
 Programmed by Natalie Poist
 July 11, 2022
 Lab 3 - Audio Visual Equipment
 
 Test Data 2:
 How many TVs were sold? 100
 How many Theatre System units were sold? 5
 How many Remote Controller units were sold? 25
 How many DVRs were sold? 0
 How many Blue-Ray Disc Players were sold? 100
 How many Projectors were sold? 80
 QTY    Description             Unit Price    Total Price
 100    TV                         379.00       37900.00
 5      THEATRE SYSTEM             429.99        2149.95
 25     REMOTE CONTROLLER           35.20         880.00
 0      DVR                        149.98           0.00
 100    Blu-Ray Disc Player        248.00       24800.00
 80     PROJECTOR                 1300.00      104000.00

                                 SUBTOTAL   169729.95
                                      TAX    15496.34
                                    TOTAL   185226.29
 Programmed by Natalie Poist
 July 11, 2022
 Lab 3 - Audio Visual Equipment
 
 
 */
