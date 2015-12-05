#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream> //convert data types in getline
#include <vector>
using namespace std;


int main(){
	
	int* p;				// initializes pointer p
	int* z;				// initializes pointer z 
	p=new int;			
	*p=120;

	z= new int;
	*z=100;
	*z=*z+*p;
	cout << z << " " << *z << endl;	
//	delete p;
//	delete z; 
//	cout << *z <<  " " << *p << endl;
	*p=10;
	*z=*z+*p;
	cout << z << " " << *z << endl;

}	
