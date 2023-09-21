#include "s21_map.h"

namespace s21 {
template <typename Key, typename T>
map<Key, T>::map() : node(nullptr), root(nullptr) {}

// map<Key,T>::map(std::initializer_list<value_type> const &items) {
//   for (const auto &item : items)  insert(item);
// }

template <typename Key, typename T>
map<Key, T>::~map() {
  // if (root) delete root;
}
template <typename Key, typename T>
std::pair<typename map<Key, T>::Iterator, bool> map<Key, T>::insert(
    const value_type val) {
  return insert_recursive(root, val, true, false);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::Iterator, bool> map<Key, T>::insert(
    const Key& key, const T& obj) {
  std::pair<Key, T> val = {key, obj};
  return insert_recursive(root, val, true, false);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::Iterator, bool> map<Key, T>::insert_or_assign(
    const Key& key, const T& obj) {
  std::pair<Key, T> val = {key, obj};
  return insert_recursive(root, val, true, true);
}
//________________________________________________Element_access______________________________________________________________
template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& key) {
  Node<Key, T>* x = root;
  while (x) {
    if (key == x->key) return x->value;
    if (key < x->key) x = x->left;
    if (key > x->key) x = x->right;
  }

  if (!x) {
    cout << "Error" << endl;
    pair<int, char> a1 = {1, 'l'};
    Node<Key, T>* next = new Node<Key, T>(a1);
    x = next;
  }
  return x->value;
}
//________________________________________________Capacity______________________________________________________________
// template <typename Key, typename T>
// bool map<Key, T>::empty() {
//   return !root->left && !root->right;
// }
//________________________________________________Iterators______________________________________________________________
template <typename Key, typename T>
typename map<Key, T>::Iterator map<Key, T>::begin() {
  if (!root) return root;
  Iterator begin = root;
  while (begin->left) begin = begin->left;
  return begin;
}
template <typename Key, typename T>
typename map<Key, T>::Iterator map<Key, T>::end() {
  if (!root) return root;
  Iterator end = root;
  while (end->right) end = end->right;
  return end;
}
//________________________________________________Support______________________________________________________________
template <typename Key, typename T>
std::pair<typename map<Key, T>::Iterator, bool> map<Key, T>::insert_recursive(
    Node<Key, T>* x, value_type val, bool check, bool permission) {
  if (!x) {
    Node<Key, T>* next = new Node<Key, T>(val);
    if (!root) root = next;
    std::pair<Iterator, bool> p(next, true);
    return p;
  }
  if (val.first == x->key) {
    if (!permission)
      check = false;
    else
      x->value = val.second;
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
  // std::pair<Iterator, bool> z(Nurlanization(x), check);
  return std::pair<Iterator, bool>(Nurlanization(x), check);
}

template <typename Key, typename T>
Node<Key, T>* map<Key, T>::Nurlanization(Node<Key, T>* x) {
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
Node<Key, T>* map<Key, T>::rotate_Left(Node<Key, T>* x) {
  Node<Key, T>* p = x->right;
  p->parent = x->parent;
  x->right = p->left;
  p->left = x;
  if (p->parent == nullptr) root = p;
  get_balance_factor(p);
  get_balance_factor(x);
  return p;
}
template <typename Key, typename T>
Node<Key, T>* map<Key, T>::rotate_Right(Node<Key, T>* x) {
  Node<Key, T>* q = x->left;
  q->parent = x->parent;
  x->left = q->right;
  q->right = x;
  if (!q->parent) root = q;
  get_balance_factor(q);
  get_balance_factor(x);
  return q;
}

template <typename Key, typename T>
int map<Key, T>::get_balance_factor(Node<Key, T>* node) {
  if (node == nullptr) return 0;
  int left_height = get_height(node->left);
  int right_height = get_height(node->right);
  node->balanceFactor = -left_height + right_height;
  return node->balanceFactor;
}

template <typename Key, typename T>
int map<Key, T>::get_height(Node<Key, T>* node) {
  if (node == nullptr) return 0;
  int left_height = get_height(node->left);
  int right_height = get_height(node->right);
  return 1 + std::max(left_height, right_height);
}

template <typename Key, typename T>
void map<Key, T>::printTree(const Node<Key, T>* x, int level) {
  if (x == nullptr) return;
  printTree(x->right, level + 3);
  for (int i = 0; i < level; i++) std::cout << " ";
  std::cout << x->key << "[" << x->value << "]" << std::endl;
  printTree(x->left, level + 3);
}
}  // namespace s21