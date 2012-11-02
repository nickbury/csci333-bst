#include "BST.h"
#include <iostream>

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  
}


template <typename T>
bool BST<T>::find(T v) {
  Node<T>* temp = new Node<T>(v);
  root = temp;  
  return true;
}

template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;

  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;
}

template <typename T>
void BST<T>::remove(T v) {
  Node<T>** curr = &root;
  while (*curr != 0 && (*curr)->getValue() != v) {
    if ((*curr)->getValue() > v)
      curr = &((*curr)->getLeftChild());
    else if ((*curr)->getValue() < v)
      curr = &((*curr)->getRightChild());
  }
  //if node doesn't exist
  if (*curr == 0) {
    std::cout << "Value not found in tree" << std::endl;
  } else {

  Node<T>* temp = *curr;
  if ((*curr)->getLeftChild() == 0 && (*curr)->getRightChild() == 0) {
    *curr = 0;
    delete temp;
  }else if ((*curr)->getLeftChild() == 0) {
    *curr = (*curr)->getRightChild();
    delete temp;
  }else if ((*curr)->getRightChild() == 0) {
    *curr = (*curr)->getLeftChild();
    delete temp;
  }else {
    //find inorder successor (ios)
    Node<T>* ios = (*curr)->getRightChild();
    while (ios->getLeftChild() != 0) {
      ios = ios->getLeftChild();
    }
    ios->setLeftChild(*((*curr)->getLeftChild()));
    *curr = ios;
    delete temp;
  }
 }
}

template <typename T>
void BST<T>::print() {
  
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    traversalPrint(root->getLeftChild());
    std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
  }
}

template class BST<int>;
template class BST<double>;
template class BST<std::string>;
