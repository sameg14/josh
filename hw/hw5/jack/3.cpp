#include<iostream>

using namespace std;

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

    //display the contents of the list
    void display();
    
    // remove all occurrances of val from the list
    bool remove_all(int);
    
    // insert val after the value before in the list
    bool insert(int,int);
    
    // remove val from the list while perserving current order
    bool remove_ordered(int);
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

bool MyList::remove(int v){
  //check if v exists in the list
  for (int i=0;i<size;i++)
    //need to remove v if the following
      //condition is satisfied
    if (a[i]==v){
      //overwrite the current cell where v is found with 
        //the last element in the list
      a[i]=a[size-1];
      //update size
      size--;
      return true;
    }

  //didn't find v in the list
  return false;
}

bool MyList::remove_all(int val){
bool flag = false;
	for(int i = 0; i < size; i++)
		if (a[i] == val){
			a[i] = a[size - 1];
			size --;
			flag = true;
			}
		return flag;
		}
		
bool MyList::insert(int before, int val){
bool flag = false;
	for(int i = 0; i < size; i++){
		if (a[i] == before){
			if (size == cap)
				return flag;
				
			for (int j = size; j > i; j--){
				a[j] = a[j-1];
				
				}
				a[i+1] = val;
				size ++;
				flag = true;
		}
	
	}
	return flag;
	}
			
bool MyList::remove_ordered(int val){
bool flag = false;
	for(int i = 0; i < size; i++){
		if (a[i] == val){
			flag = true;
			for (int j = i; j < size; j++){
				a[j] = a[j+1];
				}
				size--;
				i--;
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
  MyList l2(5);
  for (int i=0;i<3;i++){
    if(l1.add(i))
      cout << "Successfully added: " << i << endl;
    else
      cout << "Cannot add: " << i << endl;
  }
  l1.display();
    
  l1.remove_ordered(1); // adjust value in () to test function
  l1.display();
  
  
}


