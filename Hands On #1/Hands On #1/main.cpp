/* Hands On #1
 Natalie Poist
 Correct the errors in the following program using 10 as test data
 Calculates the area of a circle given the radius
 */

#include <iostream>
using namespace std;

#define PI 3.141592

int main()
{
//Declare variables
double radius, area;
    
//Input the radius
cout << "Enter the radius: ";
cin >> radius;

//Compute the area
area = radius * radius * PI;

//Output the area
cout << "Area of Circle: " << area << endl;
cout << "Programmed By: Natalie Poist" << endl;
system("pause");
return 0;

}

/* Execution Results
 Enter the radius: 10
 Area of Circle: 314.159
 Programmed By: Natalie Poist */
