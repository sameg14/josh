#include<iostream>
using namespace std;

//Implement the function below that takes two arrays and their respective
//sizes and returns true if their contents are the same. The order of
//appearance of the elements in the two arrays does not matter.
bool is_equivalent(int*, int, int*, int);
bool is_present(int, int*, int);
//Param 1: array a
//Param 2: size of array a
//Param 3: array b
//Param 4: size of array b
//Behavior:
  //Returns true: 
    //if every element in array a is present in array b and
    //every element in array b is present in array a. Order of the arrays does
    //not matter.
  //Return false: 
    //otherwise
 
int main(){
  int a[10];
  int b[10];

  //assign some values to the 2 arrays
  int count=9;
  for (int i=0;i<10;i++){
    a[i]=i;
    b[i]=count;
    count--;
  }

  //the following would print:
  //0 1 2 3 4 5 6 7 8 9
  //9 8 7 6 5 4 3 2 1 0
  for (int i=0;i<10;i++)
    cout << a[i] << " ";
  cout << endl;
  for (int i=0;i<10;i++)
    cout << b[i] << " ";
  cout << endl;

  //compare the 2 arrays
  //the following should print "Equivalent."
  if (is_equivalent(a,10,b,10))
    cout << "Equivalent.\n";
  else
    cout << "Not equivalent.\n";

  a[4]=15;
  //the following should print "Not equivalent."
  if (is_equivalent(a,10,b,10))
    cout << "Equivalent.\n";
  else
    cout << "Not equivalent.\n";
}

bool is_equivalent(int* a,int asz,int* b,int bsz){
	if(asz!=bsz){
		return false;
	}		
	for(int i=0; i<asz; i++){
		if(!is_present(a[i],b,bsz)){
			return false;
		}	
	}
	return true;
}
bool is_present(int v, int* b, int sz){
	for(int i=0; i<sz;i++){
		if(v==b[i]){
			return true;
		}
	}
	return false;
}

