/***********************************************************************
* Program:
*    Assignment 01, Genetic          (e.g. Assignment 01, Hello World)  
*    Brother Dudley, CS165
* Author:
*    Joshua Pearson
* Summary: 
*    Gathers some dna things for a few people and compares their
*    similarities and pushes it out as a percentage that is similar.
*
*    Estimated:  2.0 hrs   
*    Actual:     0.0 hrs
*      Strings. I hate strings in C++. I really miss JS and Python
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int getNumberOfRelatives();
void getUserDNA(string userDNA);
void getRelativeName(string * names, int index);
void getRelativeDNA(string * DNA, int index);
int compareRelative(string userDNA, string * names, int index, int * matchPercentage);
void displayRelative(int * matchPercentage, string * names, int index);

/**********************************************************************
 * Main
 * Declares arrays and variables, calls functions.
 ***********************************************************************/
int main()
{
   string userDNA;
   getUserDNA(userDNA);
   int numberOfRels = getNumberOfRelatives();
   string names[numberOfRels];
   string DNA[numberOfRels];
   int matchPercentage[numberOfRels];

   for (int i = 0; i < numberOfRels; i++)
      getRelativeName(names, i);

   for (int i = 0; i < numberOfRels; i++)
      getRelativeDNA(DNA, i);

   for (int i = 0; i < numberOfRels; i++)
      compareRelative(userDNA, names, i, matchPercentage);

   for (int i = 0; i < numberOfRels; i++)
      displayRelative(matchPercentage, names, i);
   
   return 0;
}
