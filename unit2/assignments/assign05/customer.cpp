// File: customer.cpp

#include "customer.h"
#include <iostream>

void Customer::setName(std::string name)
{
    this->name = name;
}
void Customer::setAddress(Address address)
{
    this->address = address;
}

void Customer::display()
{
    std::cout << this->name << std::endl;
    Address::display();
}
