#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){

	int a=10;
	cout << "a: " << a << endl;
	int* p;
	cout << "p: " << p << endl;

	p=&a;
	cout << "p: " << p << endl;
	cout << "&a: " << &a << endl;

	cout << "*p: " << *p << endl;

	*p=20;

	cout << "a: " << a << endl;
	cout << "*p: " << *p << endl;

	a=30;
	cout << "a: " << a << endl;
	cout << "*p: " << *p << endl;

	*p = (*p)+1;
	cout << "a: " << p << endl;
	cout << "*p: " << &a << endl;

	p++;
	cout << "p: " << p << endl;
	cout << "*p: " << *p << endl;
	









return 0;
}
