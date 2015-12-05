//pointers
int main(){
	int var=20;
	int *ip;int **ptrptr;
    //example of double pointer
	ip=&var;
    ptrptr=&ip;
    cout<<ip<<endl;
	cout<<*ip<<endl;
    cout<<**ptrptr<<endl;
	ip=NULL;//release pointer
    ptrptr=NULL;
	//arithmetic of pointers;++, --,+,-
//	int arr[3]={1,2,3};
//	int *ptr;
/*	ptr=arr;
	for(int i=0;i<3;i++){
		cout<<"addre "<<ptr<<" value "<<*ptr<<endl;
		ptr++;
	}
*/
/*	ptr=&arr[2];
	for(int i=0; i<3;i++){
		cout<<"addre "<<ptr<<" value "<<*ptr<<endl;
		ptr--;
	}
*/
	//pointer comparison
/*	ptr=arr;
	while(ptr<=&arr[2]){
		cout<<"addre "<<ptr<<" value "<<*ptr<<endl;
		ptr++;

	}
*/
	return 0;
}
