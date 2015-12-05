#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>


using namespace std;

double calculate_total_rice(double);

int main(){

double rice_desired = 0;
double z = 0;

cout <<" Please enter desired ammount of rice: ";
cin >> rice_desired;

z = calculate_total_rice(rice_desired);

cout <<" Desired rice is " <<rice_desired<<endl;

if (z > 0){
cout <<" The square count is " <<z<<endl;
}
else{
cout <<" There can not be more than 64 squares. Your request is unreasonable. "<<endl;
}
   
return 0;
}

double calculate_total_rice(double rice_desired){
    double rice_total = 0;
    double rice_in_square = 1;
    double square = 0;
    
      do{
         rice_total += rice_in_square;
         rice_in_square *= 2;
         square++;
        } 
      while (rice_total < rice_desired);             
            
if (square <= 64){
return square ;
}
    
else{
return 0;
}
}
