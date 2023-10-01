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
  // if(root) delete root;
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
  Node* new_node = new Node(val);
  if (root == terminal_node) root = nullptr;

  add_terminal_node(root, false);
  std::pair<typename BinaryTree<Key, T, Value>::iterator, bool> res = {
      Iterator(new_node),
      insert_recursive(root, val, &result, false, new_node).second};
  add_terminal_node(root, true);
  // if (!result) delete new_node;
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
  Node* new_node = new Node(val);
  add_terminal_node(root, false);
  std::pair<typename BinaryTree<Key, T, Value>::iterator, bool> res =
      insert_recursive(root, val, &result, true, new_node);
  add_terminal_node(root, true);
  // delete new_node;
  return res;
}

template <typename Key, typename T, typename Value>
void BinaryTree<Key, T, Value>::erase(iterator it) {
  if (!it.node || it.node == terminal_node) return;

  auto nod = it.node;
  auto par = it.node->parent;
  auto lef = it.node->left;
  auto rig = it.node->right;

  if (lef && rig && rig != terminal_node)
    delete_node_with_all_childrens(it);
  else if (!lef && rig && rig != terminal_node)
    delete_node_with_right_childrens(it);
  else if (lef && (!rig || rig == terminal_node))
    delete_node_with_left_childrens(it);
  else
    delete_node_with_not_childrens(it);

  Nurlanization(root);
  // delete it.node;
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::iterator BinaryTree<Key, T, Value>::erase(
    const_iterator it) {
  iterator it2(it);
  erase(it2);
  return ++it;
}

template <typename Key, typename T, typename Value>
void BinaryTree<Key, T, Value>::swap(BinaryTree& other) {
  auto first = other.root;
  other.root = root;
  root = first;

  std::swap(terminal_node, other.terminal_node);
}

template <typename Key, typename T, typename Value>
void BinaryTree<Key, T, Value>::merge(BinaryTree& other) {
  auto it = other.begin();
  for (; it != other.end(); ++it)
    if (insert(*it).second) other.erase(it);
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
  iterator begin(root);
  while (begin.node->left) begin.node = begin.node->left;
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
BinaryTree<Key, T, Value>::Iterator::Iterator(const Iterator& it)
    : node(it.node) {}

// template <typename Key, typename T, typename Value>
// BinaryTree<Key, T, Value>::Iterator::Iterator(Iterator&& it) : node(it.node)
// {
//   it.node = nullptr;
// }

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::Iterator&
BinaryTree<Key, T, Value>::Iterator::operator++() {
  if (!node) return *this;

  if (node->right) {
    node = node->right;
    while (node->left) node = node->left;
  } else {
    if (node->parent->right == node)
      while (node->parent->parent && node->parent->right == node) {
        node = node->parent;
      }
    node = node->parent;
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

  if (node->left) {
    node = node->left;
    while (node->right) node = node->right;
  } else {
    if (node->parent->left == node)
      while (node->parent->parent && node->parent->left == node) {
        node = node->parent;
      }
    node = node->parent;
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
bool BinaryTree<Key, T, Value>::Iterator::operator==(const iterator& it) {
  return node == it.node;
}

template <typename Key, typename T, typename Value>
bool BinaryTree<Key, T, Value>::Iterator::operator!=(const iterator& it) {
  return node != it.node;
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::Iterator&
BinaryTree<Key, T, Value>::Iterator::operator=(const iterator& it) {
  node = it.node;
  return *this;
}

//________________________________________________Const_Iterators______________________________________________________________

// template <typename Key, typename T, typename Value>
// BinaryTree<Key, T, Value>::Const_Iterators::Const_Iterators() : node(nullptr)
// {}

// template <typename Key, typename T, typename Value>
// BinaryTree<Key, T, Value>::Const_Iterators::Const_Iterators(Node* newnode) :
// node(newnode) {}

// template <typename Key, typename T, typename Value>
// BinaryTree<Key, T, Value>::Const_Iterators::Const_Iterators(BinaryTree<Key,
// T, Value>::Iterator::Iterators it) : node(it.node) {}

//________________________________________________Capacity______________________________________________________________
template <typename Key, typename T, typename Value>
bool BinaryTree<Key, T, Value>::empty() {
  return !root->left && !root->right;
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::size_type
BinaryTree<Key, T, Value>::size() {
  size_type res = 0;
  BinaryTree<Key, T, Value>::iterator it(begin());
  while (it.node && it.node != terminal_node) {
    it++;
    res++;
  }
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
                                            bool* check, bool permission,
                                            Node* new_node) {
  if (!x || x == terminal_node) {
    if (!root || root == terminal_node) root = new_node;
    std::pair<iterator, bool> p(Iterator(new_node), true);
    return p;
  }
  if (get_key(val) == get_key(x->node_key)) {
    if (!permission) {
      *check = false;
    } else
      set_val(x, val);  // x->node_key.second = val.second;
  } else {
    if (get_key(val) < get_key(x->node_key))
      x->left = insert_recursive(x->left, val, check, permission, new_node)
                    .first.node;

    if (get_key(val) > get_key(x->node_key))
      x->right = insert_recursive(x->right, val, check, permission, new_node)
                     .first.node;
  }

  get_balance_factor(x);
  return std::pair<iterator, bool>(Iterator(Nurlanization(x)), *check);
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::Node*
BinaryTree<Key, T, Value>::Nurlanization(Node* x) {
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
  if (!node) return 0;
  if (node->left) node->left->parent = node;
  if (node->right) node->right->parent = node;
  int left_height = get_height(node->left);
  int right_height = get_height(node->right);
  node->balanceFactor = -left_height + right_height;
  return node->balanceFactor;
}

template <typename Key, typename T, typename Value>
int BinaryTree<Key, T, Value>::get_height(Node* node) {
  if (!node) return 0;
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

template <typename Key, typename T, typename Value>
void BinaryTree<Key, T, Value>::delete_node_with_all_childrens(iterator it) {
  if (!it.node->left || !it.node->right) return;
  auto nod = it.node;
  auto par = it.node->parent;
  auto lef = it.node->left;
  auto rig = it.node->right;

  it.node = it.node->right;
  if (!it.node->left) {
    if (nod == nod->parent->left) par->left = it.node;
    if (nod == nod->parent->right) par->right = it.node;
    it.node->parent = par;

    it.node->left = lef;
    lef->parent = it.node;
  } else if (it.node->left) {
    while (it.node->left) it.node = it.node->left;
    it.node->parent->left = nullptr;
    if (it.node->right) {
      if (nod == nod->parent->left) par->left = it.node;
      if (nod == nod->parent->right) par->right = it.node;
      it.node->parent = par;
      lef->parent = it.node;
      it.node->right->right = rig;
      rig->parent = it.node->right->right;
    } else {
      if (nod == root)
        root = it.node;
      else if (nod == nod->parent->left)
        par->left = it.node;
      else if (nod == nod->parent->right)
        par->right = it.node;
      lef->parent = it.node;
      it.node->left = lef;

      it.node->right = rig;
      rig->parent = it.node;
    }
  }
}

template <typename Key, typename T, typename Value>
void BinaryTree<Key, T, Value>::delete_node_with_right_childrens(iterator it) {
  if (it.node->parent) {
    if (it.node->parent->right == it.node)
      it.node->parent->right = it.node->right;
    if (it.node->parent->left == it.node)
      it.node->parent->left = it.node->right;
    it.node->right->parent = it.node->parent;
  } else {
    root = it.node->right;
    it.node->right->parent = nullptr;
  }
}

template <typename Key, typename T, typename Value>
void BinaryTree<Key, T, Value>::delete_node_with_left_childrens(iterator it) {
  auto nod = it.node;
  if (it.node->parent) {
    it.node->parent->left = it.node->left;
    it.node->left->parent = it.node->parent;
  } else {
    root = it.node->left;
    it.node->left->parent = nullptr;
    it.node = it.node->left;
    while (it.node->right) it.node = it.node->right;
    it.node->right = terminal_node;
    terminal_node->parent = it.node;
  }
}

template <typename Key, typename T, typename Value>
void BinaryTree<Key, T, Value>::delete_node_with_not_childrens(iterator it) {
  if (!it.node) return;
  if (it.node->parent) {
    if (it.node->parent->right == it.node)
      it.node->parent->right = it.node->right;
    else
      it.node->parent->left = nullptr;
  } else
    root = it.node->right;
  // ?????????????????????????????????????????????????????????????????????
}
// template <typename Key, typename T, typename Value>
// void BinaryTree<Key, T, Value>::printTree(typename BinaryTree<Key, T,
// Value>::Node* x,
//                                    int level) {
//   if (x == nullptr) return;
//   printTree(x->right, level + 3);
//   for (int i = 0; i < level; i++) std::cout << " ";
//   std::cout << get_key(x->node_key) << "[" << get_val(x->node_key) << "]"
//             << std::endl;
//   printTree(x->left, level + 3);
// }
}  // namespace s21