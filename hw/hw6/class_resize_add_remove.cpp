#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream> //convert data types in getline
#include <vector>
using namespace std;
//(10 points) Look at the List code implementation based on dynamic array      (lecture 17). Implement two
//resize class functions much like that of a vector:
//http://www.cplusplus.com/reference/vector/vector/resize/
//The signatures are:
//void resize(int n); /* n is the new list size, expressed in number of elements.*/
//void resize(int n, int val); /* n is the new list size, expressed in number of //elements. Also, val is copied to
//the new slots added, in case that n is greater than the current list size.*/
//These 2 functions should resize the list so that it contains n elements.
//If n is smaller than the current list size, the content is reduced to its first n elements, removing those
//beyond (and de-allocating them).
//If n is greater than the current list size, the content is expanded by inserting at the end as many
//elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of
//val, otherwise, they are initialized to 0.
//If n is also greater than the current list capacity, an automatic reallocation of the allocated storage space
//takes place.
//Notice that these functions may change the actual content of the list by inserting or erasing elements
//from it.
/*
MyList::resize(int n)
MyList::resize(int n, int val)
1. n = new list size expresed in number of elements
2. val copied to new slots, in case n is greater than current list size
3. functions resize list so n elements are contained
4. n < current list size, content reduced to its first n elements, de_allocating them
5. n > current list size, content expanded adding elements of val to end to  	reach size n, otherwise val = 0
6. n > current list capacity, reallocation of allocated storage space takes place
*/
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
  for (int i=0;i<6;i++){
    if(l1.add(i))
      cout << "Successfully added: " << i << endl;
    else
      cout << "Cannot add: " << i << endl;
  }
  
  l1.display();
  l1.resize(10);
  l1.display();
 /* 
  l1.resize(10,100); // Change this argument to test
  
  l1.display();

  l1.resize(12); // Change this argument to test
  l1.display();
 */ 
}



































