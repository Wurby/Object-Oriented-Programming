/***********************************************************************
* Program:
*    Checkpoint ###, ????          (e.g. Checkpoint 01a, review)  
*    Brother Dudley, CS165
* Author:
*    Joshua Pearson
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>

/**********************************************************************
 * Class: Book
 * Purpose: has title, author variables and prompt and display methods
 ***********************************************************************/
class Book
{
   private:
      std::string author;
      std::string title; 
   public:
      void prompt();
      void display();
};

/**********************************************************************
 * Function: Prompt
 * Purpose: prompts for title and author
 ***********************************************************************/
void Book :: prompt()
{
   std::cout << "Title: ";
   std::cin >> title;
   std::cout << "Author: ";
   std::cin >> author;
}
/**********************************************************************
 * Function: Display
 * Purpose: displays the above stored variable data.
 ***********************************************************************/
void Book :: display()
{
   std::cout << "\"" << title << "\"" << " by " << author << std::endl;
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   Book book;
   book.prompt();
   book.display();

   return 0;
}
