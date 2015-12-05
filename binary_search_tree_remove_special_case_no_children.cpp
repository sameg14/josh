#include<iostream>
using namespace std;

class Node{
  private:
    int val;
    Node* left;
    Node* right;

  public:
    Node();
    Node(int);
    bool set_val(int);
    int get_val();
    bool set_left(Node*);
    Node* get_left();
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
    //helper methods for display
    void preorder(Node*);
    void inorder(Node*);
    void postorder(Node*);
    //helper method for destructor
    void cleanUp(Node*);
    //helper methods for remove
    Node* get_parent(int);
    Node* get_address(int);
    Node* get_largest(Node*);

  public:
    BST();
    ~BST();
    bool add(int);
    bool is_present(int);
    void display();
    bool remove(int);
};

bool BST::remove(int v){
  if (!is_present(v))
    return false;
  Node* curr=get_address(v);
  Node* parent=get_parent(v);

  if (curr->get_left()==NULL && curr->get_right()==NULL){
    if (curr==root){
      delete curr;
      root=NULL;
      return true;
    }
    if (curr->get_val()>parent->get_val()){
      parent->set_right(NULL);
      delete curr;
      return true;
    }
    else{
      parent->set_left(NULL);
      delete curr;
      return true;
    }
  }
}

Node* BST::get_largest(Node* n){
  Node* curr=root;
  while(curr->get_right()!=NULL)
    curr=curr->get_right();
  return curr;
}

Node* BST::get_address(int v){
  if (!is_present(v))
    return NULL;
  Node* curr=root;
  while(curr!=NULL){
    if (curr->get_val()>v)
      curr=curr->get_left();
    else if (curr->get_val()<v)
      curr=curr->get_right();
    else
      return curr;
  }
  return NULL;
}

Node* BST::get_parent(int v){
  if (!is_present(v))
    return NULL;

  Node* curr=root;
  if (v==curr->get_val())
    return NULL;

  Node* parent=curr;

  while(curr!=NULL){
    if (curr->get_val()>v){
      parent=curr;
      curr=curr->get_left();
    }
    else if (curr->get_val()<v){
      parent=curr;
      curr=curr->get_right();
    }
    else
      return parent;
  }
  return NULL;
}

BST::~BST(){
  cout << "Destructor invoked.\n";
  cleanUp(root);
}

void BST::cleanUp(Node* curr){
  if (curr==NULL) return;
  cleanUp(curr->get_left());
  cleanUp(curr->get_right());
  cout << "Deleting: " << curr->get_val() << endl;
  delete curr;
}

void BST::display(){
  //cout << get_largest(root)->get_val() << endl;
  cout << "Preorder traversal: ";
  preorder(root);
  cout << endl;
  cout << "Inorder traversal: ";
  inorder(root);
  cout << endl;
  cout << "Postorder traversal: ";
  postorder(root);
  cout << endl;
}

void BST::postorder(Node* curr){
  if (curr==NULL) return;
  postorder(curr->get_left());
  postorder(curr->get_right());
  cout << curr->get_val() << " ";
  //cout << get_address(curr->get_val())->get_val() << endl;
}

void BST::inorder(Node* curr){
  if (curr==NULL) return;
  inorder(curr->get_left());
  cout << curr->get_val() << " ";
  inorder(curr->get_right());
}

void BST::preorder(Node* curr){
  if (curr==NULL) return;
  cout << curr->get_val() << " ";
  /*
  if (get_parent(curr->get_val())!=NULL)
    cout << "Its parent: " << get_parent(curr->get_val())->get_val() << endl;
    */
  preorder(curr->get_left());
  preorder(curr->get_right());
}

BST::BST(){
  root=NULL;
}

bool BST::add(int v){
  Node* temp=new Node(v);
  if (root==NULL){
    root=temp;
    return true;
  }
  Node* curr=root;
  while(curr!=NULL){
    int x=curr->get_val();
    if(v==x){
      delete temp;
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

  cout<<"===================\n";
  b.display();
  cout<<"===================\n";
  b.remove(350);
  b.remove(450);
  b.remove(750);
  b.remove(825);
  b.remove(900);
  cout<<"===================\n";
  b.display();
  cout<<"===================\n";

  cout<<"===================\n";
  b.display();
  cout<<"===================\n";
  b.remove(850);
  b.remove(300);
  b.remove(400);
  b.remove(800);
  b.remove(500);
  cout<<"===================\n";
  b.display();
  cout<<"===================\n";
}

