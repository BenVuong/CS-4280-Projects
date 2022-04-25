//filename: TreeParser.cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <bits/stdc++.h>
#include <vector>
#include "Scanner.h"
#include "TestTree.h"
#include "TreeParser.h"
#include "Token.h"
#include "Node.h"
#include "SemanticChecker.h"
using namespace std;

void TestTree::printIndent(int level)
{
  for(int x = 0; x < level; x++)
  {
    cout << "  ";
  }

}

void TestTree::displaySymbolTable()
{
 for(int x = 0; x<2; x++)
 {
   cout<<table[x]<<endl;
 }
}

void TestTree::printTree(Node *nodePtr, int level)
{
  int currentLevel = level;
  string temp;
  char label = nodePtr->label;
  switch(label)
  {
    case 'S':
      printIndent(currentLevel);
      cout << "NonTerminal Label: " << nodePtr->label << " Current Level: " << currentLevel << endl;
      printIndent(currentLevel);
      cout << " " << nodePtr->token1 << endl;
      printIndent(currentLevel);
      cout << " Identifier " << nodePtr->token2<<endl;
      //temp = nodePtr->token2;
      //table[0] = temp;
      printIndent(currentLevel);
      cout << " " << nodePtr->token3 << endl;
      cout << " Identifier " << nodePtr->token4 << endl;
      printIndent(currentLevel);
      printTree(nodePtr->leftChild, (currentLevel + 1));
      printTree(nodePtr->rightChild, (currentLevel + 1));
      cout<<endl;
      //displaySymbolTable();
      break;
    case 'R':
      printIndent(currentLevel);
      cout << "NonTerminal Label: "<< nodePtr->label << " Current Level: " << currentLevel << endl;
      printIndent(currentLevel);
      cout << nodePtr->token1 << endl;
      printTree(nodePtr->leftChild, (currentLevel + 1));
      printTree(nodePtr->middleChild, (currentLevel + 1));
      printIndent(currentLevel);
      cout << nodePtr->token2 << " " << endl;
      break;
    case 'E':
      printIndent(currentLevel);
      cout << "NonTerminal Label: " << nodePtr->label << " Current Level: " << currentLevel << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << nodePtr->token1 << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << "Identifier " << nodePtr->token2 << endl;
      break;
    case 'A':
      printIndent(currentLevel);
      cout << "NonTerminal Label: " << nodePtr->label<<" Current Level: " << currentLevel <<endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << nodePtr->token1 << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << "Identifier " << nodePtr->token2 << endl;
      //temp = nodePtr->token2;
      //table[1] = temp;
      break;
    case 'B':
      printIndent(currentLevel);
      cout << "NonTerminal Label: " << nodePtr->label << " Current Level: " << currentLevel <<endl;
      if(nodePtr->leftChild != nullptr &&  nodePtr->middleChild != nullptr)
      {
        printIndent(currentLevel);
        cout << nodePtr->token1 << endl;
        printIndent(currentLevel);
        printTree(nodePtr->leftChild, (currentLevel + 1));
        printIndent(currentLevel);
        cout << nodePtr->token2 << endl;
        printIndent(currentLevel);
        printTree(nodePtr->middleChild, (currentLevel + 1));
      }
      else
      {
        printIndent(currentLevel);
        printIndent(currentLevel);
        cout << "Empty" << endl;
      }
      break;
    case 'C':
      printIndent(currentLevel);
      cout << "NonTerminal Label: " << nodePtr->label << " Current Level: " << currentLevel << endl;
      printIndent(currentLevel);
      printTree(nodePtr->leftChild, (currentLevel + 1));
      break;
    case 'D':
     printIndent(currentLevel);
      cout << "NonTerminal Label: " << nodePtr->label << " Current Level: " << currentLevel << endl;
      printIndent(currentLevel);
      printTree(nodePtr->leftChild, (currentLevel + 1));
      break;
    case 'F':
      printIndent(currentLevel);
      cout << "NonTerminal Label: " << nodePtr->label << " Current Level: " << currentLevel << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << nodePtr->token1 << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << nodePtr->token2 << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << "Identifier " << nodePtr->token3 << endl;
      printIndent(currentLevel);
      printTree(nodePtr->leftChild, (currentLevel + 1));
      printIndent(currentLevel);
      printTree(nodePtr->middleChild, (currentLevel + 1));
      printIndent(currentLevel);
      printTree(nodePtr->rightChild, (currentLevel + 1));
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << nodePtr->token4 << endl;
      break;
    case 'G':
      printIndent(currentLevel);
      cout << "NonTerminal Label: " << nodePtr->label << " Current Level: " << currentLevel << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << nodePtr->token1 << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << "Number " << nodePtr->token2 << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << nodePtr->token3 << endl;
      break;
    case 'T':
      printIndent(currentLevel);
      cout << "NonTerminal Label: " << nodePtr->label << " Current Level: " << currentLevel << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << "Operator " << nodePtr->token1 << endl;
      break;
    case 'V':
      printIndent(currentLevel);
      cout << "NonTerminal Label: " << nodePtr->label << " Current Level: " << currentLevel << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << "Operator: " << nodePtr->token1 << endl;
      break;
    case 'H':
      printIndent(currentLevel);
      cout << "NonTerminal Label: " << nodePtr->label << " Current Level: " << currentLevel << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << "Operator: " << nodePtr->token1 << endl;
      printIndent(currentLevel);
      printTree(nodePtr->leftChild, (currentLevel + 1));
      break;
    case 'J':
      printIndent(currentLevel);
      cout << "NonTerminal Label: " << nodePtr->label << " Current Level: " << currentLevel << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << nodePtr->token1 << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << "Identifier " << nodePtr->token2 << endl;
      printIndent(currentLevel);
      printTree(nodePtr->leftChild, (currentLevel + 1));
      break;
    case 'K':
      printIndent(currentLevel);
      cout << "NonTerminal Label: "<<nodePtr->label<<" Current Level: " << currentLevel <<endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << nodePtr->token1 << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      if(isdigit(nodePtr->token2.at(0)) == true)
      {
        cout << "Number: " << nodePtr->token2 << endl;
      }
      else
      {
        cout << "Identifier: " << nodePtr->token2 << endl;
      }
      
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout <<nodePtr->token3<<endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      if(isdigit(nodePtr->token4.at(0))==true)
      {
        cout << "Number: " << nodePtr->token4 << endl;
      }
      else
      {
        cout << "Identifier: " << nodePtr->token4 << endl;
      }
      
      break;
    case 'L':
      printIndent(currentLevel);
      cout << "NonTerminal Label: " << nodePtr->label << " Current Level: " << currentLevel << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << nodePtr->token1 << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      cout << "Identifier " << nodePtr->token2 << endl;
      break;
    case 'W':
      printIndent(currentLevel);
      cout << "NonTerminal Label: " << nodePtr->label << " Current Level: " << currentLevel << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      if(nodePtr->leftChild != nullptr)
      {
        cout << "Number " << nodePtr->token1 << endl;
        printIndent(currentLevel);
        printTree(nodePtr->leftChild, (currentLevel + 1));
        printIndent(currentLevel);
        cout << "Number " << nodePtr->token2 << endl;
      }
      else
      {
        cout << "Number " << nodePtr->token1 << endl;
        printIndent(currentLevel);
        printIndent(currentLevel);
        cout << "Operator " << nodePtr->token2 << endl;
        
      }
      break;
    case 'Z':
      printIndent(currentLevel);
      cout << "NonTerminal Label: " << nodePtr->label << " Current Level: " << currentLevel << endl;
      printIndent(currentLevel);
      printIndent(currentLevel);
      if(isdigit(nodePtr->token1.at(0)) == true)
      {
        cout << "Number " << nodePtr->token1 << endl;
      }
      else
      {
        cout << "Identifier " << nodePtr->token1 << endl;
      }
      break;
  }

}