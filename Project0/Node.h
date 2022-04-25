//filename: Node.h
#ifndef NODE_H
#define NODE_H
#include <string>
//declares a node struct and 
//all of its properties
struct Node
{
  char key;
  Node *left;
  Node *right;
  int count = 1;
  int level;
  std::string word="";
};

#endif 