#include <iostream>
using namespace std;

int main(){
//	int a=1; float b; char c;bool d;
/*	cout<<sizeof(int)<<endl;
	cout<<sizeof(float)<<endl;
	cout<<sizeof(double)<<endl;
	cout<<sizeof(char)<<endl;
	cout<<sizeof(bool)<<endl;
*/
	//initialize a var
/*	b=0.1;
	cout<<"input c "<<endl;
	cin>>c;
	cout<<c<<endl;
*/
	//operators
/*	int a=3; int b=5;
	cout<<"a+b"<<a+b<<endl;
	cout<<"a-b"<<a-b<<endl;
	cout<<"a*b"<<a*b<<endl;
	cout<<"a/b"<<a/b<<endl;
	cout<<"a%b"<<a%b<<endl;
*/
	//condition statement
	//&& and; || or; ! not
/*	int a=3, b=5;
	if(!(a==5)){
		cout<<"a is true"<<endl;
	}
	else{
		cout<<"a is false"<<endl;
	}
*/
	//switch-case 
/*	char vara,var_b;
	vara = 'a';
	switch(vara){
		case 'a':
		cout<<"a"<<endl;
		break;
		case 'b':
		cout<<"b"<<endl;
		break;
		default:
		cout<<"else"<<endl; 
	}
*/
	//forloop and while loop
/*	for(int i=5;i<10;i=i+2)
		cout<<i<<" ";
*/
/*	int i=1;
	while(i<10){
		cout<<i<<endl;
		i=i+2;
	}
*/
	//print out all the prime number from 1-100
	int count;
	for(int i=1;i<=100;i++){
		count=0;
		for(int j=1; j<=i; j++){
			if(i%j==0){
				count++;
			}
		}
		if(count==2){
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;
}

