
/****************
Template created by Kazumi Slott
CS311

Your name: Daniel Herrera
Your programmer number: 11
Any difficulties?: ??????
HOW does the forward declarations work on templates?
How does the template argument work with friend class?

How do you replace a string with a new string? 

I discovered: 

When you want to replace every instance of a given string, you can use a simple command that tells Emacs to do just that. 
Type ESC x replace-string RETURN, then type the search string and press RETURN. 
Now type the replacement string and press RETURN again.

//clean up all use of string "root" with "p" in private methods!
*****************/

#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <queue> //AVL2 BFT
#include <stack>
using namespace std;

//forward declaration of AVL class. We need this because AVL class is used as a friend in Node. 
//Check your stack_L_T.h if you don't know what to put here.
template<class T>
class AVL; 

template<class T> 
class Node;

//Make Node and AVL template classes.
//You put the class definition and member function implementations in .h when you use template.  
//If you don't know how to make them template,
//Check page 3 of CS211 "Lec Notes on Exception Handling". I have a template stack class there.
//Also you made stack_L_T.h using template at the beginning of this semester.

template<class T>  //make it a templare class
class Node
{
  friend class AVL<T>; //AVL wants to access private members of Node
private:
  T el;
  Node* right;
  Node* left;
  //add 2 data members & update constructor
  //up & BF (balance factor)
  int BF;
  Node* up; 
public:
  Node() {right = left = up = NULL;BF = 0;} //default constructor. set right and left to NULL
  Node(const T& e){ el = e; left = right = up = NULL;BF = 0;}; 
  T getEl() const {return el;} //returns el
};

template<class T> //Make it a template class
class AVL
{
private:
  Node<T>* root; //check stack_L_T.h to see how to declare top

  void inOrderPrint(Node<T>* p);
  void destroy(Node<T>* p);
  int getMaxLength(Node<T>* p);
  // These 4 are new additions
  Node<T>* rightRotation(Node<T>* P);
  Node<T>* leftRotation(Node<T>* P);
  void balanceTree(Node<T>* P);
  Node<T>* updateBF(Node<T>* Q);

 public:
  AVL() {root = NULL;} //implement constructor here
  ~AVL(); 
  void insertNodeI(const T& e);
  void inOrderPrint();
  void BFTprint();  //Breadth First Traversal Print
  int getMaxLength();
};

//implement the member functions in the header if you are making a template class


//destructor.
//If you don't know how to make the destructor, check the following
//CS211 Lec notes on AVL recursive functions - destroy and in order traversal
//CS211 Lecture recording - Lecture 4/28(Wed) - AVL:: inOrderPrint(), destroy()

template<class T> 
AVL<T>::~AVL()
{
  destroy(root);
}

template<class T>
void AVL<T>::destroy(Node<T>* p) //private function. WHY?
{ 
  //destroy all nodes
  if( p == NULL ) return;
  destroy(p->left);
  destroy(p->right);
  // cout << p->el << "-->"; //debugger
  delete p;
}

//This is an insert function using iteration.
//You will see insert function using iteration is unwieldy compared to that using recursion above.
//The hemework document "HMWK AVL - reveiw of cs211" has a diagram to show how this function works.
template <class T>
void AVL<T>::insertNodeI(const T& e)
{
  Node<T>* newNode = new Node<T>(e); //make a new node.  Check stack_L_T.h to see how you made a new node.
  Node<T>* p = root; //I modified root as root in my implementation
  Node<T>* parent = NULL; //points to the parent of p. 

  //move p to NULL
  while(p != NULL)
    {
      //parent points to the parent node while p points to the left or right child.
      parent = p; //we need parent for later after while loop 
      if(e < p->el) 
	p = p->left; 
      else //p->el >= e
	p = p->right;
    }
  
  if(parent == NULL)
    {
      root = newNode; //the parent is the root, which is the new first node
    }
  else if(e < parent->el)
    {
      parent->left = newNode; //new Node<T>(e);
    }
  else
    {
      parent->right = newNode; // new Node<T>(e);
    }
  newNode->up = parent;
  balanceTree(newNode);//of course it is segmentation fault. this does not work yet
}



//If you don't how to make this, check the following
//CS211 Lec notes on AVL recursive functions - destroy and in order traversal
//CS211 Lecture recording - Lecture 4/28(Wed) - AVL:: inOrderPrint(), destroy()

