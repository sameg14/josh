#include<iostream>
using namespace std;

bool add(int*,int*,int,int);
void display(int*,int);

int main(){
  int sz=10;			//size of the array
  int a[sz];			//array 
  int csz=0;			
  bool flag=false;
  int val=109;

  for (int i=0;i<10;i++){
    flag=add(a,&csz,sz,i);
    if (flag)
      cout << "Successfully added.\n";
    else
      cout << "Add unsuccessful.\n";
  }

  display(a,csz);
}
////add(points to begin of array, current size of array, capacity, value)
bool add(int* p, int* s, int cap, int v){ 
  if (*s==cap)
    return false;

  p[*s]=v;
  (*s)++;
  return true;
}

void display(int* p, int s){
  for (int i=0;i<s;i++)
    cout << p[i] << " ";
    cout << endl;
  return;
}
