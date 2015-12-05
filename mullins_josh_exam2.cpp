#include<iostream>
#include<vector>
using namespace std;

class MyList{
  private:
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

    //Implement the following functions:

    //1. (10 points) This function removes every element present in the
    //"other" list object from the list object on which this function is
    //invoked.
    void operator-(MyList& other);
void MyList::operator-(MyList& other){
}

    //2. (15 points) This function finds the intersection of the values
    //between the list object on which this function is invoked and the
    //"other" list object. For example, if "this" list contains
    //{20,30,1,20} and the "other" list contains {45,43,1,3,20,20,65,987},
    //then the intersection is {20,1}. Note that this array is free of
    //duplicates.  
    //
    //Output: The function returns a pointer to an array containing the
    //elements of the intersection as output. The memory for this array is
    //dynamically allocated inside this function. The calling function
    //(e.g. main) takes care of deallocating this array. The size of this
    //array is communicated to the calling function (e.g. main function)
    //via the input reference variable "size".
    //
    //Input: The function takes a reference to the size of the array
    //intersection that is returned, and the "other" list object as inputs.
    //The function should set the size of the intersected array in the
    //reference variable "size" so that the main function knows the size of
    //this array.
    int* intersection(MyList& other, int& size);
// goes outside of the class
void MyList::intersection(MyList& other, int& size){

}
    //3. (10 points) This function returns the number of kinds of duplicates in the
    //list. For example, if the list contains {10,2,10,3,3,3,2,45,56}, then
    //the function returns 3. This is because elements 10, 2, and 3 are
    //duplicates in the list.
    int duplicate_kind_count();
// goes outside of the class
void MyList::duplicate_kind_count(){
	for(int i=0; i<size; i++){
		if(a[i]==){
// make a[i]= b[i], start b[i]'s=0 when duplicates found add 1 to current size, count times duplicates found and output val. 
	}
	}
}
    //4. (10 points) Returns true if every element in the list is a prime
    //number, false otherwise. A number is a prime number if that number is
    //greater than 0, and is evenly divisible only by itself and 1. 
    //The number 2 is also a prime number.
    bool list_is_prime();
// goes outside of the class
bool MyList::list_is_prime(){
	for(int i=0; i<size; i++){
		if(a[i]>0 && a[i]/1=a[i] && a[i]==2)
			return true;
	}
}
    //5. (5 points) This function resets the list by making its capacity 0.
    //Make sure to deallocate the memory and reset all data members of the
    //class appropriately.
    void reset();
// goes outside of the class
void MyList::reset(){
	cout << "This list is of capacity: " << cap;
	cout << "This current size is: " << size;
	cout << "The content of the list is below: " << ?;	
}
};

MyList::MyList(){
  size=0;
  cap=2;
  inc=2;
  a=new int[cap];
  b=new int[cap];
}

MyList::MyList(int c){
  size=0;
  if (c<=0)
    cap=2;
  else
    cap=c;
  inc=2;
  a=new int[cap];
  b=new int[cap];
}

MyList::~MyList(){
  delete[] a;
  delete[] b;
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
    tempb[i]=b[i];
  delete[] a;
  delete[] b;
  a=temp;
  b=tempb;
  cap=cap+inc;
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

  //Test operator-
  MyList l1,l2;
  for (int i=0;i<20;i++)
    l1.add(i);
  l1.display();

  for (int i=0;i<10;i++)
    l2.add(i);
  l2.display();

  l1-l2;

  //should print: 10 11 12 13 14 15 16 17 18 19
  l1.display();

  //Test intersection
  int* temp;
  int size;
  l1.add(1);
  l1.add(1);
  l1.add(9);

  temp=l1.intersection(l2,size);
  //Should display:
  //Intersection: 1 9
  cout << "Intersection: ";
  for (int i=0;i<size;i++)
    cout << temp[i] << " ";
  cout << endl;
  delete[] temp;

  //Test duplicate_kind_count
  l1.add(11);
  l1.add(14);
  l1.add(13);
  l1.add(13);
  //Should print:
  //Duplicate kind count: 4
  l1.display();
  cout << "Duplicate kind count: " << l1.duplicate_kind_count() << endl;

  //Test list_is_prime
  MyList l3;

  l3.add(2);
  l3.add(7);
  l3.add(23);
  //should print "Prime list"
  if (l3.list_is_prime())
    cout << "Prime list\n";
  else
    cout << "Not a prime list.\n";
  l3.add(45);
  //should print "Not a prime list"
  if (l3.list_is_prime())
    cout << "Prime list\n";
  else
    cout << "Not a prime list.\n";

  //Test reset
  l1.reset();
  //Should print:
  //This list is of capacity: 0
  //The current size is: 0
  //The content of this list is below:
  //
  l1.display();

  l1.add(34);
  //Should print:
  //This list is of capacity: 2
  //The current size is: 1
  //The content of this list is below:
  //34
  l1.display();
}
