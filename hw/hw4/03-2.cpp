//Due Oct 13,2015
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream> //convert data types in getline
#include <vector>
using namespace std;

void display(int* d, int sz){
	for(int i=0; i<sz; i++){
		cout<<d[i]<<"  ";
	}
	cout<<endl;
}

int* insert(int* d, int val,int* sz, int cap, int before){
	int position=0;
//	int* temp=new int[*sz+1];
	for(int i=0; i<*sz; i++)
		if(before==d[i]){
			position=i;
		}
	for(int i=0; i<*sz; i++){
		d[*sz]=d[position+1];
	}
	
	d[position+1]=val;
	*sz=*sz+1;
	delete [] d;
	return d;
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
	d=insert(d, 6, &size, 10, 3);
	display(d,size);

	return 0;
}
