/******************************************
Template created by Kazumi Slott
CS311
Graph of social network implmemented with a matrix

Your name: Daniel Herrera
Your programmer number: 11
Outputs:
Any difficulties?:
********************************************/


#include <iostream>
using namespace std;

const int NUM = 8;

//Function Declarations

//until my proof of concept for these functions are complete, return type for all will be void
void find_friends(int matrix[][NUM], int stop, char friends[]);
char* check_row(int matrix[][NUM], int friend_index);
char find_letter(int number); //switch case
/*
  MY CUSTOM UTILITY FUNCTIONS
*/
void find_friends(int matrix[][NUM], int stop, char friends[])
{
    /*
    Note: when finished, change from copies to pass by reference

    might not need this function if I make a switch case function

    I made check_row a return char* therefore, assignment needs to be lhs of funct call
        also, that would mean find_friends also returns char* to main
   */
  for(int i = 0; i < stop; i++)
    {
      if(friends[i] - '0' == 18) // B
	{
	  check_row(matrix,i);
      	}
      if(friends[i] - '0' == 19) // C
	{
	  check_row(matrix,i);
      	}
      if(friends[i] - '0' == 21) // E
	{
	  check_row(matrix,i);
      	}
    }
}
char* check_row(int matrix[][NUM], int friend_index)
{
    /*
    Note: when finished, change from copies to pass by reference
   */
char refer[NUM];
int start = 0; //keeps tracks of refer friends index array

for(int i = friend_index; i < friend_index + 1; i++)
  {
    for(int j = 0; j < NUM; j++)
      {
	if(matrix[friend_index][j] == true and matrix[friend_index][0])
	  {
	    refer[start] = //code;
	      ++start;
	  }
      }
  }
//return refer;
}
//find_letter funct
char find_letter(int number)
{
  switch(number) {
  case 17 :
    return 'A';
  case 18 :
    return 'B';
  case 19 :
    return 'C';
  case 20 :
    return 'D';
  case 21 :
    return 'E';
  case 22:
    return 'F';
  case 23:
    return 'G';
  case 24:
    return 'H';
  default :
    cout << "Invalid Letter" << endl;
  }
}
/*
  END OF FUNCTIONS
 */
void printArray(char a[], int stop) //pass array
{
  //This would come in handy
  
  for(int i = 0; i < stop; i++)
    {
      	cout << a[i] << ' ';
    }
  cout << endl;
}

int main()
{
  const int stop = 3; //user can choose any stop value if they decide to change NUM
  //This program should still work even if we change NUM to 100 and change the matrix.

  //       row column  
  int m[NUM][NUM] = {{0, 1, 1, 0, 1, 0, 0, 0},//i = 0
			{1, 0, 1, 0, 0, 1, 1, 0},//i = 1
			{1, 1, 0, 0, 1, 1, 0, 0},//i = 2
			{0, 0, 0, 0, 1, 0, 0, 0},//i = 3
			{1, 0, 1, 1, 0, 1, 0, 1},//i = 4
			{0, 1, 1, 0, 1, 0, 0, 0},//i = 5
			{0, 1, 0, 0, 0, 0, 0, 0},//i = 6
			{0, 0, 0, 0, 1, 0, 0, 0} //i = 7
                       };  //Mij where i is row and j is column
  //A(0), B(1), ....

  //check if A and F are friends
  if(m[0][5] == 1)
    cout << "Yes" << endl;
  else
    cout << "No"  << endl;

  //Show all friends of A                                                                                                                                    
  cout << "{ ";                                              
  for (int i = 0;i < 1;i++)
    {
      for (int j = 0; j < NUM; j++)
        {
	  cout << m[i][j] << " ";
        }
    }
  cout << "}" << endl;

  char friends[NUM]; //store all A's direct friends                            
  if(m[0][1] == true)
    {
      friends[0] = find_letter('B' - '0'); //does the same as code below in the last 2 if statements
    }
  if(m[0][2] == true)
    {
      friends[1] = 'C';
    }
  if(m[0][4] == true)
    {
      friends[2] = 'E';
    }
  printArray(friends,stop);                                                                                                                              

  //Aswer: B, C, E                                                             
  cout << 'A' - '0'; //testing                                                                                                                             

  //refer A A's friends' direct friends                                                                                                                                                                     
  char refer[NUM]; //store referred friends for A                                                                                                                                                           
  //I made one more function to keep the loop small                                                                                                                                                         

  //Answer: D, F, G, H  (don't repeat the same person. Order doesn't matter)                                                                                                                                


  //Test your code above with a new matrix - the picture is in the document "Lec supplement - matrix for 11/15(Mon)" under "Assignments"                                                                    
  int m2[NUM][NUM] = {{0, 1, 0, 1, 1, 0, 0, 0},{1, 0, 1, 0, 0, 0, 0, 0},{0, 1, 0, 0, 1, 1, 0, 0},{1, 0, 0, 0, 1, 0, 0, 0},
                      {1, 0, 1, 1, 0, 0, 1, 0},{0, 0, 1, 0, 0, 0, 0, 1},{0, 0, 0, 0, 1, 0, 0, 1},{0, 0, 0, 0, 0, 1, 1, 0}};

  //A's friends -> B, D, and E                                                                                                                                                                              

  //friends referred to A -> C and G                                                                                                                                                                        

  /***** Sample run using m2 - my code ask for 2 perople. You don't need to.                                                                                                                                
[kslott@empress cs311]$ ./a.out                                                                                                                                                                             
Enter 1st name: F                                                                                                                                                                                           
Enter 2nd name: E                                                                                                                                                                                           
No, F and E are NOT friends                                                                                                                                                                                 
F is a friend with C H                                                                                                                                                                                      
The friends referred to F are B E G                                                                                                                                                                         
[kslott@empress cs311]$                                                                                                                                                                                     
  ********/

  return 0;
}


