#ifndef AVL_H
#define AVL_H


#include <iostream>

using namespace std;

class Node  
{  
    public:   
    Node *left = nullptr;  
    Node *right = nullptr;  
    int height; 
    int num;
    int decimal; 

    
};  

class avl{
  public:
    void insert(int num, int decimal);
    void Delete(int num, int decimal);
    void search(int num, int decimal);
    void approx_search(int num, int decimal);
    
    
    void in_order() const;
    void preorder() const;
    
    Node *root = NULL;

  private:
  
    void in_order(Node* n) const;
    void preorder(Node* n) const;
    
};




#endif