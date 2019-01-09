/***********************************************************************
* Program:
*    Checkpoint 01a, C++ BASICS          (e.g. Checkpoint 01a, review)  
*    Brother Dudley, CS165
* Author:
*    Joshua Pearson
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

void display(int age, string name);
string getName();
int getAge();
void greeting();
/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   greeting();
   display(getAge(), getName());


   return 0;
}

string getName()
{
   string name;
   cout << "Please enter your first name: ";
   cin >> name;
   return name;
}

int getAge()
{
   int age;
   cout << "Please enter your age: ";
   cin >> age;
   return age;
}

void display(int age, string name)
{
   cout << endl;
   cout << "Hello " << name << ", you are "
        << age << " years old.\n";
}

void greeting()
{
   cout << "Hello CS 165 World!\n";
}