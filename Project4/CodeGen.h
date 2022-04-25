//filename: CodeGen.h
#ifndef CODEGEN_H
#define CODEGEN_H
#include <string>
#include <list>
#include <fstream>
#include <algorithm>
#include "Token.h"
#include "Scanner.h"
#include "Node.h"
#include "TreeParser.h"
#include "SemanticChecker.h"
using namespace std;
class CodeGen
{
private:

public:
  void generateCode(Node *, int level);
  list<string> code;
};
#endif