#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Functions Protoypes
double double_check();
double prod_num();

// Main
int main() {
double z = 0;
z = prod_num();
cout << "The product is "<<z<<endl;
 
return 0;
}

//Function Definitions
double double_check(){
string input = "";

 // How to get a double.
 double myNumber = 0;
 while (true) {
   cout << "Please enter a valid double: ";
   getline(cin, input);
   // This code converts from string to number safely.
   stringstream myStream(input);
   if (myStream >> myNumber)
     break;
   cout << "Invalid double, please try again" << endl;
 } 
 return myNumber;
 }
 
double prod_num(){
int doubnum = 0;
cout << "Please enter the number of doubles to multiply. "<<endl;
cin >> doubnum;

// Manually allocate the memory for the array
int *myArray;
myArray = new int[doubnum];
for (int i = 0; i < doubnum; i++){
myArray[i] = double_check();
}
double prod = 1;
for (int i = 0; i < doubnum; i++){
prod *= myArray[i];
}
// Remember to delete memory allocation
delete [] myArray;
return prod;

}


 

