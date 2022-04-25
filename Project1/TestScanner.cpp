//filename TestScanner.cpp 
#include <iostream>
#include <string>
#include <fstream>
#include "Scanner.h"
#include "TestScanner.h"
using namespace std;
string input; 
int line = 0;
void TestScanner::useScanner(const std::string filename)// takes in a filename and open the file to use the scanner
{
  ifstream inFile(filename);
  if(inFile == NULL)
  {
    cout << "Error: could not find file: " << filename << endl; 
  }
  else if(inFile.is_open())
  {
    while(std::getline(inFile, input))
    {
      
      cout << "\n Line: "<< line + 1 << " " << input << endl;
      
      scan.scanToken(input, line);
      
      line++;
    }
    scan.displayTokenID(1006);
  }
}