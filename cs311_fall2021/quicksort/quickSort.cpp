/**********************************
Templated created by Kazumi Slott
CS311

Your name: Daniel Herrera 
Your programmer number: 11
Any difficulties?:
Why does int& ar[] not work? "array of references" ?
Why did my intial work posted in another document-not work ?
I want to see the implementation of 'if(start and end) return' checker.  
***********************************/
#include <iostream>

using namespace std;

//I did not use these utility functions, they were convoluted 
bool check_array(const int ar[], const int start, const int end);

bool check_array(const int ar[], const int start, const int end)
{
  int count = 0;
  
  for(int i = start; i < end; ++i)
    {
      ++count;  //count number of elements in the array
    }
   if(count == 0 or count == 1) {return true;}
  else return false;
}

void printAr(const int ar[], int s)
{
 for(int i = 0; i < s; i++)
    cout << ar[i] << " ";
  cout << endl;
}

//It is good to have the swap function so partition() won't get crowded. 
void swap(int* index,int* swap_index) //arrays decay into pointers 
{
  int temp = *index;   //store value of index in temp
  *index = *swap_index; //store value of swap_index into index
  *swap_index = temp; //store original value of index(temp) into swap_index
}

//This function returns the index where the pivot value went in. 
int partition(int ar[], int start, int end)
{
  //I have 3 variables: pivot, index and swap_index. You may have any local variables. 
  int pivot = ar[end]; 
  int index = (start - 1); //index to move along the array
   
  for(int j = start; j <= end - 1; ++j)   //get initial swap_index value 
    {
      if(ar[j] < pivot) //swap_index points to the first value greater than pivot 
	{
	  ++index;
	  swap(&ar[index], &ar[j]); 
     	}
    }
  swap(&ar[index + 1], &ar[end]);
  return( index + 1 ); 
}

void quickSort(int ar[], int start, int end)
{
  
  //If the partition has only one element or none, return. 
                   //In other words, if the partition has at least 2 elements, go inside the if.
                   //use start and end to figure out.

  //no such thing as a NULL array but they can hold are references. Without pointing to an array, the array variable (ar) can hold NULL

    if((start == end) or ar == NULL) return; //if start and end match (0 == 0) means 1 element array, and an [empty array] is NULL.
    if(start < end) 
    {
      //call partition.
      int partition_index = partition(ar,start,end); 
      //quickSort on the left partition
      quickSort(ar,start,partition_index - 1); 
      //quickSort on the right partition
      quickSort(ar,partition_index + 1, end); 
    }
  else return; // just in case there is an edge case, return 
}

int main()
{
  int ar[] = {15, 10, 5, 7, 1, 4, 12, 8, 6};
  quickSort(ar, 0, 8);
  printAr(ar, 9); //1 4 5 6 7 8 10 12 15

  int ar1[] = {1, 7, 5, 3, 9, 4};
  quickSort(ar1, 0, 5);
  printAr(ar1, 6); //1 3 4 5 7 9 

  int ar2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  quickSort(ar2, 0, 9);
  printAr(ar2, 10); //1 2 3 4 5 6 7 8 9 10

  //0 element array
  int ar3[] = {};
  quickSort(ar3,0,0);
  printAr(ar3,0); //prints nothing 

  //1 element array
  int ar4[] = {2};
  quickSort(ar4,0,0); //pass array, starting index ,ending  index 0 = value '2'
  printAr(ar4,1); //prints '2'

  return 0;
}
