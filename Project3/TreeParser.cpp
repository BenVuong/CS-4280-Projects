//filename: TreeParser.cpp
#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
#include <list>
#include "Scanner.h"
#include "TreeParser.h"
#include "Token.h"
#include "Node.h"
#include "SemanticChecker.h"
using namespace std;
Node* TreeParser::getNode(char tokenLabel)
{
  Node *newNode = nullptr;
  
  newNode = new Node;
  newNode->label = tokenLabel;
  return newNode;
}

Node* TreeParser::buildParserTree(string input)
{
  cout<<"Building Parse Tree now"<<endl;
  tk = scan.scanToken(input, 0);
  root = S(input);
  return root;
 
}

Node* TreeParser::S(string input)
{
  Node* s = getNode('S');
  
  if(tk.tokenInstance == "Name")
  {
    s->token1 = tk.tokenInstance;
    tk = scan.scanToken(input,0);
    if(tk.tokenID == 1001)
    {
      s->token2 = tk.tokenInstance;
      tk = scan.scanToken(input,0);
      if(tk.tokenInstance == "Spot")
      {
        s->token3 = tk.tokenInstance;
        tk = scan.scanToken(input,0);
        if(tk.tokenID == 1001)
        {
          s->token4 = tk.tokenInstance;
          tk = scan.scanToken(input,0);
          s->middleChild = nullptr;
          s->leftChild = R(input);
          tk = scan.scanToken(input,0);
          s->rightChild = E(input);  
            
        }
      }
    } 
  }
  return s; 
}


Node* TreeParser::R(string input)
{
  Node* r = getNode('R');
  
  if(tk.tokenInstance == "Place")
  {
    r->token1 = tk.tokenInstance;
    tk = scan.scanToken(input,0);
    r->leftChild = A(input);
    tk = scan.scanToken(input,0);
    r->middleChild = B(input);
    if(tk.tokenInstance == "Home")
    {
      r->token2 = tk.tokenInstance;
      
    }
  
  }
  return r;
}

Node* TreeParser::A(string input)
{
  Node* a = getNode('A');
  
  if(tk.tokenInstance == "Name")
  {
    a->token1 = tk.tokenInstance;
    tk = scan.scanToken(input,0);
    if(tk.tokenID == 1001)
    {
      a->token2 = tk.tokenInstance;
      
    }
  }
  
  return a;
}

Node* TreeParser::E(string input)
{
  Node* e = getNode('E');
  
  if(tk.tokenInstance == "Show")
  {
    e->token1 = tk.tokenInstance;
    tk = scan.scanToken(input,0);
    if(tk.tokenID == 1001)
    {
      e->token2 = tk.tokenInstance;
      
    }
  }
  return e;
}

Node* TreeParser::G(string input)
{
  Node* g = getNode('G');
  
  if(tk.tokenInstance == "Here");
  {
    g->token1 = tk.tokenInstance;
    tk = scan.scanToken(input,0);
    if(tk.tokenID == 1004)
    {
      g->token2 = tk.tokenInstance;
      tk = scan.scanToken(input,0);
      if(tk.tokenInstance == "There")
      {
        g->token3 = tk.tokenInstance;
      }
    }
  }
  return g;
}

Node* TreeParser::T(string input)
{
  Node* t = getNode('T');
  
  if(tk.tokenInstance == "<<" || tk.tokenInstance == "<-")
  {
    t->token1 = tk.tokenInstance;
  }
  
  return t;
}

Node* TreeParser::V(string input)
{
  Node* v = getNode('V');
  
  if(tk.tokenInstance == "+" || tk.tokenInstance == "%" || tk.tokenInstance == "&")
  {
    v->token1 = tk.tokenInstance;
  }
  
  return v;
}

Node* TreeParser::K(string input)
{
  Node* k = getNode('K');
  
  if(tk.tokenInstance == "Spot")
  {
    k->token1 = tk.tokenInstance;
    tk = scan.scanToken(input,0);
    if(tk.tokenID == 1004)
    {
      k->token2 = tk.tokenInstance;
      tk = scan.scanToken(input,0);
      if(tk.tokenInstance == "Show")
      {
        k->token3 = tk.tokenInstance;
        tk = scan.scanToken(input,0);
        if(tk.tokenID == 1004)
        {
          k->token4 = tk.tokenInstance;
        }
      }
    }
  }
  else if(tk.tokenInstance == "Move")
  {
    k->token1 = tk.tokenInstance;
    tk = scan.scanToken(input,0);
    if(tk.tokenID == 1001)
    {
      k->token2 = tk.tokenInstance;
      tk = scan.scanToken(input,0);
      if(tk.tokenInstance == "Show")
      {
        k->token3 = tk.tokenInstance;
        tk = scan.scanToken(input,0);
        if(tk.tokenID == 1001)
        {
          k->token4 = tk.tokenInstance;
        }
      }
    }
  }
  
  return k;
}

Node* TreeParser::L(string input)
{
  Node* l = getNode('L');
  
  if(tk.tokenInstance == "Flip")
  {
    l->token1 = tk.tokenInstance;
    tk = scan.scanToken(input,0);
    if(tk.tokenID == 1001)
    {
      l->token2 = tk.tokenInstance;
      
    }
  }
  
  return l;
}

