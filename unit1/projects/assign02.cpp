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

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

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
void readFile(std::string & filename, Record record[500]);
long getStartTime();
long getEndTime();
void filterRecords(Record record[500], Record filteredRecords[500], long startTime, long endTime);
void displayList(Record filteredRecords[500]);



/**********************************************************************
 * main
 * triggers all functions and passes relevant data
 ***********************************************************************/
int main()
{
   std::string filename;
   long startTime;
   long endTime;
   Record record[500];
   Record filteredRecords[500];

   getFilename(filename);
   readFile(filename, record);
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
}

/**********************************************************************
 * readFile
 * pulls data from file and places in record array
 ***********************************************************************/
void readFile(std::string & filename, Record record[500])
{
   std::ifstream fin;
   fin.open(filename.c_str());
   for (int i = 0; i < 500; i++) // I couldn't figure out how to get this to
   {                             // stop at the end of file instead of 500
      if (!fin.fail())
      {
         fin >> record[i].filename;
         fin >> record[i].username;
         fin >> record[i].timestamp;
      }
      else
         i = 499;
   }
   fin.close();
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
   return endTime;
}

/**********************************************************************
 * filterRecords
 * takes the access entries within a timerange and puts it in the
 * filtered record array ready for printing.
 ***********************************************************************/
void filterRecords(Record record[500], Record filteredRecords[500], long startTime, long endTime)
{
   for (int i = 0; i < 500; i++) // same as above, unsure how to stop
   {                             // when the end of the data is reached
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
void displayList(Record filteredRecords[500])
{
   std::setw(15);
   std::cout << "\tTimestamp" << "\tFile" << "\tUser";
   std::cout << "--------------- ------------------- -------------------";
   for (int i = 0; i < 500; i++) // Yup... 500. Bad. So bad. Gonna hit the end
   {                             // of the data and just keep on truckin'
      std::cout << "\t" << filteredRecords[i].filename 
                << "\t" << filteredRecords[i].username 
                << "\t" << filteredRecords[i].timestamp << std::endl;
   }
}