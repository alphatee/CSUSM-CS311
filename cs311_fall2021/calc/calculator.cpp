#include "stack_L_T.h"
#include<iostream>
#include<string>

/********************************************

                    Functions Declarations

*********************************************/

int priority_operator(const char& ch); //return priority number 

bool isa_operator(const char& ch); //returns true if is is an operator (+,-,*,/)

bool isa_operand(const char& ch); //returns true if ch is an operand (digit) 

template <class T>
string make_postfix(Stack<T>& s,string& infix); //convert from infix to postfix, returns postfix 

int evaluate_postfix(const int& opr1, const char& opt, const int& opr2); //return result of opr1 opt opr2

int char_to_int(const char& ch); //converts a character to integer (if a token is a digit)

/********************************************                                     
                    Functions Definitions
                                        
*********************************************/

int priority_operator(const char& ch)  //return priority number                                     
{
  if( ch == '+' or ch == '-') return 1;
  else if ( ch == '*' or ch == '/') return 2;
  //should I error handle? 
}                                                                                                                         

bool isa_operator(const char& ch) //returns true if is is an operator (+,-,*,/)                                                                                                                      
{
  /*
  for(int i = 0; i < infix.length(); ++i)
    {
      if( infix[i] == '+' ) return true;
      else if( infix[i] == '-' ) return true;
      else if( infix[i] == '+' ) return true;
      else if( infix[i] == '+' ) return true;
      else return false; 
    }
  */
  return (( ch == '+') or ( ch == '-') or ( ch == '*') or ( ch == '/')) ? true:false; 
}

bool isa_operand(const char& ch)  //returns true if ch is an operand (digit)                            
{                            
  return (ch >= '0' && ch <= '9') ? true : false;
}

template <class T>
string make_postfix(Stack<T>& s,string& infix) //convert from infix to postfix, returns postfix                                                                                                                    
{
  //loop (there are still tokens left in the expressions AND no error found) 
  //Do I want to make parameter const? Do I want to return reference obj
  string the_postfix = "";
  for(int i = 0; i < infix.length(); ++i)
    {
      if( !( isa_operator( infix[i] ) ) or !( isa_operand( infix[i] ) ) ) 
	{
	  throw "The expression is in a wrong format";
	}
      else if(isa_operator( infix[i] ))
	{
	  s.push(infix[i]);
     	}
      //another else if?
      else if( infix[i] == '(' )
	{
	  s.push(infix[i]);
	}
      else if( infix[i] == ')' )
	{
	  for(int j = i; j != '('; --j)
	    {
	      if( isa_operator(infix[j]) )
		{
      		  s.pop();
		  the_postfix += infix[j] ;
		}
		else if(infix[j] == '(' or infix[j] == ')')
		  {
		    s.pop();
		  }
	    } 
	}
      else //assuming no wrong chars given 
	{
	  the_postfix += infix[i];
	}
    }
  return the_postfix; 
}

int evaluate_postfix(const int& opr1, const char& opt, const int& opr2) //return result of opr1 opt opr2
{
  switch(opt)
    {
    case '+': return opr1 + opr2;
    case '-': return opr1 - opr2;
    case '*': return opr1 * opr2;
    case '/': return opr1 / opr2;
      //should I set default as an error check?
    }
}                                                                                                                      

int char_to_int(const char& ch) //converts a character to integer (if a token is a digit)      
{
  return ch - '0';
}

/********************************************                                                                                                                                                             
                    Main Function                                                                                                                                                                                                                     
*********************************************/			 							        


int main()
{ 
  //too much is happening. redo, baby steps

  //create a stack 
  
  string infix = ""; //empty string obj
  Stack<char> s; //can this be an int OR must it be a string
  string postfix = "";
  
  try
    {
      /*
	make_postfix();
	    throw "The expression is in the wrong format";
       */

        
        cin >> infix;
	postfix = make_postfix(s,infix);

	//evaluate_postfix(postfix); // return type is set to int
	cout << postfix; 
    }
  catch(Stack<int>::Underflow)
    {
      cout << "Error:The Stack is empty." << endl;
    }
  catch(const char* msg)
    {
      cout << msg << endl;
    }
    
  //maybe I do not have to do the code below
  //postfix += token; //token(char) is added to the end of postfix. string::operator+=(char c) is called here.



  // there is still more to do after the loop 
  return(0);
}
