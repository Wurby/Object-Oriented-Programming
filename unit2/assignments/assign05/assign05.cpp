/*****************************************************************
 * File: assign05.cpp
 * Purpose: This main function will exercise all the classes of
 *    this project.
 *
 * You may comment out certain parts while you are working on the
 * program, but you should make sure it is all present when you
 * submit.
 *****************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

#include "order.h"
#include "product.h"
#include "address.h"
#include "customer.h"

int main()
{
   ///////////////////////////////////////
   // Address Class
   ///////////////////////////////////////
   std::cout << "*** ADDRESS ***\n";
   std::cout << "Default constructor:\n";
   Address home;
   home.display();
   std::cout << std::endl;

   std::cout << "Getters/Setters:\n";
   home.setStreet("Bag End");
   home.setCity("The Shire");
   home.setState("ME");
   home.setZip("12345");

   std::cout << "Street: " << home.getStreet() << std::endl;
   std::cout << "City: " << home.getCity() << std::endl;
   std::cout << "State: " << home.getState() << std::endl;
   std::cout << "Zip: " << home.getZip() << std::endl;
   std::cout << std::endl;

   std::cout << "Display:\n";
   home.display();
   std::cout << std::endl;

   std::cout << "Non-default constructor:\n";
   Address hotel("The Prancing Pony", "Bree", "BR", "99999");

   hotel.display();
   std::cout << std::endl;

   /////////////////////////////////////////
   // Customer Class
   /////////////////////////////////////////
   std::cout << "*** CUSTOMER ***\n";
   std::cout << "Default constructor:\n";
   Customer frodo;
   frodo.display();
   std::cout << std::endl;

   std::cout << "Getters/Setters\n";
   frodo.setName("Frodo Baggins");
   frodo.setAddress(home);

   std::cout << "Name: " << frodo.getName() << std::endl;
   std::cout << "Address:\n";
   frodo.getAddress().display();
   std::cout << std::endl;

   std::cout << "Non-default constructor:\n";
   Customer gandalf("Gandalf the Grey", hotel);
   gandalf.display();
   std::cout << std::endl;

   /////////////////////////////////////////////
   // Product Class
   /////////////////////////////////////////////
   std::cout << "*** PRODUCT ***\n";
   std::cout << "Default constructor:\n";
   Product theRing;
   theRing.displayAdvertising();
   std::cout << std::endl;

   std::cout << "Getters/Setters:\n";
   theRing.setName("Ring of Power");
   theRing.setDescription("One Ring to bring them all and in the darkness bind them");
   theRing.setWeight(1);
   theRing.setBasePrice(999);

   std::cout.setf(std::ios::fixed);
   std::cout.setf(std::ios::showpoint);
   std::cout.precision(2);

   std::cout << "Name: " << theRing.getName() << std::endl;
   std::cout << "Description: " << theRing.getDescription() << std::endl;
   std::cout << "Weight: " << theRing.getWeight() << std::endl;
   std::cout << "BasePrice: " << theRing.getBasePrice() << std::endl;
   std::cout << std::endl;

   std::cout << "Non-default constructor:\n";
   Product staff("Wizard Staff", "More than just a walking stick", 100, 10);

   std::cout << "\nAdvertising:\n";
   staff.displayAdvertising();

   std::cout << "\nInventory:\n";
   staff.displayInventory();

   std::cout << "\nReceipt:\n";
   staff.displayReceipt();
   std::cout << std::endl;

   ////////////////////////////////////
   // Order Class
   ////////////////////////////////////
   std::cout << "*** ORDER ***\n";
   std::cout << "Default constructor:\n";
   Order orderRing;
   orderRing.displayInformation();
   std::cout << std::endl;

   std::cout << "Getters/Setters:\n";
   orderRing.setProduct(theRing);
   orderRing.setQuantity(1);
   orderRing.setCustomer(frodo);

   std::cout << "Product:\n";
   orderRing.getProduct().displayReceipt();
   std::cout << "Quantity: " << orderRing.getQuantity() << std::endl;
   std::cout << "Customer:\n";
   orderRing.getCustomer().display();
   std::cout << "Shipping Zip: " << orderRing.getShippingZip() << std::endl;
   std::cout << "TotalPrice: " << orderRing.getTotalPrice() << std::endl;
   std::cout << std::endl;

   std::cout << "Non-default constructor:\n";
   Order orderStaff(staff, 2, gandalf);

   std::cout << "Display Shipping Label:\n";
   orderStaff.displayShippingLabel();

   std::cout << "\nDisplay Information:\n";
   orderStaff.displayInformation();

   return 0;
}
