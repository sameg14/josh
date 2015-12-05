#include "iostream"
#include "vector"
using namespace std;

void swap(int *p, int* q){
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
int factorial(int n){
    if(n==1)
        return 1;
    else
        return n*factorial(n-1);
}
float CtoF(float c){
    float f;
    f=c*9/5+32;
    return f;
}
vector<int> ReadInts(int n){
    vector<int> a;
    int b;
    for(int i=0;i<n;i++){
        cout<<"input a number"<<endl;
        cin>>b;
        a.push_back(b);
    }
    return a;
}
bool print_x(int x, char a){
    if(x<=0)
        return false;
    else
        for(int i=0;i<x;i++){
            cout<<a<<"  ";
        }
    cout<<endl;
    return true;
}
double comp_sum(double* arr, int size){
    double sum=0;
    for(int i=0;i<size;i++)
        sum+=arr[i];
    return sum;
}


int main(){
    //f'11-1
    /*   int a=20;
     float b=20.31;
     long int c=25000000000;
     char d='A';
     string e="Hello\n";
     cout<<a<<endl;
     cout<<b<<endl;
     cout<<c<<endl;
     cout<<d<<endl;
     cout<<e<<endl;
     */
    //f'11-2
    /*   int a[10];
     a[9]=25;
     cout<<a[9]<<endl;
     */
    //f'11-6
    /*    int i=5;
     int *ip=&i;
     cout<<*ip<<endl;
     */
    //f'11-7
    /*    int p=1, q=2;
     swap(&p,&q);
     cout<<p<<"  "<<q<<endl;
     */
    //f'12-1
/*    double d=2000002;
    cout.precision(7);//this is for print out, may not need in the exam
    cout<<d<<"  ";
    double* ptr=&d;
    *ptr=*ptr+20;
    cout<<d<<endl;
*/
    //f'13-4
/*    int n;
    cout<<"input n"<<endl;
    while (!(cin>>n)) {
        cout<<"error!"<<endl;
        cin.clear();
        cin.ignore(10000,'\n');
        cout<<"input n"<<endl;
    }
    cout<<"n! is "<<factorial(n)<<endl;
  */
    //f'13-5,3
   // cout<<CtoF(37)<<endl;
    //f'13-6
/*    vector<int> vec=ReadInts(4);
    for(int i=0;i<4;i++){
        cout<<vec[i]<<"  ";
    }
    cout<<endl;
*/
    //f'14-11,6
//    print_x(3, 'a');
    //f'14-12,7
    double a[3]={1.1,2.2,3.3};
    cout<<comp_sum(a,3);
    
    return 0;
}