Node* TreeParser::Z(string input)
{
  Node* z = getNode('Z');
  
  if(tk.tokenID == 1001 || tk.tokenID == 1001)
  {
    z->token1 = tk.tokenInstance;
  
  }
  
  return z;
}

Node* TreeParser::H(string input)
{
  Node* h = getNode('H');
  
  if(tk.tokenInstance == "/")
  {
    h->token1 = tk.tokenInstance;
    tk = scan.scanToken(input,0);
    h->leftChild = Z(input);
  }
  
  return h;
}

Node* TreeParser::W(string input)
{
  Node* w = getNode('W');
  
  if(tk.tokenID == 1004)
  {
    w->token1 = tk.tokenInstance;
    tk = scan.scanToken(input,0);
    if(tk.tokenInstance == "+" || tk.tokenInstance == "%" || tk.tokenInstance == "&")
    {
      w->leftChild = V(input);
      tk = scan.scanToken(input,0);
      if(tk.tokenID == 1004)
      {
        w->token2 = tk.tokenInstance;
      } 
    }
    else if(tk.tokenInstance == ".")
    {
      w->token2 = tk.tokenInstance;
    }
  }
  
  return w;

}

Node* TreeParser::J(string input)
{
  Node* j = getNode('J');
  
  if(tk.tokenInstance == "Assign")
  {
    j->token1 = tk.tokenInstance;
    tk = scan.scanToken(input,0);
    if(tk.tokenID == 1001)
    {
      j->token2 = tk.tokenInstance;
      tk = scan.scanToken(input,0);
      j->leftChild = D(input);
      
    }
  }
  
  return j;
}

Node* TreeParser::D(string input)
{
  Node* d = getNode('D');
  
  if(tk.tokenInstance == "/")
  {
    d->leftChild = H(input);
    
  }
  else if(tk.tokenInstance == "Assign")
  {
    d->leftChild = J(input);
    
  }
  else if(tk.tokenInstance == "Spot" || tk.tokenInstance == "Move")
  {
    d->leftChild = K(input);
    
  }
  else if(tk.tokenInstance == "Flip")
  {
    d->leftChild = L(input);
    
  }
  else if(tk.tokenInstance == "Show")
  {
    d->leftChild = E(input);
    
  }
  else if(tk.tokenInstance == "{")
  {
    d->leftChild = F(input); 
    
  }
  
  return d;
}


Node* TreeParser::F(string input)
{
  Node* f = getNode('F');
  
  if(tk.tokenInstance == "{")
  {
    f->token1 = tk.tokenInstance;
  }
  
  tk=scan.scanToken(input,0);
  if(tk.tokenInstance == "If")
  {
    f->token2 = tk.tokenInstance;
    tk = scan.scanToken(input, 0);
    if(tk.tokenID == 1001)
    {
      f->token3 = tk.tokenInstance;
      tk = scan.scanToken(input,0);
      f->leftChild = T(input);
      tk = scan.scanToken(input,0);
      f->middleChild = W(input);
      tk = scan.scanToken(input,0);
      f->rightChild = D(input);
      tk = scan.scanToken(input,0);
      if (tk.tokenInstance == "}")
      {
        f->token4 = tk.tokenInstance;
      }
      
    }
  
  }
  else if(tk.tokenInstance == "Do")
  {
    f->token2 = tk.tokenInstance;
    tk = scan.scanToken(input, 0);
    if(tk.tokenInstance == "Again")
    {
      f->token3 = tk.tokenInstance;
      tk = scan.scanToken(input,0);
      f->leftChild = D(input);
      tk = scan.scanToken(input,0);
      f->middleChild = T(input);
      tk = scan.scanToken(input,0);
      f->rightChild = W(input);
      tk = scan.scanToken(input,0);
      if (tk.tokenInstance == "}")
      {
        f->token4 = tk.tokenInstance;
      }
      
    }

  }
 return f; 
}

Node* TreeParser::C(string input)
{
  Node* c = getNode('C');
  
  if(tk.tokenInstance == "{")
  {
    c->leftChild = F(input);
  
  }
  else if(tk.tokenInstance == "Here")
  {
    c->leftChild = G(input);
  }
  
  return c;
}

Node* TreeParser::B(string input)
{
  Node* b = getNode('B');
  
  if(tk.tokenInstance == "Home")
  {
    b->token1 = "";
    b->leftChild = nullptr;
    b->middleChild = nullptr;
  }
  else if(tk.tokenInstance == ".")
  {
    b->token1 = tk.tokenInstance;
    tk = scan.scanToken(input, 0);
    b->leftChild = C(input);
    tk = scan.scanToken(input, 0);
    if(tk.tokenInstance == ".")
    {
      b->token2 = tk.tokenInstance;
      tk = scan.scanToken(input, 0);
      b->middleChild = B(input);
    }
  }
  else if(tk.tokenInstance == "/" || tk.tokenInstance == "Assign" || tk.tokenInstance == "Spot" || tk.tokenInstance == "Move" || tk.tokenInstance == "Flip" || tk.tokenInstance == "Show" || tk.tokenInstance == "{")
  {
    b->leftChild = D(input);
    tk = scan.scanToken(input, 0);
    b->middleChild = B(input);
  }
  
  
  return b;

}


