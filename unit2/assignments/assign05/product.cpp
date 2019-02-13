/***************************************************************
 * File: product.cpp
 * Author: Joshua Pearsob
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"
#include <string>
#include <iomanip>
#include <iostream>

Product::Product()
{
   this->name = "none";
   this->description = "";
   this->basePrice = 0;
}
Product::Product(std::string name, std::string description, double basePrice, double weight)
{
   this->name = name;
   this->description = description;
   this->basePrice = basePrice;
   this->weight = weight;
}

void Product::setBasePrice(double price)
{
   this->basePrice = price;
}
void Product::setSalesTax(double price)
{
   this->taxCost = price;
}
void Product::setShippingCost(double price)
{
   this->shippingCost = price;
}
void Product::setTotalPrice(double price)
{
   this->totalPrice = price;
}
void Product::setName(std::string name)
{
   this->name = name;
}
void Product::setDescription(std::string description)
{
   this->description = description;
}
void Product::setWeight(double Weight)
{
   this->weight = Weight;
}

/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
void Product::prompt()
{
   std::string name;
   std::string description;
   double basePrice;
   double taxCost;
   double totalPrice;
   double weight;

   std::cout << "Enter name: ";
   getline(std::cin, name);
   setName(name);

   std::cout << "Enter description: ";
   getline(std::cin, description);
   setDescription(description);

   std::cout << "Enter weight: ";
   std::cin >> weight;
   setWeight(weight);

   basePrice = getBasePrice();
   totalPrice = getTotalPrice();
}

/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
double Product::getBasePrice()
{
   // bool check = false;
   // double price = 0;
   // do
   // {
   //    std::cout << "Enter price: ";
   //    std::cin >> price;
   //    if (std::cin.fail())
   //    {
   //       std::cin.clear();
   //       std::cin.ignore(256, '\n');
   //       check = false;
   //    }
   //    else if (price < 1)
   //    {
   //       check = false;
   //    }
   //    else
   //    {
   //       check = true;
   //    }
   // } while (!check);

   return this->basePrice;
}

/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
double Product::getSalesTax()
{
   return basePrice * .06;
}
/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
double Product::getShippingCost()
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
   if (this->weight == 0)
   {
      shippingCost = 0;
   }
   return shippingCost;
}
/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
double Product::getTotalPrice()
{
   // this->taxCost = getSalesTax();
   // this->shippingCost = getShippingCost();
   return this->basePrice + this->shippingCost + this->taxCost;
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
void Product::displayInventory()
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

std::string Product::getName()
{
   return this->name;
}
std::string Product::getDescription()
{
   return this->description;
}
double Product::getWeight()
{
   return this->weight;
}