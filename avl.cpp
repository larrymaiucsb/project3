#include "avl.h"
#include <iostream>
#include <stdlib.h>
#include<bits/stdc++.h>
#include <cstdlib>

using namespace std;

void avl::preorder() const {
    preorder(root);
}

void avl::in_order() const {
  in_order(root);
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






bool biggerkey(int num1, int decimal1, int num2, int decimal2){
  if((num1 > num2)|| (num1 == num2)){
    if(decimal1 > decimal2){
      cout << "num1 bigger" << endl;
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
/*

bool biggerkey(int num1, int decimal1, int num2, int decimal2){
  if(num1 > num2){
    return true;
  }
  else if(num1 == num2){
    if(decimal1 > decimal2){
      return true;
    }
    
  }
  else if(num1 < num2){
    return false;
  }
}
*/
void avl::preorder(Node *n) const {
    if (n != NULL) {
      cout << n->num << "." <<  n->decimal << " " << endl;
      preorder(n->left);
      preorder(n->right);
      
    }
  }
  void avl::in_order(Node *n) const{
    if (n != NULL) {
      in_order(n->left);
      cout << n->num << "." << n->decimal  << " " << endl;
      in_order(n->right);
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
  else{
    cout << "printing left" << endl;
    cout << height(n->left) << endl;
    cout << "printing right" << endl;
    cout << height(n->right) << endl;
    return height(n->left)- height(n->right);
  }
}




Node* insertH(Node* n, int num, int decimal){
  if(n == nullptr){
    return newNode(num, decimal);
  }

  if((n->num == num) &&(n->decimal == decimal)){
    return n;
  }

  else if(biggerkey(n->num, n->decimal, num, decimal) == true){
    n->left = insertH(n->left, num, decimal);
  }

  else{
    cout << "inserting right" << endl;
    n->right= insertH(n->right, num, decimal);
    cout << "inserted right" << endl;

  }
  


  n->height = 1 + max(height(n->left),height(n->right));
  cout << "finished height" << endl;
  int balance = balancef(n);
  cout << "finished balance" << endl;
  cout << balance << endl;
  if((balance > 1) && biggerkey(n->left->num, n->left->decimal, num, decimal)){

    cout << "did a left left case" << endl;
    return rr(n);
  }

  cout << "not ll" << endl;

  if((balance < -1) && biggerkey(num, decimal, n->right->num, n->right->decimal)) {
    cout << balance << endl;
    cout << "did a right right case" << endl;
    return lr(n);
  }
  cout << "not rr" << endl;

  if((balance > 1)  &&  biggerkey(num, decimal, n->left->num, n->left->decimal)){
    cout << "lr" << endl;
    n->left = lr(n->left);
    return rr(n);
  }
  cout << "not lr" << endl;

  if((balance < -1) && biggerkey(n->left->num, n->left->decimal, num, decimal)){
    cout << "rl" << endl;
    n->right = rr(n->right);
    return lr(n);
  }
cout << "not rl" << endl;
  return n;

}

void avl::insert(int num, int decimal){
  if(this->root == NULL){
    this->root = newNode(num,decimal);
  }
  else{
    
    this->root = insertH(this->root, num, decimal);
  }
}



Node * minValueNode(Node* node)  
{  
    Node* current = node;  
  
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
}  

Node* deleteh(Node* root, int num, int decimal){
  // STEP 1: PERFORM STANDARD BST DELETE  
    if (root == NULL)  
        return root;  
  
    // If the key to be deleted is smaller  
    // than the root's key, then it lies 
    // in left subtree  
    if (biggerkey(root->num,root->decimal,num,decimal)){ 
      cout << "lies in left subtree for deletion" << endl;
        root->left = deleteh(root->left, num, decimal);  
    }
    // If the key to be deleted is greater  
    // than the root's key, then it lies  
    // in right subtree  
    else if(biggerkey(num,decimal,root->num,root->decimal)){
      cout << "lies in right subtree for deletion" << endl;
        root->right = deleteh(root->right, num, decimal);  
    }
    // if key is same as root's key, then  
    // This is the node to be deleted  
    else
    {  
      cout<< "found node to delete" << endl;
        // node with only one child or no child  
        if( (root->left == NULL) || 
            (root->right == NULL) )  
        {  
            Node *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }  
            else // One child case  
            *root = *temp; // Copy the contents of  
                           // the non-empty child  
            free(temp);  
        }  
        else
        {  
            // node with two children: Get the inorder  
            // successor (smallest in the right subtree)  
            Node* temp = minValueNode(root->right);  
  
            // Copy the inorder successor's  
            // data to this node  
            root->num = temp->num;  
            root->decimal = temp->decimal;
  
            // Delete the inorder successor  
            root->right = deleteh(root->right,  
                                     temp->num,temp->decimal);  
            cout<< "inorder succ deleted" << endl;
        }  
    }  
  
    // If the tree had only one node 
    // then return  
    if (root == NULL)  
    return root;  
  
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    root->height = 1 + max(height(root->left),  
                           height(root->right));  
  
    // STEP 3: GET THE BALANCE FACTOR OF  
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = balancef(root);  
  
    // If this node becomes unbalanced,  
    // then there are 4 cases  
  
    // Left Left Case  
    if (balance > 1 &&  
        balancef(root->left) >= 0)  
        return rr(root);  
  
    // Left Right Case  
    if (balance > 1 &&  
        balancef(root->left) < 0)  
    {  
        root->left = lr(root->left);  
        return rr(root);  
    }  
  
    // Right Right Case  
    if (balance < -1 &&  
       balancef(root->right) <= 0)  
        return lr(root);  
  
    // Right Left Case  
    if (balance < -1 &&  
        balancef(root->right) > 0)  
    {  
        root->right = rr(root->right);  
        return lr(root);  
    }  
  
    return root;  
}

void avl::Delete(int num, int decimal){
  
  deleteh(this->root, num, decimal);
  cout << num << "." << decimal << " deleted" << endl;
}

bool findh(struct Node* node, int num, int decimal)
{
    if (node == NULL)
        return false;
 
    if ((node->num == num) && (node->decimal == decimal))
        return true;
 
    /* then recur on left sutree */
    bool res1 = findh(node->left, num,decimal);
    // node found, no need to look further
    if(res1) return true; 
 
    /* node is not found in left, 
    so recur on right subtree */
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
