#include<iostream>
using namespace std;

int* purge_duplicates(int*,int,int*);
bool is_present(int*,int,int);

int main(){
  int a[5]={1,3,3,1,2};
  int c=0;

  for (int i=0;i<5;i++)
    cout << a[i] << " ";//cout 1 3 3 1 2
  cout << endl;

  int* q = purge_duplicates(a,5,&c);

  for (int i=0;i<c;i++)
    cout << q[i] << " ";
  cout << endl;
  delete[] q;
}
/// FUNCTIONS ///
bool is_present(int* b, int bsz, int v){
  for (int i=0;i<bsz;i++)
    if (b[i]==v)
      return true;

  return false;
}

int* purge_duplicates(int* a, int asz, int* count){
  int b[asz];
  for (int i=0;i<asz;i++){
   // if not present go to next element 
    if (!is_present(b,asz,a[i])){
      b[*count]=a[i];
      (*count)++;
    }
  }
  int* p = new int[*count];
  for (int i=0;i<*count;i++)
    p[i]=b[i];

  return p;
}
