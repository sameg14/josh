#include<iostream>
using namespace std;

int main(){
  int x=0;
  int y=0;

  bool flag=true;

  if (flag)
    cout << "flag is true.\n";
  else
    cout << "flag is false.\n";

  cout << "Input x: ";		//input varable
  cin >> x;

  cout << "Input y: ";		//input varable 
  cin >> y;

  if (x>y){
    cout << x << " is greater than " << y << endl;
    cout << "bye!\n";
  }
  else if (x<y){
    cout << x << " is less than " << y << endl;
    cout << "bye!\n";
  }
  else if (x==y){
    cout << x << " is equal to " << y << endl;
    cout << "bye!\n";
  }
  else{
    cout << "wow, something is weird!!\n";
    cout << "bye!\n";
  }

  return 1;
}
