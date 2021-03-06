//Due Oct 13,2015
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream> //convert data types in getline
#include <vector>
using namespace std;
/*
(2 points) A function bool increase_capacity_by(int* d, int size, int* cap, int inc_by) that would increase the capacity of the list by inc_by.
*/
void display(int* d, int sz){
	for(int i=0; i<sz; i++){
		cout<<d[i]<<"  ";
	}
	cout<<endl;
}
int* increase_capacity_by(int* d, int sz, int* cap, int inc_by){
	int* temp=new int[*cap+inc_by];   //cap+inc_by
	for(int i=0; i<sz; i++)
		temp[i]=d[i];
	delete []d;
	return temp;
}

int main(){
	int cap=5;
	int size=5;
	int* d=new int[size];
	for(int i=0; i<size; i++){
		d[i]=i;
	}
	cout<<"original array: ";
	display(d,size);
	cout<<"after increasing capacity: ";
	d=increase_capacity_by(d, 5, 5, &cap, 3);
	display(d,size);

return 0;
}
