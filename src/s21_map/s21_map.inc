#include <iostream>

#include "s21_map.h"

using std::cout;
using std::endl;
using std::pair;

namespace s21 {
template <typename Key, typename T>
map<Key, T>::map() {}

// // map<Key,T>::map(std::initializer_list<value_type> const &items) {
// //   for (const auto &item : items)  insert(item);
// // }

// template <typename Key, typename T>
// map<Key, T>::~map() {
//   // if (root) delete root;
// }

// template <typename Key, typename T>
// std::pair<typename map<Key, T>::iterator, bool>  map<Key, T>::insert(const
// Key& key, const T& obj) {

// cout<<"insert"<<endl;
//   std::pair<Key, T> val = {key, obj};
//   bool result = true;
//   return insert_recursive(root, val, &result, false);
// }

// template <typename Key, typename T>
// std::pair<typename map<Key, T>::iterator, bool> map<Key,
// T>::insert_or_assign(
//     const Key& key, const T& obj) {
//   std::pair<Key, T> val = {key, obj};
//   bool result = true;
//   return insert_recursive(root, val, &result, true);
// }
//________________________________________________Element_access______________________________________________________________
template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& key) {
  auto x = BinaryTree<Key, T>::root;
  auto terminal_node = BinaryTree<Key, T>::terminal_node;

  while (x && x != terminal_node) {
    if (key == x->node_key.first) return x->node_key.second;
    if (key > x->node_key.first)
      x = x->right;
    else
      x = x->left;
  }
  if (!x || x == terminal_node) BinaryTree<Key, T>::insert(Key(key));
  // cout << BinaryTree<Key, T>::root->node_key.first << "\n" << endl;
  return x->node_key.second;
}
//________________________________________________Capacity______________________________________________________________
// template <typename Key, typename T>
// bool map<Key, T>::empty() {
//   return !root->left && !root->right;
// }
// //________________________________________________iterators______________________________________________________________
// template <typename Key, typename T>
// typename map<Key, T>::iterator map<Key, T>::begin() {
//   if (!root) return root;
//   iterator begin = root;
//   while (begin->left) begin = begin->left;
//   return begin;
// }
// template <typename Key, typename T>
// typename map<Key, T>::iterator map<Key, T>::end() {
//   if (!root) return root;
//   iterator end = root;
//   while (end->right) end = end->right;
//   return end;
//   // я не знаю что это такое, если бы знали что это такое, я не знаю что это
//   // такое
// }
// //________________________________________________Support______________________________________________________________
// template <typename Key, typename T>
// std::pair<typename map<Key, T>::iterator, bool> map<Key,
// T>::insert_recursive(
//     Node<Key, T>* x, value_type val, bool* check, bool permission) {
//   if (!x) {
//     Node<Key, T>* next = new Node<Key, T>(val);
//     if (!root) root = next;
//     std::pair<iterator, bool> p(next, true);
//     return p;
//   }
//   if (val.first == x->key) {
//     if (!permission)
//       *check = false;
//     else
//       x->value = val.second;
//     return std::pair<iterator, bool>(Nurlanization(x), *check);
//   }

//   if (val.first < x->key) {
//     x->left = insert_recursive(x->left, val, check, permission).first;
//     x->left->parent = x;
//   }
//   if (val.first > x->key) {
//     x->right = insert_recursive(x->right, val, check, permission).first;
//     x->right->parent = x;
//   }
//   get_balance_factor(x);
//   return std::pair<iterator, bool>(Nurlanization(x), *check);
// }

// template <typename Key, typename T>
// Node<Key, T>* map<Key, T>::Nurlanization(Node<Key, T>* x) {
//   if (x->balanceFactor < -1) {
//     if (x->left->balanceFactor > 0) x->left = rotate_Left(x->left);
//     return rotate_Right(x);
//   }
//   if (x->balanceFactor > 1) {
//     if (x->right->balanceFactor < 0) x->right = rotate_Right(x->right);
//     return rotate_Left(x);
//   }
//   return x;
// }

// template <typename Key, typename T>
// Node<Key, T>* map<Key, T>::rotate_Left(Node<Key, T>* x) {
//   Node<Key, T>* p = x->right;
//   p->parent = x->parent;
//   x->right = p->left;
//   p->left = x;
//   if (p->parent == nullptr) root = p;
//   get_balance_factor(p);
//   get_balance_factor(x);
//   return p;
// }
// template <typename Key, typename T>
// Node<Key, T>* map<Key, T>::rotate_Right(Node<Key, T>* x) {
//   Node<Key, T>* q = x->left;
//   q->parent = x->parent;
//   x->left = q->right;
//   q->right = x;
//   if (!q->parent) root = q;
//   get_balance_factor(q);
//   get_balance_factor(x);
//   return q;
// }

// template <typename Key, typename T>
// int map<Key, T>::get_balance_factor(Node<Key, T>* node) {
//   if (node == nullptr) return 0;
//   int left_height = get_height(node->left);
//   int right_height = get_height(node->right);
//   node->balanceFactor = -left_height + right_height;
//   return node->balanceFactor;
// }

// template <typename Key, typename T>
// int map<Key, T>::get_height(Node<Key, T>* node) {
//   if (node == nullptr) return 0;
//   int left_height = get_height(node->left);
//   int right_height = get_height(node->right);
//   return 1 + std::max(left_height, right_height);
// }

template <typename Key, typename T>
void map<Key, T>::printTree(typename BinaryTree<Key, T>::Node* x, int level) {
  if (x == nullptr) return;
  printTree(x->right, level + 3);
  for (int i = 0; i < level; i++) std::cout << " ";
  std::cout << x->node_key.first << "[" << x->node_key.second << "]"
            << std::endl;
  printTree(x->left, level + 3);
}

}  // namespace s21