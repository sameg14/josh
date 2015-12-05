#include<iostream>
#include<cmath>
using namespace std;
//hw-2.4
int* purge_duplicates(int *arr, int arr_sz, int* sz){
	static int nw[100]; 
	int size=-1;
	bool found;   //if return local varible, needs to declare as static
	for(int i=0;i<arr_sz;i++){
		found=false;
		for(int j=0;j<i;j++){
			if(arr[j]==arr[i]){
				found=true;
				break;
			}
		}
		if(!found){
			nw[++size]=arr[i];
		}
	}
	size=size+1;
	*sz=size;
	return nw;
}

int main(){
	int arr[8]={1,2,2,3,3,4,5,5};
	int sz;
	int* nw_arr=purge_duplicates(arr,8,&sz);
	for(int i=0;i<sz;i++)
		cout<<*(nw_arr+i)<<"  ";
	cout<<endl;
	nw_arr=NULL;
	return 0;
}
