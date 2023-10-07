#include <iostream>

#include "s21_map.h"

using std::cout;
using std::endl;
using std::pair;

namespace s21 {
template <typename Key, typename T>
map<Key, T>::map() {}

template <typename Key, typename T>
map<Key, T>::map(const std::initializer_list<value_type>& items) {
  for (auto it = items.begin(); it != items.end(); it++) this->insert(*it);
}

template <typename Key, typename T>
map<Key, T>& map<Key, T>::operator=(map&& m) {
  if (this != &m) BinaryTree<Key, T, value_type>::operator=(std::move(m));
  return *this;
}

template <typename Key, typename T>
map<Key, T>& map<Key, T>::operator=(const map& other) {
  if (this != &other) BinaryTree<Key, T, value_type>::operator=(other);
  return *this;
}

//________________________________________________Element_access______________________________________________________________
template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& key) {
  return search(true, key);
}

template <typename Key, typename T>
T& map<Key, T>::at(const Key& key) {
  return search(false, key);
}

//________________________________________________Support______________________________________________________________

template <typename Key, typename T>
T& map<Key, T>::search(bool add, const Key& key) {
  auto root = BinaryTree<Key, T, value_type>::root;
  auto x = root;
  auto terminal_node = BinaryTree<Key, T, value_type>::terminal_node;

  while (x && x != terminal_node) {
    if (key == x->node_key.first) return x->node_key.second;
    if (key > x->node_key.first)
      x = x->right;
    else
      x = x->left;
  }
  if (add) {
    auto res = BinaryTree<Key, T, value_type>::insert(Key(key), T());
    return res.first.node->node_key.second;
  } else
    throw std::out_of_range("Key not found");
  return root->node_key.second;
}

}  // namespace s21