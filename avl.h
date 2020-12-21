#ifndef AVL_H
#define AVL_H


#include <iostream>


using namespace std;

class Node  
{  
    public:   
    Node *left = nullptr;  
    Node *right = nullptr;  
    int height = 1; 
    int num;
    int decimal; 
    
    
};  

class avl{
  public:
    void insert(int num, int decimal);
    void Delete(int num, int decimal);
    void search(int num, int decimal);
    void approx_search(int num, int decimal);

    int max(int a, int b);
    
    
    void in_order() const;
    void preorder() const;
    
    Node *root = NULL;
    int k;
    avl(int k);

  private:
  
    void in_order(Node* n) const;
    void preorder(Node* n) const;
    
};




#endif