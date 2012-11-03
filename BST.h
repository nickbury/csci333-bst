#ifndef __BST_H__
#define __BST_H__

#include "Node.h"
#include <string>
#include <list>

//value container for printQ
template <typename T>
class VCT {
  private:
    T value;
    //state initialized in constructor with value of 0
    //determines whether a value is displayed in the tree
    int state;

  public:
    VCT<T>();
    T getValue();
    void setValue(T v);
    int getState();
    void stateOn();
};

template <typename T>
class BST {
 private:
  Node<T>* root;
  void traversalPrint(Node<T>* root);
  std::list< VCT<T>* >* createPrintQueue();

 public:
  BST<T>();
  ~BST<T>();

  bool find(T v);
  void remove(T v);
  void insert(T v);
  void print();
};




#endif
