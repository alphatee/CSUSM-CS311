/************************************
Template created by Kazumi Slott
CS311
Homework on radix sort

Description of this program: ?????
Your name: Daniel Herrera
Your programmer number: 11
Any difficulties?: ?????
************************************/

#include <iostream>
#include <fstream>

using namespace std;

const int LEN = 3; //the length of words
const int ALPHABET = 26; //total number of letters

class Node
{
  friend class LL;
private:
  string el;
  Node* next;
public:
  Node(const string& s){el = s; next = NULL;}
  string getElem() const {return el;}
};

class LL
{
private:
  Node* front;
  Node* rear;
  int num;
public:
  LL(){front = rear = NULL; num = 0;}
  ~LL();
  bool empty()const{return (front == NULL && rear == NULL && num == 0);}
  void addRear(const string& s);
  void addRear(Node* p);
  void append(const LL& other);
  void clear(){front = rear = NULL; num = 0;}
  Node* begin() const{return front;}
  Node* goToNext(Node* curr) const{return curr->next;}
  int size() const{return num;}
};

LL::~LL()
{
  cout << "destructor is called" << endl;
  Node* p = front;
  while(!empty())
    {
      front = front->next;
      delete p;
      p = front;
      if(front == NULL)
	rear = NULL;
      num--;
    }
}

//add a new node at the end of this list. The element of the new node is s.
void LL::addRear(const string& s)
{
  //This function is just like what you made in LL class from CS211.
  Node* p = new Node(s);

  if(empty())
    front = rear = p;
  else
    {
      rear->next = p;
      rear = rear->next;
    }    
  num++;
}

//Implementing this function
//add the node pointed to by p (p points to one of the nodes in all list) at the end of this list
void LL::addRear(Node* p) //confidence 10/10
{
  //Don't make a new node.

  //You need a special case when the list is empty
  if(empty())
    front = rear = p;
  else 
    {
      rear->next = p;
      rear = rear->next;
    }
  //you don't need to place NULL in the next field of the rear node of this list.
  num++;
  //don't forget to increment num

}

//Implement this function
//appending another linked list at the end of this linked list 
void LL::append(const LL& other) //confidence 10/10
{
  //Don't forget to update num of this list
  LL* temp = new LL(other); //create a new list to append at the end of linked list
  this->rear = temp->front; //attach the end of list to the head of the 'other' list 
  
  //close the end of this list by putting NULL in the next field of the rear node
  temp->rear = NULL; //store NULL @ temp->rear 
  rear = temp->rear; //assign rear address @ temp->rear

  num++; //increment the number of lists
}

void radixSort(LL& all);
void makeLL(LL& all, const string a[], int n);
void printLL(const LL& l);
void checkBuckets(const LL buckets[], int n);
void combineLists(LL& all_lists,LL buckets[]);
void makeLL(LL& all);

int main()
{
  LL all; //holds all words
  makeLL(all); //all contains strings in the original order
  radixSort(all);
  cout << "Final result ----" << endl;
  printLL(all); //all contains strings in sorted sorter
  cout << endl;

  return 0;
}

//Implement this function
//using the radix sort algorithm to sort strings that contain lowercase letters. 
void radixSort(LL& all)
{
  //Each slot of the buckets array is a LL object.
  //??? buckets[ALPHABET]; //bucket[0] is for 'a'. There are 26 buckets.   

  //checking each place
  //To go through each string in all list, check printLL() to see how to iterate
  //go to the correct bucket depending on the letter at the current place and add the node from the all list at the end of the bucket 
}

//Implement this function
//combining all lists from buckets
void combineLists(LL& all_lists,LL buckets[]) //redundant and convoluted
{
   int i = 0; //start index of buckets 
   Node* temp; //iterator for while loop
   temp = all_lists.begin(); //assign the head address of all_lists to temp
   
   //call clear() to reset the all list. All the nodes went to correct buckets already.
   all_lists.clear();
   //populate the all list by combining the lists from the buckets by calling append()
   while(temp != NULL) //keep looping until the end of the list
     {
       all_lists.append(buckets[i]); //append to all_lists by combining each  list from the buckets
       ++i; //move along buckets by 1
       temp = all_lists.goToNext(temp);
     } 
  //reset each list in b[i] by calling clear(). All the nodes were moved to all list already.
   i = 0; //reset counter 
   temp = buckets->goToNext(temp);
   while (temp != NULL)
     {
       buckets[i].clear();
       ++i; //move along buckets til the end of list
       temp = buckets->goToNext(temp);
     }
}

//Make a linked list of words from an input file  
void makeLL(LL& all)
{
  string s;  
  fstream fin;
  fin.open("radix.in");

  fin >> s;
  while(fin)
    {
      all.addRear(s);
      fin >> s;
    }
}

//This function shows the contents of all the buckets
void checkBuckets(const LL buckets[], int n)
{
  for(int i = 0; i < n; i++)
    {
      cout << i << ": ";
      printLL(buckets[i]);
      cout << endl;
    }
}

//This function prints all the elements in l
void printLL(const LL& l)
{
  int i;
  Node* p;

  //iterate l from the first node to last node
  for (i = 0, p = l.begin(); i < l.size(); i++, p = l.goToNext(p))
    cout << p->getElem() << ' ';
}

