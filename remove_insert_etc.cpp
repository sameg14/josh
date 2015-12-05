#include<iostream>
using namespace std;

bool add(int*,int*,int,int);
void display(int*,int);
bool remove(int*,int*,int);
bool remove_all(int*,int*,int);

int main(){
// sz max _cap	
  int sz=10;
  int a[sz];
//current size 
  int csz=0;
  bool flag=false;
  int val=109;

  for (int i=0;i<15;i++){
    flag=add(a,&csz,sz,i);
    if (flag)
      cout << "Successfully added.\n";
    else
      cout << "Add unsuccessful.\n";
  }
  display(a,csz);

  for (int i=0;i<15;i++){
    flag=remove(a,&csz,i);
    if (flag)
      cout << "Successfully removed.\n";
    else
      cout << "Remove unsuccessful.\n";
  }
  display(a,csz);

  for (int i=0;i<5;i++)
    flag=add(a,&csz,sz,3);

  display(a,csz);
  cout << remove_all(a,&csz,3) << endl;
  display(a,csz);

}

bool add(int* p, int* s, int cap, int v){
  if (*s==cap)
    return false;

  p[*s]=v;
  (*s)++;
  return true;
}

void display(int* p, int s){
  for (int i=0;i<s;i++)
    cout << p[i] << " ";
  cout << endl;
  return;
}
// sz runs through function to check for item to remove 
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
