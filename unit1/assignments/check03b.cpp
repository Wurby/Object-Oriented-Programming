/***********************************************************************
* Program:
*    Checkpoint 03b,           (e.g. Checkpoint 01a, review)  
*    Brother Dudley, CS165
* Author:
*    Joshua Pearson
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

int prompt();

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int number = 0;
   number = prompt();
   cout << "The number is: " << number << "." << endl;
   return 0;
}

int prompt()
{
   int number = 0;
   cout << "Enter a number: ";
   cin >> number;
   if (cin.fail())
   {
      cin.clear();
      cin.ignore(256, '\n');
      cout << "Invalid input." << endl;
      number = prompt();
   }
   return number;
}