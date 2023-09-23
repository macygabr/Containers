#include <iostream>

#include "BinaryTree.h"
using std::cout;
using std::endl;
using std::pair;

namespace s21 {
template <typename Key, typename T>
BinaryTree<Key, T>::BinaryTree() {
  std::cout << "Hi" << std::endl;
  this->root = nullptr;
}

template <typename Key, typename T>
pair<typename BinaryTree<Key, T>::iterator, bool>  BinaryTree<Key, T>::insert(const Key& key, const T& obj) {
    cout<<"insert"<<endl;
  std::pair<Key, T> val = {key, obj};
  bool result = true;
  // return insert_recursive(root, val, &result, false);
}

//________________________________________________Element_access______________________________________________________________
template <typename Key, typename T>
T& BinaryTree<Key, T>::operator[](const Key& key) {
  Node* x = root;
  while (x) {
    if (key == x->key) return x->value;
    if (key > x->key)
      x = x->right;
    else
      x = x->left;
  }
  if (!x) insert(std::pair<Key, T>(key, T()));
  return x->value;
}
//________________________________________________Capacity______________________________________________________________
// template <typename Key, typename T>
// bool BinaryTree<Key, T>::empty() {
//   return !root->left && !root->right;
// }
//________________________________________________iterators______________________________________________________________
template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::begin() {
  if (!root) return root;
  iterator begin = root;
  while (begin->left) begin = begin->left;
  return begin;
}
template <typename Key, typename T>
typename BinaryTree<Key, T>::iterator BinaryTree<Key, T>::end() {
  if (!root) return root;
  iterator end = root;
  while (end->right) end = end->right;
  return end;
  // я не знаю что это такое, если бы знали что это такое, я не знаю что это
  // такое
}
//________________________________________________Support______________________________________________________________
template <typename Key, typename T>
std::pair<typename BinaryTree<Key, T>::iterator, bool> BinaryTree<Key,T>::insert_recursive(
    Node* x, value_type val, bool* check, bool permission) {
  if (!x) {
    Node* next = new Node(val);
    if (!root) root = next;
    std::pair<iterator, bool> p(next, true);
    return p;
  }
  if (val.first == x->key) {
    if (!permission)
      *check = false;
    else
      x->value = val.second;
    return std::pair<iterator, bool>(Nurlanization(x), *check);
  }

  if (val.first < x->key) {
    x->left = insert_recursive(x->left, val, check, permission).first;
    x->left->parent = x;
  }
  if (val.first > x->key) {
    x->right = insert_recursive(x->right, val, check, permission).first;
    x->right->parent = x;
  }
  get_balance_factor(x);
  return std::pair<iterator, bool>(Nurlanization(x), *check);
}

template <typename Key, typename T>
Node* BinaryTree<Key, T>::Nurlanization(Node* x) {
  if (x->balanceFactor < -1) {
    if (x->left->balanceFactor > 0) x->left = rotate_Left(x->left);
    return rotate_Right(x);
  }
  if (x->balanceFactor > 1) {
    if (x->right->balanceFactor < 0) x->right = rotate_Right(x->right);
    return rotate_Left(x);
  }
  return x;
}

template <typename Key, typename T>
Node* BinaryTree<Key, T>::rotate_Left(Node* x) {
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
Node* BinaryTree<Key, T>::rotate_Right(Node* x) {
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
void BinaryTree<Key, T>::printTree(const Node* x, int level) {
  if (x == nullptr) return;
  printTree(x->right, level + 3);
  for (int i = 0; i < level; i++) std::cout << " ";
  std::cout << x->key << "[" << x->value << "]" << std::endl;
  printTree(x->left, level + 3);
}



template <typename Key, typename T>
BinaryTree<Key, T>::Iterator::Iterator(){}
}  // namespace s21