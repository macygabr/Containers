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
  if (root) delete root;
}

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
  Iterator it_result = Iterator(root);
  std::pair<typename BinaryTree<Key, T, Value>::iterator, bool> res;
  if (root == terminal_node) root = nullptr;

  add_terminal_node(root, false);
  res = insert_recursive(root, val, &it_result, false);
  res.first = it_result;
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
  Iterator it_result = Iterator(root);
  std::pair<typename BinaryTree<Key, T, Value>::iterator, bool> res;
  if (root == terminal_node) root = nullptr;

  add_terminal_node(root, false);
  res = insert_recursive(root, val, &it_result, true);
  res.first = it_result;
  add_terminal_node(root, true);
  return res;
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::iterator BinaryTree<Key, T, Value>::erase(
    iterator it) {
  if (!it.node || it.node == terminal_node)
    throw std::out_of_range("Iterator not found");

  auto nod = it.node;
  auto par = it.node->parent;
  auto lef = it.node->left;
  auto rig = it.node->right;

  if (lef && rig && rig != terminal_node)
    it = delete_node_with_all_childrens(it);
  else if (!lef && rig && rig != terminal_node)
    it = delete_node_with_right_childrens(it);
  else if (lef && (!rig || rig == terminal_node))
    it = delete_node_with_left_childrens(it);
  else
    it = delete_node_with_not_childrens(it);

  while (abs(it.node->balanceFactor) > 1) {
    get_balance_factor(it.node);
    Nurlanization(it.node);
  }
  return it;
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
  iterator it = other.begin();
  for (it = other.begin(); it != other.end();) {
    if (insert(*it).second) it = other.erase(it);
  }
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

// template <typename Key, typename T, typename Value>
// BinaryTree<Key, T, Value>::Iterator::Iterator() : node(nullptr) {}

// template <typename Key, typename T, typename Value>
// BinaryTree<Key, T, Value>::Iterator::Iterator(Node* newnode) : node(newnode)
// {}

// template <typename Key, typename T, typename Value>
// BinaryTree<Key, T, Value>::Iterator::Iterator(const Iterator& it)
//     : node(it.node) {}

// template <typename Key, typename T, typename Value>
// BinaryTree<Key, T, Value>::Iterator::Iterator(const_iterator& it)
//     : node(it.node) {}

// template <typename Key, typename T, typename Value>
// BinaryTree<Key, T, Value>::Iterator::Iterator(Iterator&& it) : node(it.node)
// {
//   it.node = nullptr;
// }

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::Iterator&
BinaryTree<Key, T, Value>::Iterator::operator++() {
  // if(newnode) printf("%d\n", newnode->node_key.first);

  if (!node) {
    // if (newnode) {
    //   node = newnode;
    // }
    // else
    throw std::out_of_range("Iterator out of range");
  }

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
// BinaryTree<Key, T, Value>::Const_Iterators::Const_Iterators() :
// node(nullptr){}

// template <typename Key, typename T, typename Value>
// BinaryTree<Key, T, Value>::Const_Iterators::Const_Iterators(Node* newnode) :
// node(newnode) {}

// template <typename Key, typename T, typename Value>
// BinaryTree<Key, T, Value>::Const_Iterators::Const_Iterators(const
// BinaryTree<Key, T, Value>::Iterator::Iterators it) : node(it.node) {}

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
                                            Iterator* it_result,
                                            bool permission) {
  bool bool_result = true;
  std::pair<iterator, bool> pair;
  if (!x || x == terminal_node) {
    Node* new_node = new Node(val);
    if (!root || root == terminal_node) root = new_node;
    it_result->node = new_node;
    return std::pair<iterator, bool>(Iterator(new_node), true);
  }
  if (get_key(val) == get_key(x->node_key)) {
    if (!permission) {
      it_result->node = x;
      return std::pair<iterator, bool>(Iterator(x), false);
    } else
      set_val(x, val);  // x->node_key.second = val.second;
  } else {
    if (get_key(val) < get_key(x->node_key)) {
      pair = insert_recursive(x->left, val, it_result, permission);
      x->left = pair.first.node;
      x->left->parent = x;
    }

    if (get_key(val) > get_key(x->node_key)) {
      pair = insert_recursive(x->right, val, it_result, permission);
      x->right = pair.first.node;
      x->right->parent = x;
    }
  }

  get_balance_factor(x);
  bool_result = pair.second;
  return std::pair<iterator, bool>(Iterator(Nurlanization(x)), bool_result);
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
  if (x->parent && x->parent->left == x) x->parent->left = p;
  if (x->parent && x->parent->right == x) x->parent->right = p;
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
  if (x->parent && x->parent->left == x) x->parent->left = q;
  if (x->parent && x->parent->right == x) x->parent->right = q;
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
typename BinaryTree<Key, T, Value>::iterator
BinaryTree<Key, T, Value>::delete_node_with_all_childrens(iterator it) {
  // if (!it.node->left || !it.node->right) return;
  auto nod = it.node;
  auto par = it.node->parent;
  auto lef = it.node->left;
  auto rig = it.node->right;
  nod = rig;
  if (!nod->left) {
    if (it.node == it.node->parent->left) par->left = nod;
    if (it.node == it.node->parent->right) par->right = nod;
    nod->parent = par;

    nod->left = lef;
    lef->parent = nod;
  } else {
    while (nod->left) nod = nod->left;
    // nod->parent->left = nullptr;
    // if (nod->right) {
    // if (nod == nod->parent->left) par->left = it.node;
    // if (nod == nod->parent->right) par->right = it.node;
    // it.node->parent = par;
    // lef->parent = it.node;
    // it.node->right->right = rig;
    // rig->parent = it.node->right->right;
    // } else
    // {
    if (it.node == root)
      root = nod;
    else if (it.node == it.node->parent->left) {
      nod->parent->left = nullptr;
      par->left = nod;
    } else if (it.node == it.node->parent->right) {
      nod->parent->left = nullptr;
      par->right = nod;
    }
    lef->parent = nod;
    nod->left = lef;

    nod->right = rig;
    rig->parent = nod;
    // }
  }
  delete it.node;
  return Iterator(nod);
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::iterator
BinaryTree<Key, T, Value>::delete_node_with_right_childrens(iterator it) {
  auto nod = it.node;
  auto par = it.node->parent;
  auto lef = it.node->left;
  auto rig = it.node->right;

  if (it.node->parent) {
    if (it.node->parent->right == it.node)
      it.node->parent->right = it.node->right;
    if (it.node->parent->left == it.node)
      it.node->parent->left = it.node->right;
    it.node->right->parent = it.node->parent;
    nod = it.node->right;
  } else {
    root = it.node->right;
    it.node->right->parent = nullptr;
  }
  delete it.node;
  return Iterator(nod);
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::iterator
BinaryTree<Key, T, Value>::delete_node_with_left_childrens(iterator it) {
  auto nod = it.node;
  auto par = it.node->parent;
  auto lef = it.node->left;
  auto rig = it.node->right;
  if (it.node->parent) {
    if (it.node->parent->right == it.node)
      it.node->parent->right = it.node->left;
    if (it.node->parent->left == it.node) it.node->parent->left = it.node->left;
  } else {
    root = it.node->left;
    it.node->left->parent = nullptr;
    nod = it.node->left;
    nod->right = rig;
    rig->parent = nod;
  }
  delete it.node;
  return Iterator(nod);
}

template <typename Key, typename T, typename Value>
typename BinaryTree<Key, T, Value>::iterator
BinaryTree<Key, T, Value>::delete_node_with_not_childrens(iterator it) {
  auto nod = it.node;

  // if (!it.node) return Iterator(root);
  if (it.node->parent) {
    if (it.node->parent->right == it.node)
      it.node->parent->right = it.node->right;
    else
      it.node->parent->left = it.node->left;
    nod = it.node->parent;
  } else {
    root = it.node->right;
    nod = root;
  }

  delete it.node;
  return Iterator(nod);
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