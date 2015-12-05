#include<iostream>
using namespace std;

void swap_v1(int*,int*);
void swap_v2(int&,int&);

int main(){
  int a=10;
  int b=20;
  swap_v1(&a,&b);
  cout << a << " " << b << endl;

  swap_v2(a,b);
  cout << a << " " << b << endl;
}

void swap_v2(int& ra, int& rb){
  int temp=ra;
  ra=rb;
  rb=temp;
}

void swap_v1(int* pa, int* pb){
  int temp=*pa;
  *pa=*pb;
  *pb=temp;
}
