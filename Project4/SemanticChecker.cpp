//fileName: SemantiChecker.cpp
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include "SemanticChecker.h"

using namespace std;

bool SemanticChecker::verify(string id)
{
  bool found = false;
  
  for (auto element : symbolTable)
  {
    if(element == id)
    {
      found = true; 
    }
  }
  return found;
}


void SemanticChecker::check(Node *nodePtr)
{
  string temp;
  char label = nodePtr->label;
  switch(label)
  {
    case 'S':
      if(verify(nodePtr->token2) == false)//declare id
      {
        insert(nodePtr->token2);
      }
      else
      {
        cout << "Error: Identifier: " << nodePtr->token2 << " has already been declared" << endl;
        break;
      }
      
      if(verify(nodePtr->token4) == false)//declare id
      {
        insert(nodePtr->token4);
      }
      else
      {
        cout << "Error: Identifier: " << nodePtr->token4 << " has already been declared" << endl;
        break;
      }
      check(nodePtr->leftChild);
      check(nodePtr->rightChild);
      break;
    case 'R':
      check(nodePtr->leftChild);
      check(nodePtr->middleChild);
      break;
    case 'E':
      if(verify(nodePtr->token2) == false)//uses id
      {
        cout << "Error: Identifier: " << nodePtr->token2 << " has not been declared" << endl;
        break;
      }
      
      break;
    case 'A':
      if(verify(nodePtr->token2) == false)//declare id
      {
        insert(nodePtr->token2);
      }
      else
      {
        cout << "Error: Identifier: " << nodePtr->token2 << " has already been declared" << endl;
        break;
      }
      break;
    case 'B':
       if(nodePtr->leftChild != nullptr &&  nodePtr->middleChild != nullptr)
      {
      
        check(nodePtr->leftChild);
        check(nodePtr->middleChild);
      }
      else
      {
        
      }
      break;
    case 'C':
      check(nodePtr->leftChild);
      break;
    case 'D':
      check(nodePtr->leftChild);
      break;
    case 'F':
   
      if(verify(nodePtr->token3) == false && nodePtr->token3 != "Again")//uses id
      {
        cout << "Error: Identifier: " << nodePtr->token3 << " has not been declared" << endl;
        break;
      }
      
      check(nodePtr->leftChild);
      check(nodePtr->middleChild);
      check(nodePtr->rightChild);
      break;
    case 'G':
      break;
    case 'T':
      break;
    case 'V':
      break;
    case 'H':
      break;
    case 'J':
      if(verify(nodePtr->token2) == false)//uses id
      {
        cout << "Error: Identifier: " << nodePtr->token2 << " has not been declared" << endl;
        break;
      }
      check(nodePtr->leftChild);
      break;
    case 'K':
      if(nodePtr->token1 == "Move")
      {
        if(isdigit(nodePtr->token2.at(0)) == false)
        {
          if(verify(nodePtr->token2) == false)//uses id
          {
            cout << "Error: Identifier: " << nodePtr->token2 << " has not been declared" << endl;
            break;
          }
          
        }
      
      }
      
        
      break;
    case 'L':
      if(verify(nodePtr->token2) == false)//uses id
      {
        cout << "Error: Identifier: " << nodePtr->token2 << " has not been declared" << endl;
        break;
      }
      break;
    case 'W':
      if(nodePtr->leftChild != nullptr)
      {
        check(nodePtr->leftChild);
      }
      break;
    case 'Z':
      if(isdigit(nodePtr->token1.at(0)) == false)
      {
        if(verify(nodePtr->token1) == false)//uses id
        {
          cout << "Error: Identifier: " << nodePtr->token1 << " has not been declared" << endl;

          break;
        }
      }
      break;
  }
}



void SemanticChecker::displaySymbolTable()
{
  cout<<"Printing Symbol Table...."<<endl;
  
  for (auto element : symbolTable)
  {
    cout<< element << endl;
  }
  cout<<endl;
}

void SemanticChecker::insert(string id)
{  
  symbolTable.push_back(id);
}

void SemanticChecker::addSymbolTable()
{
  cout << "STOP" << endl;
  symbolTable.push_back("T1");//Declares temp1 variable
  symbolTable.push_back("T2");//Declares temp2 variable
  for (auto element : symbolTable)
  {
    cout << element << " 0" << endl;
  }
  cout << endl;

}