#include <iostream>
#include "avl.h"

using namespace std;


int main(){
    avl a;
      
    cout << "humguh" << endl;
    a.insert(10,0);
    a.insert(20,0);
    a.insert(30,0);
    a.insert(40,0);
    a.insert(50,0);
    a.insert(25,0);
    a.Delete(10,0);
    a.search(99,0);
    a.search(50,0);


    cout << "Preorder traversal of the "
            "constructed AVL tree is " << endl; 
    a.preorder();  
    cout << "inorder traversal" << endl;
    a.in_order();
      
    
}  
