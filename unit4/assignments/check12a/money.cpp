/***********************
 * File: money.cpp
 ***********************/

#include <iostream>
#include <iomanip>
using namespace std;

#include "money.h"

/*****************************************************************
 * Function: prompt
 * Purpose: Asks the user for values for dollars and cents
 *   and stores them.
 ****************************************************************/
void Money ::prompt()
{
   int dollars;
   int cents;

   cout << "Dollars: ";
   cin >> dollars;

   cout << "Cents: ";
   cin >> cents;

   setDollars(dollars);
   setCents(cents);
}

/*****************************************************************
 * Function: display
 * Purpose: Displays the value of the money object.
 ****************************************************************/
void Money ::display() const
{
   cout << "$" << dollars << ".";
   cout << setfill('0') << setw(2) << cents;
}

std::ostream &operator<<(std::ostream &out, const Money money1)
{
   out << money1.getDollars() << "." << money1.getCents();
   return out;
}
bool operator==(const Money &money1, const Money &money2)
{
   return (money1.getCents() == money2.getCents() &&
           money1.getDollars() == money2.getDollars());
}
bool operator!=(const Money &money1, const Money &money2)
{
   return (money1.getCents() != money2.getCents() &&
           money1.getDollars() != money2.getDollars());
}
