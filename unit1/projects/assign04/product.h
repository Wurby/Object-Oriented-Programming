/***************************************************************
 * File: product.h
 * Author: Joshua Pearsob
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
class Product
{
   private:
      std::string name;
      std::string description;
      double basePrice;
      double taxCost;
      double totalPrice;
      double weight;
   public:
      void prompt();
      void getSalesTax();
      void getShippingCost();
      void getTotalPrice();
      void displayAdvertising();
      void displayInventoryLine();
      void displayReceipt();
};

#endif
