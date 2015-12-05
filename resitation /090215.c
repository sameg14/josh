//cin-getline
//scope of variables
//functions

#include<iostream>
#include<sstream> //convert data types in getline()
using namespace std;
/*
int a=2, b=3;//global varibles

//bool odd(int a);
void swap(int a, int b){//swap(int& a, int& b)--pass by reference
	int temp;
	temp=a;
	a=b;
	b=temp;
}
 

*/
int main(){
/*	string a;
	cout<<"what is your name?"<<endl;
	cin>>a;
	cout<<a<<endl;
*/
/*	int a;
	cin>>a;
	cout<<"a= "<<a<<endl;
*/
	//getline
/*	string str;
	cout<<"what is your name?"<<endl;
	getline(cin,str);
	cout<<str<<endl;
*/
/*	string str;
	int quantity;
	float price;
	cout<<"input a price: "<<endl;
	getline(cin,str);
	stringstream(str)>>price;
	cout<<"price is "<<price<<endl;
	cout<<"input a quantity: "<<endl;
	getline(cin,str);
	stringstream(str)>>quantity;
	cout<<"quantity: "<<quantity<<endl;
	cout<<"total price: "<<quantity*price<<endl;
	return 0;
*/
	//scope of varibles:1.global 2.local
	//global:variable inherited from a level block;extern to declare a varible if share between .c files
	//local:variable declared with the block

/*	{
		b=1;
		//a is invisible
		{
			a=2;
			//b is visible
		}
	}
*/
	//functions:1. single return 2. no return: void 3. multiple returns--reference
	//cout<<odd(4)<<endl;
/*	swap(a,b);
	cout<<"a= "<<a<<" b= "<<b<<endl;// a and b donot swap, since c++ is passing by value
                                    // two ways to fix this:1. declare a and b as global varible
                                    //                     2. use reference
*/
}
/*bool odd(int a){//single return function
	if(a%2==0)
		return false;
	else
		return true;
}*/

//overload functions--same function but different argument lists
	int velocity(int vol){
		return vol;
	}
	int velocity(int dis,int time){
		return dis/time;
	}
	float velocity(float dis,float time){
		return dis/time;
	}
	float velocity(int dis,int time){

	}//error;cannot overload a function by different return type only
	//call overload function;
	velocity(1);//call the first function
	velocity(1,2);//call the second function
	velocity(2.1,3.4);//call the third function


