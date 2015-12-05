#include<iostream>
using namespace std;

bool add(int*,int*,int,int);
void display(int*,int,int);
bool remove(int*,int*,int);
bool remove_all(int*,int*,int);

bool insert_after(int*,int,int*,int,int);
int is_present(int*,int,int);

int main(){
  int sz=10;
  int a[sz];
  int csz=0;
  bool flag=false;
  int val=109;

  for (int i=0;i<4;i++){
    flag=add(a,&csz,sz,i);
    if (flag)
      cout << "Successfully added.\n";
    else
      cout << "Add unsuccessful.\n";
  }
  display(a,csz,sz);
//void display(int* p, int s, int cap)
  
  insert_after(a,sz,&csz,5,0);
//bool insert_after(int* a, int cap, int* csz, int val, int after)
  display(a,csz,sz);

  insert_after(a,sz,&csz,6,3);
  display(a,csz,sz);

  insert_after(a,sz,&csz,98,2);
  display(a,csz,sz);

  insert_after(a,sz,&csz,7,3);
  display(a,csz,sz);

  insert_after(a,sz,&csz,8,7);
  display(a,csz,sz);

  //cannot add
  insert_after(a,sz,&csz,87,23);
  display(a,csz,sz);

  insert_after(a,sz,&csz,9,8);
  display(a,csz,sz);

  //cannot add
  insert_after(a,sz,&csz,10,9);
  display(a,csz,sz);
}

int is_present(int* a, int sz, int after){
  for (int i=0;i<sz;i++)
    if (a[i]==after)
      return i; //returns the position in the list (array) at which the value "after" is found
  		//note: this position cannot be a negative value
  return -1; //returns a negative value if "after" not found in the list
}

bool insert_after(int* a, int cap, int* csz, int val, int after){
  //if not enough capacity, cannot insert
  if (*csz==cap)
    return false;

  int position=is_present(a,*csz,after);

  //if "after" not found in the list, cannot insert
  if (position<0)
    return false;

  //shift every element down by one level from 
  //list index "current size (*csz)"
  //to the index at which the value "after" was found in the list ("position")
  for (int i=*csz;i>position;i--)
    a[i]=a[i-1];

  //insert val
  a[position+1]=val;

  //update list size
  *csz=(*csz)+1;

  //success
  return true;
}

bool add(int* p, int* s, int cap, int v){
  if (*s==cap)
    return false;

  p[*s]=v;
  (*s)++;
  return true;
}

void display(int* p, int s, int cap){
  cout << endl;
  cout << "List Capacity: " << cap << endl;
  cout << "Current number of elements in the list: " << s << endl;
  cout << "List contents: ";
  for (int i=0;i<s;i++)
    cout << p[i] << " ";
  cout << endl;
  cout << endl;
  return;
}

bool remove(int* p, int* sz, int v){
  int index=-1;
  for (int i=0;i<*sz;i++)
    if (p[i]==v)
      index=i;
  if (index==-1)
    return false;
  p[index]=p[(*sz)-1];
  (*sz)--;
  return true;
}

bool remove_all(int* p, int* sz, int v){
  bool exists_at_least_once=false;
  while(remove(p,sz,v))
    exists_at_least_once=true;
  return exists_at_least_once;
}
