//fileName: SemanticChecker.h
#ifndef SEMANTICCHECKER_H
#define SEMANTICCHECKER_H
#include <string>
#include <list>
#include "Token.h"
#include "Scanner.h"
#include "Node.h"

using namespace std;
class SemanticChecker
{

private:
  
  Scanner scan;
  Token tk;

public:
  list<string> symbolTable;
  void check(Node*);
  void displaySymbolTable();
  void addSymbolTable();
  void insert(string id);
  bool verify(string id);
  
  
};

#endif