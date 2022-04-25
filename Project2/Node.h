//filename: Node.h
#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;
struct Node
{
  char label;
  Node *leftChild;
  Node *middleChild;
  Node *rightChild;
  std::string token1;
  std::string token2;
  std::string token3;
  std::string token4;
};
#endif