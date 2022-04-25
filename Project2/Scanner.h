//filename: Scanner.h
#ifndef SCANNER_H
#define SCANNER_H
#include <string>
#include <list>
#include "Token.h"
#include <algorithm>
using namespace std;
class Scanner
{
private:
  int fsaTable[10][9];

public:
  list<Token> listOfTokens;
  string testInput;
  int x = 0;
  int lineNum = 0;

  Scanner()
  {
    
    fsaTable[0][0] = 1;
    fsaTable[0][1] = 3;
    fsaTable[0][2] = 6;
    fsaTable[0][3] = 4;
    fsaTable[0][4] = 5;
    fsaTable[0][5] = -1;
    fsaTable[0][6] = 7;
    fsaTable[0][7] = 0;
    fsaTable[0][8] = 1006;
    
    fsaTable[1][0] = 2;
    fsaTable[1][1] = 2;
    fsaTable[1][2] = 2;
    fsaTable[1][3] = -1;
    fsaTable[1][4] = -1;
    fsaTable[1][5] = -1;
    fsaTable[1][6] = -1;
    fsaTable[1][7] = -1;
    fsaTable[1][8] = -1;
    
    fsaTable[2][0] = 2;
    fsaTable[2][1] = 2;
    fsaTable[2][2] = 2;
    fsaTable[2][3] = 1001;
    fsaTable[2][4] = 1001;
    fsaTable[2][5] = 1001;
    fsaTable[2][6] = 1001;
    fsaTable[2][7] = 1001;
    fsaTable[2][8] = 1001;
    
    fsaTable[3][0] = 3;
    fsaTable[3][1] = 1002;
    fsaTable[3][2] = 1002;
    fsaTable[3][3] = 1002;
    fsaTable[3][4] = 1002;
    fsaTable[3][5] = 1002;
    fsaTable[3][6] = 1002;
    fsaTable[3][7] = 1002;
    fsaTable[3][8] = 1002;
    
    fsaTable[4][0] = 1003;
    fsaTable[4][1] = 1003;
    fsaTable[4][2] = 1003;
    fsaTable[4][3] = 1003;
    fsaTable[4][4] = 1003;
    fsaTable[4][5] = 1003;
    fsaTable[4][6] = 1003;
    fsaTable[4][7] = 1003;
    fsaTable[4][8] = 1003;
    
    fsaTable[5][0] = -1;
    fsaTable[5][1] = -1;
    fsaTable[5][2] = -1;
    fsaTable[5][3] = -1;
    fsaTable[5][4] = 9;
    fsaTable[5][5] = 9;
    fsaTable[5][6] = -1;
    fsaTable[5][7] = -1;
    fsaTable[5][8] = -1;
    
    fsaTable[6][0] = 1004;
    fsaTable[6][1] = 1004;
    fsaTable[6][2] = 6;
    fsaTable[6][3] = 1004;
    fsaTable[6][4] = 1004;
    fsaTable[6][5] = 1004;
    fsaTable[6][6] = 1004;
    fsaTable[6][7] = 1004;
    fsaTable[6][8] = 1004;
    
    
    fsaTable[7][0] = 7;
    fsaTable[7][1] = 7;
    fsaTable[7][2] = 7;
    fsaTable[7][3] = 7;
    fsaTable[7][4] = 7;
    fsaTable[7][5] = 7;
    fsaTable[7][6] = 8;
    fsaTable[7][7] = 7;
    fsaTable[7][8] = -1;
    
    fsaTable[8][0] = 1005;
    fsaTable[8][1] = 1005;
    fsaTable[8][2] = 1005;
    fsaTable[8][3] = 1005;
    fsaTable[8][4] = 1005;
    fsaTable[8][5] = 1005;
    fsaTable[8][6] = 1005;
    fsaTable[8][7] = 1005;
    fsaTable[8][8] = 1005;
    
    
    fsaTable[9][0] = -1;
    fsaTable[9][1] = -1;
    fsaTable[9][2] = -1;
    fsaTable[9][3] = -1;
    fsaTable[9][4] = 1003;
    fsaTable[9][5] = 1003;
    fsaTable[9][6] = -1;
    fsaTable[9][7] = 1003;
    fsaTable[9][8] = 1003;
  }
  Token getToken();
  void displayTable();
  int getChar(char);
  int countWords(const std::string input);
  list <Token> returnListOfTokens( );
  Token scanToken( const std::string input, int line);
  void displayTokenID(int);
  void isKeywordValid(const std::string& );
  void printToken(Token );
  void printListOfTokens();
  

};

#endif