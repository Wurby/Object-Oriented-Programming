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

 public:
   Product();
   Product(std::string name, std::string description, double basePrice, double weight);
   void setBasePrice(double price);
   void setSalesTax(double price);
   void setShippingCost(double price);
   void setTotalPrice(double price);
   void setName(std::string name);
   void setDescription(std::string description);
   void setWeight(double weight);
   void prompt();
   double getBasePrice();
   double getSalesTax();
   double getShippingCost();
   double getTotalPrice();
   void displayAdvertising();
   void displayInventory();
   void displayReceipt();
   std::string getName();
   std::string getDescription();
   double getWeight();
};

#endif
