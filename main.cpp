#include <iostream>
#include "avl.h"

using namespace std;


int main(){
    avl a(1);
    
      
    cout << "humguh" << endl;
    a.insert(10,0);
    a.insert(20,0);
    a.insert(30,0);
    a.insert(40,0);
    a.insert(50,0);
    a.insert(25,0);
    a.search(99,0);
    a.search(50,0);
    a.approx_search(10,0);
    a.approx_search(2000,1);
    a.Delete(9,1);



    cout << "Preorder traversal of the "
            "constructed AVL tree is " << endl; 
    a.preorder();  
    
    cout << "inorder traversal" << endl;
    a.in_order();
      
    
}  
