/***********************************************************************
* Program:
*    Assignment 03, DIGITAL FORENSICS  (e.g. Assignment 01, Hello World)  
*    Brother Dudley, CS165
* Author:
*    Joshua Pearson
* Summary: 
*    This reads a logfile and filters it to find users that logged in 
*    during certain windows, displaying errors along the way
*    with currupted data.
*    Estimated:  4.0 hrs   
*    Actual:     9.5 hrs
*      Got some help with parseline and parsefile from Daniel.
************************************************************************/



#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>

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
void parsefile(const std::string & filename, std::vector<Record> & parsedRecords);
Record parseLine(const std::string & line) throw (std::string);
long getStartTime();
long getEndTime();
void filterRecords(std::vector<Record> & record, std::vector<Record> & filteredRecords, long startTime, long endTime);
void displayList(std::vector<Record> & filterRecords);



/**********************************************************************
 * main
 * triggers all functions and passes relevant data
 ***********************************************************************/
int main()
{
   std::string filename;
   long startTime = 0;
   long endTime = 0;
   std::vector<Record> parsedRecords;
   std::vector<Record> filteredRecords;

   getFilename(filename);
   parsefile(filename, parsedRecords);
   startTime = getStartTime();
   endTime = getEndTime();
   filterRecords(parsedRecords, filteredRecords, startTime, endTime); 
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
 * parseFile
 * this reads a line from a file and passes line to parseline, catching
 * any returned errors.
 ***********************************************************************/
void parsefile(const std::string & filename, std::vector<Record> & parsedRecords)
{
   std::ifstream fin;
   fin.open(filename.c_str());
   if (fin.fail())
   {
      std::cout << "Failed to open file " << filename << std::endl;
      return;
   }
   std::string line;
   Record tempRecord;
   while (getline(fin, line))
   {
      try
      {
      tempRecord = parseLine(line);
      parsedRecords.push_back(tempRecord);
      }
      catch (std::string message)
      {
         std::cout << message << std::endl;
      }
   }
   fin.close();
   std::cout << std::endl;
}

/**********************************************************************
 * parseLine
 * This get a line and checks it for errors, then adds it to a Record
 * throws any errors that may come up.
 ***********************************************************************/
Record parseLine(const std::string & line) throw (std::string)
{
   std::stringstream ssline(line);
   Record tempRecord;
   ssline >> tempRecord.filename >> tempRecord.username >> tempRecord.timestamp;
   if (ssline.fail() || tempRecord.timestamp < 1000000000 || tempRecord.timestamp > 10000000000)
   {
      std::string err = "Error parsing line: ";
      err += line;
      throw err;
   }
   else
   {
      return tempRecord;
   }
   
   
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
void filterRecords(std::vector<Record> & record, std::vector<Record> & filteredRecords, long startTime, long endTime)
{
   for (int i = 0; i < record.size(); i++) 
   {                             
      if (record[i].timestamp > startTime)
      {
         if (record[i].timestamp < endTime)
         {
            filteredRecords[i].filename = record[i].filename;
            filteredRecords[i].username = record[i].username;
            filteredRecords[i].timestamp = record[i].timestamp;
         }
      }
   }
}

/**********************************************************************
 * displayList
 * prints filtered record array.
 ***********************************************************************/
void displayList(std::vector<Record> & filteredRecords)
{
   std::cout << "The following records match your criteria:\n";
   std::cout << "      Timestamp" << "                File" << "                User\n";
   std::cout << "--------------- ------------------- -------------------\n";
   std::cout << std::setw(15);
   for (int i = 0; i < filteredRecords.size(); i++)
   {
      std::cout << "\t" << filteredRecords[i].filename 
                << "\t" << filteredRecords[i].username 
                << "\t" << filteredRecords[i].timestamp << std::endl;
   }
   std::cout << "End of records\n";
   
}