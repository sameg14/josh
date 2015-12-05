#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream> //convert data types in getline
#include <vector>
using namespace std;

class Point{
	private:
	  int x;
	  int y;

	public:
	  Point();
	  Point(int, int); 
	  void display();
	  void add(int c,int d);
	  void subtract(int e, int f);
};
Point::Point(){
	x=0;
	y=0;
}
Point::Point(int a, int b){
	x=a;
	y=b;
}
void Point::add(int c, int d){
	x+=c;
	y+=d;
}
void Point::subtract(int e, int f){
	x-=e;
	y-=f;
}
void Point::display(){
	cout << endl;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
}
int main(){
	int y;
	int z;
	Point p1;
	p1.display();
	cout << "Enter val for y: ";
	cin >> y;
	cout << "Enter val for z: ";
	cin >> z;
	Point p2(y, z);
	//p2.display();
	p2.add(2,3);
	p2.display();
	p2.subtract(3,5);
	p2.display();





}
