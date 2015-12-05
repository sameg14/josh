/*
Problem 3 (4 points). Suggested time: 30 minutes.
Implement a function int* purge_duplicates(int* arr, int arr_sz, int* sz) that takes an array of integers and the array’s size as its input. The input array to this function may contain duplicate integer values. The goal of the function is to return a different array that contains no duplicate values. The size of this duplicate-free array is stored in the address sz, which is the third variable in the function. Using a main function, demonstrate that it works.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include<sstream> //convert data types in getline

using namespace std;
/*
int* purge_duplicates(int* array, int array_size, int* size)
*/

void rmdup(int *array, int length)
{
    int *current , *end = array + length - 1;

    for ( current = array + 1; array < end; array++, current = array + 1 )
    {
        while ( current <= end )
        {
            if ( *current == *array )
            {
                *current = *end--;
            }
            else
            {
                current++;
            }
        }
    }
}
int main(){
  int a[5];

  for (int i=0;i<5;i++){
    rmdup(a,5);	
    cin >> a[i];
}
  for (int i=0;i<5;i++){
    rmdup(a,5);
    cout <<  a[i] << endl;
}
return 0;
}


