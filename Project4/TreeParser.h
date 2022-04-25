//filename: TreeParser.h
#ifndef TREEPARSER_H
#define TREEPARSER_H
#include <string>
#include <list>
#include <algorithm>
#include "Token.h"
#include "Scanner.h"
#include "Node.h"
#include "SemanticChecker.h"
using namespace std;
class TreeParser
{
private:
  
  Scanner scan;
  Token tk;
  void insert(Node *&, Node *&);
  Node* S(string input);
  Node* R(string input);
  Node* E(string input);
  Node* A(string input);
  Node* B(string input);
  Node* C(string input);
  Node* D(string input);
  Node* F(string input);
  Node* G(string input);
  Node* T(string input);
  Node* V(string input);
  Node* H(string input);
  Node* J(string input);
  Node* K(string input);
  Node* L(string input);
  Node* W(string input);
  Node* Z(string input);
  Node* getNode(char tokenLabel);
  
public:
  TreeParser()
  {
    root = nullptr;
  }
  
  Node* root;
  
  
  Node* buildParserTree(string input);
  
  
};

#endif