#include <iostream>

using namespace std;


int main(){
     Node *root = NULL;  
      

    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);  
      

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    preOrder(root);  
      
    return 0;  
}  
