//filename: Parser.cpp
#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
#include <vector>
#include "Scanner.h"
#include "Parser.h"
#include "Token.h"
#include "CodeGen.h"
using namespace std;
Node*  Parser::getRoot()
{
  return parseTree.root;

}
void Parser::startParser(string input) //takes in the input and goes through all of the node functions to validate each terminal and nonterminals
{
    cout << "\nInput:\n" << input << endl;
    cout << "\nStarting Parser now" << endl;
    tk = scan.scanToken(input, 0);
    S(input);
    tk = scan.scanToken(input, 0);
    if(tk.tokenID == 1006)
    {
      cout << "EOF Token has been met" << endl;
      cout << "Input has been parsed successfully!\n" << endl;
      parseTree.buildParserTree(input);
      tree.printTree(parseTree.root, 0);
      
    }
    else
    {
      cout << "Error: Input is invalid\n" << endl;
      
    }
   
    return;
    
    
}

void Parser::S(string input)
{
    if(tk.tokenInstance == "Name")
    {
      tk = scan.scanToken(input, 0);
      if(tk.tokenID == 1001)
      {
        tk = scan.scanToken(input, 0);
        if(tk.tokenInstance == "Spot")
        {
          tk = scan.scanToken(input, 0);
          if(tk.tokenID == 1001)
          {
            tk = scan.scanToken(input, 0);
            R(input);
            tk = scan.scanToken(input, 0);
            E(input);
            cout<<"Non-Terminal S has been validated"<<endl;
          }
          else
          {
            cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be an Identifier" << endl;
          }
        }
        else
        {
          cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be Keyword: Spot" << endl;
        }
      }
      else
      {
        cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be an Identifier" << endl;
      }
    }
    else
    {
      cout << "Error: token " << tk.tokenInstance << " on Line: " <<tk.lineNum << " should be Keyword: Name"<<endl;
    }
}

void Parser::E(string input)
{
  if(tk.tokenInstance == "Show")
  {
    tk = scan.scanToken(input, 0);
    if(tk.tokenID == 1001)
    {
      cout << "Non-Terminal E has been validated" << endl;
    }
    else
    {
      cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be an Identifier" << endl;
    }
  
  }
  else
  {
    cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be Keyword: Show" << endl;
  }
}

void Parser::A(string input)
{
  if(tk.tokenInstance == "Name")
  {
    tk = scan.scanToken(input, 0);
    if(tk.tokenID == 1001)
    {
      cout << "Non-Terminal A has been validated" << endl;
    }
    else
    {
      cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be an Identifier" << endl;
    }
  }
  else
  {
    cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be Keyword: Name"<<endl;
  }
}

void Parser::R(string input)
{
  if(tk.tokenInstance == "Place")
  {
    tk = scan.scanToken(input,0);
    A(input);
    tk = scan.scanToken(input, 0);
    B(input);
    if(tk.tokenInstance == "Home")
    {
      cout << "Non-Terminal R has been validated" << endl;
    }
    else
    {
      cout << "Error: token " << tk.tokenInstance << " on Line: " <<tk.lineNum << " should be Keyword: Home"<<endl;
    }
  }
  else
  {
    cout << "Error: token " << tk.tokenInstance << " on Line: " <<tk.lineNum << " should be Keyword: Place"<<endl;
  }

}

void Parser::G(string input)
{
  if(tk.tokenInstance == "Here")
  {
    tk = scan.scanToken(input,0);
    if(tk.tokenID == 1004)
    {
      tk = scan.scanToken(input,0);
      if(tk.tokenInstance == "There")
      {
        cout << "Non-Terminal G has been validated" << endl;
      }
      else
      {
        cout << "Error: token " << tk.tokenInstance << " on Line: " <<tk.lineNum << " should be Keyword: There" << endl;
      }
    }
    else
    {
      cout << "Error: token " << tk.tokenInstance << " on Line: " <<tk.lineNum << " should be a Number" << endl;
    }
  }
  else
  {
    cout << "Error: token " << tk.tokenInstance << " on Line: " <<tk.lineNum << " should be Keyword: Here" << endl;
  }
}

