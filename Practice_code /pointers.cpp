#include <iostream>
#include <cstdlib>
#include <cmath>
#include<sstream> //convert data types in getline

using namespace std;

// Declare Variables 

int main(){

	int a=10;
	int b=20;

	int*p;
	int*z;
	int*d;
	
	p=&a;
	//d=&b;
	z=p;
	cout << "the address of p: " << p << endl; 
	cout << "the value of address p: " << *p << endl; 
	cout << "the address of z is also p: " << z << endl; 
	cout << "the value of address z: " << *z << endl;
	cout << "the address of a: " << &a << endl;
	cout << "the address of b: " << &b << endl;
 	




//return 0;   // return not needed 
}
