/***********************************************************************
* Program:
*    Checkpoint 02b, Complex Numbers
*    Brother {Burton, Falin, Ercanbrack}, CS165
* Author:
*    your name
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

// TODO: Define your Complex struct here
struct Complex
{
   double realPart;
   double imaginaryPart;
};

// TODO: Add your prompt function here
void prompt(Complex & x, Complex & y)
{
   cout << "Real: ";
   cin >> x.realPart;
   cin.ignore();
   cout << "Imaginary: ";
   cin >> x.imaginaryPart;
   cout << "Real: ";
   cin >> y.realPart;
   cin.ignore();
   cout << "Imaginary: ";
   cin >> y.imaginaryPart;
}

// TODO: Add your display function here
void display(Complex & sum)
{
   cout << "The sum is: " << sum.realPart << " + " << sum.imaginaryPart
        << "i";
}

/**********************************************************************
 * Function: addComplex
 * Purpose: Adds two complex numbers together and returns the sum.
 ***********************************************************************/
void addComplex(const Complex & x, const Complex & y, Complex & sum)
{
   // TODO: Fill in the body of the add function
   sum.realPart = x.realPart + y.realPart;
   sum.imaginaryPart = x.imaginaryPart + y.imaginaryPart;
}


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare two Complex objects, c1 and c2
   Complex c1;
   Complex c2;

   // Call your prompt function twice to fill in c1, and c2 
   prompt(c1, c2);

   // Declare another Complex for the sum
   Complex sum;

   // Call the addComplex function, putting the result in sum;
   addComplex(c1, c2, sum);
   
   cout << "\nThe sum is: ";
   display(sum);
   cout << endl;
 
   return 0;
}


