#include<iostream>
#include<cmath>
using namespace std;
//programming problem1---insert sort
int main(){
	int array[8]={1,3,22,34,5,6,7,9};
	int j; int temp;
	for(int i=0;i<8;i++){
		j=i;
		while(j>0&&array[j-1]>array[j]){
			temp=array[j];
			array[j]=array[j-1];
			array[j-1]=temp;
			j--;
		}	
	}
	for(int i=0;i<8;i++)
		cout<<array[i]<<"  ";
	cout<<endl;

	return 0;
}

