/***********************************************************************
* Program:
*    Assignment 01, Genetic Geneology         (e.g. Assignment 01, Hello World)  
*    Brother Dudley, CS165
* Author:
*    Joshua Pearson
* Summary: 
*    Gathers some dna things for a few people and compares their
*    similarities and pushes it out as a percentage that is similar.
*
*    Estimated:  2.0 hrs   
*    Actual:     3.0 hrs
*      Strings. I hate strings in C++. I really miss JS and Python
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int getNumberOfRelatives();
void getUserDNA(string * userDNA);
void getRelativeName(string * names, int index);
void getRelativeDNA(string * DNA, int index, string * names);
void compareRelative(string * userDNA, string * DNA, int index, int * matchPercentage);
void displayRelative(int * matchPercentage, string * names, int index);

/**********************************************************************
 * Main
 * Declares arrays and variables, calls functions.
 ***********************************************************************/
int main()
{
   string user;
   string * userDNA = &user;
   getUserDNA(userDNA);
   int numberOfRels = getNumberOfRelatives();
   cout << endl;
   string names[numberOfRels];
   string DNA[numberOfRels];
   int matchPercentage[numberOfRels];

   for (int i = 0; i < numberOfRels; i++)
      getRelativeName(names, i);
   cout << endl;
   for (int i = 0; i < numberOfRels; i++)
      getRelativeDNA(DNA, i, names);
   cout << endl;
   for (int i = 0; i < numberOfRels; i++)
      compareRelative(userDNA, DNA, i, matchPercentage);

   for (int i = 0; i < numberOfRels; i++)
      displayRelative(matchPercentage, names, i);
   
   return 0;
}

void getUserDNA(string * userDNA)
{
   cout << "Enter your DNA sequence: ";
   cin >> *userDNA;
}

int getNumberOfRelatives()
{
   int rels = 0;
   cout << "Enter the number of potential relatives: ";
   cin >> rels;
   return rels;
}

void getRelativeName(string * names, int index)
{
   cout << "Please enter the name of relative #"
        << index + 1 << ": ";
   cin >> names[index];
}

void getRelativeDNA(string * DNA, int index, string * names)
{
   cout << "Please enter the DNA sequence for "
        << names[index] << ": ";
   cin >> DNA[index];
}

void compareRelative(string * userDNA, string * DNA, int index, int * matchPercentage)
{
   int percentage = 0;
   for (int i = 0; i < 10; i++)
   {
      if (userDNA[i] == DNA[i])
         percentage += 10;
   }
   matchPercentage[index] = percentage;
}

void displayRelative(int * matchPercentage, string * names, int index)
{
   cout << "Percent match for " << names[index] << ": "
        << matchPercentage[index] << "%" << endl;
}