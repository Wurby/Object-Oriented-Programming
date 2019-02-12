// File: address.h
#include <string>

#ifndef ADDRESS_H
#define ADDRESS_H

// Ready for testing.

class Address
{
 private:
   std::string street;
   std::string city;
   std::string state;
   std::string zip;

 public:
   Address()
   {
      street = "unknown";
      city = "";
      state = "";
      zip = "00000";
   }
   Address(std::string street, std::string city, std::string state, std::string zip)
   {
      this->street = street;
      this->city = city;
      this->state = state;
      this->zip = zip;
   }
   void setStreet(std::string street);
   void setCity(std::string city);
   void setState(std::string state);
   void setZip(std::string zip);

   std::string getStreet()
   {
      return this->street;
   }
   std::string getCity()
   {
      return this->city;
   }
   std::string getState()
   {
      return this->state;
   }
   std::string getZip()
   {
      return this->zip;
   }
   void display();
};

#endif
