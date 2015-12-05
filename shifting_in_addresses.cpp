#include<iostream>
using namespace std;

void increment_by_one(int*,int);

int main(){
  int a[10];
  for (int i=0;i<10;i++)
    a[i]=i*10;
  for (int i=0;i<10;i++)
    cout << a[i] << " ";
  cout << endl;
  increment_by_one(a,10);
  for (int i=0;i<10;i++)
    cout << a[i] << " ";
  cout << endl;
}

void increment_by_one(int*p, int sz){
  for (int i=0;i<sz;i++)
    *(p+i)=(*(p+i))+1;
}

