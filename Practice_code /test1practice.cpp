#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream> //convert data types in getline
# include <stdio.h>
#include <vector>
using namespace std;

bool print_x(int* a){
	while(!(cin>>*a)){
		cin.clear();
		cin.ignore(1000,'\n');
		return false;
	}
	 
		return true;

}	
	
main(){

 
	int a;
	int f; 
	cout << "enter a valid interger ";
	f=print_x(&a);
	if(f==1)
		cout << "you entered a valid int! ";
	
	else 
		cout << "you did not enter int! " ;
	
//	for(int i=0;i<5;i++){
//		cout << read_ints(a) << endl;
//	}




}
//	int* x;
//	for(int i=0;i<5;i++){
//		x=x+1;	
//	}
/*	cout << a << " " << b << endl;
	swap(&a,&b);	
	int* p1;
	int* p2;
	p2=&b;
	p1=&a;
	cout << p1 << " " << p2 << endl;
*/
//	cout << x << endl;
//	for(int i=0;i<5;i++){
//		x=x+1;
//		cout << *x << endl;
//	}
//	cout << x[1] << endl;
//	cout << a << " "  << b << endl;


//Param 1: array a
//Param 2: size of array a
//Param 3: array b#include<iostream>







//Param 4: size of array b
//Behavior:
  //Returns true: 
    //if every element in array a is present in array b and
    //every element in array b is present in array a. Order of the arrays does
    //not matter.
  //Return false: 
    //otherwise
 



/*
int readint(int* a){
	for(int i=0;i<5;i++){
		cin >> a[i];	 
		
	}
}
main(){
	int a[10];
	readint(a);
	for(int i=0;i<5;i++){
		cout << a[i] << endl;
	}
*/
/*
float ctof(float a){
	float f;
	f=a*(9/2)+32;
	return f;
}

main(){
	float a;
	cout << "enter centigrade: ";
	cin >> a;
	ctof(a);
	cout << "degrees in fahrenheit is " << ctof(a) << endl;
*/
/*
int fact(int n){
	if(n==1)
		return 1;
	else 
		return n*fact(n-1);

}
main(){
	int n;
	cout << "enter a factorial: ";
	while(!(cin>>n)){
		cout << "enter a n number: ";
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "input n ";
}
	cout << "n! is " << fact(n) << endl;
*/
/*
void CtoF(int& a){
	
	a=a+273;
	return;
}
main(){	
	int c=60;
	CtoF(c);
	cout << c << endl;
*/
//	for(int i=0; i<11;i++){
//	cout << pd[i] << endl;
//}
/*int swap(int* a, int* b){
	int* temp;
	a=temp;
	b=a;
	b=temp;	
}
	int c=10;
	int d=11;
	swap(c,d);
	cout << c << endl << d << endl;
*/
/*	int a=5;
	int *ip;

	*ip=a; 
	cout << a << endl << ip << endl;
*/	
//	int z=0;
//	z=plusone(2);
//	cout << *z << endl;

//	for (i=0; i<10;i++){
//	plusone(i)=plusone(i)+1;
//	}


/*	int a[10]={25};
	int b[9]={200};
	cout << *a << endl << *b << endl;	
*/
/*	int a=20;
	float b=20.31;
	long int c=25000000000;
	char d='A';
	string e="Hello \n";
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	cout << e << endl;
*/	
// return 0;
//}












