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
    void resize(int n); // prototype for designed class function
    void resize(int n, int val); // overloaded function
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

void MyList::resize(int n){ // new funtction
	if (n > cap){
		cap = n + 2;
		int* temp = new int[cap];
			for (int i = 0; i < cap; i++){
				temp[i] = a[i];
				}
			delete [] a;
			a = temp;
	}		
	if (n < size){
		size = n;
	}
	if (n > size){
		for(int i = size; i < n; i++){
			a[i] = 0;
			size++;
		}
	}
	if (n == size)
		cout << " Size is already equal to "<< n<<endl;
}
		
void MyList::resize(int n, int val){ // overloaded function
	if (n > cap){
		cap = n + 2;
		int* temp = new int[cap];
			for (int i = 0; i < cap; i++){
				temp[i] = a[i];
				}
			delete [] a;
			a = temp;
	}		
	if (n < size){
		size = n;
	}
	if (n > size){
		for(int i = size; i < n; i++){
			a[i] = val;
			size++;
		}
	}
	if (n == size)
		cout << " Size is already equal to "<< n<<endl;
}	
	

int main(){
  MyList l1;
  for (int i=0;i<5;i++){
    if(l1.add(i))
      cout << "Successfully added: " << i << endl;
    else
      cout << "Cannot add: " << i << endl;
  }
  
  l1.display();
  
  l1.resize(8,100); // Change this argument to test
  
  l1.display();

  l1.resize(12); // Change this argument to test
  l1.display();
  

  

}


		
	
