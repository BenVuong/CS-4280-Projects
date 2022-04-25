//filename: BuildTree.cpp
#include<bits/stdc++.h>
#include <iostream>
#include "Node.h"
#include "BuildTree.h"
using namespace std;

//insert a node into a tree
//starts at the root and inserts in the correct position
//if a node has the same key value dont insert node 
//but increase count by one and add word to a string of words of the node
void BuildTree::insert(Node *&nodePtr, Node *&newNode, std::string newWord)
{
  if (nodePtr == nullptr)
  {
    nodePtr = newNode;
  }
  else if (newNode->key < nodePtr->key)
  {
    insert (nodePtr->left, newNode, newWord);
  }
  else if (newNode->key > nodePtr->key)
  {
    insert(nodePtr->right, newNode, newWord);
  }
  else
  {
    nodePtr->count++;
    nodePtr->word = nodePtr->word + " " + newWord;
  }
}

//function takes in key value then creates a node with that key value
//then sends that node to the insert function
void BuildTree::insertNode(int num, std::string newWord)
{
  Node *newNode = nullptr;
  
  newNode = new Node;
  newNode->key = num;
  newNode->word = newWord;
  newNode->left = newNode->right = nullptr;
  insert(root, newNode, newWord);
}