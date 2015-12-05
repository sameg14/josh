#include<iostream>
using namespace std;

int main(){
  int x=-1;
  cout << "Input a value from 0-3: ";
  cin >> x;

  //if (x<0 && x>3)
  /*
  if (x<0 || x>3){
    cout << "Invalid input.\n";
    cout << "bye!\n";
    return 1;
  }
  */

  switch(x){
    case 1:
      cout << "You typed ONE.\n";
      break;

    case 2:
      cout << "You typed TWO.\n";
      break;

    case 3:
      cout << "You typed THREE.\n";
      break;

    default:
      cout << "Invalid input.\n";
  }
}
