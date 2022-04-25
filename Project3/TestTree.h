//filename: TestTree.h
#ifndef TESTTREE_H
#define TESTTREE_H
#include <string>
#include <list>
#include <algorithm>
#include "Token.h"
#include "Scanner.h"
#include "Node.h"
#include "TreeParser.h"
#include "SemanticChecker.h"
using namespace std;
class TestTree
{
private:
void printIndent(int level);//print spaces to indent new line according to node's level
string table[2] = {" ", " "};
public:
  void printTree(Node *, int level);//print the parse tree in preorder
  void displaySymbolTable();

};
#endif