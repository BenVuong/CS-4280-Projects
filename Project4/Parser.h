#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <list>
#include <algorithm>
#include "Token.h"
#include "Scanner.h"
#include "TreeParser.h"
#include "TestTree.h"
#include "CodeGen.h"
using namespace std;
class Parser
{
private:
;
//CodeGen generator;
Scanner scan;
Token tk;
TreeParser parseTree;
string testInput;
TestTree tree;
void S(string input);
void R(string input);
void E(string input);
void A(string input);
void B(string input);
void C(string input);
void D(string input);
void F(string input);
void G(string input);
void T(string input);
void V(string input);
void H(string input);
void J(string input);
void K(string input);
void L(string input);
void W(string input);
void Z(string input);

public:
void startParser(string input);
Node* getRoot();

};

#endif