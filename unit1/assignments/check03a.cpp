/***********************************************************************
* Program:
*    Checkpoint 03a, Exceptions          (e.g. Checkpoint 01a, review)  
*    Brother Dudley, CS165
* Author:
*    Joshua Pearson
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>

int prompt();

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int number = 0;
   number = prompt();

   std::cout << "The number is " << number << std::endl;

   return 0;
}

// Function: prompt
// Purpose: does tigs and throws errors when wrong.
int prompt()
{
   int number = 0;
   std::cout << "Enter a number: ";
   std::cin >> number;
   try 
   {
      if (number < 0)
         throw std::string("The number cannot be negative.");
      if (number > 100)
         throw std::string("The number cannot be greater than 100.");
      if (number % 2 > 0)
         throw std::string("The number cannot be odd.");

      return number;
   }
   catch(const std::string message)
   {
      std::cout << "Error: " << message << std::endl;
   }
}