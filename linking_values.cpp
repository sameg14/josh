#include<iostream>
using namespace std;

int main(){
  int x=10;
  cout << x << endl;

  //reference variables
  int& r=x;

  cout << r << endl;

  x=20;
  cout << x << endl;
  cout << r << endl;

  r=30;
  cout << x << endl;
  cout << r << endl;

  int y=2;
  r=y;
  cout << x << endl;
  cout << r << endl;
  r=45;
  cout << x << endl;
  cout << r << endl;

  int p=10;
  int q;
  q=p;
}
