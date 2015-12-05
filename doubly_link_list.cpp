#include<iostream>
using namespace std;

class Node{
  private:
    int val;
    Node* prev;
    Node* next;

  public:
    Node(int);
    int get_val();
    bool set_val(int);

    bool set_next(Node*);
    Node* get_next();

    bool set_prev(Node*);
    Node* get_prev();
};

Node::Node(int v){
  val=v;
  prev=NULL;
  next=NULL;
}

int Node::get_val(){
  return val;
}

bool Node::set_val(int v){
  val=v;
  return true;
}

bool Node::set_next(Node* n){
  next=n;
  return true;
}

bool Node::set_prev(Node* n){
  prev=n;
  return true;
}

Node* Node::get_next(){
  return next;
}

Node* Node::get_prev(){
  return prev;
}

class MyList{
  private:
    Node* begin;

  public:
    MyList();
    ~MyList();
    bool add(int);
    void display() const;
    void operator=(const MyList&);
};

void MyList::operator=(const MyList& other){
  if (this==&other)
    return;
  Node* curr = begin;
  while(curr!=NULL){
    Node* temp = curr->get_next();
    delete curr;
    curr=temp;
  }
  cout << "I'm out of cleaning up!\n";

  curr=other.begin;
  if (curr==NULL){
    begin=NULL;
    return;
  }

  cout<<"Curr is not null\n";

  while(curr!=NULL){
    int v=curr->get_val();
    cout << "Adding: " << v << endl;
    add(v);
    cout << "Added\n";
    curr=curr->get_next();
  }
  return;
}

MyList::MyList(){
  begin=NULL;
}

bool MyList::add(int v){
  Node* temp=new Node(v);
  if (temp==NULL)
    return false;
  if(begin==NULL){
    begin=temp;
    return true;
  }

  Node* curr=begin;
  while(curr->get_next()!=NULL)
    curr=curr->get_next();

  curr->set_next(temp);
  temp->set_prev(curr);
  return true;
}

void MyList::display() const{
  Node* temp=begin;

  while(temp!=NULL){
    cout << temp->get_val() << " ";
    temp=temp->get_next();
  }
  cout << endl;
}

MyList::~MyList(){
  Node* temp=begin;
  while(temp!=NULL){
    Node* save=temp->get_next();
    cout << "Deleting " << temp->get_val() << endl;
    delete temp;
    temp=save;
  }
}

int main(){
  MyList l1;

  for (int i=0;i<20;i++)
    l1.add(i);
  l1.display();

  MyList l2;
  for (int i=0;i<30;i++)
    l2.add(i);
  l2.display();

  l2=l1;
  l1.add(-100);
  l2.add(-200);

  l1.display();
  l2.display();
}

