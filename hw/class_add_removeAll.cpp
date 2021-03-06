#include <iostream>
#include <cstdlib>
#include <cmath>
#include <sstream> //convert data types in getline
#include <vector>
using namespace std;
/*
(2 points) A function bool remove_all(int val) that would remove all occurrences of val from the
list. The current order of elements in the list need not be preserved.

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
    bool remove_all(int);

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

bool MyList::remove_all(int v){
	//bool flag=false;
	for(int i=0; i<size; i++){
		if(a[i]==v){
			//flag=true;
			a[i]=a[size-1];
			size--;
			return true;
		}
	}

	return false;
	//return flag;
}
void MyList::display(){
  cout << "This list is of capacity: " << cap << endl;
  cout << "The current size is: " << size << endl;
  cout << "The content of this list is below: \n";
  for (int i=0;i<size;i++)
    cout << a[i] << " ";
  cout<<endl<< endl;

}

int main(){ 
  MyList l1;
  MyList l2(10);
  for (int i=0;i<7;i++){
    if(l1.add(i))
      cout << "Successfully added: " << i << endl;
    else
      cout << "Cannot add: " << i << endl;
  }

  l1.display();

  l1.remove_all(0);
  l1.display();

  l1.remove_all(1);
  l1.display();

  l1.remove_all(2);
  l1.display();
/*
  l2.add(10);
  l2.add(10);
  l2.add(10);
  l2.add(10);
  l2.add(10);
  l2.add(10); 
  l2.remove_all(10);
  l2.display();
*/
}

