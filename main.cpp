#include <iostream>
#include "avl.h"
#include <stdio.h>
#include <string.h>
#include <sstream> 
#include <string> 
#include <vector>

using namespace std;

int main(){
  
    avl a(1);
     
    a.insert(4,5);
    a.insert(3,9);
    a.insert(3,5);
    a.insert(2,7);
    a.insert(2,6);
    a.search(99,0);
    a.search(50,0);
    a.approx_search(10,0);
    a.approx_search(2000,1);
    a.Delete(9,1);
    a.Delete(10,0);



    cout << "Preorder traversal of the "
            "constructed AVL tree is " << endl; 
    a.preorder();  
    
    cout << "inorder traversal" << endl;
    a.in_order();
} 

