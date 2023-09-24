#include <iostream>

#include "BinaryTree.h"
using std::cout;
using std::endl;
using std::pair;

namespace s21 {
template <typename Key, typename T, typename Value>
BinaryTree<Key, T,Value>::BinaryTree() : root(nullptr) {}


template <typename Key, typename T, typename Value>
std::pair<typename BinaryTree<Key, T,Value>::iterator, bool> BinaryTree<Key, T,Value>::insert(const value_type val) {
  bool result = true;
  return insert_recursive(root, val, &result, false);
}

template <typename Key, typename T, typename Value>
std::pair<typename BinaryTree<Key, T,Value>::iterator, bool> BinaryTree<Key, T,Value>::insert(const Key& key, const T& obj) {
  std::pair<Key, T> val = {key, obj};
  bool result = true;
  return insert_recursive(root, val, &result, false);
}

template <typename Key, typename T, typename Value>
std::pair<typename BinaryTree<Key, T,Value>::iterator, bool> BinaryTree<Key, T,Value>::insert_or_assign(const Key& key, const T& obj) {
  std::pair<Key, T> val = {key, obj};
  bool result = true;
  return insert_recursive(root, val, &result, true);
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T,Value>::iterator BinaryTree<Key, T,Value>::begin() {
  if (!root) return root;
  iterator begin = root;
  while (begin.node->left) begin = begin.node->left;
  return begin;
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T,Value>::iterator BinaryTree<Key, T,Value>::end() {
  if (!root) return root;
  iterator end = root;
  while (end.node->right) end = end.node->right;
  return end;
// я не знаю что это такое, если бы знал что это такое, я не знаю что это такое
}
//________________________________________________Support______________________________________________________________
template <typename Key, typename T, typename Value>
std::pair<typename BinaryTree<Key, T,Value>::iterator, bool> BinaryTree<Key, T,Value>::insert_recursive(Node* x, value_type val, bool* check, bool permission) {
  if (!x) {
    Node* next = new Node(val);
    if (!root) root = next;
    std::pair<iterator, bool> p(Iterator(next), true);
    // std::cout<<p.first.node->key<<std::endl;
    return p;
  }
  
  if (val.first == x->node_key) {
    if (!permission)
      *check = false;
    else
      x->node_val = val.second;
    return std::pair<iterator, bool>(Nurlanization(x), *check);
  }

  if (val.first < x->node_key) {
    x->left = insert_recursive(x->left, val, check, permission).first.node;
    x->left->parent = x;
  }
  if (val.first > x->node_key) {
    x->right = insert_recursive(x->right, val, check, permission).first.node;
    x->right->parent = x;
  }
  get_balance_factor(x);
  return std::pair<iterator, bool>(Nurlanization(x), *check);
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T,Value>::iterator BinaryTree<Key, T,Value>::Nurlanization(Node* x) {
  if (x->balanceFactor < -1) {
    if (x->left->balanceFactor > 0) x->left = rotate_Left(x->left);
    return Iterator(rotate_Right(x));
  }
  if (x->balanceFactor > 1) {
    if (x->right->balanceFactor < 0) x->right = rotate_Right(x->right);
    return Iterator(rotate_Left(x));
  }
  return Iterator(x);
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T,Value>::Node* BinaryTree<Key, T,Value>::rotate_Left(Node* x) {
  Node* p = x->right;
  p->parent = x->parent;
  x->right = p->left;
  p->left = x;
  if (p->parent == nullptr) root = p;
  get_balance_factor(p);
  get_balance_factor(x);
  return p;
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T,Value>::Node* BinaryTree<Key, T,Value>::rotate_Right(Node* x) {
  Node* q = x->left;
  q->parent = x->parent;
  x->left = q->right;
  q->right = x;
  if (!q->parent) root = q;
  get_balance_factor(q);
  get_balance_factor(x);
  return q;
}

template <typename Key, typename T, typename Value>
int BinaryTree<Key, T,Value>::get_balance_factor(Node* node) {
  if (node == nullptr) return 0;
  int left_height = get_height(node->left);
  int right_height = get_height(node->right);
  node->balanceFactor = -left_height + right_height;
  return node->balanceFactor;
}

template <typename Key, typename T, typename Value>
int BinaryTree<Key, T,Value>::get_height(Node* node) {
  if (node == nullptr) return 0;
  int left_height = get_height(node->left);
  int right_height = get_height(node->right);
  return 1 + std::max(left_height, right_height);
}


//________________________________________________Iterator______________________________________________________________
template <typename Key, typename T, typename Value>
BinaryTree<Key, T,Value>::Iterator::Iterator(): node(nullptr){}

template <typename Key, typename T, typename Value>
BinaryTree<Key, T,Value>::Iterator::Iterator(Node* newnode): node(newnode){}

// template <typename Key, typename T, typename Value>
// typename BinaryTree<Key, T,Value>::Iterator& BinaryTree<Key, T,Value>::Iterator::operator=(const Iterator& it) {
  // std::cout << "\noperator=\n" << std::endl;
  // if (this != &other)
  //   node = other.node;
  // return *this;
// }
}  // namespace s21