template <class T>
void AVL<T>::inOrderPrint()
{
  return inOrderPrint(root);
}

template <class T> //private function. WHY?
void AVL<T>::inOrderPrint(Node<T>* p)
{
  if( p == NULL)
    return;
  inOrderPrint(p->left);
  cout << p->el << "-->";
  inOrderPrint(p->right); 
}
/****************************************************************************************************                                                                                                    
//getMaxLength() public and private methods                                                                                                                                                              
/*****************************************************************************************************/
//This function return the maximum length from the root. If there is only one node, this function returns 1.                                                                                              
template <class T>
int AVL<T>::getMaxLength()
{
  return getMaxLength(root);
}

template <class T>
int AVL<T>::getMaxLength(Node<T>* p) //private function. Why?                                                                                                                                             
{
  if ( p == NULL ) return(0);

  int L = getMaxLength(p->left);
  int R = getMaxLength(p->right);

  //two subtrees L && R                                                                                                                                                                                   
  if( L > R )
    {
      return L+ 1; //since it does not record the root, add 1                                                                                                                                             
    }
  else
    {
      return R + 1;
    }
}
/****************************************************************************************************
//BELOW IS AVL2.h 
/*****************************************************************************************************/

template <class T>
void AVL<T>::BFTprint()  //Breadth First Traversal Print
{
  //Use the library's queue. https://www.google.com/url?client=internal-element-cse&cx=000747561938282180878:lrfgxurgbda&q=https://www.cplusplus.com/reference/queue/queue/&sa=U&ved=2ahUKEwimjMj9v-nzAhXDC\jQIHXeYDm8QFnoECAUQAQ&usg=AOvVaw3vUfDpaPV6Q--9naQsl681

  //Make sure to include <queue> at the top
  //create a queue obj of pointers to Nodes
  queue<Node<T>*> q; //queue object

  q.push(root);

  Node<T>* p = root; //pointer for travse
  //algorithm is discussed in lecture
  /*
    IMPLEMENTATION NOTE: None of the lecture recordings have queue algorithm explained. 
    I ASSUMED the process was the same but opposite(i.e., push left first then push right for queue).
   */
  while(!(q.empty()))
    {
      p = q.front();
      if(p->up == NULL)
	{
	  cout << p->el << ' ' << p->BF << ' ' <<  "-->"; //show el, BF and up->el
	}
      else
	{
	  cout << p->el << ' ' << p->BF << ' ' << p->up <<  "-->"; //show el, BF and up->el
	}

      if(q.front()->left != NULL)
	{
	  q.push(q.front()->left);
	}
      if(q.front()->right != NULL)
	{
	  q.push(q.front()->right);
	}
        q.pop(); //remove front element
    }
  //NOTICE
  //front() gives you the front element but it doesn't remove it from the queue.
  //pop() removes the front element
}

