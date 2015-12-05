#include <iostream>
#include <cmath>
using namespace std;
//hw1-1
/*
int cal(int grain){
	int total=0;
	double sqr=0;
	int prev=1;
	while(sqr<=64 && total<grain){
		total=total+prev;
		prev=prev*2;
//		total=total+pow(2.0,sqr);
		sqr++;
		cout<<sqr<<"   "<<total<<endl;
	}
	return sqr;
}

int main(){
	int grains;
	cout<<"input grains "<<endl;
	cin>>grains;
	cal(grains);
	return 0;
}
*/
//hw1-2
/*
double read(){
	cout<<"input a double"<<endl;
	double x;
	while(!(cin>>x)){
		cout<<"not valid"<<endl;
		cin.clear();
		cin.ignore(10000,'\n');
		cout<<"input a double"<<endl;
	}
	return x;
}

double product(int n){
	double pro=1;
	double num;
	for(int i=0; i<n;i++){
		num=read();
		pro=pro*num;		
	}
	return pro;
}
int main(){
	int a;
	cout<<"how many?"<<endl;
	cin>>a;
	cout<<product(a)<<endl;
	return 0;
}

*/
