/***********************************************************************
* Program:
*    Checkpoint 01b, C++ BASICS          (e.g. Checkpoint 01a, review)  
*    Brother Dudley, CS165
* Author:
*    Joshua Pearson
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

int getSize();
void getList(int size, int * list);
void displayMultiples(int size, int list[]);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int size = getSize();
   int list[size];
   int * plist = list;
   getList(size, plist);
   displayMultiples(size, plist);

   return 0;
}

int getSize()
{
   int size = 0;
   cout << "Enter the size of the list: ";
   cin >> size;
   return size;
}

void getList(int size, int * list)
{
   for (int i = 0; i < size; i++)
   {
      cout << "Enter number for index " << i << ": ";
      cin >> list[i];
   }
   cout << endl;
}

void displayMultiples(int size, int * list)
{
   cout << "The following are divisible by 3:\n";
   for (int i = 0; i < size; i++)
   {
      if (list[i] % 3 == 0)
      {
         cout << list[i] << endl;
      }
   }
}