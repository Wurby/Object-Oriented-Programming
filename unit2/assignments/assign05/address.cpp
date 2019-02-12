// File: address.cpp

#include "address.h"
#include <iomanip>
#include <string>
#include <iostream>

// Ready for testing.

void Address::display()
{
    std::cout << this->street << std::endl;
    std::cout << this->city << ", " << this->state << " " << this->zip;
}

void Address::setState(std::string state)
{
    this->state = state;
}
void Address::setStreet(std::string street)
{
    this->street = street;
}
void Address::setZip(std::string zip)
{
    this->zip = zip;
}
void Address::setCity(std::string city)
{
    this->city = city;
}