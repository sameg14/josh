#include <iostream>
#include <cstdlib>
#include <cmath>
#include<sstream> //convert data types in getline
# include <stdio.h>
using namespace std;

int* insertValue (int* originalArray, int positionToInsertAt, 
		  int ValueToInsert, int sizeOfOriginalArray)
{
  // Create the new array - user must be told to delete it at some point
  int* newArray = new int[sizeOfOriginalArray + 1];

  
  for (int i=0; i<=sizeOfOriginalArray; ++i)
  {
    if (i < positionToInsertAt)  // All the elements before the one that must be inserted
    {
       newArray[i] = originalArray[i];
    }
  
    if (i == positionToInsertAt)  // The right place to insert the new element
    {
      newArray[i] = ValueToInsert;
    }
 
    if (i > positionToInsertAt)  // Now all the remaining elements
    {
      newArray[i] = originalArray[i-1];
    }
  }
return newArray;
}


int main()
{
  int x[5]={0, 1, 2, 3, 4};
  for (int y=0;y<5;y++)
    cout << x[y] << " ";
    cout << endl;
   int* z = insertValue(x,3,7,5);
   for (int y=0;y<6;y++)
    cout << z[y] << " ";
  delete[] z;
  return 0;

}
