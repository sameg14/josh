#include<iostream>
#include<cmath>
using namespace std;

class Point{
  private:
    int x;
    int y;

  public:
    Point();
    Point(int,int);
    ~Point();
    bool set(int,int);
    bool move_by(int,int);
    float distance_from_origin();
    int get_x();
    int get_y();
    void display();
};

Point::Point(){
  cout << "\nConstructor invoked.\n";
  cout << "Initializing Point object using a default constructor.\n\n";
  x=0;
  y=0;
}

Point::Point(int xc, int yc){
  cout << "\nConstructor invoked.\n";
  cout << "Initializing Point object using a parameterized constructor.\n\n";
  x=xc;
  y=yc;
}

Point::~Point(){
  cout << "\nDestructor invoked.\n";
  cout << "Cleaning up...\n";
  cout << "Nothing to do.\n\n";
}

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
  cout << endl;
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  cout << "Distance from origin: " << distance_from_origin() << endl;
  cout << endl;
}

int main(){
  Point p1;
  Point p2(-1,-1);

  p1.set(10,20);
  p1.move_by(2,-3);
  p1.display();
  cout << "Distance from origin (p1): " << p1.distance_from_origin() << endl;

  p2.display();
  cout << "Distance from origin (p2): " << p2.distance_from_origin() << endl;
}