template <class T>
void AVL<T>::balanceTree(Node<T>* P) 
{
  
    P =  updateBF(P);
    Node<T>* tmp;
    Node<T>* parent; //stores old root for end of func
    if(P == NULL) return; //no need to balance tree
    //figure out if P(the root of the subtree that needs to be fixed) comes from left or right of its parent or root. 
    //if(
    parent = P->up;
    //There are 4 types of violations. LL, RR, LR, or RL. Check my lecture nodes for the diagrams. For each type, call rotateRight(), rotateLeft() or both.
    //LL
    if(P->BF == 2 && P->left != NULL && P->left->BF == 1) // à Which type of violation?
      {
	tmp = rightRotation(P);
      }
    //RR
    if(P->BF == -2 && P->right != NULL && P->right->BF == -1) //opposite of violation above
      {
	tmp = leftRotation(P); 
      }
    //LR
    if(P->BF == 2 && P->left != NULL && P->left->BF == -1)
      {
	//final iteration, cleaner, and reverse of process for RL
	P->left = leftRotation(P->left);
	tmp = P->left->up;
	tmp->left = P->left;
	tmp = rightRotation(P);
	/*
	Node<T>* tmp = P->left;
	Node<T>* tmp2 = tmp->right;
	tmp2 = leftRotation(tmp2);
      	tmp = rightRotation(tmp);
        */

	//my attempt to move around the fixed part 
	/*
	Node<T>* fixed = P->right;
	P = leftRotation(P);
      	P = rightRotation(P);
	P->right->right = fixed;
	*/ 
    }
    //RL
    if(P->BF == -2 && P->right != NULL && P->right->BF == 1)
      {
	/*
      	Node<T>* tmp = P->right;
	Node<T>* tmp2 = tmp->left;	
      	tmp2 = rightRotation(tmp2);
	tmp = leftRotation(tmp);
        */

        P->right = rightRotation(P->right); //pass right node
	tmp = P->right->up; //store before lost ptr
	tmp->right = P->right; // bring back prev ptr
	tmp = leftRotation(P); //tmp - > new root
      }

    //Don’t forget to attach the fixed subtree to the parent or root
    //attach parent left or right to the new root because when I rotate
    //the root changes so the parent is attached to the old root
    if(root == P) 
      {
	root = tmp;
      }
    if(parent->right == P)
      {   //means the root is P and the left subtree is missing
	  //P->up->left = P->left; //attach 'L' 'R' 'T'
	parent->right = tmp; //attach left subtree to left side of parent                  
      }
    else //P is on the left side of the tree 
      {
	parent->left = tmp;
      }
}
//newNode points to the newly added node
/*
    call updateBF() //The algorithm is in my lecture notes. Use that.
    If updateBF() returns NULL, no need to balance the tree
    figure out if P(the root of the subtree that needs to be fixed) comes from left or right of its parent or root.
  
    There are 4 types of violations. LL, RR, LR, or RL. Check my lecture nodes for the diagrams. For each type, call rotateRight(), rotateLeft() or both.
  
    Don’t forget to attach the fixed subtree to the parent or root
*/
template <class T>
Node<T>* AVL<T>::updateBF(Node<T>* Q)
{
  Node<T>* P;
  P->right = Q; //p is parent of Q
  Q->up = P;

  if(Q == P->left) //if Q is the left child of P  //NOTE I know the reasoning is correct
    {
      P->BF++;
    }
  else
    {
      P->BF--;
    }

  while((P != root) and ((P->BF != 2) or (P->BF != -2))) // while p is not the root and p->balanceFactor is not +-2
	{
	  Q = P;
	  P = P->right;//P = p's parent //NOT SURE???

	  if(Q->BF == 0)
	    {//return NULL if there is no violation
	      return NULL; //because the tree is still balanced after insertion A. There was a child under
	      //this node. The new inserted node completed this parent node. 
	    }
	  if(Q == P->left) //if Q is the left child of P //NOTE: reasoning is solid
	    {
	      P->BF++;
	    }
	  else
	    {
	      P->BF--;
	    }
	}

  //go out of while because P reached root or P->BF is +-2
  if((P->BF == 2) or (P->BF == -2)) //if p->balanceFactor is +-2
    {
      balanceTree(P);//rebalance the subtree rooted at P
    }
}
/*
return the pointer to the node with a violation.
OR
return NULL if there is no violation.
*/
template <class T>
Node<T>* AVL<T>::rightRotation(Node<T>* p)
{
  if(p == NULL or root == NULL) return NULL; //check if p and root is empty
  if(p->left == NULL or root->right == NULL) return NULL; //check if children exist 
  
  Node<T>* tmp;

  root = p->left; 
  tmp = root->right;

  //old root p
  //3rd operation 
  root->right = p;

  //4th operation 
  p->left = tmp;

  root->up = p->up; //set your up
  root->BF = getMaxLength(root->left) - getMaxLength(root->right);
  
  return root;
}
template <class T>
Node<T>* AVL<T>::leftRotation(Node<T>* p)
{
  if(p == NULL or root == NULL) return NULL; //check if p and root is empty
  if(p->right == NULL or root->left == NULL) return NULL; //check if children exist 
  Node<T>* tmp; 

  //NULL checks before executing following two lines of code
  //these next 2 lines do the setup
  root = p->right; //give root the address stored at p->right
  tmp = root->left; // give tmp the address stored at root->left
    
  //operation 1
  root->left = p;
  //operation 2
  p->right = tmp;
  //when do i do this?

  root->up = p->up; //set your up
  root->BF = getMaxLength(root->left) - getMaxLength(root->right);
  
  return root;
}
/*
Don't forget to change up and BF as well appropriate pointers.
This function returns the new root.
Check the YouTube video on AVL you watched. He gives you a simplified algorithm for
this. I have 10 lines of code in this function. 
*/
#endif
