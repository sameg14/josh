//cin-getline
//scope of variables
//functions

#include <iostream>
#include <cstdlib>
#include <cmath>
#include<sstream> //convert data types in getline
using namespace std;


bool odd(int a){
	if(a%2==0)
		return false; 
	else
		return true;
}
	int velocity(int vol){
		return vol;
}
	int velocity(int dis, int time){
		return dis/time;
}  
	float velocity(float dis, float time){
		return dis/time;
}
	float velocity(int dis,int time){
		
	}

int main(){
/*	string a;
	cout<<"what is your name? "<<endl;
	cin>>a;
	cout<<a<<endl
*/
/*	int a;
	cin>>a;
	cout<<"a= "<<a<<endl;
*/
	//getline
/*	string str;
	cout<<"what is your name? "<<endl;
	getline(cin,str);
	cout << str << endl;
*/
/*	string str;
	int quainity;
	float price;
	cout<<"input a price: "<<endl;
	getline(cin,str);		//
	stringstream(str)>>price;
	cout<<"price is " << price<<endl;
	cout<<"input a quanity: "<<endl;
	getline(cin,str);
	stringstream(str)>>quanity;
	cout<<"quanity: " << quanitity<<endl;
	cout<< "total prince: "<<quantity*price<<endl;
*/
	//scope of cariables:1.global 2.local
	//global:cariable inderited from a higher level block; use extern to 		declare a variable if share between .c file	
	//local: variable declared with the block 

/*	{ 
	b=1;{
	//a is invisable 
		a=2;
		//b is visable 

	}

}
*/

	//Functions:  1.single return
	      	    //2.not return
		    //3.void       	
// bool odd(int a){
//	if(a%2==0)
//		return false; 
//	else
//		return true;
//}
/*
	cout << odd(2) <<endl;
*/
	//overload fuction -- same fuction but different argument lists



	//error; cannot overload a fuction by a different return type only
	// call overload function;
	cout<< velocity(1);//call the first function
	cout<< velocity(1,2);//call the second function 
	cout<< velocity(2.1,3.4);//call the third 


return 0;
}
