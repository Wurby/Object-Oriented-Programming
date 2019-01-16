/***********************************************************************
* Program:
*    Checkpoint 02a, STRUCT          (e.g. Checkpoint 01a, review)  
*    Brother Dudley, CS165
* Author:
*    Joshua Pearson
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;


struct Student 
{
   string firstName;
   string lastName;
   int id;
};

void getStudentInfo(Student & user);
void displayStudentInfo(Student & user);


/**********************************************************************
 * Function: main
 * Purpose: does the things
 ***********************************************************************/
int main()
{
   Student user;
   getStudentInfo(user);
   displayStudentInfo(user);
   return 0;
}

/**********************************************************************
 * Function: getStudentInfo
 * Purpose: gets the things
 ***********************************************************************/
void getStudentInfo(Student & user)
{
   
   cout << "Please enter your first name: ";
   cin >> user.firstName;
   cin.ignore();
   cout << "Please enter your last name: ";
   cin >> user.lastName;
   cin.ignore();
   cout << "Please enter your id number: ";
   cin >> user.id;
   cin.ignore();
}

/**********************************************************************
 * Function: displayStudentInfo
 * Purpose: prints the things gotted by getStudentInfo
 ***********************************************************************/
void displayStudentInfo(Student & user)
{
   cout << "\nYour information:\n"
        << user.id << " - "
        << user.firstName << " "
        << user.lastName << endl;
}