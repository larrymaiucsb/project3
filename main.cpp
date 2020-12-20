#include <iostream>
#include "avl.h"

using namespace std;


int main(){
     Node *root = NULL;  
      

    root = insert(45,3);  
    root = insert(31,1);  
    root = insert(30,5);  
    root = insert(26,6);  
    root = insert(25,1);  
    root = insert(25,2);  
      

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    preorder(root);  
      
    return 0;  
}  
