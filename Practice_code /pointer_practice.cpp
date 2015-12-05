#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream> //convert data types in getline
#include <vector>
using namespace std;

// Declare Variables 
void swap(int* p, int* z){
	int temp = 0; 
	temp = *p;
	*p = *z;
	*z = temp;
	return; 	
}

int sum(int *c, int* d){
	int temp = 0; 
	temp = *c + *d; 
	return temp;
}

int sum_v1(int* x, int* y, int* o){	
	*o = *x + *y;
	return *o;
}
void all_sum(int* a, int* asz){
	
}
int main(){
	
	int a = 10; 
	int b = 20; 
	swap(&a,&b);
	cout << a << " " << b << endl;

	int newsum = 0; 
	newsum = sum(&a,&b);
	cout << newsum << endl;

	int sum = 0; 
	sum = sum_v1(&a, &b, &sum);
	cout << sum << endl;

	int f[5] = {1,1,1,1,1}

return 0;
}

