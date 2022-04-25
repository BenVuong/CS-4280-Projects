//filename: Traversals.cpp
#include<bits/stdc++.h>
#include <iostream>
#include "Node.h"
#include "BuildTree.h"
using namespace std;
int i;

void displayInOrder(Node *nodePtr)
{
  if (nodePtr)
  {
    displayInOrder(nodePtr->left);
    string str;
    str.append(1,nodePtr->key);
    cout << str << " " << nodePtr-> word << " " << endl;
    displayInOrder(nodePtr->right);
  }
}

void displayPreOrder(Node *nodePtr)
{
  if (nodePtr)
  {
    string str;
    str.append(1,nodePtr->key);
    cout << str << " " << nodePtr->word << " " << endl;
    displayPreOrder(nodePtr->left);
    displayPreOrder(nodePtr->right);
  }
}

void displayPostOrder(Node *nodePtr)
{
  if (nodePtr)
  {
    displayPostOrder(nodePtr->left);
    displayPostOrder(nodePtr->right);
    string str;
    str.append(1, nodePtr->key);
    cout << str << " " << nodePtr->word << " " << endl;
  }
}

//calculates the node a binary tree
int height(Node *nodePtr)
{
  if (nodePtr == nullptr)
  {
    return 0;
  }
  else
  {
    int lheight = height(nodePtr->left);
    int rheight = height(nodePtr->right);
    
    if (lheight > rheight)
    {
      return (lheight + 1);
    }
    else
    {
      return (rheight + 1);
    }
  }
}

void printCurrentLevel(Node *nodePtr, int level)
{
  if (nodePtr == nullptr)
  {
    return;
  }
  
  if(level == 0)
  {
    string str;
    str.append(1,nodePtr->key);
    if(i > 0)
    {
      //indenations for each level
      //1 space for level 1
      //2 spaces for level 2
      for(int x = 0; x <i; x++)
      {
        cout << " ";
      }
    }
    cout << "Level " << i << " " << str << " " << nodePtr->word << " " << endl;
  }
  else if (level > 0)
  {
    
    printCurrentLevel(nodePtr->left, level - 1);
    printCurrentLevel(nodePtr->right, level - 1);
    
  }
}

//prints the tree going through level by level
void traverseLevelOrder(Node *nodePtr)
{
  int h = height(nodePtr);
  
  for (i = 0; i <= h; i++)
  {
    printCurrentLevel(nodePtr, i);
  }
}



