/*
Problem 3 (2 points). Suggested time: 10 minutes.
Implement a function bool is_fibonacci(int) which determines if the input number is a number in the Fibonacci sequence. The first two numbers in the Fibonacci sequence are 0 and 1 respectively. Subsequent numbers are calculated by adding the previous two numbers in the sequence. A partial sequence is: <0, 1, 1, 2, 3, 5, 8, 13, 21, ....> Demonstrate using a main function that it works for sample inputs.
*/


#include <iostream>
#include <cstdlib>
#include <cmath>
#include<sstream> //convert data types in getline

using namespace std;

bool is_fibonacci(int number_to_check, int two_previous_numbers, int previous_number){
	//bool number_in_fib=false;
		if(number_to_check == two_previous_numbers || number_to_check == previous_number){
		//number_in_fib=true;
		return true;
		}
		int fib_current_number = two_previous_numbers + previous_number;
		if(fib_current_number == number_to_check){
		//number_in_fib=true;
		return true;
		}
		else if(fib_current_number > number_to_check){
		//number_in_fib=false;
		return false;
		}
	//return number_in_fib;
	return is_fibonacci(number_to_check,previous_number,fib_current_number);
}

int main(){
	int b=0;
	cout << "Enter a number to see if it is in fibonacci sequence: ";
	cin >> b;

	bool out=is_fibonacci(b,0,1);
	if(out=1){
		cout << b << " is part of the fibonacci sequence! " << endl;
	}
	else{
		cout << b << "is not part of the fibonacci sequeance. " << endl;	
	}

return 0; 
}

