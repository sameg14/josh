/*
Problem 1 (2 points). Suggested time: 10 minutes.
Implement a function called add_array that takes two float arrays, their respective sizes, computes the sum of respective indices, and stores the result in the corresponding index of the second array, and returns true or false indicating success or failure. (Note that the function overwrites the content of the second array with the sum.) Using a main function, demonstrate that it works.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include<sstream> //convert data types in getline
using namespace std;

bool add_array(float array1[], int a1size, float array2[], int a2size){
	bool sucess=true;
	if (a1size!=a2size){
		sucess=false;	
	}
	else{
		for(int i=0;i<a1size;i++){
			array2[i]=array2[i]+array1[i];
		}
	}
	return sucess;
}

int main(){
	float a1[]={4,3,9};
	float a2[]={2,7,6};
	int a1size=3;
	int a2size=3;
	for(int b=0;b<a1size;b++){
		cout << "a1[" << b << "] = " << a1[b] << endl ;
		cout << "a2[" << b << "] = " << a2[b] << endl ;
	}	
	add_array(a1,a1size,a2,a2size);

		for(int b=0;b<a1size;b++){
		cout << "a1[" << b << "] = " << a1[b] << endl ;
		cout << "a2[" << b << "] = " << a2[b] << endl ;
	}
	return 0;
}
