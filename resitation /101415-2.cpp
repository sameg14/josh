#include <iostream>
using namespace std;

bool erase_all(int* d, int* size, int val){
	bool flag=false;
	//preserve order
/*	for(int i=0;i<*size;i++){
		if(d[i]==val){
			flag=true;
			//shifting
			for(int j=i; j<*size; j++){
				d[j]=d[j+1];
			}
			*size=*size-1;
			i=i-1;
		}
	}
*/
	//unordered
	for(int i=0; i<*size; i++){
		if(d[i]==val){
			flag=true;
			d[i]=d[*size-1];
			*size=*size-1;
		}
	}


	return flag;
}
void display(int* d, int size){
	for(int i=0; i<size; i++)
		cout<<d[i]<<" ";
	cout<<endl;
}
bool increase_capacity_by(int* d, int size, int* cap, int inc_by){
	if(size> *cap)
		return false;
	*cap=*cap+inc_by;
	d=new int[*cap];
	return true;
}
bool insert(int* d, int* size, int* cap, int before, int val){
	bool flag=false;
	for(int i=0;i<*size; i++){
		if(d[i]==before){
			flag=true;
			if(*cap==*size){
				increase_capacity_by(d,*size, cap,1);
			}
			*size=*size+1;
			//inserting--shift
			for(int j=*size-1; j>i;j--){
				d[j]=d[j-1];
			}
			d[i+1]=val;
		//	break;
		}
	}
	return flag;
}

int main(){
	int size=10;
	int cap=10;
	int* d= new int[cap];
	for(int i=0; i<size; i++){
		if(i%2==0)
			d[i]=i;
		else
			d[i]=i-1;

	}
	cout<<"original array: "<<endl;
	display(d,size);
	erase_all(d,&size,0);
	cout<<"after erase 0"<<endl;
	display(d,size);
	increase_capacity_by(d,size,&cap,2);
	cout<<"cap value: "<<cap<<endl;
	insert(d,&size, &cap,2, 10);
	cout<<"after inserting: "<<endl;
	display(d,size);


	return 0;
}
