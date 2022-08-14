//
//  main.cpp
//  Averaging Grades with Deviations
//
//  Created by Natalie Poist on 7/29/22.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//prototypes
int findHighest(double [], int);

int main(){
    //Declare variables
    int pin[45]; double score[45];  double avg; int index;
    string name[45];
    double sum = 0.0; int count = 0;
    
    //establish the file
    ifstream inFile;
    
    //open the file + check existence
    inFile.open("gradesWithNames.txt");
    if (inFile.fail()) {
        cout << "No such file" << endl;
        exit (100);
    }
    
    //Input each number and add it into the sum
    while(!inFile.eof()) { //when NOT the end of the file, executes
        getline(inFile, name[count]);
        inFile >> pin[count];
        inFile >> score[count];
        //cout << name[count] << " " << pin[count] << " " << score[count] << endl;
        sum = sum + score[count];
        count ++;
        inFile.ignore(); //Mac users sometimes have 2 \n at the end of the line
        inFile.ignore(); //ignore ignores the next character/space after what was taken in
    }
    
    
    //Calculate average
    avg = sum / static_cast<double>(count);
    
    
    //Output the average
    cout << "Average: " << avg << endl;
    for(int i = 0; i < count; i++) {
        cout << name[i] << "   " << pin[i] << "   " << score[i] << "   " << score[i] - avg << endl;
    }
    
    //finding the highest score
    index = findHighest(score, count);
    cout << "Highest score: " << score[index] << endl;
    
    
return 0;
}

int findHighest(double sc[], int num) {
    /* Pre: sc[] - array of scores
     num - number of values in the array
     Post: subscript of the highest value in the array (assume no ties)
     Purpose: find the highest value*/
    int highIndex = 0;
    
    for(int i=0; i < num; i++) {
        if(sc[highIndex] < sc[i]) {
            highIndex = i;
        }
    }
    
    return highIndex;
}
