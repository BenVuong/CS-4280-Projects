//filename: token.h
#ifndef TOKEN_H
#define TOKEN_H
#include <string>
using namespace std;
struct Token
{
  int tokenID;
  string tokenInstance;
  int lineNum = 1;
};
#endif