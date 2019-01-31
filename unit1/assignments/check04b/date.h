/********************************************************************
 * File: date.h
 * Purpose: Holds the definition of the Date class.
 ********************************************************************/

#ifndef DATE_H
#define DATE_H

// put your class definition here
// along with the data members, and method prototypes

class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        void set(int month, int day, int year);
        void displayAmerican();
        void displayEuropean();
        void displayISO();
};


#endif
