#include<iostream>
#include<cmath>
using namespace std;//programming problem2--convert decimal to binary
int dectobinary(int x){
	int digit=0,result=0,remainder;
	int y=x;
	while(y!=0){
		y=y/2;
		digit++;
	}
	for(int i=0;i<digit;i++){
		remainder=x%2;
		x=x/2;
		result=remainder*pow(10,i)+result;
	}	

	return result;
}
int main(){
	int dec;
	cin>>dec;
	cout<<dectobinary(dec);
	return 0;
}

