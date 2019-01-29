/***********************************************************************
* Program:
*    Assignment 03, DIGITAL FORENSICS  (e.g. Assignment 01, Hello World)  
*    Brother Dudley, CS165
* Author:
*    Joshua Pearson
* Summary: 
*    This reads a log file a filters it to find users that logged in 
*    during certain windows, displaying errors along the way
*    with currupted data.
*    Estimated:  4.0 hrs   
*    Actual:     6.5 hrs
*      I think it's not reading the file. Can't figure out why.
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
void parseLine(std::string line, std::vector<Record> parsedRecords);
long getStartTime();
long getEndTime();
void filterRecords(std::vector<Record> record, std::vector<Record> filteredRecords, long startTime, long endTime);
void displayList(std::vector<Record> filterRecords);



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
   
   while (!fin.eof())
   {
   getline(fin, line);
   parseLine(line, parsedRecords);
   }
   fin.close();
}

void parseLine(std::string line, std::vector<Record> parsedRecords)
{
   std::stringstream ssline(line);

   std::string filename;
   std::string username;
   std::string timestamp;
   Record tempRecord;

   try
   {
      while (ssline >> filename)
      {
         std::stringstream fn(filename);

         while (fn)
         {
            std::string fname;
            if (fn >> fname)
               tempRecord.filename = fname;
            else
            {
               throw "Error parsing line: ";
               fn.clear();
               fn.ignore();
            }
         }
      }

      while (ssline >> username)
      {
         std::stringstream un(username);

         while (un)
         {
            std::string uname;
            if (un >> uname)
               tempRecord.username = uname;
            else
            {
               throw "Error parsing line: ";
               un.clear();
               un.ignore();
            }
            
         }
      }
      
      while (ssline >> timestamp)
      {
         std::stringstream ts(timestamp);

         while (ts)
         {
            long tstamp;
            if (ts >> tstamp)
            {
               if (tstamp < 1000000000)
                  throw "Error parsing line: ";
               if (tstamp > 10000000000)
                  throw "Error oarsing line: "; 
               tempRecord.timestamp = tstamp;
            }
            else
            {
               throw "Error parsing line: ";
               ts.clear();
               ts.ignore();
            }
            
         }
      }
      parsedRecords.push_back(tempRecord);
   }
   
   catch (const char * message)
   {
      std::cout << message << line << std::endl; 
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
   for (int i = 0; i < 500; i++) 
   {                             
      std::cout << "\t" << filteredRecords[i].filename 
                << "\t" << filteredRecords[i].username 
                << "\t" << filteredRecords[i].timestamp << std::endl;
   }
}