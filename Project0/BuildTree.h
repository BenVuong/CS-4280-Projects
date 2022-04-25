//filename: BuildTree.h
#ifndef BUILDTREE_H
#define BUILDTREE_H
#include "Node.h"
class BuildTree
{
private:
  
  void insert(Node *&, Node *&, std::string word);
  
  
public: 
  Node *root;
  BuildTree() //constructor
  {
    root = nullptr;
  }
  
  void insertNode(int, std::string word);

};
#endif