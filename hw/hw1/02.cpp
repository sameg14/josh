/*
Problem 2 (5 points)

Write a function to read one valid double. Write another function that will compute the product of n numbers (where n is an input to the function), and return the product. Write a main function that uses the above 2 functions to read a few doubles and compute their product. Here is a the expected output:

Input 5 doubles:
1
2
3
4
5

use:  input1 input2
int funcx(int p,  int v){
Now must specify the returned input goes where

ex. 
int main(){
	int x=10;
	int y=20;
	int sum;
sum = compute_sum(x,y)         //now must store in file  
	cout << "your sum is: " << sum; 

	int a=12;
	int b=13;

int compute_sum(int a, int b);
	cout << 

double
product of n #, return product 



*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream>

using namespace std;

// Declare Variables 

double product(double a, double b){
	
	double r;
	r=a*b;
	return r;
	}

int main(){

	double a;
	double b;
	double k;
	double h;
	double z;

	string input = "";

 // How to get a number.
 int myNumber = 0;

 while (true) {
   cout << "Please enter a valid double: ";
   getline(cin, input);

   // This code converts from string to number safely.
   stringstream myStream(input);
   if (myStream >> myNumber)
     break;
   cout << "Invalid number, please try again" << endl;
 }
 cout << "Your double entered: " << myNumber << endl << endl;
/* ////WORKS BUT DOES NOT WORK IF LETTERS ARE TYPED WILL NOT///
   ////NEEDS TO KNOW IF LETTERS ARE TYPED, LOOK ABOVE//////////
	int z;
	cout << "enter two doubles to find product ";
	cin >> a;
	cin >>b;
	z=product(a,b);
	cout << "the result is " << z << endl;
*/

string str;
	int valueone;
	float valuetwo;
	cout<<"Input first number to multiply by: ";
	getline(cin,str);
	stringstream(str)>>valueone;			//enter valueone
	cout<<"Input second number to multiply by: ";
	getline(cin,str);
	stringstream(str)>>valuetwo;			//enter valuetwo
	z=product(valueone,valuetwo);
	cout<<"The multiplication of two numbers is: "<< z <<endl;

//////////////NOT USING A FUCTION SHOWN BELOW////////////////
//	cout<<"the multiplication of two numbers is: "<<valueone*valuetwo<<endl;
	return 0;

/* /////DOES NOT SEND GETLINE INTO product(a,b)///////////////	
	double z;
	string firstvalue;
	string secondvalue;
	cout << "Enter the first value to multiply by: ";
	getline(cin,firstvalue); 		//cin >> firstvalue works 
	//a=firstvalue;
	cout << "Enter the second value to multiply by: ";
	getline(cin,secondvalue);		//cin >> second value works
	//b=secondvalue;
	z=product(a,b);				//DIDNT cin>>first/secondvalue
	cout << a << b;
	cout << "The multiple value is " << z << endl;
*/

/*	
	int z;
	cout << "enter two doubles to find product ";
	cin >> a;
	cin >>b;
	z=product(a,b);
	cout << "the result is " << z << endl;
*/
return 0;
}


/*

///////////////////////getline///////////////////////////////
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

 string input = "";

 // How to get a string/sentence with spaces
 cout << "Please enter a valid sentence (with spaces):\n>";
 getline(cin, input);
 cout << "You entered: " << input << endl << endl;

 // How to get a number.
 int myNumber = 0;

 while (true) {
   cout << "Please enter a valid number: ";
   getline(cin, input);

   // This code converts from string to number safely.
   stringstream myStream(input);
   if (myStream >> myNumber)
     break;
   cout << "Invalid number, please try again" << endl;
 }
 cout << "You entered: " << myNumber << endl << endl;

 // How to get a single char.
 char myChar  = {0};

 while (true) {
   cout << "Please enter 1 char: ";
   getline(cin, input);

   if (input.length() == 1) {
     myChar = input[0];
     break;
   }

   cout << "Invalid character, please try again" << endl;
 }
 cout << "You entered: " << myChar << endl << endl;

 cout << "All done. And without using the >> operator" << endl;

 return 0;
}


*/




























