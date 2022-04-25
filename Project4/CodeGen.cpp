//filename: CodeGen.cpp
//Generates the assembly code
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctype.h>
#include <bits/stdc++.h>
#include <list>
#include "Scanner.h"
#include "TestTree.h"
#include "TreeParser.h"
#include "Token.h"
#include "Node.h"
#include "CodeGen.h"
using namespace std;

void CodeGen::generateCode(Node *nodePtr, int level)
{
  int currentLevel = level;
  
  string temp;
  char label = nodePtr->label;
  switch(label)
  {
    case 'S':
      
      cout << "LOAD 0" << endl;
      code.push_back("LOAD 0\n");
      cout << "STORE " << nodePtr->token2 << endl;
      code.push_back("STORE " + nodePtr->token2 + "\n");//push back code into a list that will be used in main.cpp to load into a asm file
      cout << "READ " << nodePtr->token4 << endl;
      code.push_back("READ " + nodePtr->token4 + "\n");
      generateCode(nodePtr->leftChild, (currentLevel + 1));//Jumps to nonterminal R
      generateCode(nodePtr->rightChild, (currentLevel + 1));//Jumps to nonterminal E
      break;
    case 'R':
      generateCode(nodePtr->leftChild, (currentLevel + 1));//Jumps to nonterminal A
      generateCode(nodePtr->middleChild, (currentLevel + 1));//Jumps to nonterminal B
      break;
    case 'E':
      if(level == 1)
      {
        cout << "LOAD " << nodePtr->token2 << endl;
        code.push_back("LOAD " + nodePtr->token2 + "\n");
      }
      cout << "WRITE " << nodePtr->token2 << endl;
      code.push_back("WRITE " + nodePtr->token2 + "\n");
      break;
    case 'A':
      cout << "LOAD 0" << endl;
      code.push_back("LOAD 0\n");
      cout << "STORE " << nodePtr->token2 << endl;
      code.push_back("STORE " + nodePtr->token2 + "\n");
      
      break;
    case 'B':
      if(nodePtr->leftChild != nullptr &&  nodePtr->middleChild != nullptr)
      {
        generateCode(nodePtr->leftChild, (currentLevel + 1));//Jumps to either nonterminal C or D
        generateCode(nodePtr->middleChild, (currentLevel + 1));//Jumps to nonterminal B
      }
      break;
    case 'C':
      generateCode(nodePtr->leftChild, (currentLevel + 1));//Jumps to nonterminal F or G
      break;
    case 'D':
      generateCode(nodePtr->leftChild, (currentLevel + 1));//Jumps to nonterminal H, J, K, L, E, or F
      break;
    case 'F':
      if(nodePtr->token2 == "If")
      {
        generateCode(nodePtr->middleChild,(currentLevel+1));//Jumps to nonterminal W
        cout << "STORE T1" << endl;
        code.push_back("STORE T1\n");
        cout << "SUB T1" << endl;
        code.push_back("SUB T1\n");
        generateCode(nodePtr->leftChild, (1));//Jumps to nonterminal T
        generateCode(nodePtr->rightChild, (currentLevel + 1));//Jumps to nonterminal D
        cout << "Done: NOOP" << endl;
        code.push_back("Done: NOOP\n");
        
      }
      else if(nodePtr->token2 == "Do")
      {
        cout << "LOAD 0" << endl;
        code.push_back("LOAD 0\n");
        cout << "STORE T2" << endl;
        code.push_back("STORE T2\n");
        cout << "Repeat" << level<<": NOOP" <<endl;
        code.push_back("Repeat" + to_string(level) + ": NOOP\n");
        generateCode(nodePtr->leftChild, (currentLevel + 1));//Jumps to nonterminal D
        generateCode(nodePtr->rightChild, (currentLevel + 1));//Jumps to nonterminal W
        cout << "STORE T1" << endl;
        code.push_back("STORE T1\n");
        cout << "LOAD T2" << endl;
        code.push_back("LOAD T2\n");
        cout << "ADD 1" << endl;
        code.push_back("ADD 1\n");
        cout << "STORE T2" << endl;
        code.push_back("STORE T2\n");
        cout << "LOAD T1" << endl;
        code.push_back("LOAD T1\n");
        cout << "SUB T2" << endl;
        code.push_back("SUB T2\n");
        generateCode(nodePtr->middleChild, (0));//Jumps to nonterminal T
        cout << "Repeat" << level << endl;
        code.push_back("Repeat" + to_string(level) + "\n");
        
      }
      break;
    case 'G':
      cout << "LOAD " << nodePtr->token2 << endl;
      code.push_back("LOAD " + nodePtr->token2 + " \n");
      cout << "STORE T1" <<endl;
      code.push_back("STORE T1\n");
      cout << "BRZNEG Done" << endl; 
      code.push_back("BRZNEG Done\n");
      cout << "Repeat" << level << ": WRITE T1" << endl; //make it so each label is unqiue
      code.push_back("Repeat" + to_string(level) + ": WRITE T1\n");
      cout << "SUB 1" << endl;
      code.push_back("SUB 1\n");
      cout << "BRPOS Repeat" << level << endl;//make it so each label is unqiue
      code.push_back("BRPOS Repeat" + to_string(level) + " \n");
      cout << "Done: NOOP" << endl;
      code.push_back("Done: NOOP\n");
      break;
    case 'T':
      if(nodePtr->token1 == "<-")
      {
        if (level == 0)
        {
          cout << "BRZPOS ";
          code.push_back("BRZPOS ");
        }
        else if(level == 1)
        {
          cout << "BRNEG Done" << endl;
          code.push_back("BRNEG Done\n");
        }
        else
        {
          cout << "BRPOS Done" << endl;
          code.push_back("BRZPOS Done\n");
        }
      }
      else if(nodePtr->token1 == "<<")
      {
        if(level == 0)
        {
          cout << "BRNEG ";
          code.push_back("BRNEG ");
        }
        else if(level == 1)
        {
          cout << "BRZPOS Done" << endl;
          code.push_back("BRZPOS Done\n");
        }
        else
        {
          cout << "BRNEG Done" << endl;
          code.push_back("BRNEG Done\n");
        }
      }
      break;
    case 'V':
      if(nodePtr->token1 == "+")
      {
        cout << "ADD ";
        code.push_back("ADD ");
      }
      else if(nodePtr->token1 == "%")
      {
        cout << "DIV ";
        code.push_back("DIV ");
      }
      else if(nodePtr->token1 == "&")
      {
        cout << "MULT ";
        code.push_back("MULT ");
      } 
      break;
    case 'H':
      cout << "LOAD ";
      code.push_back("LOAD ");
      generateCode(nodePtr->leftChild,(currentLevel + 1));//Jumps to nonterminal Z
      cout << "SUB 1"<<endl;
      code.push_back("SUB 1\n");
      generateCode(nodePtr->leftChild,(0));//Jumps to nonterminal Z
      break;
    case 'J':
      generateCode(nodePtr->leftChild, (currentLevel + 1));//Jumps to nonterminal D
      cout << "STORE " << nodePtr->token2 << endl;
      code.push_back("STORE " + nodePtr->token2 + "\n");
      break;
    case 'K':
      if(nodePtr->token1 == "Spot")
      {
        cout << "LOAD " << nodePtr->token2 << endl;
        code.push_back("LOAD " + nodePtr->token2 + "\n");
        cout << "WRITE " << nodePtr->token4 << endl;
        code.push_back("WRITE " + nodePtr->token4 + "\n");
      
      }
      else if(nodePtr->token1 == "Move")
      {
        cout << "LOAD " << nodePtr->token2 << endl;
        code.push_back("LOAD " + nodePtr->token2 + "\n");
        cout << "WRITE " << nodePtr->token4 << endl;
        code.push_back("WRITE " + nodePtr->token4 + "\n");
      
      }
      break;
    case 'L':
      cout << "LOAD " << nodePtr->token2 << endl;
      code.push_back("LOAD " + nodePtr->token2 + "\n");
      cout << "MULT -1" << endl;
      code.push_back("MULT -1\n");
      cout << "STORE " << nodePtr->token2 << endl;
      code.push_back("STORE " + nodePtr->token2 + "\n");
      break;
    case 'W':
      if(nodePtr->leftChild != nullptr)
      {
        cout << "LOAD " << nodePtr->token1 <<endl;
        code.push_back("LOAD " + nodePtr->token1+"\n");
        generateCode(nodePtr->leftChild,(currentLevel + 1));//Jumps to nonterminal V
        cout << nodePtr->token2 << endl;
        code.push_back(nodePtr->token2 + "\n");
      }
      else
      {
        if(level == 0)
        {
          cout << nodePtr->token1 << endl;
          code.push_back(nodePtr->token1 + "\n");
        }
        else
        {
          cout << "LOAD " << nodePtr->token1 << endl;
          code.push_back("LOAD " + nodePtr->token1 + "\n");
        }
      }
      break;
    case 'Z':
      if(level == 0)
      {
        if (isdigit(nodePtr->token1.at(0)) == false)
        {
          cout << "STORE " << nodePtr->token1 << endl;
          code.push_back("STORE " + nodePtr->token1 + "\n");
        }
      }
      else
      {
        cout << nodePtr->token1 << endl;
        code.push_back(nodePtr->token1 + "\n");
      }
      
      break;
  }

}