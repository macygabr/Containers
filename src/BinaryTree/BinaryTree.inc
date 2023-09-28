#include <iostream>

#include "BinaryTree.h"
using std::cout;
using std::endl;
using std::pair;

//________________________________________________Member_functions______________________________________________________________

namespace s21 {
template <typename Key, typename T, typename Value>
BinaryTree<Key, T, Value>::BinaryTree() {
  terminal_node = new Node();
  root = terminal_node;
}

template <typename Key, typename T, typename Value>
BinaryTree<Key, T, Value>::~BinaryTree() {
  clear();
  delete root;
}

//________________________________________________Element_access______________________________________________________________

// template <typename Key, typename T, typename Value>
// T& BinaryTree<Key, T, Value>::operator[](const Key& key) {
//   auto x = root;

//   while (x && x != terminal_node) {
//     if (key == x->node_key.first) return x->node_key.second;
//     if (key > x->node_key.first)
//       x = x->right;
//     else
//       x = x->left;
//   }
//   if (!x || x == terminal_node) insert(Key(key));
//   return x->node_key.second;
// }

//________________________________________________Modifiers______________________________________________________________

template <typename Key, typename T, typename Value>
void BinaryTree<Key, T, Value>::clear() {
  freeTree(root);
  root = terminal_node;
  root->parent = nullptr;
}

template <typename Key, typename T, typename Value>
std::pair<typename BinaryTree<Key, T, Value>::iterator, bool>
BinaryTree<Key, T, Value>::insert(const value_type val) {
  if (size() == MAX_SIZE) throw std::length_error("Tree is full");
  bool result = true;
  if (root == terminal_node) root = nullptr;

  add_terminal_node(root, false);
  std::pair<typename BinaryTree<Key, T, Value>::iterator, bool> res =
      insert_recursive(root, val, &result, false);
  add_terminal_node(root, true);
  return res;
}

template <typename Key, typename T, typename Value>
std::pair<typename BinaryTree<Key, T, Value>::iterator, bool>
BinaryTree<Key, T, Value>::insert(const Key& key, const T& obj) {
  std::pair<Key, T> val = {key, obj};
  return insert(val);
}

template <typename Key, typename T, typename Value>
std::pair<typename BinaryTree<Key, T, Value>::iterator, bool>
BinaryTree<Key, T, Value>::insert_or_assign(const Key& key, const T& obj) {
  std::pair<Key, T> val = {key, obj};
  bool result = true;
  add_terminal_node(root, false);
  std::pair<typename BinaryTree<Key, T, Value>::iterator, bool> res =
      insert_recursive(root, val, &result, true);
  add_terminal_node(root, true);
  return res;
}

template <typename Key, typename T, typename Value>
void BinaryTree<Key, T, Value>::erase(iterator it) {
  if (!it.node || it.node == terminal_node) return;

  // auto par = it.node->parent;
  // auto lef = it.node->left;
  // auto rig = it.node->right;

  // if (!par) {
  //    if (lef && rig && rig!=terminal_node) {
  //     root = rig;
  //     rig->left = lef;
  //     lef->parent = rig;
  //   }
  //   if (lef && (!rig || rig == terminal_node)) par->right = lef;
  //   if (!lef && rig) par->right = rig;
  //   if (!lef && (!rig || rig == terminal_node)) par->right = nullptr;
  //   return;
  // }

  // if (par->right == it.node) {
  //   if (lef && rig) {
  //     par->right = rig;
  //     rig->right = lef;
  //     rig->parent = par;
  //     lef->parent = rig;
  //   }
  //   if (lef && !rig) par->right = lef;
  //   if (!lef && rig) par->right = rig;
  //   if (!lef && !rig) par->right = nullptr;

  //   return;
  // }

  // if (par->left == it.node) {
  //   if (lef && rig) {
  //     par->left = rig;
  //     rig->left = lef;
  //     rig->parent = par;
  //     lef->parent = rig;
  //   }
  //   if (lef && !rig) par->left = lef;
  //   if (!lef && rig) par->left = rig;
  //   if (!lef && !rig) par->left = nullptr;
  //   return;
  // }

  // delete it.node;
  Nurlanization(root);
}

//________________________________________________Lookup______________________________________________________________
template <typename Key, typename T, typename Value>
bool BinaryTree<Key, T, Value>::contains(const Key& key) {
  auto x = root;
  while (x && x != terminal_node) {
    if (key == get_key(x->node_key)) return true;
    if (key > get_key(x->node_key))
      x = x->right;
    else
      x = x->left;
  }
  return false;
}
//________________________________________________Iterators______________________________________________________________
template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::iterator
BinaryTree<Key, T, Value>::begin() {
  if (!root) return root;
  iterator begin = root;
  while (begin.node->left) begin = begin.node->left;
  return begin;
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::iterator BinaryTree<Key, T, Value>::end() {
  return terminal_node;
}

template <typename Key, typename T, typename Value>
BinaryTree<Key, T, Value>::Iterator::Iterator() : node(nullptr) {}

template <typename Key, typename T, typename Value>
BinaryTree<Key, T, Value>::Iterator::Iterator(Node* newnode) : node(newnode) {}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::Iterator&
BinaryTree<Key, T, Value>::Iterator::operator++() {
  if (!node) return *this;

  if (node->right) {
    node = node->right;
    while (node->left) node = node->left;
    return *this;
  } else {
    if (node->parent->right == node) {
      while (node->parent->right == node) node = node->parent;
      node = node->parent;
    } else
      node = node->parent;
    return *this;
  }
  return *this;
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::Iterator
BinaryTree<Key, T, Value>::Iterator::operator++(int) {
  Iterator temp = *this;
  operator++();
  return temp;
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::Iterator&
BinaryTree<Key, T, Value>::Iterator::operator--() {
  if (!node) return *this;

  if (!node->left) {
    if (node->parent->right)
      node = node->parent;
    else
      node = node->parent->parent;
    return *this;
  } else {
    node = node->left;
    while (node->right) node = node->right;
    return *this;
  }
  return *this;
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::Iterator
BinaryTree<Key, T, Value>::Iterator::operator--(int) {
  Iterator temp = *this;
  operator--();
  return temp;
}

template <typename Key, typename T, typename Value>
bool BinaryTree<Key, T, Value>::Iterator::operator!=(const iterator& it) {
  return node != it.node;
}

//________________________________________________Capacity______________________________________________________________
template <typename Key, typename T, typename Value>
bool BinaryTree<Key, T, Value>::empty() {
  return !root->left && !root->right;
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::size_type
BinaryTree<Key, T, Value>::size() {
  size_type res = 0;
  BinaryTree<Key, T, Value>::iterator it = begin();
  // while (it.node && it.node != terminal_node) {
  //   it++;
  //   res++;
  // }
  return size_type(res);
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::size_type
BinaryTree<Key, T, Value>::max_size() {
  return MAX_SIZE;
}

//________________________________________________Support______________________________________________________________
template <typename Key, typename T, typename Value>
std::pair<typename BinaryTree<Key, T, Value>::iterator, bool>
BinaryTree<Key, T, Value>::insert_recursive(Node* x, value_type val,
                                            bool* check, bool permission) {
  if (!x || x == terminal_node) {
    Node* next = new Node(val);
    if (!root || root == terminal_node) root = next;
    std::pair<iterator, bool> p(Iterator(next), true);
    return p;
  }
  if (get_key(val) == get_key(x->node_key)) {
    if (!permission)
      *check = false;
    else
      set_val(x, val);  // x->node_key.second = val.second;
    return std::pair<iterator, bool>(Nurlanization(x), *check);
  }
  if (get_key(val) < get_key(x->node_key))
    x->left = (insert_recursive(x->left, val, check, permission)).first.node;

  if (get_key(val) > get_key(x->node_key))
    x->right = insert_recursive(x->right, val, check, permission).first.node;

  get_balance_factor(x);
  return std::pair<iterator, bool>(Nurlanization(x), *check);
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::Iterator
BinaryTree<Key, T, Value>::Nurlanization(Node* x) {
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
typename BinaryTree<Key, T, Value>::Node*
BinaryTree<Key, T, Value>::rotate_Left(Node* x) {
  Node* p = x->right;
  p->parent = x->parent;
  x->right = p->left;
  p->left = x;
  x->parent = p;
  if (p->parent == nullptr) root = p;
  get_balance_factor(p);
  get_balance_factor(x);
  return p;
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::Node*
BinaryTree<Key, T, Value>::rotate_Right(Node* x) {
  Node* q = x->left;
  q->parent = x->parent;
  x->left = q->right;
  q->right = x;
  x->parent = q;
  if (!q->parent) root = q;
  get_balance_factor(q);
  get_balance_factor(x);
  return q;
}

template <typename Key, typename T, typename Value>
int BinaryTree<Key, T, Value>::get_balance_factor(Node* node) {
  if (node->left) node->left->parent = node;
  if (node->right) node->right->parent = node;
  if (node == nullptr) return 0;
  int left_height = get_height(node->left);
  int right_height = get_height(node->right);
  node->balanceFactor = -left_height + right_height;
  return node->balanceFactor;
}

template <typename Key, typename T, typename Value>
int BinaryTree<Key, T, Value>::get_height(Node* node) {
  if (node == nullptr) return 0;
  int left_height = get_height(node->left);
  int right_height = get_height(node->right);
  return 1 + std::max(left_height, right_height);
}

template <typename Key, typename T, typename Value>
void BinaryTree<Key, T, Value>::add_terminal_node(Node* node, bool add) {
  if (!node || node == terminal_node) return;

  while (node->right) node = node->right;

  if (add) {
    node->right = terminal_node;
    terminal_node->parent = node;
  } else
    node->parent->right = nullptr;
}

template <typename Key, typename T, typename Value>
void BinaryTree<Key, T, Value>::freeTree(Node* x) {
  if (!x || x == terminal_node) return;
  freeTree(x->left);
  freeTree(x->right);
  delete x;
}

// template <typename Key, typename T, typename Value>
// void BinaryTree<Key, T, Value>::printTree(typename BinaryTree<Key, T,
// Value>::Node* x,
//                                    int level) {
//   if (x == nullptr) return;
//   printTree(x->right, level + 3);
//   for (int i = 0; i < level; i++) std::cout << " ";
//   std::cout << get_key(x->node_key) << "[" << get_val(x->node_key) << "]"prin
//             << std::endl;
//   printTree(x->left, level + 3);
// }
}  // namespace s21