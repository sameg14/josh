#include<iostream>
using namespace std;

class Node{
  private:
    int val;
    DoublyLinkedInts taskIds;
    DoublyLinkedStrings taskNames;
    Node* left;
    Node* right;

  public:
    Node();
    Node(int);
    bool set_val(int);
    int get_val();
    bool set_left(Node*);
    Node* get_left();s
    bool set_right(Node*);
    Node* get_right();
};

Node::Node(){
  val=0;
  left=right=NULL;
}

Node::Node(int v){
  val=v;
  left=right=NULL;
}

bool Node::set_val(int v){
  val=v;
  return true;
}

int Node::get_val(){
  return val;
}

bool Node::set_left(Node* n){
  left=n;
  return true;
}

Node* Node::get_left(){
  return left;
}

bool Node::set_right(Node* n){
  right=n;
  return true;
}

Node* Node::get_right(){
  return right;
}

class BST{
  private:
    Node* root;

  public:
    BST();
    bool add(int);
    bool is_present(int);
};

BST::BST(){
  root=NULL;
}

bool BST::add(int v){//(int priority, int taskId, char* taskName){
  Node* temp=new Node(v);
  if (root==NULL){
    root=temp;
    root->add_task(taskId, taskName);
    return true;
  }
  Node* curr=root;
  while(curr!=NULL){
    int x=curr->get_val();
    //int curPriority = curr->get_priority();
    if(x==v){
    //if(priority==curPriority){
      delete temp;
      //curr->add_task(taskId, taskName);
      return false;
    }
    else if (v>x){
      if (curr->get_right()==NULL){
	curr->set_right(temp);
	return true;
      }
      else
	curr=curr->get_right();
    }
    else{
      if (curr->get_left()==NULL){
	curr->set_left(temp);
	return true;
      }
      else
	curr=curr->get_left();
    }
  }
}

bool BST::is_present(int v){
  Node* curr=root;
  if (curr==NULL)
    return false;

  while(curr!=NULL){
    if (curr->get_val()==v)
      return true;
    else if (curr->get_val() > v)
      curr=curr->get_left();
    else
      curr=curr->get_right();
  }
  return false;
}

int main(){
  BST b;
  b.add(500);
  b.add(800);
  b.add(750);
  b.add(850);
  b.add(825);
  b.add(900);

  b.add(400);
  b.add(300);
  b.add(450);
  b.add(350);

  cout << b.is_present(750) << endl;
  cout << b.is_present(825) << endl;
  cout << b.is_present(450) << endl;
  cout << b.is_present(1000) << endl;
}
ch 
