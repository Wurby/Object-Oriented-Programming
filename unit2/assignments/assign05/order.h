// File: order.h

#ifndef ORDER_H
#define ORDER_H

#include "product.h"
#include "customer.h"


// Put your Order class here

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
