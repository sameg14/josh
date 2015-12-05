#include<iostream>
using namespace std;

//(10 points) Implement the remove operation for a singly linked list discussed today in lecture 21.

class MyList{
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
  };

  private:
    Node* begin;

  public:
    MyList();
    ~MyList();
    bool add(int);
    bool remove(int);
    void display();
    bool insert_val_before(int before, int val);
};
bool MyList::insert_val_before(int before, int val){
    if(begin==NULL)
	return false; 
  Node* curr; 
  Node* prev;
  curr=begin;
  while(curr->get_val()!=val){
	if(curr==NULL)
		return false;
 	prev=curr;
	curr=curr->get_next();
  }
  Node* insertbox;
  insertbox=prev->set_next();
//  curr=insertbox->set_next();
//  insertbox->set_val(val);
}

bool MyList::remove(int v){
  if (begin==NULL)
    return false;

  Node* curr;
  Node* prev;

  curr=begin;
  
  while(curr->get_val()!=v){
    if (curr==NULL)
      return false;
    prev=curr;
    curr=curr->get_next();  
  }
  Node* remove_next_2;
  remove_next_2=curr->get_next();
  prev->set_next(remove_next_2->get_next());
  delete curr; 
  return true;
}


MyList::Node::Node(){
  val=0;
  next=NULL;
}

MyList::Node::Node(int v){
  val=v;
  next=NULL;
}

int MyList::Node::get_val(){
  return val;
}

bool MyList::Node::set_val(int v){
  val=v;
  return true;
}

MyList::Node* MyList::Node::get_next(){
  return next;
}

bool MyList::Node::set_next(MyList::Node* n){
  next=n;
}

MyList::MyList(){
  begin=NULL;
}

bool MyList::add(int v){
  MyList::Node* temp = new MyList::Node(v);

  if (begin==NULL){
    begin=temp;
    return true;
  }
  else{
    temp->set_next(begin);
    begin=temp;
    return true;
  }
}

void MyList::display(){
  MyList::Node* temp=begin;

  while(temp!=NULL){
    cout << temp->get_val() << " ";
    temp=temp->get_next();
  }
  cout << endl;
}

MyList::~MyList(){
  MyList::Node* temp=begin;
  while(temp!=NULL){
    Node* save=temp->get_next();
    cout << "Deleting " << temp->get_val() << endl;
    delete temp;
    temp=save;
  }
}

int main(){
  MyList l;
  for (int i=0;i<10;i++)
    l.add(i);
  l.remove(5);
  l.display();
}
