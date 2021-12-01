/**************************************
Template created by Kazumi Slott
CS311

Your name:
Your programmer number:
Any difficulties?:
**************************************/

#include <iostream>
using namespace std;

void swap(int& data1, int& data2)
{
  int temp = data1;
  data1 = data2;
  data2 = temp;
}

void print(const int ar[], int n)
{
  for(int i = 0; i < n; i++)
    cout << ar[i] << " ";
}

void insertionSort(int ar[], int n)
{
  //https://www.youtube.com/watch?v=ROalU379l3U
  //Implement the insertion sort by watching the above youTube video. Your algorithm has to match their dance.
  //call swap
  for( int i = 0; i < n; i++)
    {
      while( ar[i] > ar[i+1] )
	{
	  swap(ar[i],ar[i+1]);
	  i--;
	}
    }
}

void selectionSort(int array[], int N)
{
  //Implement selection sort by moving the smallest element to the beginning.
  //call swap
    
  int small_index; //the index of the smallest value
  
  //last is the last index in unsorted area
  for(int first = 0; first <= N-2; first++) //assume that index 0 is the smallest element in the array
    {
      small_index = first; //assume the first item is the smallest
      
      /*
	find the smallest in unsorted area ([0..last])
	find the smallest in unsorted array
	since first is the current smallest, compare it to the value that is 
	after a[first].....a[first+1] 
	and check each index til the end of the array
      */
  
      for(int i = first + 1; i <= N-1; i++)
	{
	  if(array[i] < array[small_index]) //The current item is smaller, then keep the current index
	    {
	      small_index = i; //store i as new smallest value
	    }
	}
      swap(array[small_index],array[first]); //swap smallest value with the first element  
    }
  
  //You can find more information in my homework document
}

//Implemented by Kazumi Slott
//ar is an integer array of any size
//s is the size of the array
//For more info, read my CS211 lec notes "Lec notes 2-2: bubble sort"
//You could also watch my CS211 lecture recording "Lecture 2/5(Fri) - bubble sort and enum" 
void bubbleSort(int ar[], int s)
{
  bool done = false; //set to false if there was swapping meaning not done yet.                                   
  int last = s - 2; //last is the index of the left element in the last pair to be checked. In the first step, last should point to the second to last.                                                                            
  while(!done) //swapping required in the previous iteration or the first iteration starts                        
    {
      done = true; //no swapping has happened yet when a new step starts.                                         

      for(int i = 0; i <= last; i++) //check each adjacent pair of items in the unsorted part                     
        {
	  if(ar[i] < ar[i + 1]) //the pair is out of order                                                          
	    {
	      swap(ar[i], ar[i+1]);
	      done = false; //swapping required. needs to proceed to the next iteration.                            
	    }
        }
      last--; //the area to be checked shrinks down after each iteration                                         
    }//end of while                                                                                               
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
          swap(ar[index], ar[j]);
        }
    }
  swap(ar[index + 1], ar[end]);
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

void merge(int ar[], int first, int last)
{
  //copy and paste merge() from your mergeSort.cpp   
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


