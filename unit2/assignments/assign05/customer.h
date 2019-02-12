// File: customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "address.h"

class Customer : public Address // Is this bad practice and should I have used Product::constructorName?
{
  public:
    Customer()
    {
        name = "unspecified";
        Address();
    }
    Customer(std::string name, Address address)
    {
        this->name = name;
        this->address = address;
    }

  private:
    std::string name;
    Address address;

  public:
    std::string getName()
    {
        return this->name;
    }
    Address getAddress()
    {
        return this->address;
    }
    void setName(std::string name);
    void setAddress(Address address);

    void display();
};

// Create a class for a Customer that has the following private data members:
// name : string
// address : Address
//
// It should also contain the following public methods:
// getName / setName
// getAddress / setAddress
// display - Displays the name, then calls the address's display method. Thus the format is:
//
// name
// street
// city, state zip
//
// It should also have the following constructors:
// Default - Set the name to "unspecified" and uses the address's default constructor.
// Non-default - Accept a name and an address object.

#endif