void Parser::T(string input)
{
  if(tk.tokenInstance == "<<" || tk.tokenInstance == "<-")
  {
    cout << "Non-Terminal T has been validated" << endl;
  }
  else
  {
    cout << "Error: token " << tk.tokenInstance << " on Line: " <<tk.lineNum << " should be Operator: << or <-" << endl;
  }  
}

void Parser::V(string input)
{
  if(tk.tokenInstance == "+" || tk.tokenInstance == "%" || tk.tokenInstance == "&")
  {
    cout << "Non-Terminal V has been validated" << endl;
  }
  else
  {
    cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be Operator: +, %, or &" << endl;
  }

}

void Parser::K(string input)
{
  if(tk.tokenInstance == "Spot")
  {
    tk = scan.scanToken(input,0);
    if(tk.tokenID == 1004)
    {  
      tk = scan.scanToken(input,0);
      if(tk.tokenInstance == "Show")
      {
        tk = scan.scanToken(input,0);
        if(tk.tokenID == 1004)
        {
          cout << "Non-Terminal K has been validated" << endl;
        }
        else
        {
          cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be a Number" << endl;
        }
      }
      else
      {
        cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be Keyword: Show" << endl; 
      }
    }
    else
    {
      cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be a Number" << endl;
    }
  }
  else if(tk.tokenInstance == "Move")
  {
    tk = scan.scanToken(input,0);
    if(tk.tokenID == 1001)
    {
      tk = scan.scanToken(input,0);
      if(tk.tokenInstance == "Show")
      {
        tk = scan.scanToken(input,0);
        if(tk.tokenID == 1001)
        {
          cout << "Non-Terminal K has been validated" << endl;
        }
        else
        {
          cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be an Identifier" << endl;
        }
      }
      else
      {
        cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be Keyword: Show" << endl;
      }
    }
    else
    {
      cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be an Identifier" << endl;
    }
  }
  else
  {
    cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be Keyword: Spot or Move" << endl;
  }
}

void Parser::L(string input)
{
  if(tk.tokenInstance == "Flip")
  {
    tk = scan.scanToken(input,0);
    if(tk.tokenID == 1001)
    {
      cout << "Non-Terminal L has been validated" << endl;
    }
    else
    {
      cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be an Identifier" << endl;
    }
  }
  else
  {
    cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be Keyword: Flip" << endl;
  }
}

void Parser::Z(string input)
{
  if(tk.tokenID == 1001 || tk.tokenID == 1004)
  {
    cout << "Non-Terminal Z has been validated" << endl;
  }
  else
  {
    cout<<"Error: token " << tk.tokenInstance << " on Line: " <<tk.lineNum << " should be an Identifier or Number"<<endl;
  }
}

void Parser::H(string input)
{
  if(tk.tokenInstance == "/")
  {
    tk = scan.scanToken(input,0);
    Z(input);
    cout << "Non-Terminal H has been validated" << endl;
  }
  else
  {
    cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be Operator: /" << endl;
  }
}

void Parser::W(string input)
{
  if(tk.tokenID == 1004)
  {
    tk = scan.scanToken(input,0);
    if(tk.tokenInstance == "+" || tk.tokenInstance == "%" || tk.tokenInstance == "&")
    {
      V(input);
      tk = scan.scanToken(input,0);
      if(tk.tokenID == 1004)
      {
        cout << "Non-Terminal W has been validated" << endl;
      }
      else
      {
        cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be a Number" << endl;
      }
    }
    else if(tk.tokenInstance == ".")
    {
      cout << "Non-Terminal W has been validated" << endl;
    }
    else
    {
      cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be Operator: +, %, &, or ." << endl;
    }
    
  }
  else
  {
    cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be a Number" << endl;
  }
}

void Parser::J(string input)
{
  if (tk.tokenInstance == "Assign")
  {
    tk = scan.scanToken(input, 0);
    if(tk.tokenID == 1001)
    {
      tk = scan.scanToken(input, 0);
      D(input); 
      cout << "Non-Terminal J has been validated" << endl;
    }
    else
    {
      cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be an Identifier" << endl;
    }
  }
  else
  {
    cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be Keyword: Assign" << endl;
  }
}

