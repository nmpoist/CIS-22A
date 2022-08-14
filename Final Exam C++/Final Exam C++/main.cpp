/* Natalie Poist
 CIS 22A Final Exam (Summer 2022)
 */

#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

//prototype
void range(int arr[], int num);


int main() {
    int arr[] = {-27, 0, 5, 12, 121, -50, 6, 120, 11110, 100};
    int num = 10;
    range(arr, num);
    
    return 0;
}

void range(int arr[], int num){
    /* Pre: arr[] - one dimensional array of integers
     num - integer representing the actual number of elements in the array
     Post: nothing
     Purpose: replace all negative array values with 0, and all array values > 100 with 100
     */
    
    for (int i = 0; i < num; i++) {
        if (arr[i] < 0) {
            arr[i] = 0;
        }
        else if (arr[i] > 100) {
            arr[i] = 100;
        }
    }
}

/* prototype
void calcEfficiency(ifstream& fpln);

int main() {
    
    ifstream fpln;
    
    fpln.open("carpools.txt");
    
    if (fpln.fail()) {
        cout << "No such file" << endl;
        exit (100);
    }
    
    calcEfficiency(fpln);
    
    return 0;
}
void calcEfficiency(ifstream& fpln) {
     Pre: fpln - reference to input file
     Post: nothing
     Purpose: calculate the efficiency of the carpool, and if over 25.0, pint efficiency and money earned
    
    int people; double distance; double gallons;
    double efficiency;
    double money;
    
    cout << setw(20) << left << "Efficiency" << left << "Money" << endl;
    
    while (!fpln.eof()) {
        fpln >> people >> distance >> gallons;
        
        efficiency = (people * distance) / gallons;
        
        if (efficiency > 25.0) {
            cout << fixed << setprecision(1);
            cout << setw(19) << left << efficiency;
            money = distance * 0.08;
            cout << fixed << setprecision(2);
            cout << "$" << setw(6) << right << money << endl;
        }
    }
}
*/

/* //prototypes
 void getData(double& weight, double& height, double& age, char& sex);
 double calcBMR(double weight, double height, double age, char sex);

 int main() {
     // Local Declarations
     double weight, height, age;
     char sex;
     double valBMR;
              
     //Call function to input person's information
     getData(weight, height, age, sex);
     
     //Call function to calculate BMR
     valBMR = calcBMR(weight, height, age, sex);
     
     // Output
     cout << "BMR: " << valBMR << endl;
     
     return 0;
 }

 void getData(double& weight, double& height, double& age, char& sex) {
      Pre: weight - reference to weight
      height - reference to height
      age - reference to age
      sex - reference to sex
      Post: nothing
      Purpose: Get data input from user
      
     cout << "Enter person's weight: ";
     cin >> weight;
     
     cout << "Enter person's height in inches: ";
     cin >> height;
     
     cout << "Enter person's age: ";
     cin >> age;
     
     cout << "Enter person's sex (F/M): ";
     cin >> sex;
     sex = toupper(sex);
     if (sex != 'F' && sex != 'M') {
         cout << "Invalid Entry" << endl;
         exit (100);
     }
     
     return;
 }

 double calcBMR(double weight, double height, double age, char sex) {
      Pre: weight - weight
      height - height
      age - age
      sex - sex (F/M)
      Post: BMR - BMR of individual
      Purpose: Calculate the BMR of the person using user input data
      
     double BMR;
     
     if (sex == 'F') {
         BMR = 655 + (4.3 * weight) + (4.7 * height) + (4.7 * age);
     }
     else if (sex == 'M') {
         BMR = 66 + (6.3 * weight) + (12.9 * height) + (6.8 * age);
     }
     return BMR;
 }
*/

/* #25
 #define WEIGHT 62.42796
 double length, width, depth;
 double weight;
 
 cout << "Enter length (ft): ";
 cin >> length;
 
 cout << "Enter width (ft): ";
 cin >> width;
 
 cout << "Enter depth (ft): ";
 cin >> depth;
 
 weight = (length * width * depth) * WEIGHT;
 
 cout << fixed << setprecision(1);
 cout << "Weight: " << weight << " pounds" << endl;
*/

//Plug and run problems
//#4
//cout << "abc\ndef\tghi\njkl" << endl << endl << "mno\npqr\n";

/* #10
int a = 17;
int x;

x = a  %  3;
cout  << x << endl ;
*/

/* #16
double a = 7.8; double b = .2;  int x;

x = static_cast <int> (a - b + 0.5);
cout << x << endl;

if (a > b && b > 0) {
    if (a <= 10) {
        a = 14.2;
    }
     
   else {
       a = 10.5;
       b = 21.3;
       
   }
    cout << a << " " << b << endl;
}
 */

/* #17 & 18
int age;
float admission;

cout << "Enter the age " << endl;
cin >> age;
if (age < 7) {
  age = 0;
}
if (age >= 65) {
  age = 60;
}
switch (age)
{
case 0: admission = 0;
        break;
case 60: admission = 15;
default: admission = 40;
}

cout << admission << endl;
*/


/* #19
int i = 7;

while (i > 10) {
    cout << i;
    i += 3;
}
 */

/* #20
int i = 7;

while (i < 10) {
    cout << i;
    i += 3;
    
}
*/

/* #21
int arr[5] = {213, 258, 36};

cout << arr[1] + arr[2] << endl;

cout << arr[0 + 2] << endl;
 */

