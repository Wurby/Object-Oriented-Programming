/***********************************************************************
* Program:
*    Assignment 02, DIGITAL FORENSICS  (e.g. Assignment 01, Hello World)  
*    Brother Dudley, CS165
* Author:
*    Joshua Pearson
* Summary: 
*    This reads a log file a filters it to find users that logged in 
*    during certain windows.
*    Estimated:  3.0 hrs   
*    Actual:     5.5 hrs
*      I have some holes in understanding files and arrays.
************************************************************************/


/**********************************************************************
 * This has a lot of problems, and I have been unable to figure them 
 * out in the necessary time. I have already emailed Daniel at this
 * point, I think my issues mostly are rooted in my poor understanding
 * of arrays and how files are read and stored. See notes below for
 * where I already know there are problems. I wish I'd had more time
 * this week to work on this assignment.
 ***********************************************************************/
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

/**********************************************************************
 * struct: Record
 * basica data type for the individual records and their relevant
 * information.
 ***********************************************************************/
struct Record 
{
   std::string username;
   std::string filename;
   long timestamp;
};

void getFilename(std::string & filename);
void parsefile(std::string filename, std::vector<Record> parsedRecords);
void parsefile(std::string filename, std::vector<Record> parsedRecords);
long getStartTime();
long getEndTime();
void filterRecords(std::vector<Record> record, std::vector<Record> filteredRecords, long startTime, long endTime);
void displayList(Record filteredRecords[500]);



/**********************************************************************
 * main
 * triggers all functions and passes relevant data
 ***********************************************************************/
int main()
{
   std::string filename;
   long startTime = 0;
   long endTime = 0;
   std::vector<Record> record;
   std::vector<Record> parsedRecords;
   std::vector<Record> filteredRecords;

   getFilename(filename);
   startTime = getStartTime();
   endTime = getEndTime();
   filterRecords(record, filteredRecords, startTime, endTime); 
   displayList(filteredRecords);

   return 0;
}

/**********************************************************************
 * getFilename
 * prompts user for path and stores in string
 ***********************************************************************/
void getFilename(std::string & filename)
{
   std::cout << "Enter the access record file: ";
   std::cin >> filename;
   std::cout << std::endl;
}

void parsefile(std::string filename, std::vector<Record> parsedRecords)
{

}

void parseLine(std::string line, std::vector<Record> parsedRecords)
{

}

/**********************************************************************
 * getStartTime
 * prompts for start time to filter by
 ***********************************************************************/
long getStartTime()
{
   long startTime = 0;
   std::cout << "Enter the start time: ";
   std::cin >> startTime;
   return startTime;
}

/**********************************************************************
 * get end time
 * prompts for end time to filter by
 ***********************************************************************/
long getEndTime()
{
   long endTime = 0;
   std::cout << "Enter the end time: ";
   std::cin >> endTime;
   std::cout << std::endl;
   return endTime;
}

/**********************************************************************
 * filterRecords
 * takes the access entries within a timerange and puts it in the
 * filtered record array ready for printing.
 ***********************************************************************/
void filterRecords(std::vector<Record> record, std::vector<Record> filteredRecords, long startTime, long endTime)
{
   for (int i = 0; i < 500; i++) 
   {                             
      if (endTime > record[i].timestamp > startTime)
      {
         filteredRecords[i].filename = record[i].filename;
         filteredRecords[i].username = record[i].username;
         filteredRecords[i].timestamp = record[i].timestamp;
      }
   }
}

/**********************************************************************
 * displayList
 * prints filtered record array.
 ***********************************************************************/
void displayList(std::vector<Record> filteredRecords)
{
   std::cout << "The following records match your criteria:\n\n";
   std::setw(15);
   std::cout << "      Timestamp" << "           File" << "           User\n";
   std::cout << "--------------- ------------------- -------------------\n";
   for (int i = 0; i < 500; i++) // Yup... 500. Bad. So bad. Gonna hit the end
   {                             // of the data and just keep on truckin'
      std::cout << "\t" << filteredRecords[i].filename 
                << "\t" << filteredRecords[i].username 
                << "\t" << filteredRecords[i].timestamp << std::endl;
   }
}