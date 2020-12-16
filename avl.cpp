#include "avl.h"
#include <iostream>

using namespace std;

void avl::insert(int num, int decimal, Node * & t){
  int whole = num+decimal;
  if (t == nullptr){
    t = new Node{
      whole, nullptr, nullptr 
      };
      else if(whole < t->element){
        insert(whole, t->left);
      }
      else if(t->element < whole)

    }
  }

}