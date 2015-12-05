#include <iostream>
#include <cstdlib>
#include <cmath>
#include<sstream> //convert data types in getline

using namespace std;


/*  //////////// Prints message /////////////
void printmessage(){
	cout << " what!!!! " << endl;
}

int main(){

	printmessage();
}
*/

/* ///// Function duplicate multiplies x, y and z by 2 /////////
void duplicate (int& a, int& b, int& c)
{
  a*=2;
  b*=2;
  c*=2;
}

int main ()
{
  int x=1, y=3, z=7;
  duplicate (x, y, z);
  cout << "x=" << x << ", y=" << y << ", z=" << z;
  return 0;
}


