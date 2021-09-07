#include<iostream>
#include "stack_L_T.h"

using namespace std;

int main() 
{
  Stack<int> s;
  int elem; //place holder for pop()

  try
    {
      elem = s.getTop();
      cout << elem << endl;
      s.push(1);
      elem = s.getTop();
      cout << elem << endl;
      s.push(2);
      s.push(3);
      // s.push(4); test

      //s.pop();
      //s.pop();
      //s.pop();
      //s.pop();
    }
  catch(Stack<int>::Underflow)
    {
      cout << "Error:The stack is empty." << endl;
    }
  catch(Stack<int>::Overflow e)
    {
      cout << "Error: trying to push when the stack is full. Couldn't insert: " << e.getElem() << endl;
    }
  return 0;
}
