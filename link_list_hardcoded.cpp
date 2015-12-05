#include<iostream>
using namespace std;

class Node{
  private:
    int val;
    Node* next;

  public:
    Node();
    Node(int);

    int get_val();
    bool set_val(int);

    Node* get_next();
    bool set_next(Node*);
    void display();
    ~Node();
};

void Node::display(){
  cout << "Address of node: " << this << endl;
  cout << "Val in node: " << get_val() << endl;
  cout << "Next in node: " << get_next() << endl;
  cout << "Size of a node is: " << sizeof(Node) << endl;
}


Node::Node(){
  val=0;
  next=NULL;
}

Node::Node(int v){
  val=v;
  next=NULL;
}

int Node::get_val(){
  return val;
}

bool Node::set_val(int v){
  val=v;
  return true;
}

Node* Node::get_next(){
  return next;
}

bool Node::set_next(Node* n){
  next=n;
  return true;
}

Node::~Node(){
}

int main(){
  Node n1(10);
  n1.display();

  Node n2(20);
  n2.display();

  n1.set_next(&n2);
  n1.display();

  Node* p;
  p=&n1;
  cout << p << endl;

  //cout << p.get_val() << endl;
  cout << (*p).get_val() << endl;
  cout << p->get_val() << endl;

  cout << p->get_next() << endl;

  Node* t;
  t=p->get_next();
  cout << t << endl;

  cout << t->get_val() << endl;
}

