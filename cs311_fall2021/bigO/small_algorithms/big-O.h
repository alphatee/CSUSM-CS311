/**********************************
CS311 Kazumi Slott

Your name: Daniel Herrera
Your program number: 11
Describe any difficulties here: 
*********************************/

/********************************************************************
//Make your own test client and test your functions thorougly.
//You will submit this header file only. My test client will test your functions.
********************************************************************/
bool all_negative_values(const int a[], int& sz);

bool all_negative_values(const int a[], int& sz)
{
  int count = 0; //keep track of all negative values                                                                                                                                                      
  for( int k = 0; k < sz; k++)
    {
      if(a[k] < 0)
	{
          ++count;
	}
    }
  if(count == sz) return true; // this means all the values in the array are negative ... return 0 by default 
  return false;
}

//What is the runntime complexity of this algorithm? O(N)
//Even if you cannot get this function to work, you may guess the complexity and provide your answer above.
int algoA(const int a[], int sz)//Don't change the function headers
{
  if(all_negative_values(a,sz)) return 0; //returning 0 for default if it is true that all values are negative 

  int i,j,k;    //declare now because I am assigning the letters to each other later 
  int sum,max_sum = 0;  //declare necessary

  for( i = 0; i < sz; i++)
    {
      for( j = i; j < sz; j++)
	{
	  sum = 0;
	  for(k = i ; k < j; k++)
	    {
	      sum +=  a[k];
	    }
	  if(sum > max_sum)
	    {
	      max_sum = sum;
	    }
	}
    }
  return max_sum;
}

//What is the runntime complexity of this algorithm? O(N^2)
//Even if you cannot get this function to work, you may guess the complexity and provide your answer above..
int algoB(const int a[], int sz)
{
  if(all_negative_values(a,sz)) return 0; //returning 0 for default if it is true that all values are negative 

  int sum,max_sum = 0; 
  for( int i = 0; i < sz; i++)
    {
      //     sum = 0;
       for( int j = i; j < sz; j++)
	 {
	   sum += a[i];
	 }
       if( sum > max_sum)
	 {
	   max_sum = sum;
	 }
    }
   return max_sum;
}

//What is the runntime complexity of this algorithm? O(nLOGn)
//Even if you cannot get this function to work, you may guess the complexity and provide your answer above..
int algoC(const int a[], int sz)
{

}
