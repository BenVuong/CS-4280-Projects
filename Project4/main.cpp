//filename: main.cpp
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "SemanticChecker.h"
#include "Scanner.h"
#include "Parser.h"
#include "TreeParser.h"
#include "TestTree.h"
#include "Token.h"
#include "CodeGen.h"
using namespace std;
int main(int argc, char** argv)//takes in the filename as a string and sends to useScanner method of testscanner
{
  Scanner scan;
  Parser parser;
  TreeParser parseTree;
  string testInput;
  SemanticChecker checker;
  CodeGen gen;
  fstream file;
  
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
    parser.startParser(testInput);//the parser will go through the code and build the parse tree
    checker.check(parser.getRoot());//checks the static semantics by going through the parse tree
    checker.displaySymbolTable();
    cout<<"Generating Assembly Code..."<<endl;
    gen.generateCode(parser.getRoot(),0);//goes through the parse tree and generate assembly code
    checker.addSymbolTable();
    cout<<endl;
    file.open("out.asm",ios::out);
    cout<<endl;
    for(auto element : gen.code)//gets the list that contains the generate code and load it into a asm file
    {
       file<<element;
    }
    file<<"STOP"<<endl;
    for (auto element : checker.symbolTable)//loads in the variables into the asm file
    {
       file<<element<<" 0"<<endl;
    }
    file.close();
     cout<<"Created assembly code file: out.asm"<<endl;
    
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
      parser.startParser(testInput);//the parser will go through the code and build the parse tree
      checker.check(parser.getRoot());//checks the static semantics by going through the parse tree
      checker.displaySymbolTable();
      cout<<"Generating Assembly Code..."<<endl;
      gen.generateCode(parser.getRoot(),0);//goes through the parse tree and generate assembly code
      checker.addSymbolTable();
      fileName +=".asm";
      file.open(fileName,ios::out);
      cout<<endl;
      for(auto element : gen.code)//gets the list that contains the generate code and load it into a asm file
      {
        file<<element;
      }
      file<<"STOP"<<endl;
      for (auto element : checker.symbolTable)//loads in the variables into the asm file
      {
        file<<element<<" 0"<<endl;
      }
      file.close();
      cout<<"Created assembly code file: "<<fileName<<endl;
    
      
    }
  }
}

