#include<iostream>
#include<cmath>
using namespace std;

class Point{
  int x;
  int y;

  public:
    bool set(int,int);
    bool move_by(int,int);
    float distance_from_origin();
    int get_x();
    int get_y();
    void display();
};

bool Point::set(int xc, int yc){
  x=xc;
  y=yc;
}

bool Point::move_by(int dx, int dy){
  x+=dx;
  y+=dy;
}

float Point::distance_from_origin(){
  return sqrt(pow(x,2)+pow(y,2));
}

int Point::get_x(){
  return x;
}

int Point::get_y(){
  return y;
}

void Point::display(){
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
}

int main(){
  Point p1, p2;

  p1.set(10,20);
  p1.move_by(2,-3);
  p1.display();
  cout << "Distance from origin (p1): " << p1.distance_from_origin() << endl;

  p2.set(-1,-1);
  p2.display();
  cout << "Distance from origin (p2): " << p2.distance_from_origin() << endl;
}

