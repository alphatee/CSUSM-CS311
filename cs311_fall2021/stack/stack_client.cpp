#include<iostream>
#include "stack_L_T.h"

using namespace std;

int main() 
{
  Stack<int> s;
  int elem; //place holder for pop()
  

  try
    {
      s.push(1);
      s.push(2);
      s.push(3);
      
      Stack<int> s2;
      s2 = s;
            
      cout << s2 << endl;
    }
  catch(Stack<int>::Underflow)
    {
      cout << "Error:The stack is empty." << endl;
    }

  return 0;
}
