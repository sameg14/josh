#include<iostream>
using namespace std;

int main(){
	int x=0;
	x=read_int();
	cout << x << endl;


int readInt(){
	int v=0;

	cout << "input valid interger: ";
	while(!(cin >> v)){
		cout << "invalid input!\n"
		cout << "input valid interger: ";
		cin.clear();
		cin.ignore(10000,"\n");
		cout <<"input a valid interger ";
}
return v;
/*
int main(){

	int x = 0; 
	float f = 0.0;
	cout << "input an non interger: " << endl;

while(!(cin >> x)){
	cout << "invalid input\n"; 
	cin.clear();  			// clear cin, Resest error state
	cin.ignore(10000,'\n');		// clear buffer 
	cout << "input an interger: ";
}	
	cout << "your interger is: ";

/*

	if (cin >> x){
	cout << "5 divided by " << x << "is: " (float)5/x << endl;
	cout << "bye\n";
	return 1;
}
else{
	cout << "invalid input\n";
	cout << " goodbye! "	
}
*/
return 1;
}
