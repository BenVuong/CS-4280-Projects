//filename Scanner.cpp
#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
#include "Scanner.h"
#include "Token.h"
using namespace std;
void Scanner::displayTable() //used to test fsaTable
{
  for (int x = 0; x < 10; x++)
  {
    for(int y = 0; y < 8; y++)
    {
      cout << fsaTable[x][y] << " ";
    }
    cout << endl;
  }
}


int Scanner::getChar(char character) //takes in a character and see what class it is and returns number that represents that class
{
  if(isalpha(character))
  {
    if(islower(character))
    {
      return 0;
    
    }
    else
    {
      return 1;
    }
  }
  else if(isdigit(character))
  {
    return 2;
  
  }
  else if(character == '&' || character == '+' || character == '/' || character == '%' || character == '.' || character == '{' || character == '}')
  {
    return 3;
  }
  else if(character == '<')
  {
    return 4;
  }
  else if(character == '-')
  {
    return 5;
  }
  else if(character == '*')
  {
    return 6;
  }
  else if(isspace(character))
  {
    return 7;
  }
  else if(character == '\0')
  {
    return 8;
  }
  else
  {
    return -1;
  }
  
}

void Scanner::displayTokenID(int id)// takes in the number id for a token and prints the Token Class
{
  switch(id) 
  {
    case 1001:
      cout << "ID Token";
      break;
    case 1002:
      cout << "Keyword Token";
      break;
    case 1003:
      cout << "Operator Token";
      break;
    case 1004:
      cout << "Digit Token";
      break;
    case 1005:
      cout << "Comment Token";
      break;
    case 1006:
      cout << "EOF Token"<<endl;
      break;
    default:
      cout << "";
  }

}

void Scanner::isKeywordValid(const std::string& keyword)// check if the  Keyword is valid
{
  if(keyword == "Again" || keyword == "If" || keyword == "Assign" || keyword == "Move" || keyword == "Show" 
  || keyword == "Flip" || keyword == "Name" || keyword == "Home" || keyword == "Do" || keyword == "Spot"
  || keyword == "Place" || keyword == "Here" || keyword == "There")
  {
    cout << " Valid KeyWord";
    
  }
  else
  {
    cout << " Invalid KeyWord";
  }
   
    

}

void Scanner::printToken(Token *&token)// takes in a token and prints its instance, token id, and line number
{
  cout << token->tokenInstance << " ";
  
  if(token->tokenID == 1002)
  {
    string instance = token->tokenInstance;
    if(isalpha(instance.back()) == false)
    {
      cout<< " Error Invalid token ";
    }
    else
    {
      isKeywordValid(token->tokenInstance);
    }
  }
  else
  {
    displayTokenID(token->tokenID);
  }
  cout << " Line: " << token->lineNum<<endl;
  
}


void Scanner::scanToken(const std::string input, int line)//takes in string and with each character goes through the fsa table to find the token id
{
  string str = "";
  int row = 0, col = 0,entry, x = 0;
  int inputNum = input.length();
 
  char stringChar[inputNum+1];
  strcpy(stringChar,input.c_str());
  
  //cout<<input<<endl;
  while(stringChar[x] != '\0')
  {
    if(stringChar[x] == '\n')
    {
      line++;
    }
    col = getChar(stringChar[x]);
    if(isspace(stringChar[x]) == false)
    {
      str.append(1,stringChar[x]);
    }
    
    
    if (col == -1)
    {
      cout << "Error invalid token " << str << " Line: " << (line + 1) <<endl;
      return;
    }
    
    entry = fsaTable[row][col];
    if (entry == -1)
    {
      cout << "Error invalid token " << str << " Line: " << (line + 1)  <<endl;
      return;
    }
    
    if(entry > 1000 && entry != 1005)
    {
      Token *newToken = nullptr;
      newToken = new Token;
      newToken->tokenID = entry;
      newToken->tokenInstance = str;
      newToken->lineNum += line;
      printToken(newToken);

      row = 0;
      str = "";
      
    }
    else
    {
      
      row = entry;
    }
    
    
    x++;
  }
  
  
  
}