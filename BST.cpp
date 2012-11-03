#include "BST.h"
#include <iostream>
#include <sstream>
#include <list>

using std::string;

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
  std::list<string>* printQ = createPrintQueue();
  for (int i=0; i<=(int)printQ->size(); ++i) {
    std::cout << printQ->front() << std::endl;
    printQ->pop_front();
  }
}

template <typename T>
std::list<string>* BST<T>::createPrintQueue() {
  std::list<string>* printQ = new std::list<string>();
  std::list< Node<T>* >* q = new std::list< Node<T>* >();
  
  Node<T>* curr = root;
  printQ->push_back(toString(curr->getValue()));
  q->push_back(curr);
  while (!q->empty()) {
    curr = q->front();
    q->pop_front();
    if (curr->getLeftChild() != 0) {
      printQ->push_back(toString(curr->getLeftChild()->getValue()));
      q->push_back(curr->getLeftChild());
    }else {
      printQ->push_back("-");
    }
    if (curr->getRightChild() != 0) {
      printQ->push_back(toString(curr->getRightChild()->getValue()));
      q->push_back(curr->getRightChild());
    }else {
      printQ->push_back("-");
    }
  }
  delete q;
  return printQ;  
}

template <typename T>
string BST<T>::toString(T v) {
  std::stringstream s;
  s << v;
  return s.str();
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
