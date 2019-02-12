// File: order.h

#ifndef ORDER_H
#define ORDER_H

#include "product.h"
#include "customer.h"

class Order : public Product, public Customer // Is this bad practice and should I have used Product::constructorName?
{
  public:
    Order()
    {
        this->quantity = 0;
        Product();
        Customer();
    }
    Order(Product product, int quantity, Customer customer)
    {
        this->product = product;
        this->quantity = quantity;
        this->customer = customer;
    }

  private:
    Product product;
    int quantity;
    Customer customer;

  public:
    Product getProduct()
    {
        return this->product;
    }
    int getQuantity()
    {
        return this->quantity;
    }
    Customer getCustomer()
    {
        return this->customer;
    }

    void setProduct(Product product);
    void setQuantity(int quantity);
    void setCustomer(Customer customer);

    std::string getShippingZip()
    {
        return getZip();
    }
    double getTotalPrice()
    {
        return Product::getTotalPrice();
    }
    void displayShippingLabel();
    void displayInformation();
};

// Create a class for an Order that has the following private data members:
// product : Product
// quantity : int
// customer : Customer
//
// It should also contain the following public methods:
// getProduct / setProduct
// getQuantity / setQuantity
// getCustomer / setCustomer
// getShippingZip - Returns the Zip from the customer's address
// getTotalPrice - Returns the total price of the product (including tax and shipping) multiplied by the quantity.
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
//
// It should also have the following constructors:
// Default - Set the quantity to 0 and uses the product and customer's default constructors.
// Non-default - Accepts a Product, quantity, and Customer

#endif
