#include<iostream>
#include<vector>
using namespace std;

class MyList{
  private:
    //a pointer to store the address of where the array begins
    int* a;

    int size;
    int cap;
    int inc;
    bool move();

  public:
    MyList();
    MyList(int);
    void display();
    bool add(int);
    bool remove(int);
    ~MyList();
};

MyList::~MyList(){
  delete[] a;
}

MyList::MyList(){
  size=0;
  cap=2;
  inc=2;
  a=new int[cap];
}

MyList::MyList(int c){
  size=0;
  if (c<=0)
    cap=2;
  else
    cap=c;
  inc=2;
  a=new int[cap];
}

bool MyList::add(int v){
  if (size==cap)
    move();

  a[size]=v;
  size++;
  return true;
}

bool MyList::move(){
  cout << "Moving...\n";
  cout << "Current cap: " << cap << endl;
  cout << "Target cap: " << cap+inc << endl;
  int* temp = new int[cap+inc];
  for (int i=0;i<size;i++)
    temp[i]=a[i];
  delete[] a;
  a=temp;
  cap=cap+inc;
  inc=2*inc;
  cout << "Done moving.\n";
  return true;
}

bool MyList::remove(int v){
  for (int i=0;i<size;i++)
    if (a[i]==v){
      a[i]=a[size-1];
      size--;
      return true;
    }
  return false;
}

void MyList::display(){
  cout << "This list is of capacity: " << cap << endl;
  cout << "The current size is: " << size << endl;
  cout << "The content of this list is below: \n";
  for (int i=0;i<size;i++)
    cout << a[i] << " ";
  cout<<endl;
}

int main(){
  MyList l1;
  for (int i=0;i<20;i++){
    if(l1.add(i))
      cout << "Successfully added: " << i << endl;
    else
      cout << "Cannot add: " << i << endl;
  }
  l1.display();

  vector<int> v;
  vector<double> d;
  for (int i=0;i<20;i++){
    cout << v.capacity() << endl;
    v.push_back(i);
  }

  for (int i=0;i<v.size();i++)
    cout << v[i] << " ";
  cout << endl;

  MyList l2;
  l2=l1;
  l2.display();

}

