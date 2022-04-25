//filename main.cpp
#include <iostream>
#include <string>
#include <fstream>
#include "TestScanner.h"
using namespace std;
int main(int argc, char** argv)//takes in the filename as a string and sends to useScanner method of testscanner
{
  TestScanner testScan;
  if (argc == 1)// if filename is not given
  {
    int numOfLines;
    string line;
    cout << "Enter in the numbers of line that will be entered" << endl;
    cin >> numOfLines;
    cin.ignore();
    
    ofstream file("tempFile.txt");
    for(int x = 0; x < numOfLines; x++)
    {
      
      cout << "Enter in line " << x+1 << " of code " << endl;
      getline(cin, line);
      line += " ";
      file << line;
      file << endl;
    }
    file.close();
    testScan.useScanner("tempFile.txt");
  
  }
  
  if(argc == 2)// if filename is given
  {
    string filename = argv[1];
    testScan.useScanner(filename);
  }  
  
  if(argc > 2)//if there is more than 1 argument when the program is first executed
  {
    cout << "Error: improper usage, more than 1 arugment was entered" << endl;
    return 1;
  }

}