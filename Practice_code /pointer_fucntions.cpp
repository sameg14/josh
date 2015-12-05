#include <iostream>
#include <cstdlib>
#include <cmath>
#include<sstream> //convert data types in getline
# include <stdio.h>
using namespace std;

int foo(int& b){
	b++;
}
int boo(int* p){
	(*p)=(*p)*20;
}	
int main(){
 	
	int a=10;
	foo(a);
	cout << a << endl;
	int b=20;
	boo(&b);
	cout << b << endl;
return 0;
}
