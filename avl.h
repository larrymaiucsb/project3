#include <iostream>

class avl{
  public:
    void insert(int num, int decimal);
    void Delete(int num, int decimal);
    bool search(int num, int decimal);
    void approx_search(int num, int decimal);
    void in_order();
    void preorder();

  private:
    struct Node{
      int num;
      int decimal;

      Node*  left;
      Node* right;
      int height;

      
    };

    int height(Node *t)const{
      return t == nullptr ? -1 :t->height;
    }

    int max(int a, int b) { 
      return (a > b)? a : b; 
} 
  void avl::preorder(Node *n) const {
    if (n) {
      cout << n->info << " ";
      preorder(n->left);
      preorder(n->right);
    }
  }
  void avl::in_order(Node *n) const{
    if (n) {
      in_order(n->left);
      cout << n->info << " ";
      in_order(n->right);
    }
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



}