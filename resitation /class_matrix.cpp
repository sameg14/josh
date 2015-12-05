#include<iostream>
using namespace std;

class Matrix{
private:
	float x11;
	float x12;
	float x21;
	float x22;	
public:
	Matrix(float x1,float x2, float x3, float x4){
		x11=x1;
		x12=x2;
		x21=x3;
		x22=x4;
		cout<<"object is being created"<<endl;
	}//constructor	
	float det(){
		return x11*x22-x12*x21;
	}
	float getx11(){//accessor, access private instance member
		return x11;
	}
	float getx12(){
		return x12;
	}
	float getx21(){
		return x21;
	}
	float getx22(){
		return x22;
	}
	bool isSingular(){
		if(x11*x22-x12*x21!=0)
			return false;
		else
			return true;

	}
	void inverse(float x1, float x2, float x3, float x4){
		float det=x1*x4-x2*x3;
		x11=x4/det;
		x12=-x2/det;
		x21=-x3/det;
		x22=x1/det;
	}
	void print(){
		cout<<x11<<"   "<<x12<<endl;
		cout<<x21<<"   "<<x22<<endl;
	}

};
int main(){
	Matrix mat(1,2,3,4);//create object
	cout<<"x11: "<<mat.getx11()<<"  "<<"x12: "<<mat.getx12()<<endl;
	cout<<"x21: "<<mat.getx21()<<"  "<<"x22: "<<mat.getx22()<<endl;
	cout<<"det: "<<mat.det()<<endl;
	cout<<"is singular: "<<mat.isSingular()<<endl;
	cout<<"inverse: ";
	mat.inverse(1,2,3,4);
	mat.print();

	return 0;
}
