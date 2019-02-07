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
      if (cents > 0)
         this->cents = cents;
      else
      {
         this->cents = -cents;
      }
   }
   void setDollars(int dollars)
   {
      if (dollars > 0)
         this->dollars = dollars;
      else
      {
         this->dollars = -dollars;
      }
      
   }
public:
   void prompt();
   void display() const;
   int getCents() const
   {
      return cents;
   }
   int getDollars() const
   {
      return dollars;
   }
};

#endif
