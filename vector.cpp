#include<iostream>
#include<vector>
using namespace std;

void foo(vector<int>);
void boo(vector<int>*);

int main(){
  vector<int> v;
  cout << "Current size of the vector: " << v.size() << endl;
  cout << "Current capacity of the vector: " << v.capacity() << endl;
  cout << endl;

  for (int i=0;i<20;i++)
    v.push_back(i);

  for (int i=0;i<v.size();i++)
    cout << v[i] << " ";
  cout << endl;
  cout << "Current size of the vector: " << v.size() << endl;
  cout << "Current capacity of the vector: " << v.capacity() << endl;
  cout << endl;

  foo(v);
  for (int i=0;i<v.size();i++)
    cout << v[i] << " ";
  cout << endl;
  cout << "Current size of the vector: " << v.size() << endl;
  cout << "Current capacity of the vector: " << v.capacity() << endl;
  cout << endl;

  boo(&v);
  for (int i=0;i<v.size();i++)
    cout << v[i] << " ";
  cout << endl;
  cout << "Current size of the vector: " << v.size() << endl;
  cout << "Current capacity of the vector: " << v.capacity() << endl;
  cout << endl;
}

void foo(vector<int> t){
  cout << "Inside foo.\n";
  for (int i=0;i<t.size();i++)
    cout << t[i] << " ";
  cout << endl;
  cout << "Current size of the vector: " << t.size() << endl;
  cout << "Current capacity of the vector: " << t.capacity() << endl;

  for (int i=20;i<30;i++)
    t.push_back(i);

  for (int i=0;i<t.size();i++)
    cout << t[i] << " ";
  cout << endl;
  cout << "Current size of the vector: " << t.size() << endl;
  cout << "Current capacity of the vector: " << t.capacity() << endl;
  cout << "Exiting foo.\n";
  cout << endl;
}

void boo(vector<int>* p){
  cout << "Inside boo.\n";
  for (int i=0;i<(*p).size();i++)
    cout << (*p)[i] << " ";
  cout << endl;
  cout << "Current size of the vector: " << (*p).size() << endl;
  cout << "Current capacity of the vector: " << (*p).capacity() << endl;

  for (int i=20;i<30;i++)
    (*p).push_back(i);

  for (int i=0;i<(*p).size();i++)
    cout << (*p)[i] << " ";
  cout << endl;
  cout << "Current size of the vector: " << (*p).size() << endl;
  cout << "Current capacity of the vector: " << (*p).capacity() << endl;
  cout << "Exiting boo.\n";
  cout << endl;
}
