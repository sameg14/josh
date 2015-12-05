#include<iostream>
#include<vector>
using namespace std;

class MyList{
  private:

    //initial value by which an array should be expanded
    static const int initial_expand_by=5;

    //initial capacity of the list, by default
    static const int initial_cap=10;

    //a pointer to store the address of where the array begins
    int* a;
    int* b; //create pointer for new array 
    int size;
    int inc;
    int cap;

    //a helper function to copy contents of the current array to
    //a new array of bigger capacity, and to deallocate the memory
    //of that current array.
    bool move();

  public:
    MyList();
    MyList(int);
    void display();
    bool add(int);
    bool remove(int);
    ~MyList();

    //implement the following functions:

    //returns true if v is present in the list, false otherwise.
    bool is_present(int v);

    /*
    Implement a function called void histogram() that prints
    the number of times the is_present function has been called for each
    value in the list. You may need to modify the class design/functions.
    */
    void histogram();

};

MyList::MyList(){
  size=0;
  inc=initial_expand_by;
  cap=initial_cap;
  a=new int[cap]; 
  b=new int[cap]; // create new array
}

MyList::MyList(int c){
  size=0;
  if (c<=0)
    cap=initial_cap;
  else
    cap=c;
  inc=initial_expand_by;
  a=new int[cap];
  b=new int[cap]; // expand array
}
      //~ deconstruct MyList
MyList::~MyList(){
  delete[] a;
  delete[] b; // deallocate memory 
}

bool MyList::add(int v){
  if (size==cap)
    move();
  b[size]=0; // set arrray b values to = 0
  a[size]=v;
  size++;
  return true;
}

bool MyList::move(){
  cout << "Moving...\n";
  cout << "Current cap: " << cap << endl;
  cout << "Target cap: " << cap+inc << endl;
  int* tempa = new int[cap+inc];
  int* tempb = new int[cap+inc]; // create new temp array with increased capacity
  for (int i=0;i<size;i++){
    tempa[i]=a[i];
    tempb[i]=b[i]; // set arrray to temp
  }
  delete[] a;
  delete[] b; // deallocate b 
  a=tempa;
  b=tempb; // copy tempb to b
  cap=cap+inc;
  inc=2*inc;
  cout << "Done moving.\n";
  return true;
}
/*
bool MyList::remove(int v){
  for (int i=0;i<size;i++)
    if (a[i]==v){
      a[i]=a[size-1];
      size--;
      return true;
    }
  return false;
}
*/
void MyList::display(){
  cout << "This list is of capacity: " << cap << endl;
  cout << "The current size is: " << size << endl;
  cout << "The content of this list is below: \n";
  for (int i=0;i<size;i++)
    cout << a[i] << " ";
  cout<<endl;
}

bool MyList::is_present(int v){
	for(int i=0 ; i<size; i++){
		if(v==a[i]){
			b[i]=b[i]+1;
			return true;
		}
	}
	return false;
}

void MyList::histogram(){
	for(int i=0; i<size; i++){
		cout << "The array of a: " << a[i] << endl;
		cout << "The number of times called: " << b[i] << endl;
	}
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

  for (int i=0;i<10;i++){
    l1.is_present(i);
    l1.is_present(i);
    l1.is_present(9);
  }
  l1.histogram();
  
}
