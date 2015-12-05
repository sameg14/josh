#include <iostream>
#include <cstdlib>
#include <cmath>
#include<sstream> //convert data types in getline

using namespace std;

void swap_v0(int, int);
void swap_v0(int* p, int q){

	int temp = p;
	p=q;
	q= temp;
	cout << "in swap_v0: ";
	cout << p << " " << q << endl;
	return;


}

int main(){
	
	int a=10;
	int b=20;
	cout << a << " " << b << endl;
	swap_v0(a,b);
	cout << a << " " << b << endl;
	


return 0;
}

