#include "BST.h"

int main() {
  BST<int>* bst = new BST<int>();

  bst->insert(6);
  bst->insert(5);
  bst->insert(3);
  bst->insert(4);
  bst->insert(7);
  bst->insert(12);

  bst->remove(6);

  bst->print();


}
