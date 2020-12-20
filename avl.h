#ifndef AVL_H
#define AVL_H


#include <iostream>

using namespace std;

class Node  
{  
    public:   
    Node *left;  
    Node *right;  
    int height; 
    int num;
    int decimal; 
};  

class avl{
  public:
    void insert(int num, int decimal);
    void Delete(int num, int decimal);
    bool search(int num, int decimal);
    void approx_search(int num, int decimal);
    
    /*
    void in_order();
    void preorder();
    */
    Node *root = NULL;

  private:
  /*
    string in_order(Node* n);
    string preorder(Node* n);
    */
};




#endif