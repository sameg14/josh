#include<iostream>
using namespace std;

//Implement the function below.

bool is_fibonacci_array(int*,int);

//Param 1: pointer to the beginning of an array of integers
//Param 2: size of that array
//Returns: true, is every element in the input array is a Fibonacci number
		//(the order of the numbers in the array need not be ordered
		//as per the Fibonacci sequence)
	//false, otherwise

//A Fibonacci sequence is generated as follows.
//The first two numbers in the sequence are 0 and 1.
//The following numbers in the sequence are calculated by adding
//the previous two numbers in the sequence. Thus the third number in the
//sequence would be 1 (i.e., 0+1), the fourth being 2 (i.e., 1+1), the
//fifth being 3 (i.e., 1+2), and so on, giving the following sequence:
//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, etc.

int main(){
  int a[5]={317811,28657,75025,3,8};
  int b[3]={0,1,4};

  bool flag=is_fibonacci_array(a,5);

  //should print "Is a Fibonacci array."
  if (flag)
    cout << "Is a Fibonacci array.\n";
  else
    cout << "Is not a Fibonacci array.\n";

  flag=is_fibonacci_array(b,3);

  //should print "Is not a Fibonacci array."
  if (flag)
    cout << "Is a Fibonacci array.\n";
  else
    cout << "Is not a Fibonacci array.\n";
}

bool is_fibonacci_array(int* a,int size){
    for(int i=0;i<size;i++){
	 if ((a[i] == 0) || (a[i] == 1)) {
        	return true;
         }
    	 else {
         	return is_fibonacci_array(a[i-1]) + is_fibonacci_array(a[i-2]);
         }
    }
}








