/**************************************************************************
~/cs311/stack_Client_op.cpp
Implemented by Kazumi Slott
11-1-2021

Testing operator==()
**************************************************************************/
#include <iostream>
using namespace std;
#include "stack_L_T.h"

int main()
{
  cout << "testing operator==" << endl;
  Stack<int> t1, t2;
  cout << "Same when the 2 stacks are both empty" << endl;
  if(t1 == t2)
    cout << "Same" << endl;
  else
    cout << "Different" << endl;

  t1.push(1);
  t1.push(2);
  t1.push(3);
  t2.push(1);
  t2.push(2);
  t2.push(3);
  cout << "Same t1 = 3, 2, 1. t2 = 3, 2, 1." << endl;
  if(t1 == t2)
    cout << "Same" << endl;
  else
    cout << "Different" << endl;

  t1.pop();
  t1.push(4);
  cout << "Different t1 = 4, 2, 1. t2 = 3, 2, 1." << endl;
  if(t1 == t2)
    cout << "Same" << endl;
  else
    cout << "Different" << endl;

  Stack<int> t3;
  t3.push(0);
  t3.push(1);
  t3.push(2);
  t3.push(3);
  
  t1.pop();
  t1.push(3);

  cout << "Different t1 = 3, 2, 1. t3 = 3, 2, 1, 0" << endl;
  if(t1 == t3)
    cout << "Same" << endl;
  else
    cout << "Different" << endl;

  Stack<int> t4;
  t4.push(0);
  t4.push(1);
  t4.push(2);
  t4.push(3);
  
  cout << "Different t4 = 3, 2, 1, 0. t1 = 3, 2, 1" << endl;
  if(t4 == t1)
    cout << "Same" << endl;
  else
    cout << "Different" << endl;

  return 0;
}
