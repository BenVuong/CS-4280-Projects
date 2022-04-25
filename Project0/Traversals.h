//filename: Traversals.h
#ifndef TRAVERSALS_H
#define TRAVERSALS_H
#include "Node.h"
 
void displayInOrder(Node *);
void displayPreOrder(Node *);
void displayPostOrder(Node *);
void traverseLevelOrder(Node *);
void printCurrentLevel(Node*, int);
int height(Node *);

#endif