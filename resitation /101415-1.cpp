#include <iostream>
using namespace std;

class Stack{
private:
    int a[5];
    int length;
public:
    Stack(){
        length=5;
        for(int i=0; i<length;i++)
            a[i]=i;
        cout<<"default constructor is called"<<endl;
    }
    ~Stack(){
        cout<<"default deconstructor is called"<<endl;
    }
    void push(int x){
        a[length++]=x;
    }
    void pop(){
        length--;
    }
    bool isEmpty(){
        if(length==0)
            return true;
        else
            return false;
    }
    bool isFull(){
        if(length==5)
            return true;
        else
            return false;
    }
    void print(){
        for(int i=0;i<length;i++)
            cout<<a[i]<<"  ";
        cout<<endl;
    }
};

int main() {
    Stack stack;
    cout<<"int stack is ";
    stack.print();
    stack.pop();
    cout<<"after pop fuction, int stack is ";
    stack.print();
    cout<<"after push 6 into stack, int stack is ";
    stack.push(6);
    stack.print();
    cout<<"is stack full? "<<stack.isFull()<<endl;
    cout<<"is stack empty? "<<stack.isEmpty()<<endl;
    return 0;
}
