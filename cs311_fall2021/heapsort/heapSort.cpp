/*****************************************
Template written by Kazumi Slott
CS311

Your name: Daniel Herrera
Your programmer number: 11
Any difficulties?: ?????????
*******************************************/
#include <iostream>
using namespace std;

//print an integer array of size n
void print(int ar[], int n)
{
  for(int i = 0; i < n; i++)
    cout << ar[i] << " ";
  cout << endl;
}

//called from max_heapify and heapSort
void exchange(int* index, int* swap_index)
{
  //I have 3 lines of code here.
  int temp = *index;
  *index = *swap_index; 
  *swap_index = temp;
}

//turn a heap into a max-heap rooted at i, assuming the left and right subtrees are already max-heaps.
//n is the size of the heap
void max_heapify(int ar[], int n, int i)
{
  int l = (2*i) + 1; //the index of the left child of i
  int r = (2*i) + 2; //the index of the right child of i
  int largest = i;    //an index of the largest child of an array

  //look for the largest among 3 elements at i, l and r. largest gets the index of the largest value.
  //Make sure l and r don't go over the heap's range.
  //The key of node is >= the keys of its children
  //Recall how you found the largest value among 3 values in CS111.
  //I have 6 lines of code here. You can have more or less.
  if( l < n and ar[l] > ar[largest])
    {
      largest = l;
    }
  if( r < n and ar[r] > ar[largest])
    {
      largest = r;
    }

  if(largest != i)
    {
      exchange(&ar[i], &ar[largest]);
      max_heapify(ar, n, largest);
    }
}


//turn the entire array/tree into a max heap rooted at 0
//n is the size of the array
void build_max_heap(int ar[], int n)
{
  //2 lines of code in this function
  /*
  for each non-leaf node
     call max_heapify (turn the smallest subtrees into max-heaps and work your way up)
  */
  for( int i = (n/2)-1; i >= 0; i--) //max heapify from the parent. ex) n = 15 .. 15/2=7.5...7..7-1...ar[6]. Keep going until i = negative #
    {
      max_heapify(ar,n,i); //recursive call to fix all potential violations
    }
}

//a is an unordered list to start with
//use max_heapify to sort a
//n is the size of the array
void heapSort(int a[], int n)
{
  //I have 6 lines of code in this function. You can have more or less.

  //build max heap from an unordered list
  //call build_max_heap
  
  int size = n; //size of the unsorted portion of the array

  build_max_heap(a,size); 

  while( size != 0 ) //repeat until heap is empty
    {  
      //swap max element with last element - max element is at the end of the array
      exchange(&a[0], &a[size-1]);
      //discard the last node from heap
      max_heapify(a, size-1, 0);
      //root may violate max-heap property, but children are max heaps. run max_heapify to fix it.
      --size; //when size is 0, then exit loop
    }
}

//this function corrects a violiation of max heap by bubbling up an element at i                             
//a is a heap                                                                                                
void bubbleUp(int a[], int i)
{
  //Write this function after you made insert() and while you are making remove.
  int parent = (i-1)/2; //define parent relative to i 
  while( a[parent] <  a[i]) //out of bounds check and if parent is > than what is at i =>run loop
    {
      exchange(&a[parent],&a[i]); //exchange values 
      i = parent; //make parent new starting index
      parent = (i-1)/2; //since i is changed, recalculate new parent
    } 
}

//a is a max heap                                                                                            
//cap is the capacity of the heap                                                                            
//n is the number of elements the heap currently has before insertion                                        
//el is the new element to be inserted                                                                       
void insert(int a[], int cap, int& n, int el)
{
  //refer to lecture notes
  //write this function without calling bubbleUp first. When you work on remove, you will see you will
  //have to have the same code there. Move the code into bubbleUp and call it.
  // if( n == cap ) return; //if heap is full, then return. Below main, cap is 15 and n == 10
  // cannot expand capacity. b/c static array  cap++; //expand capacity from 15 to 16 to insert another
  //a[9] == 1 and a[10] == -1 therefore insert at index 10
  //int index = n; //use index for later but store one before terminating value

  a[n] = el; //insert el at the end of the heap -> implement n later 
  int p = (n - 1)/2; //the parent of el. example n = 3. p = 1
  if ( a[p] < a[n]) //keep bubbling up if true  
    {
      bubbleUp(a,n); //fix violation
    }
  n++;
  //n is the number of elements. not the index.     i can still use n for index
}

//a is a max heap                                                                                            
//n is the number of elements the heap currently has before deletion, then decrememted after deletion                                         
//el is the element to be removed. Assume all elements are unique                                            
void remove(int a[], int& n, int el)
{
  //refer to lecture notes
  //Call bubbleUp and max_heapify instead of coding the same things.

  int found_index = 0;

  for(int i = 0; i < n; i++)
    {
      if(a[i] == el) //execute body if key is found
	{
	  found_index = i;
	  i = n; 
	}
    }
    exchange(&a[n-1],&a[found_index]); //swap what is at index i with the last elemente
    n--; //eleminate last element of heap. due to violation
          int p = (found_index - 1)/2;
	  if(a[p] < a[found_index]) //if parrent is less than root and index then bubbleUp
	    { 
	      bubbleUp(a,n);
	    }
	  else //bubbleDown otherwise
	    {
	      max_heapify(a,n,found_index);
	    }   
}

int main()
{
  int ar[10] = {11, 3, 4, 5, 7, 19, 20, 2, 8, 1};
  int ar2[10] = {5, 3, 10, 4, 7, 9, 11, 2, 8, 1};
  int ar3[2] = {2,1};

  cout << "testing max_heap rooted at index 3" << endl;
  max_heapify(ar, 10, 3); //max-heapify rooted at index 3                                                                                      
  print(ar, 10);//11 3 4 8 7 19 20 2 5 1  --> the tree rooted at 3 is now a max-heap (8 is at root. 2 and 5 are its children)                  

  cout << endl << "testing max_heap rooted at index 1" << endl;
  max_heapify(ar, 10, 1); //max-heapify rooted at index 1                                                                                      
  print(ar, 10);//11 8 4 5 7 19 20 2 3 1  --> the tree rooted at 1 is now a max-heap (8 is at root. 5 and 7 are its children. 5's children are 2 and 3)                                                                                                                                      

  cout << endl << "testing build_max_heap" << endl;
  build_max_heap(ar, 10);
  print(ar, 10);//20 8 19 5 7 11 4 2 3 1                                                                                                       

  cout << endl << "testing heapSort" << endl;
  heapSort(ar2, 10);
  print(ar2, 10);//1 2 3 4 5 7 8 9 10 11                                                                                                       

  cout << endl << "testing heapSort" << endl;
  heapSort(ar3, 2);
  print(ar3, 2);//1 2                                                                                                                          

  cout << "testing insert" << endl;
  int ar4[15] = {20, 8, 19, 5, 7, 11, 4, 2, 3, 1, -1, -1, -1, -1, -1}; //max heap with 10 elements already   
  int n = 10; //n is the number of elements in the heap                                                      
  insert(ar4, 15, n, 15); //trying to insert 15                                                              
  print(ar4, n); //20 15 19 5 8 11 4 2 3 1 7                                                                 

  cout << "testing remove" << endl;
  remove(ar4, n, 15); //trying to remove 15                                                                  
  print(ar4, n);//20 8 19 5 7 11 4 2 3 1                                                                     

  return 0;
}

