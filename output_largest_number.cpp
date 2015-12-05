//this program receives two integers as input
//from the user, and computes the largest, which
//is then displayed to the user.

#include<iostream>
using namespace std;

int main(){
  int a=0; //declare a memory big enough to hold an integer, call it a, 
  		//and store a value of 0 in it.

  int b=0; //declare a memory big enough to hold an integer, call it b, 
  		//and store a value of 0 in it.

  cout << "Input the first number: ";
  cin >> a; //wait until an enter key is pressed. when pressed,
  		//read all that has been typed in by the user
		//and store that in the memory cell referred
		//to as a.

  cout << "Input the second number: ";
  cin >> b; //wait until an enter key is pressed. when pressed,
  		//read all that has been typed in by the user
		//and store that in the memory cell referred
		//to as b.

  if (a>b){
    cout << a << " is bigger than " << b << endl;
    cout << "bye!\n";
  }
  else if (a<b){
    cout << a << " is lesser than " << b << endl;
    cout << "bye!\n";
  }
  else{ //then a and b are equal
    cout << a << " is equal to " << b << endl;
    cout << "bye!";
  }
  return 1;
}
