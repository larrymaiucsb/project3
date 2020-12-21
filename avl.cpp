#include "avl.h"
#include <iostream>
#include <stdlib.h>
#include<bits/stdc++.h>
#include <cstdlib>

using namespace std;

avl::avl(int k){
  root = nullptr;
  this->k = k;
}
void avl::preorder() const {
    preorder(root);
    cout << endl;
}

void avl::in_order() const {
  in_order(root); 
  cout << endl;
}





    int height(Node *t){
      return t == nullptr ? -1 :t->height;
    }

    int avl::max(int a, int b) { 
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





/*
bool biggerkey(int num1, int decimal1, int num2, int decimal2){
  if((num1 > num2)|| (num1 == num2)){
    if(decimal1 > decimal2){
      
      return true;
    }
    else if(num1 > num2){
      return true;
    }
    else{
      return false;
    }
  }
  else if(num1 < num2){
    return false;
  }

  
} 
*/

bool biggerkey(int num1, int decimal1, int num2, int decimal2){
  if(num1 < num2){
    return false;
  }
  else if (num1 == num2){
    if(decimal1 < decimal2){
      return false;
    }
    else{
      return true;
    }
  }
  else{
    return true;
  }
}
bool firsttime1 = true;
bool firsttime2 = true;
int counter1 = 0;
int counter2 = 0;
void avl::preorder(Node *n) const {
  if (n != NULL) {  
    if(counter1 == 0){
      counter1++;
      cout << n->num << "." << n->decimal;
      preorder(n->left);
      preorder(n->right);
    }
    else{
      cout << " " << n->num << "." << n->decimal;
    }
  }
}
  void avl::in_order(Node *n) const{
    if (n != NULL) {
      if(counter2 == 0){
        counter2++;
          in_order(n->left);
          cout << n->num << "." << n->decimal;
          in_order(n->right);
        }
    }
    else{
      cout << " " << n->num << "." << n->decimal;
    }
} 
  

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
    
  else if(n->left == NULL){
    
    return 0 - height(n->right);
  }
  
  else if(n->right == NULL){
    return height(n->left)- 0;
  }
  
  else{
    return height(n->left)- height(n->right);
  }
}




Node* insertH(Node* n, int num, int decimal, int k){
  if(n == nullptr){
    return newNode(num, decimal);
  }

  if((n->num == num) &&(n->decimal == decimal)){
    return n;
  }

  else if(biggerkey(n->num, n->decimal, num, decimal) == true){
    n->left = insertH(n->left, num, decimal, k);
  }

  else{
    
    n->right= insertH(n->right, num, decimal, k);
    

  }
  


  n->height = 1 + max(height(n->left),height(n->right));
  
  int balance = balancef(n);
  
  
  if((balance > k) && biggerkey(n->left->num, n->left->decimal, num, decimal)){

    return rr(n);
  }

  

  if((balance < (-1* k)) && biggerkey(num, decimal, n->right->num, n->right->decimal)) {
    
   
    return lr(n);
  }
 

  if((balance > k)  &&  biggerkey(num, decimal, n->left->num, n->left->decimal)){
    
    n->left = lr(n->left);
    return rr(n);
  }
  

  if((balance < (-1*k)) && biggerkey(n->left->num, n->left->decimal, num, decimal)){
    
    n->right = rr(n->right);
    return lr(n);
  }

  return n;

}

void avl::insert(int num, int decimal){
  if(this->root == NULL){
    this->root = newNode(num,decimal);
    cout << num << "." << decimal << " inserted" << endl;
  }
  else{
    
    this->root = insertH(this->root, num, decimal,k);
    cout << num << "." << decimal << " inserted" << endl;
  }
}



Node * minValueNode(Node* node)  
{  
    Node* current = node;  
  
   
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}  

Node* deleteh(Node* root, int num, int decimal,int k){
   
    if (root == NULL)  
        return root;  
  
    
    if (biggerkey(root->num,root->decimal,num,decimal)){ 
      
        root->left = deleteh(root->left, num, decimal, k);  
    }
   
    else if(biggerkey(num,decimal,root->num,root->decimal)){
      
        root->right = deleteh(root->right, num, decimal, k);  
    }
 
    else
    {  
      
        
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            Node *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else  
            *root = *temp; 
            free(temp);  
        }  
        else
        {  
             
            Node* temp = minValueNode(root->right);  
  
            
            root->num = temp->num;  
            root->decimal = temp->decimal;
   
            root->right = deleteh(root->right,  
                                     temp->num,temp->decimal, k);  
            
        }  
    }  
  
     
    if (root == NULL)  
    return root;  
  
    
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
   
    int balance = balancef(root);  
  
 
    if (balance > k &&  
        balancef(root->left) >= 0)  
        return rr(root);  
  
    
    if (balance > k &&  
        balancef(root->left) < 0)  
    {  
        root->left = lr(root->left);  
        return rr(root);  
    }  
  
     
    if (balance < (-1*k) &&  
       balancef(root->right) <= 0)  
        return lr(root);  
  
      
    if (balance < (-1*k) &&  
        balancef(root->right) > 0)  
    {  
        root->right = rr(root->right);  
        return lr(root);  
    }  
  
    return root;  
}

void avl::Delete(int num, int decimal){
  
  deleteh(this->root, num, decimal, k);
  cout << num << "." << decimal << " deleted" << endl;
}

bool findh(struct Node* node, int num, int decimal)
{
    if (node == NULL)
        return false;
 
    if ((node->num == num) && (node->decimal == decimal))
        return true;
 
  
    bool res1 = findh(node->left, num,decimal);
    
    if(res1) return true; 
 

    bool res2 = findh(node->right, num,decimal);
 
    return res2;
} 


void avl::search(int num, int decimal){
  if( findh(this->root, num, decimal)){
    cout << num << "." << decimal << " found" << endl;
  }
  else{
    cout << num << "." << decimal << " not found" << endl;
  }
}



void asearchhelper(struct Node* n, int num, int decimal, int &min_diff,int &min_diff_num, int &min_diff_decimal){
    if(n == NULL){
      return ;
    }
    
    if((n->num == num)&& (n->decimal == decimal)){
      min_diff_num = num;
      min_diff_decimal = decimal;
      return;

    }

    if(min_diff > abs(n->num - num)){
      min_diff = abs(n->num - num);
      min_diff_num = n->num;
      min_diff_decimal = n->decimal;
    }
    if(num < n->num){
      asearchhelper(n->left, num, decimal, min_diff, min_diff_num, min_diff_decimal);
    }
    else{
      asearchhelper(n->right, num, decimal, min_diff, min_diff_num, min_diff_decimal);
    }


}

int wrapperasearch(Node *n, int num, int decimal){
  int min_diff = INT_MAX, min_diff_num, min_diff_decimal = -1;
  asearchhelper(n,num,decimal,min_diff,min_diff_num, min_diff_decimal);
  return min_diff_num;
}

int wrapperasearchdecimal(Node*n, int num, int decimal){
  int min_diff = INT_MAX, min_diff_num, min_diff_decimal = -1;
  asearchhelper(n,num,decimal,min_diff,min_diff_num,min_diff_decimal);
  return min_diff_decimal;
}

void avl::approx_search(int num, int decimal){

  cout <<"closest to " << num  << "." << decimal << " is " << wrapperasearch(root, num, decimal) << "." << wrapperasearchdecimal(root, num, decimal) << endl;
      
}
