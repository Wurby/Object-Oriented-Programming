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

    std::cout << "Enter price: ";
    std::cin >> basePrice;
    this->basePrice = basePrice;
    
    Product::getSalesTax();
    Product::getShippingCost();
    Product::getTotalPrice();
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
    if (this->weight > 5)
        
}
/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
void Product::getTotalPrice()
{

}
/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
void Product::displayAdvertising()
{

}
/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
void Product::displayInventoryLine()
{

}
/***************************************************************
 * Name: 
 * Function: 
 ****************************************************************/
void Product::displayReceipt()
{

}
