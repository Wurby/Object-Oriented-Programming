/***************************************************************
 * File: product.h
 * Author: Joshua Pearsob
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>


// Add the following to your Product class:
// getName / setName
// getDescription / setDescription
// getBasePrice / setBasePrice
// getWeight / setWeight
//
// Default Constructor- Set the name to "none", description to "", and the weight and the base price to 0.
// Non-default - Accepts all four of these values (name, description, basePrice, weight) and sets them.

class Product
{
   private:
      std::string name;
      std::string description;
      double basePrice;
      double taxCost;
      double shippingCost;
      double totalPrice;
      double weight;
      void getPrice();
      void getSalesTax();
      void getShippingCost();
      void getTotalPrice();
   public:
      void prompt();
      void displayAdvertising();
      void displayInventoryLine();
      void displayReceipt();
};

#endif
