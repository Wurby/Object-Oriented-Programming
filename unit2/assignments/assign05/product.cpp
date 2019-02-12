/***************************************************************
 * File: product.cpp
 * Author: Joshua Pearsob
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"
#include <string>
#include <iomanip>
#include <iostream>

/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
void  Product::prompt()
{
   std::string name;
   std::string description;
   double basePrice;
   double taxCost;
   double totalPrice;
   double weight;

   std::cout << "Enter name: ";
   getline(std::cin, name);
   this->name = name;

   std::cout << "Enter description: ";
   getline(std::cin, description);
   this->description = description;

   std::cout << "Enter weight: ";
   std::cin >> weight;
   this->weight = weight;

   Product::getPrice();
   Product::getTotalPrice();
}

/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
void Product::getPrice()
{
   bool check = false;
   do
   {
      std::cout << "Enter price: ";
      std::cin >> basePrice;
      if (std::cin.fail())
      {
         std::cin.clear();
         std::cin.ignore();
         check = false;
      }
      else if (basePrice < 1)
      {
         check = false;
      }
      
      else
      {
         check = true;
      }
      
   }
   while (!check);
   this->basePrice = basePrice;
}

/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
void Product::getSalesTax()
{
   this->taxCost = basePrice * .06;
}
/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
void Product::getShippingCost()
{
   int weightCounter = 0;
   double extraShippingCost = 0;
   double shippingCost = 2;
   if (this->weight > 5)
   {
      weightCounter = this->weight / 1 - 5;
      extraShippingCost = weightCounter * 0.10;
      shippingCost += extraShippingCost;
   }
   this->shippingCost = shippingCost;
}
/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
void Product::getTotalPrice()
{
   this->getSalesTax();
   this->getShippingCost();
   this->totalPrice = this->basePrice + this->shippingCost + this->taxCost;
}
/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
void Product::displayAdvertising()
{
   // Finding Peace, Happiness, and Joy by Richard G. Scott - $14.49
   // (Elder Scott powerfully outlines the truths we need to understand and
   // embrace in order to experience the gifts of peace, happiness, and joy.)

   std::cout.setf(std::ios::fixed);
   std::cout.setf(std::ios::showpoint);
   std::cout.precision(2);
   std::cout << this->name << " - $" << this->basePrice << std::endl;
   std::cout << "(" << this->description << ")" << std::endl;
}
/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
void Product::displayInventoryLine()
{
   // $14.49 - Finding Peace, Happiness, and Joy by Richard G. Scott - 1.5 lbs

   std::cout.setf(std::ios::fixed);
   std::cout.setf(std::ios::showpoint);
   std::cout.precision(2);
   std::cout << "$" << this->basePrice << " - " << this->name << " - ";
   std::cout.setf(std::ios::fixed);
   std::cout.setf(std::ios::showpoint);
   std::cout.precision(1);
   std::cout << this->weight << " lbs" << std::endl;
}
/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
void Product::displayReceipt()
{
   // Finding Peace, Happiness, and Joy by Richard G. Scott
   //    Price:         $   14.49
   //    Sales tax:     $    0.87
   //    Shipping cost: $    2.00
   //    Total:         $   17.36

   // remove tab at beginning, add spacing?
   std::cout << this->name << std::endl;
   std::cout.setf(std::ios::fixed);
   std::cout.setf(std::ios::showpoint);
   std::cout.precision(2);
   
   std::cout << "  Price:         $" << std::setw(8) << this->basePrice << std::endl;
   std::cout << "  Sales tax:     $" << std::setw(8) << this->taxCost << std::endl;
   std::cout << "  Shipping cost: $" << std::setw(8) << this->shippingCost << std::endl;
   std::cout << "  Total:         $" << std::setw(8) << this->totalPrice << std::endl;

}
