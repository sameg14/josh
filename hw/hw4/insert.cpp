//Due Oct 13,2015
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream> //convert data types in getline
#include <vector>
using namespace std;

/*
(4 points) A function bool insert(int* d, int* size, int* cap, int before, int val) that would insert ‘val’ after the value ‘before’ in the list. The function should update the size and capacity if needed. Returns false if ‘before’ was not found in the list, true otherwise.
*/
void display(int* d, int sz){
	for(int i=0; i<sz; i++){
		cout<<d[i]<<"  ";
	}
	cout<<endl;
}
//insert val after before 
int* insert(int* d, int val,int* sz, int cap, int before){
	int* temp=new int[*sz+1];

	for(int i=0; i<*sz; i++)
		temp[i]=d[i];
	for(int i=2; i<*sz; i++){
		temp[i+1]=d[i];
	}
	
	temp[*sz-2]=val;
	*sz=*sz+1;
	delete [] d;
	return temp;
}

int main(){
	int size=5;
	int* d=new int[size];
	for(int i=0; i<size; i++){
		d[i]=i;
	}

	cout<<"original array: ";
	display(d,size);
	cout<<"after inserting: ";
	//                     &cap
	d=insert(d, 6, &size, 10, 2);
	display(d,size);

	return 0;
}


