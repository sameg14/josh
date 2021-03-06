#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream> //convert data types in getline
#include <vector>
using namespace std;
/*
(4 points) A function bool insert(int before, int val) that would insert ‘val’ after the value
‘before’ in the list.
 */
#define MAX 10

class MyList{
  private:
    int a[MAX];
    int size;
    int cap;

  public:
    //list of default capacity
    MyList();

    //list of user-specified capacity
    MyList(int);

    //add an element to the list
    bool add(int);

    //remove an element from the list
    bool remove(int);

    //insert an element into the list	
    bool insert(int, int);

    //display the contents of the list
    void display();
};

MyList::MyList(){
  cap=MAX;
  size=0;
}

MyList::MyList(int c){
  size=0;
  //if invalid capacity requested
  if(c<=0 || c>MAX)
    cap=MAX;
  //else obey
  else
    cap=c;
}

bool MyList::add(int v){
  //if the list is full
  if (size==cap)
    return false;

  //add to the end of the list
  a[size]=v;
  //update size
  size++;
  return true;
}
bool MyList::insert(int v, int before){
	bool flag=false;
	for(int i=0;i<size; i++){
		if(a[i]==before){
			if(cap==size){
				return flag;
			}
			for (int j = size; j > i; j--){
				a[j] = a[j-1];
				
				}
				a[i+1] = v;
				size ++;
				flag = true;
		}
	}
	return flag;
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
  MyList l2(1);
  for (int i=0;i<3;i++){
    if(l1.add(i))
      cout << "Successfully added: " << i << endl;
    else
      cout << "Cannot add: " << i << endl;
  }
  l1.display();

  l1.insert(5,1);
  l1.display();

}

