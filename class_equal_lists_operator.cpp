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
    void operator=(MyList&);
    bool operator==(MyList&);
    ~MyList();
};

MyList::MyList(){// constructor initializations 
  size=0;
  cap=2;
  inc=2;
  a=new int[cap];// cap starts at 2
}

MyList::MyList(int c){
  size=0;
  if (c<=0)     // while cap is 
    cap=2;
  else
    cap=c;
  inc=2;
  a=new int[cap];
}

MyList::~MyList(){
  delete[] a;
}

bool MyList::add(int v){
  if (size==cap)  		// increases cap to be larger than size
    move();

  a[size]=v;     		// set the size, size is smaller than cap 
  size++;
  return true;
}

bool MyList::move(){
  cout << "Moving...\n";
  cout << "Current cap: " << cap << endl;
  cout << "Target cap: " << cap+inc << endl;
  int* temp = new int[cap+inc]; // opens new temp array 
  for (int i=0;i<size;i++)
    temp[i]=a[i];		// sets original array to temp array 
  delete[] a;		
  a=temp;			// sets temp array to a[i] array 
  cap=cap+inc;
  inc=2*inc;     		//multiplied by 2 for next interval
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

void MyList::operator=(MyList& other){
  if (this==&other)
    return;
  size=other.size;
  cap=other.cap;
  inc=other.inc;
  delete[] a;
  a=new int[cap];
  for (int i=0;i<size;i++)
    a[i]=other.a[i];
}

bool MyList::operator==(MyList& other){
  if (cap!=other.cap || inc!=other.inc || size!=other.size)
    return false;

  for (int i=0;i<size;i++)
    if (a[i]!=other.a[i])
      return false;

  return true;
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

  MyList l2;
//  l2=l1;
 l2.operator=(l1);
  l2.display();

  if (l1==l2)
    cout << "Equal lists.\n";
  else
    cout << "Unequal lists.\n";

  l2.add(9);
  if (l1==l2)
    cout << "Equal lists.\n";
  else
    cout << "Unequal lists.\n";

}

