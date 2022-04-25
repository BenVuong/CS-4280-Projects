//filename main.cpp
#include <iostream>
#include <array>
#include <cstring>
#include <string>
#include<bits/stdc++.h>
#include "Node.h"
#include "BuildTree.h"
#include "Traversals.h"
using namespace std;

int main(int argc, char** argv)
{
  int numWords;
  char token;
  BuildTree tree;
  fstream file;
  string word, t, q, filename;
  
  //if the program executed without any arugments
  if(argc == 1)
  {
    cout << "enter in number of words" << endl;
    cin >> numWords;
    for(int x = 0; x < numWords; x++)
    {
      cout << "enter in a word" << endl;
      cin >> word;
      
      //check each letter of the word
      //see if the word has a capital letter, digit, or special character
      //there is then output an error
      for(int y = 0; y < word.length(); y++)
      {
        if(isupper(word.at(y))) 
        {
          cout << "Error: Captial letter" << endl;
          return 1;
        }
        else if(isdigit(word.at(y)))
        {
          cout << "Error: Digit" << endl;
          return 1;
        }
        else if(ispunct(word.at(y)))
        {
          cout << "Error: Special Character" << endl;
          return 1;
        }
      }
      
      token = word.back();
      tree.insertNode(token, word);
    } 
  
  } 
  
  //if the program has an arugment of a filename
  if(argc == 2)
  {
    filename = argv[1];
    file.open(filename.c_str());
  
    if(file == NULL)
    {
      cout << "Error: could not find file" << endl;
      return 1;
    }
    else if (file.peek() == EOF)
    {
      cout << "Error: empty file" << endl;
      return 1;
    }
    else
    {
      while(file >> word)
      {
        
        for(int y = 0; y < word.length(); y++)
        {
          if(isupper(word.at(y))) 
          {
            cout << "Error: Captial letter" << endl;
            return 1;
          }
          else if(isdigit(word.at(y)))
          {
            cout << "Error: Digit" << endl;
            return 1;
          }
          else if(ispunct(word.at(y)))
          { 
            cout << "Error: Special Character" << endl;
            return 1;
          }
        
        }
        
      token = word.back();
      tree.insertNode(token,word);
      }
  }
  
  //if there is more than 1 argument when the program is first executed
  if(argc > 2)
  {
    cout << "Error: improper usage, more than 1 arugment was entered" << endl;
    return 1;
  }
  
  //display the final traversals
  cout << "\nPreOrder traversal" <<endl;
  displayPreOrder(tree.root);
  cout << "\nPostOrder traversal" <<endl;
  displayPostOrder(tree.root);
  cout << "\nLevelOrder traversal" <<endl;
  traverseLevelOrder(tree.root);
  
  return 0;

  }
}