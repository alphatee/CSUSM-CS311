// Towers Of Hanoi program
//NOTE: CSUSM compiler does not recognize to_string() 
#include <iostream>
#include <string> //to_string() 

using namespace std; 

void towersOfHanoi(int n, int from, int to, int spare);

void towersOfHanoi(int n, int from, int to, int spare)
{
  if(n == 1)
    {
      cout <<  "moving the disk from " + to_string(from) + " to " + to_string(to) << endl;
    }
  else
    {   
      towersOfHanoi(n-1, from, spare, to);
      towersOfHanoi(1, from, to, spare);
      towersOfHanoi(n-1, spare, to, from);
    }
}
int main()
{
  /*
    Proof by induction
    Let f(n) be a recursive function
    1) Show f(1) works (base case)
    2) Assume f(n-1) works
    3) Show f(n) works using f(n-1)
  */
    
  towersOfHanoi(3,1,3,2); //7 moves
}
