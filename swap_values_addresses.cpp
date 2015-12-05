#include<iostream>
using namespace std;

void swap_v0(int,int);
void swap_v1(int*,int*);

int main(){
  int a=10;
  int b=20;
  cout << "In main: ";
  cout << a << " " << b << endl;
//DOES NOT SWAP MAIN BUT swap_v0 STACK 
  swap_v0(a,b);   
  cout << "In main: ";
  cout << a << " " << b << endl;
//DOES SWAP MAIN USING A FUNCTION 
  swap_v1(&a,&b);
  cout << "In main: ";
  cout << a << " " << b << endl;
//  swap_v2(&a,&b);
//  cout << a << b << endl;
}

//void swap_v2(int* q1,int* q2){
  
//}

void swap_v0(int p, int q){
  int temp=p;
  p=q;
  q=temp;
  cout << "In swap_v0: ";
  cout << p << " " << q << endl;
  return;
}

void swap_v1(int* p1, int* p2){
  int temp=*p1;
  *p1=*p2;
  *p2=temp;
  return;
}
