/**********************************
Templated created by Kazumi Slott
CS311

Your name: Daniel Herrera
Your programmer number: 11
Any difficulties?:??????????
***********************************/
#include <iostream>
using namespace std;

void printAr(const int ar[], int s)
{
 for(int i = 0; i < s; i++)
    cout << ar[i] << " ";
  cout << endl;
}

void merge(int ar[], int first, int last)
{
  //For implementation of this function, refer to my lecture notes "merge sort"
  //If you are using a different technique, I assume you cheated and will give you zero points.

  //create new slots 
  //(last-first)+1 // 8 - 5 = 3 + 1 == 8 ... 5,6,7,8 [4 slots]
  int size = (last-first)+1;
  int* temp = new int[size]; 

  //example {1,4,6,8,10,3,5,2,22}   {3,5,2,22}
  int left_half = first;  //example left_half == 3
  int right_half = (first+last)/2+1; //example right_half == 2
  int middle = (first+last)/2; //13/2 = 6.5 ... index is 6. Therefore  middle == 5
  int index = 0; 
  
  //fill temp array with all numbers from left and right arrays in order 
   while(left_half <= middle and right_half <= last)
   {
      if( ar[left_half] > ar[right_half] )
	{
	  temp[index] = ar[right_half];
	  ++right_half;
	  ++index;
	}
      else
	{
	  temp[index] = ar[left_half];
	  ++left_half;
	  ++index;
	}
    }
  while( left_half <= middle )
    {
          temp[index] = ar[left_half];
          ++left_half;
          ++index;
    }
  while( right_half <= last)
    {
          temp[index] = ar[right_half];
          ++right_half;
	  ++index;
    }

  //add all the sorted elements into the array at the preselected area defined by first and last
  for(int i = first, j = 0; i != last+1;++i,++j) // i <= last AND i < last+1 both work  YET i != last+1 is intuitive because it is one before last. array ends '\0'
    {
      ar[i] = temp[j]; //index j from 0 to end   AND i from first til last
    }

  delete [] temp; //delete the whole array
}

void mergeSort(int ar[], int first, int last)
{
  //For implementation of this function, refer to my lecture notes "merge sort"
  if(first == last) return; //if there is only one element, return to caller immediately. first and last being the same value means that there is only one element
  else // if there are at least two elements
    {
      int middle = (first + last) / 2;
      mergeSort(ar, first,middle); //left side, middle inclusive
      mergeSort(ar, middle + 1, last); // right side, middle exclusive
      merge(ar,first,last); // once the recursive call is finished, this merge function will be called once 
    }
}

int main()
{
  int ar[] = {1, 8, 6, 4, 10, 5, 3, 2, 22}; //the array used in my lecture notes
  mergeSort(ar, 0, 8);
  printAr(ar, 9); //1 2 3 4 5 6 8 10 22

  int ar1[] = {1, 7, 5, 3, 9, 4};
  mergeSort(ar1, 0, 5);
  printAr(ar1, 6); //1 3 4 5 7 9 

  int ar2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  mergeSort(ar2, 0, 9);
  printAr(ar2, 10); //1 2 3 4 5 6 7 8 9 10

  return 0;
}
