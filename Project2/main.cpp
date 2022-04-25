//filename: main.cpp
#include <iostream>
#include <string>
#include <fstream>
#include "Scanner.h"
#include "Parser.h"
#include "TreeParser.h"
#include "TestTree.h"
#include "Token.h"
using namespace std;
int main(int argc, char** argv)//takes in the filename as a string and sends to useScanner method of testscanner
{
  Scanner scan;
  Parser parser;
  TreeParser parseTree;
  string testInput;
  
  
  if (argc == 1)//if filename is not given
  {
    int numOfLines;
    string line;
    cout << "Enter in the numbers of line that will be entered" << endl;
    cin >> numOfLines;
    cin.ignore();
    
    for(int x = 0; x < numOfLines; x++)
    {
      cout << "Enter in line " << x+1 << " of code " << endl;
      getline(cin, line);
      testInput += " " + line + " \n ";
    } 
    parser.startParser(testInput);
    
  }
  
  if(argc == 2)//if filename is give
  {
    string input;
    string fileName = argv[1];
    ifstream inFile(fileName);
    if(inFile==NULL)
    {
      cout << "Error: could not find file: " << fileName << endl;
      
    }
    else if(inFile.is_open())
    {
      while(std::getline(inFile, input))
      {
        testInput += " " + input + " \n";
      }
      parser.startParser(testInput);
    }
  }
  
  
  
  
  
  

}