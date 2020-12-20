#include <iostream>
#include "avl.h"

using namespace std;


int main(){
    avl a;
      
    cout << "humguh" << endl;
    a.insert(33,1);
    a.insert(34,5);


    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";  
    a.preorder();  
      
    
}  
