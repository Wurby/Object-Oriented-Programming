/********************************************************************
 * File: date.cpp
 * Purpose: Holds the implementation of the Date class methods.
 ********************************************************************/
#include "date.h"
// Put your method bodies here...

void Date::set(int month, int day, int year)
{
    this->month = month;
    this->day = day;
    this->year = year;
}

void Date::displayAmerican()
{
    std::cout << month << "/" << day << "/" << year << std::endl;
}

void Date::displayEuropean()
{
    std::cout << day << "/" << month << "/" << year << std::endl;
}

void Date::displayISO()
{
    std::cout << year << "-" << month << "-" << day << std::endl;
}