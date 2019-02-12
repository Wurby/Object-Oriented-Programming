// File: order.cpp

#include "order.h"
#include <iostream>

// Put your the method bodies for your order class here
void Order::setProduct(Product product)
{
    this->product = product;
}
void Order::setQuantity(int quantity)
{
    this->quantity = quantity;
}
void Order::setCustomer(Customer customer)
{
    this->customer = customer;
}

void Order::displayShippingLabel()
{
    Customer::display();
}

void Order::displayInformation()
{
    std::cout << Customer::getName() << std::endl;
    std::cout << Product::getName() << std::endl;
    std::cout << "Total Price: $" << Product::getTotalPrice() << std::endl;
}

// displayShippingLabel - Calls the customer's display method, resulting in this format:
//
// name
// street
// city, state zip

// displayInformation - Displays the customer's name, the product's name, and the total price of the order in this format (substituting for the correct values):
//
// customerName
// productName
// Total Price: $xx.xx
