/***********************************
Template created by Kazumi Slott
CS311
Stack implemented with a LL

Your name here: Daniel Herrera
Your programmer number here: 11
Any problems you had? Explain here:
 - Underflow is empty. How about Overflow? 
 --I understand that empty classes are sufficient in order to throw an object
 
 - How did you implement this program in just 3 lines?

 - Why use 'NULL' over 'nullptr'? 
 
 - Does my destory function work?
 -- Yes. one function call contains a loop that destroys releases each node back to OS. 

 - Why does while( tmp != NULL ) work but not while ( tmp->next != NULL ) ? 

---New questions
 - What is the difference between *this and this? 
******************************************************************************************************************/
#ifndef STACK_L_T_H
#define STACK_L_T_H

#include <iostream> 
using namespace std;

template < class T > //forward declaration needed so we can make stack class a friend of node
class Stack;

template < class T > //forward declaration needed so we can make operator<< a friend of node and Stack
ostream& operator<<(ostream& o, const Stack<T>& s);


template < class T >
class Node
{
  friend class Stack<T>; //Stack class accesses the private members of Node
  friend ostream& operator<< <T>(ostream& o, const Stack<T>& s); //operator<< accesses the private members of Node

 private:
  T  elem;
  Node*  next;
 public:
  Node(){next=NULL;} //default constructor
  Node(const T& e){elem = e; next = NULL;}
};

template <class T>
class Stack
{
  friend ostream& operator<< <T>(ostream& o, const Stack& s); //operator<< accesses the private members of Stack

 private:
 Node<T>*  top;
 int  size;

 //helper functions - private because they won't be called from client
  void destroy();
  void copy(const Stack& source);

 public:
  Stack() {top = NULL; size = 0;} //Implement a small function inside the class definition 
  Stack(const Stack& other);
  ~Stack();
  Stack& operator=(const Stack& rhs); //rhs = right hand side of the operator   LHS_obj = RHS_obj
  bool empty() const{return (top==NULL && size==0);} //implement a small function inside the class definition
  int getSize() const{return size;} //implement here
  void push (const T& val);
  void pop();
  T& getTop(); //Return type is T& so client can change the top value
  const T& getTop() const; //A const object needs to call a const member function

  //Make an exception class here - You need to figure out where to throw an exception - I am throwing in 3 functions                       
  class Underflow{}; 
};


template <class T>
void Stack<T>::push(const T& val)
{
       Node<T>* new_node = new Node<T>; //create new_node
       new_node->elem = val;             //set new value to elem of the new_node
       new_node->next = top;             //set new_node->next to point to address of top
       top = new_node;                   //set address of new_node to be the new top
       size++;                           //increment size of stack by 1
      //FYI, I have 4 lines of code here. You may have less or more.
}



template <class T>
void Stack<T>::pop()
{
  if(empty())
    {
      throw Underflow();
    }
  else 
    {
      Node<T>* temp;
      temp = top; //copy address of top to temp
      top = top->next; //set address of top->next as the new top
      delete temp;
      size--;
    }
}



template <class T>
T& Stack<T>::getTop()
{
  if(!empty()) return top->elem;  //return the top element. Since the return type is T&, the client can change the top.
  else
    {
      throw Underflow();
    }
}



//***************************************************
//********  You will make this after the next lecture
//***************************************************
template <class T>
const T& Stack<T>::getTop() const //it does the same thing. We needed this version for the reason down below
{
  if(empty()) throw Underflow(); 
  else 
    { 
      return top->elem; 
    }
  // same as the getTop() above. We need to provide this so a const object can call getTop(). Recall a const object can only call const member functions.
}



/*
//This function will show all the elements in the stack in the following format.
//cout << stackObj; <== This cout is calling the following function. same as operator<<(cout, stackObj); 
//Recall operator<< cannot be a member function because the LHS of the operator (<<) is not a stack object (it's cout, an ostream object). 
//     --- Top ---
//     2
//     1
//     --- Bottom ---
*/
template <class T>
ostream& operator<<(ostream& o, const Stack<T>& s)
{
  //print from top to bottom.
  Node<T>* tmp = s.top;
  cout << "--- Top ---" << endl;
  while(tmp != NULL)
    {
      o << tmp->elem << endl;
      tmp = tmp->next;
    }
  cout << "--- Bottom ---" << endl;

  return o;
}


template <class T>
Stack<T>::~Stack()
{
  destroy();
  //cout << "destroyed item in stack" << endl; 
}


//helper function - called from destructor and operator=

template<class T>
void Stack<T>::destroy() //This function will be called by destructor and operator=
{
  if ( top == NULL) return; 

  Node<T>* temp;
  while( top != NULL ) 
    {
      temp = top;
      top = top->next;
      delete temp;
    }
  return; 
}



//***************************************************
//********  You will make this after the next lecture
//***************************************************
template <class T>
Stack<T>& Stack<T>::operator=(const Stack& rhs) //rhs = right hand side of the operator
{
  //good reading from cal tech
  //http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html

  //deep copy

  //Check the addresses of the left and right objects. If they are the same, you are trying to assign the same object   s = s;
 //You copy only if the left object is not the same as the right object.

  if(this != &rhs)
    { 
      //destroy any memory space "this" is using. "this" may have elements already. call destroy
      //call copy 
      destroy(); 
      copy(rhs);
    }
  return *this; //return the "this" object 
}




//***************************************************
//********  You will make this after the next lecture
//***************************************************
//helper fuction. called from operator= and copy constructor
template <class T>
void Stack<T>::copy(const Stack& source) //source is the stack object copied from. 
{
  if(source.empty())

    {
      throw Underflow();
    }
  Node<T>* n; // n keeps track of movement of new list 
  Node<T>* temp = source.top; // temp moves through source 

  top = new Node<T>; // create 1st node of new list 

  top->elem = temp->elem;  // assign data to new node 

  top->next = NULL;  // cap list with NULL

  n  = top; // point n to top 

  size++;   //designate top as first node 

  temp = temp->next; // go to next node in source

  while(temp != NULL) //unless you hit NULL, do not stop
    {
      n->next = new Node<T>; //allocate new memory for new node

      n = n->next; // point n to new node

      n->elem = temp->elem; // copy data

      n->next = NULL; // set default for 'next' as NULL

      size++; //increment size as 1

      temp = temp->next; //move along source 
    }
  //"this" object ends up having the same values from source
  //Make sure this function won't crush when the source stack is empty   
}





//***************************************************
//********  You will make this after the next lecture
//***************************************************
//copy constructor
template <class T>
Stack<T>::Stack(const Stack& other) : top(NULL)
{
  //This is a copy constructor. This new object will get the same values as the other object. 
  //You still need to initialize the data members.
  Node<T>* n = NULL;

  //Then you can call the copy function
  copy(other); 
}



#endif // end the definition here
