/*

Problem 1 (5 points)
Write a C++ program for the following. Do not try to generalize this program into an equation. The goal is to practice iterations.

There is an old story that the emperor wanted to thank the inventor of the game of chess and asked the inventor to name his reward. The inventor asked for one grain of rice for the first square, 2 for the
second, 4 for the third, and so on, doubling for each of the 64 squares. That may sound modest, but there wasn’t that much rice in the empire!

Write a function to calculate the number of squares that are required to give the inventor a stated number of grains of rice that is provided as the function’s input. For example, the function should calculate the number of squares that are required to earn at least 1000 grains of rice, at least 1,000,000 grains, at least 1,000,000,000 grains, etc. You’ll need a loop, of course, and probably an int to keep track of which square you are at, an int to keep the number of grains on the current square, and an int to keep track of grains of all previous squares. We suggest that you print the value of all your variables for each iteration of the loop so that you can see what’s going on. Demonstrate that the function works using sample inputs from a main function.

grain[square1]=1	Three squares is 7 grains
grain[square2]=2	first loop with one square is 1 grain, second loop
grain[square3]=4	has 2 squares and 3 grains of rice, third loop has 3 
grain[square4]=8	squares with 1+2+4=7 grains of rice
grain[square5]=16
.
.
.
grain[square64]

*/
#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;

double total_rice_calculated(double);

int main(){

double rice_desired = 0;
double z = 0;

cout <<" Enter the number of rice you would like: ";
cin >> rice_desired;

z = total_rice_calculated(rice_desired);

cout <<" Desired rice is " << rice_desired <<endl;

if (z > 0){
cout << " The square count is " << z <<endl;
}
else{
cout << " Enter less than 64 squares " << endl;
}
   
return 0;
}

double total_rice_calculated(double rice_desired){
    double rice_total = 0;
    double rice_in_square = 1;
    double square = 0;
    
      do{
         rice_total = rice_in_square + rice_in_square;
         rice_in_square = rice_in_square*2;
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


















