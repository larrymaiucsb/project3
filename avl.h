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

}