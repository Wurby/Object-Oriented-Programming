/*********************************************************************
 * File: check04b.cpp
 * Purpose: contains the main method to exercise the Date class.
 *********************************************************************/

#include "date.h"

#include <iostream>

int main()
{
   int month = 0;
   int day = 0;
   int year = 0;
   // prompt for month, day, year
   std::cout << "Month: ";
   std::cin >> month;
   std::cout << "Day: ";
   std::cin >> day;
   std::cout << "Year: ";
   std::cin >> year;
   // create a Date object
   Date test;
   // set its values
   test.set(month, day, year);
   // call each display function
   test.displayAmerican();
   test.displayEuropean();
   test.displayISO();

   return 0;
}
