#include<iostream>
using namespace std;

//Implement the function below that takes two arrays and their respective
//sizes and returns true if their contents are the same. The order of
//appearance of the elements in the two arrays does not matter.
bool is_equivalent(int* a, int asz, int* b, int bsz){
  if (asz!=bsz)
    return false;
  for (int i=0;i<asz;i++){
    if(!(is_present(a[i],b,bsz)))
      return false;
  }
  return true;
}
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
 
bool is_present(int av, int* b, int bsz){
  for (int i=0;i<bsz;i++){
    if (b[i]==av)
      return true;
  }
  return false;
}

int main(){
  int a[10];
  int b[10];

  int count=9;
  for (int i=0;i<10;i++){
    a[i]=i;
    b[i]=count;
    count--;
  }

  for (int i=0;i<10;i++)
    cout << a[i] << " ";
  cout << endl;
  for (int i=0;i<10;i++)
    cout << b[i] << " ";
  cout << endl;
  //the following should print equivalent
  if (is_equivalent(a,10,b,10))
    cout << "Equivalent.\n";
  else
    cout << "Not equivalent.\n";

  a[4]=15;
  //the following should print not equivalent
  if (is_equivalent(a,10,b,10))
    cout << "Equivalent.\n";
  else
    cout << "Not equivalent.\n";
}




