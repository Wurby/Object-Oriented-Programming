/***************************************************************
 * File: assign05.cpp
 * Author: Joshua Pearson
 * Purpose: Contains the main function to test the Product class.
 ***************************************************************/

#include <iostream>
#include <string>


#include "product.h"

int main()
{
   Product product;

   product.prompt();


   std::cout << std::endl;
   std::cout << "Choose from the following options:\n";
   std::cout << "1 - Advertising profile\n";
   std::cout << "2 - Inventory line item\n";
   std::cout << "3 - Receipt\n";
   std::cout << std::endl;
   std::cout << "Enter the option that you would like displayed: ";

   int choice;
   std::cin >> choice;

   std::cout << std::endl;

   if (choice == 1)
   {
      product.displayAdvertising();
   }
   else if (choice == 2)
   {
      product.displayInventoryLine();
   }
   else
   {
      product.displayReceipt();
   }

   return 0;
}
