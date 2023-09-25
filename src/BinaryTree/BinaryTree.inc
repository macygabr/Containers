#include <iostream>

#include "BinaryTree.h"
using std::cout;
using std::endl;
using std::pair;

namespace s21 {
template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTree(){
  terminal_node = new Node();
  root = terminal_node;
}

template <typename Key, typename T>
std::pair<typename BinaryTree<Key, T>::iterator, bool>
BinaryTree<Key, T>::insert(const value_type val) {
  bool result = true;
  if(root == terminal_node) root = nullptr;
  
  terminal_node->parent = nullptr;

  return insert_recursive(root, val, &result, false);
}

template <typename Key, typename T>
std::pair<typename BinaryTree<Key, T>::iterator, bool>
BinaryTree<Key, T>::insert(const Key& key, const T& obj) {
  std::pair<Key, T> val = {key, obj};
  bool result = true;
  return insert_recursive(root, val, &result, false);
}

template <typename Key, typename T>
std::pair<typename BinaryTree<Key, T>::iterator, bool>
BinaryTree<Key, T>::insert_or_assign(const Key& key, const T& obj) {
  std::pair<Key, T> val = {key, obj};
  bool result = true;
  return insert_recursive(root, val, &result, true);
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::begin() {
  if (!root) return root;
  iterator begin = root;
  while (begin.node->left) begin = begin.node->left;
  return begin;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::end() {
  if (!root) return root;
  iterator end = root;
  while (end.node->right) end = end.node->right;
  return end;
  // я не знаю что это такое, если бы знал что это такое, я не знаю что это
  // такое
}
//________________________________________________Support______________________________________________________________
template <typename Key, typename T>
std::pair<typename BinaryTree<Key, T>::iterator, bool>
BinaryTree<Key, T>::insert_recursive(Node* x, value_type val, bool* check,
                                     bool permission) {
  if (!x) {
    Node* next = new Node(val);
    if (!root){
    root = next;
    add_terminal_node(root, true);
    } 
    std::pair<iterator, bool> p(Iterator(next), true);
    return p;
  }

  add_terminal_node(root, false);

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
  Nurlanization(x);
  // add_terminal_node(x, true);
  return std::pair<iterator, bool>(Iterator(x), *check);
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::Iterator BinaryTree<Key, T>::Nurlanization(
    Node* x) {
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

template <typename Key, typename T>
typename BinaryTree<Key, T>::Node* BinaryTree<Key, T>::rotate_Left(Node* x) {
  Node* p = x->right;
  p->parent = x->parent;
  x->right = p->left;
  p->left = x;
  if (p->parent == nullptr) root = p;
  get_balance_factor(p);
  get_balance_factor(x);
  return p;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::Node* BinaryTree<Key, T>::rotate_Right(Node* x) {
  Node* q = x->left;
  q->parent = x->parent;
  x->left = q->right;
  q->right = x;
  if (!q->parent) root = q;
  get_balance_factor(q);
  get_balance_factor(x);
  return q;
}

template <typename Key, typename T>
int BinaryTree<Key, T>::get_balance_factor(Node* node) {
  if (node == nullptr) return 0;
  int left_height = get_height(node->left);
  int right_height = get_height(node->right);
  node->balanceFactor = -left_height + right_height;
  return node->balanceFactor;
}

template <typename Key, typename T>
int BinaryTree<Key, T>::get_height(Node* node) {
  if (node == nullptr) return 0;
  int left_height = get_height(node->left);
  int right_height = get_height(node->right);
  return 1 + std::max(left_height, right_height);
}

template <typename Key, typename T>
void BinaryTree<Key, T>::add_terminal_node(Node* node, bool add){
  while(node->right) node = node->right;
  if(add)node->right = terminal_node;
  else node->right = nullptr;
}

template <typename Key, typename T>
void BinaryTree<Key, T>::del_terminal_node(Node* node){
  while(node->right) node = node->right;
  node->right = nullptr;
}

//________________________________________________Iterator______________________________________________________________
template <typename Key, typename T>
BinaryTree<Key, T>::Iterator::Iterator() : node(nullptr) {}

template <typename Key, typename T>
BinaryTree<Key, T>::Iterator::Iterator(Node* newnode) : node(newnode) {}

template <typename Key, typename T>
typename BinaryTree<Key, T>::Iterator&
BinaryTree<Key, T>::Iterator::operator++() {
  if (!node) return *this;

  if (!node->right) {
    if (node->node_val < node->parent->node_val)
      node = node->parent;
    else
      node = node->parent->parent;
    return *this;
  } else {
    node = node->right;
    while (node->left) node = node->left;
    return *this;
  }

  // Node *tmp;
  // if (iter_node_ != nullptr) tmp = GetMax(iter_node_);
  // iter_node_ = MoveForward(iter_node_);
  // if (iter_node_ == nullptr) iter_past_node_ = tmp;

  return *this;
}

template <typename Key, typename T>
typename BinaryTree<Key, T>::Iterator BinaryTree<Key, T>::Iterator::operator++(
    int) {
  Iterator temp = *this;
  operator++();
  return temp;
}

template <typename Key, typename T>
bool BinaryTree<Key, T>::Iterator::operator!=(const iterator& it) {
  std::cout << "\n!!!===\n" << std::endl;
}
// template <typename Key, typename T>
// typename BinaryTree<Key, T>::Iterator& BinaryTree<Key,
// T>::Iterator::operator=(const Iterator& it) { std::cout << "\noperator=\n" <<
// std::endl; if (this != &other)
//   node = other.node;
// return *this;
// }
}  // namespace s21