#include "avl.h"
#include <iostream>

using namespace std;

void avl::preorder() const {
    preorder(root);
}

void avl::in_order() const {
  in_order(root);
}



Node* newNode(int key) {  
    Node* node = new Node(); 
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1; 
    return(node);  
}  

int balancef(Node* n){
  if (n == NULL){
    return 0;
  }
  else{
    return height(n->left)- height(n->right);
  }
}

void avl::insert(int num, int decimal){
  this->root = insertH(this->root, num, decimal);
}


avl::Node* avl::insertH(Node* n, int num, int decimal){
  if(n == NULL){
    return newNode(num, decimal);
  }

  if(n->num == num) &&(n->decimal == decimal){
    return n;
  }

  else if(biggerkey(n->num, n->decimal, num, decimal) == true){
    node->left = insertH(node->left, int num, int decimal);
  }

  else{
    node->right= insertH(node->right, int num, int decimal);

  }
  


  n->height = 1 + max(height(node->left),height(node->right));

  int balance = balancef(node);

  if(biggerkey(n->left->num, n->left->decimal, num, decimal) && balance > 1){
    return rr(n);
  }

  if(biggerkey(num, decimal, n->right->num, n->right->decimal)==true && balance <-1) {
    return lr(n);
  }

  if(biggerkey(num, decimal, n->left->num, n->left->decimal)==true && balance >1){
    n->left = lr(n->left);
    return rr(n);
  }

  if(biggerkey(n->left->num, n->left->decimal, num, decimal) && balance > 1){
    n->right = rr(n->right);
    return lr(n);
  }


}


  

