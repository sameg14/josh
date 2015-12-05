#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;

bool is_fibonacci(int,int,int);

int main(){
int a = 0;
cout <<" Please enter number to be checked. "<<endl;
cin >>a;

bool z = is_fibonacci(a,0,1);

cout <<z<<endl;






}
bool is_fibonacci(int numToCheck, int twoPrev , int prev ) {
    if (numToCheck == twoPrev || numToCheck == prev)
        return true;

    int currentFibNumber = twoPrev + prev;
    if (currentFibNumber == numToCheck)
        return true;
    else if (currentFibNumber > numToCheck)
        return false;

    return is_fibonacci(numToCheck, prev, currentFibNumber);
}









































