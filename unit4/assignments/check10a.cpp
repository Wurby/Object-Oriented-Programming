/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Dudley, CS165
* Author:
*    Joshua Pearson
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/

#include <vector>
#include <iostream>
#include <string>

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   std::vector<int> ints;
   std::vector<std::string> strings;
   int enteredInt;
   std::string enteredString;

   do
   {
      std::cout << "Enter int: ";
      std::cin >> enteredInt;
      if (enteredInt != 0)
         ints.push_back(enteredInt);
   } while (enteredInt != 0);

   std::cout << "Your list is: " << std::endl;
   for (std::vector<int>::iterator it = ints.begin(); it != ints.end(); ++it)
   {
      std::cout << *it << std::endl;
   }

   do
   {
      std::cout << "Enter string: ";
      std::cin >> enteredString;
      if (enteredString != "quit")
         strings.push_back(enteredString);
   } while (enteredString != "quit");

   std::cout << "Your list is: " << std::endl;
   for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); ++it)
   {
      std::cout << *it << std::endl;
   }

   return 0;
}
