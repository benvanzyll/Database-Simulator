#ifndef GENERALGeneralBST_H
#define GENERALGeneralBST_H

// Class for a GeneralBST of type General

#include "TreeNode.h"
#include <iostream>
#include <string>
using namespace std;

template <typename E>
class GeneralBST {
    private:
        TreeNode<E>* root; // root of tree
        int size; // number of elements in tree

    public:
        GeneralBST();
        ~GeneralBST();
        bool contains(string k);
        E find(string k);
        void insert(TreeNode<E>* node);
        bool remove(string k);
        TreeNode<E>* getSuccessor(TreeNode<E>* d);
        TreeNode<E>* getMin();
        TreeNode<E>* getMax();
        void inOrder(TreeNode<E>* node);
        void printTree();
        TreeNode<E>* getRoot();
        int length();
        bool isEmpty();
};

/*
Constructor, sets root and size values.
*/
template <typename E>
GeneralBST<E>::GeneralBST(){
  root = nullptr;
  size = 0;
}

/*
Destructor
*/
template <typename E>
GeneralBST<E>::~GeneralBST(){
  
}

/*
contains
Checks if tree contains node with key k.
@param k: key to find.
@return T/F
*/
template <typename E>
bool GeneralBST<E>::contains(string k){
  if (root == nullptr)
    return false;
  TreeNode<E>* curr = root;
  while (curr->key != k) {
    if (k < curr->key)
      curr = curr->left;
    else
      curr = curr->right;
    if (curr == nullptr)
      return false;
  }
  return true;
}

template <typename E>
E GeneralBST<E>::find(string k){
  if (root == nullptr)
    return E();
  TreeNode<E>* curr = root;
  while (curr->key != k) {
    if (k < curr->key)
      curr = curr->left;
    else
      curr = curr->right;
    if (curr == nullptr)
      return E();
  }
  return curr->value;
}

/*
insert
Inserts node in tree.
@param node: tree node to insert.
*/
template <typename E>
void GeneralBST<E>::insert(TreeNode<E>* node){
  if (root == nullptr)
    root = node;
  else {
    TreeNode<E>* curr = root;
    TreeNode<E>* parent;

    while (true) {
      parent = curr;
      if (node->key < curr->key) {
        curr = curr->left;
        if (curr == nullptr) {
          parent->left = node;
          break;
        }
      }
      else {
        curr = curr->right;
        if (curr == nullptr) {
          parent->right = node;
          break;
        }
      }
    }
  }
  size++;
}


/*
remove
Remove a node from tree.
@param k: key to find and delete.
@return T/F whether delete was successful.
*/
template <typename E>
bool GeneralBST<E>::remove(string k){
  if (root == nullptr) {
    return false;
  }
  TreeNode<E>* curr = root;
  TreeNode<E>* parent = root;
  bool isLeft = true;

  // locate the node to delete
  while (curr->key != k) {
    parent = curr;
    if (k < curr->key) {
      isLeft = true;
      curr = curr->left;
    }
    else {
      isLeft = false;
      curr = curr->right;
    }
    if (curr == nullptr) {
      return false;
    }
  }
  // at this point we have found the node to remove
  // case 1: no children
  if (curr->left == nullptr && curr->right == nullptr) {
    if (curr == root)
      root = nullptr;
    else if (isLeft)
      parent->left = nullptr;
    else
      parent->right = nullptr;
  }
  // case 2: one child to the left
  else if (curr->right == nullptr) {
    if (curr == root)
      root = curr->left;
    else if (isLeft)
      parent->left = curr->left;
    else
      parent->right = curr->left;
  }
  // case 3: one child to the right
  else if (curr->left == nullptr) {
    if (curr == root)
      root = curr->right;
    else if (isLeft)
      parent->left = curr->right;
    else
      parent->right = curr->right;
  }
  // case 4: two children
  else {
    TreeNode<E>* successor = getSuccessor(curr);
    if (curr == root)
      root = successor;
    else if (isLeft)
      parent->left = successor;
    else
      parent->right = successor;
    successor->left = curr->left;
  }
  size--;
  delete curr;
  return true;
}

// FOR EXAM, KNOW STEPS FOR DELETING A CERTAIN NODE!!!!!! ************************************************************************************************

/*
getSuccessor
Find a node's left most child of its right child
@param d: Node to find successor for.
@return successor node.
*/
template <typename E>
TreeNode<E>* GeneralBST<E>::getSuccessor(TreeNode<E>* d){
  TreeNode<E>* sp = d;
  TreeNode<E>* successor = d;
  TreeNode<E>* curr = d->right;
  while (curr != nullptr) {
    sp = successor;
    successor = curr;
    curr = curr->left;
  }
  if (successor != d->right) {
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

/*
getMin
Find a tree's smallest key node.
@return smallest key node
*/
template <typename E>
TreeNode<E>* GeneralBST<E>::getMin(){
  TreeNode<E>* curr = root;
  if (root == nullptr)
    return new TreeNode<E>();
  while (curr->left != nullptr)
    curr = curr->left;
  return curr;
}


/*
getMax
Find a tree's largest key node.
@return largest key node
*/
template <typename E>
TreeNode<E>* GeneralBST<E>::getMax(){
  TreeNode<E>* curr = root;
  if (root == nullptr)
    return new TreeNode<E>();
  while (curr->right != nullptr)
    curr = curr->right;
  return curr;
}

/*
inOrder
Inorder traversal starting at some node.
@param node: node to begin traversal
*/
template <typename E>
void GeneralBST<E>::inOrder(TreeNode<E>* node){
  if (node == nullptr)
    return;
  inOrder(node->left);
  node->value.PrintInfo();
  cout << endl;
  inOrder(node->right);
}

/*
printTree
Caller for inOrder.
*/
template <typename E>
void GeneralBST<E>::printTree(){
  inOrder(root);
  std::cout << std::endl;
}

/*
getRoot
@return root: root of tree.
*/
template <typename E>
TreeNode<E>* GeneralBST<E>::getRoot(){
  return root;
}

/*
length
@return size: size of tree.
*/
template <typename E>
int GeneralBST<E>::length(){
  return size;
}

/*
isEmpty
@return T/F: if size is 0 or not.
*/
template <typename E>
bool GeneralBST<E>::isEmpty(){
  return size == 0;
}

#endif