void Parser::D(string input)
{
  if(tk.tokenInstance == "/")
  {
    H(input);
    cout << "Non-Terminal D has been validated" << endl;
  }
  else if(tk.tokenInstance == "Assign")
  {
    J(input);
    cout << "Non-Terminal D has been validated" << endl;
  }
  else if(tk.tokenInstance == "Spot" || tk.tokenInstance == "Move")
  {
    K(input);
    cout << "Non-Terminal D has been validated" << endl;
  }
  else if(tk.tokenInstance == "Flip")
  {
    L(input);
    cout << "Non-Terminal D has been validated" << endl;
  }
  else if(tk.tokenInstance == "Show")
  {
    E(input);
    cout << "Non-Terminal D has been validated" << endl;
  }
  else if(tk.tokenInstance == "{")
  {
    tk = scan.scanToken(input, 0);
    F(input); 
    cout << "Non-Terminal D has been validated" << endl;
  }
  else
  {
    cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be (Keyword: Assign, Spot, Move, Flip, or Show) Or (Operator: / or {)" << endl;
  }
}

void Parser::F(string input)
{
  if(tk.tokenInstance == "If")
  {
    tk = scan.scanToken(input, 0);
    if(tk.tokenID == 1001)
    {
      tk = scan.scanToken(input, 0);
      T(input);
      tk = scan.scanToken(input, 0);
      W(input);
      tk = scan.scanToken(input, 0);
      D(input);
      tk = scan.scanToken(input, 0);
      if (tk.tokenInstance == "}")
      {
        cout << "Non-Terminal F has been validated" << endl;
      }
      else
      {
        cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be Operator: }" << endl;
      }
    }
  
  }
  else if(tk.tokenInstance == "Do")
  {
    tk = scan.scanToken(input, 0);
    if(tk.tokenInstance == "Again")
    {
      tk = scan.scanToken(input, 0);
      D(input);
      tk = scan.scanToken(input, 0);
      T(input);
      tk = scan.scanToken(input, 0);
      W(input);
      tk = scan.scanToken(input, 0);
      if (tk.tokenInstance == "}")
      {
        cout << "Non-Terminal F has been validated" << endl;
      }
      else
      {
        cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be Operator: }" << endl;
      }
    }
    else
    {
      cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be Keyword: Again " << endl;
    }
  }
  else
  {
    cout<<"Error: token " << tk.tokenInstance << " on Line: " <<tk.lineNum << " should be Keyword: If or Do"<<endl;
  }
}

void Parser::C(string input)
{
  if(tk.tokenInstance == "{")
  {
    tk = scan.scanToken(input, 0);
    F(input);
    cout << "Non-Terminal C has been validated" << endl;
  }
  else if(tk.tokenInstance == "Here")
  {
    G(input);
    cout << "Non-Terminal C has been validated" << endl;
  }
  else
  {
    cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be Operator: { or Keyword: Here" << endl;
  }
}

void Parser::B(string input)
{
  if(tk.tokenInstance == "Home")
  {
    cout << "Non-Terminal B has been validated" << endl;
  }
  else if(tk.tokenInstance == ".")
  {
    tk = scan.scanToken(input, 0);
    C(input);
    tk = scan.scanToken(input, 0);
    if(tk.tokenInstance == ".")
    {
      tk = scan.scanToken(input, 0);
      B(input);
    }
    else
    {
      cout << "Error: token " << tk.tokenInstance << " on Line: " <<tk.lineNum << " should be Operator: ." <<endl;
    }
  }
  else if(tk.tokenInstance == "/" || tk.tokenInstance == "Assign" || tk.tokenInstance == "Spot" || tk.tokenInstance == "Move" || tk.tokenInstance == "Flip" || tk.tokenInstance == "Show" || tk.tokenInstance == "{")
  {
    D(input);
    tk = scan.scanToken(input, 0);
    B(input);
  }
  else
  {
    cout << "Error: token " << tk.tokenInstance << " on Line: " << tk.lineNum << " should be (Operator: ., /, or {) or (Keyword: Home, Assign, Spot, Move, Flip, or Show) " << endl;
  }
}
