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

//________________________________________________Element_access______________________________________________________________
template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& key) {
  return search(true, key);
}

// template <typename Key, typename T>
// T& map<Key, T>::operator[](Key &&key) {

// }

template <typename Key, typename T>
T& map<Key, T>::at(const Key& key) {
  return search(false, key);
}

template <typename Key, typename T>
const T& map<Key, T>::at(const Key& key) const {
  return search(false, key);
}

//________________________________________________Support______________________________________________________________

template <typename Key, typename T>
void map<Key, T>::printTree(typename BinaryTree<Key, T, value_type>::Node* x,
                            int level) {
  if (x == nullptr) return;
  printTree(x->right, level + 3);
  for (int i = 0; i < level; i++) std::cout << " ";
  std::cout << x->node_key.first << "[" << x->node_key.second << "]"
            << std::endl;
  printTree(x->left, level + 3);
}

template <typename Key, typename T>
T& map<Key, T>::search(bool add, const Key& key) {
  auto root = BinaryTree<Key, T, value_type>::root;
  auto x = root;
  auto terminal_node = BinaryTree<Key, T, value_type>::terminal_node;

  while (x && x != terminal_node) {
    // cout<<x->node_key.first<<" "<<x->node_key.second<<endl;
    if (key == x->node_key.first) return x->node_key.second;
    if (key > x->node_key.first)
      x = x->right;
    else
      x = x->left;
  }
  if (add) {
    auto res = BinaryTree<Key, T, value_type>::insert(Key(key));
    return res.first.node->node_key.second;
  } else
    throw std::out_of_range("Key not found");
  return root->node_key.second;
}

}  // namespace s21