#include "avl.h"
#include <iostream>

using namespace std;
/*
void avl::preorder() const {
    preorder(root);
}

void avl::in_order() const {
  in_order(root);
}

*/



    int height(Node *t){
      return t == nullptr ? -1 :t->height;
    }

    int max(int a, int b) { 
      return (a > b)? a : b; 
} 



Node *lr(Node *x)  {  
    Node *y = x->right;  
    Node *T2 = y->left;  
  
     
    y->left = x;  
    x->right = T2;  
  
      
    x->height = max(height(x->left),     
                    height(x->right)) + 1;  
    y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
     
    return y;  
}  

Node *rr(Node *y)  {  
    Node *x = y->left;  
    Node *T2 = x->right;  
  
    
    x->right = y;  
    y->left = T2;  
  
     
    y->height = max(height(y->left), 
                    height(y->right)) + 1;  
    x->height = max(height(x->left), 
                    height(x->right)) + 1;  
  
    
    return x;  
} 






bool biggerkey(int num1, int decimal1, int num2, int decimal2){
  if((num1 > num2)|| (num1 == num2)){
    if(decimal1 > decimal2){
      return true;
    }
    else if(num1 > num2){
      return true;
    }
  }
  else if(num1 < num2){
    return false;
  }

  
}
/*
void avl::preorder(Node *n) const {
    if (n) {
      cout << n->num << n->decimal << " ";
      preorder(n->left);
      preorder(n->right);
    }
  }
  void avl::in_order(Node *n) const{
    if (n) {
      in_order(n->left);
      cout << n->num << n->decimal  << " ";
      in_order(n->right);
    }
  } 
  
*/
Node* newNode(int num, int decimal) {  
    Node* node = new Node(); 
    node->num = num;  
    node->decimal = decimal;
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




Node* insertH(Node* n, int num, int decimal){
  if(n == NULL){
    return newNode(num, decimal);
  }

  if((n->num == num) &&(n->decimal == decimal)){
    return n;
  }

  else if(biggerkey(n->num, n->decimal, num, decimal) == true){
    n->left = insertH(n->left, num, decimal);
  }

  else{
    n->right= insertH(n->right, num, decimal);

  }
  


  n->height = 1 + max(height(n->left),height(n->right));

  int balance = balancef(n);

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

void avl::insert(int num, int decimal){
  if(this->root == NULL){
    this->root = newNode(num,decimal);
  }
  else{
    this->root = insertH(this->root, num, decimal);
  }
}


  

