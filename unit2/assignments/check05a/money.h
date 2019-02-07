/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H

class Money
{
private:
   int dollars;
   int cents;
   void setCents(int cents)
   {
      this->cents = cents; 
   }
   void setDollars(int dollars)
   {
      this->dollars = dollars;
   }
public:
   void prompt();
   void display() const;
   void getCents()
   {
      return cents;
   }
   void getDollars()
   {
      return dollars;
   }
};

#endif
