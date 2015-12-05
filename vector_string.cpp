#include<iostream>
#include<vector>
#include<string>
using namespace std;

void foobar(vector<string>);

int main(){
  vector<string> v;
  string s;
  for (int i=0;i<3;i++){
    cin>>s;
    v.push_back(s);
  }

  cout << "====================\n";
  foobar(v);
  cout << "====================\n";
  
  for (int i=0;i<v.size();i++)
    cout << v[i] << endl;;
}

void foobar(vector<string> t){
  cout << "Inside foobar.\n";
  t.push_back("test");
  for (int i=0;i<t.size();i++)
    cout << t[i] << endl;
  cout << "Exiting foobar.\n";
}
