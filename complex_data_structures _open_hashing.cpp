#include<iostream>
#include<string>
using namespace std;

class Node{
  private:
    string val;
    Node* next;

  public:
    Node();
    Node(string);
    string get_val();
    bool set_val(string);
    Node* get_next();
    bool set_next(Node*);
};

class MyList{
  private:
    Node* begin;

  public:
    MyList();
    ~MyList();
    void cleanUp();
    bool add(string);
    bool remove(string);
    Node* get_begin() const;
    void display();
    bool swap(string);

};

Node* MyList::get_begin() const{
  return begin;
}

bool MyList::remove(string v){
  if (begin==NULL)
    return false;

  Node* curr;
  Node* prev;
  curr=begin;

  while(curr->get_val()!=v){
    prev=curr;
    curr=curr->get_next();
  }
  if (curr==NULL)
    return false;
  if (curr==begin){
    begin=curr->get_next();
    delete curr;
  }
  else{
    prev->set_next(curr->get_next());
    delete curr;
  }
  return true;
}

Node::Node(){
  val="";
  next=NULL;
}

Node::Node(string v){
  val=v;
  next=NULL;
}

string Node::get_val(){
  return val;
}

bool Node::set_val(string v){
  val=v;
  return true;
}

Node* Node::get_next(){
  return next;
}

bool Node::set_next(Node* n){
  next=n;
}

MyList::MyList(){
  cout << "Calling constructor to build a list.\n";
  begin=NULL;
}

bool MyList::add(string v){
  Node* temp = new Node(v);

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
  Node* temp=begin;

  while(temp!=NULL){
    cout << temp->get_val() << ", ";
    temp=temp->get_next();
  }
  cout << endl;
}

void MyList::cleanUp(){
  Node* temp=begin;
  cout << "Destroying a list.\n";
  if (temp==NULL)
    cout << "Nothing more to delete.\n";
  while(temp!=NULL){
    Node* save=temp->get_next();
    cout << "Deleting " << temp->get_val() << endl;
    delete temp;
    temp=save;
    if (temp==NULL)
      cout << "Nothing more to delete.\n";
  }
  begin=NULL;
}

MyList::~MyList(){
  cleanUp();
}

class OpenHash{
  private:
    static const int CAP=26;
    MyList a[CAP];
    int find_bucket(string);

  public:
    OpenHash();
    ~OpenHash();
    OpenHash(const OpenHash&);
    bool add(string);
    bool remove(string);
    void display();
    OpenHash& operator=(OpenHash&);
    friend ostream& operator<<(ostream&,OpenHash&);
};

OpenHash& OpenHash::operator=(OpenHash& that){
  if (this==&that)
    return *this;

  for (int i=0;i<CAP;i++)
    a[i].cleanUp();

  for (int i=0;i<CAP;i++){
    Node* curr=that.a[i].get_begin();
    while(curr!=NULL){
      a[i].add(curr->get_val());
      curr=curr->get_next();
    }
  }
}

OpenHash::OpenHash(const OpenHash& that){
  for (int i=0;i<CAP;i++){
    Node* curr=that.a[i].get_begin();
    while(curr!=NULL){
      a[i].add(curr->get_val());
      curr=curr->get_next();
    }
  }
}

OpenHash::OpenHash(){
  cout << "====================================\n";
  cout << "Creating an OpenHash object.\n";
  cout << "====================================\n";
}

OpenHash::~OpenHash(){
  cout << "====================================\n";
  cout << "Destroying an OpenHash object.\n";
  cout << "====================================\n";
}

int OpenHash::find_bucket(string str){
  int bucket=0;
  for (int i=0;i<str.length();i++)
    bucket=bucket+str[i];
  return bucket%CAP;
}

bool OpenHash::add(string str){
  int bucket=find_bucket(str);
  return a[bucket].add(str);
}

bool OpenHash::remove(string str){
  int bucket=find_bucket(str);
  return a[bucket].remove(str);
}

void OpenHash::display(){
  for (int i=0;i<CAP;i++){
    cout << "List " << i << ": ";
    a[i].display();
    cout << endl;
  }
}

ostream& operator<<(ostream& os, OpenHash& h);

int main(){
  OpenHash h1;
  h1.add("hello");
  h1.add("world");
  h1.add("foobar");
  h1.add("c++");
  h1.add("last day");
  h1.add("end");
  h1.add("hash is on the exam for sure!!");
  h1.add("all the world's a stage.");
  h1.add("mclaren f1");
  cout << "=================================\n";
  cout << "\nDisplaying h1.\n";
  cout << "=================================\n";
  h1.display();
  cout << "=================================\n";

  h1.remove("mclaren f1");
  h1.remove("all the world's a stage.");
  h1.add("ferrari 458");
  cout << "=================================\n";
  cout << "\nDisplaying h1.\n";
  cout << "=================================\n";
  h1.display();
  cout << "=================================\n";

  cout << "=================================\n";
  OpenHash h2(h1);
  cout << "\nDisplaying h2.\n";
  cout << "=================================\n";
  h2.display();
  cout << "=================================\n";

  h2.add("c++ and data structures");
  h1=h2;
  cout << "\nDisplaying h1.\n";
  cout << "=================================\n";
  cout << h1;
  cout << "=================================\n";
}

ostream& operator<<(ostream& os, OpenHash& h){
  h.display();
  return os;
}

