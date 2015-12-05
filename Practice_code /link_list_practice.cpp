
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
	Node n1(100);
	Node n2(200);
	Node n3(300);
	n1.set_next(&n2);
	n2.set_next(&n3);
//	n3.set_next(&n1);
	n1.get_val();
	n2.get_val();
	n3.get_val();
	n1.display();
	n2.display();
	n3.display();
	Node* p;
	p=&n1; 
	cout << p->get_val() << endl;
	cout << p->get_next() << endl;
	cout << p->get_next()->get_next() << endl;
	cout << p->get_next()->get_next()->get_next() << endl;
	Node* getme;
	getme=p->get_next();
	cout << getme->get_val() << endl;
	Node* getmenext;
	getmenext=getme->get_next();
	cout << getmenext->get_val() << endl;


	



}

