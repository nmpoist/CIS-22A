/*Using the products.txt file, write a function to input the
info into parallel arrays. Output the entire inventory to the screen.

· Add to this program a selection sort to output the products
  from the lowest to the highest. Output the result from main().

· Add a function that will output the quantity on hand and the
  price when given the product ID code.

· Add a function to output the product IDs and current number
  in stock for all products needing to be reordered.
*/

#include <iostream>
#include <fstream>
using namespace std;



#define MAX 50
//declare functions
int getData(ifstream& inFile, int id[], double price[], int qty[], int rop[]);
void output(int id[], double price[], int qty[], int rop[], int num);
int seqSearch(int arr[], int num, int target);
void sortSelect(double price[], int num, int id[], int qty[], int rop[]);

int main(void) {
    //Declare variables
    ifstream inFile;
    int id[MAX];
    double price[MAX];
    int qty[MAX];
    int rop[MAX];
    int number;
    int target, loc;
    
    //Open file
    inFile.open("products.txt");
    if (inFile.fail()) {
        cout << "No such file" << endl;
    }
    
    //Input the entire contents of the product file
    number = getData(inFile, id, price, qty, rop);
    
    //Output each product's id, quantity on hand, re-order point, and price
    output(id, price, qty, rop, number);
    
    //Looking for a particular product
    cout << "Enter the product number you are looking for: ";
    cin >> target;
    loc = seqSearch(id, number, target);
    if (loc == -1) {
        cout << "No such product" << endl;
    }
    else {
        cout << "Price: " << price[loc] << "\t" << "Quantity: " << qty[loc] << endl;
    }
    
    //Sort by the product id
    sortSelect(price, number, id, qty, rop);
    
    //Output each product's id, quantity on hand, re-order point, and price
    output(id, price, qty, rop, number);

    
    return 0;
}
///

int getData(ifstream& inFile, int id[], double price[], int qty[], int rop[]) {
    /* Pre: inFile - reference to data file
     id[] - array of product identification numbers
     price[] - array of cost for each product
     qty[] - array of number of product in warehouse
     rop[] - array of when to reorder that product
     Post: count - how many products
     Purpose: input the inventory from the data file
     */
    int count = 0;
    
    while (count < MAX && !inFile.eof()) {
        inFile >> id[count] >> price[count] >> qty[count] >> rop[count];
        //cout << id[count] << endl; //debug output statement
        count++;
    }
    
    return count;
}
///

int seqSearch(int arr[], int num, int target) {
    /* Pre: arr - array of values
     num - number of defined values
     target - what we are looking for
     Post: Location of what we are looking for, or -1 if not found
     Purpose: Find the location of a value
     */
    int loc = -1;
    
    for (int i = 0; i < num; i++) {
        if (target == arr[i]) {
            loc = i;
        }
    }
    
    return loc;
}
///

void sortSelect(double price[], int num, int id[], int qty[], int rop[]) {
    /* Pre: price[] - array of price values
     num - number of elements
     Post: nothing
     Purpose: sort the elements from low to high
     */
    int walker;
    int smallestIndex;
    double tempDouble;
    int tempInt;
    int current;
    
    for (current = 0; current < num - 1; current++) {
        smallestIndex = current;
        for (walker = current + 1; walker < num; walker++) {
            if(price[walker] < price[smallestIndex]) {
                smallestIndex = walker;
            }
        }
    //swap position
        tempDouble = price[current];
        price[current] = price[smallestIndex];
        price[smallestIndex] = tempDouble;
        
        tempInt = id[current];
        id[current] = id[smallestIndex];
        id[smallestIndex] = tempInt;
        
        tempInt = qty[current];
        qty[current] = qty[smallestIndex];
        qty[smallestIndex] = tempInt;
        
        tempInt = rop[current];
        rop[current] = rop[smallestIndex];
        rop[smallestIndex] = tempInt;
    }
}


void output(int id[], double price[], int qty[], int rop[], int num) {
    /* Pre: id[] - array of product identification numbers
     price[] - array of cost for each product
     qty[] - array of number of product in warehouse
     rop[] - array of when to reorder that product
     num - number of products in inventory
     Post: nothing
     Purpose: output the inventory to the screen
     */
    
    for (int i = 0; i < num; i++) {
        cout << id[i] << "\t" << price[i] << "\t" << qty[i] << "\t" << rop[i] << endl;
    }
    
}


