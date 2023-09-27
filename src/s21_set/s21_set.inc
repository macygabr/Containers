#include "s21_set.h"

namespace s21 {
template <typename Key>
set<Key>::set() {}

template <typename Key>
void set<Key>::first() {
  std::cout << "!!!!" << std::endl;
}

// template <typename Key>
// std::pair<iterator, bool> set::insert(const value_type val) {
//   return BinaryTree<Key, T>::insert(const std::pair<Key, Key> val)
// }
// template <typename Key>
// void set<Key>::printTree(typename BinaryTree<Key, Key>::Node* x, int level) {
//   if (x == nullptr) return;
//   printTree(x->right, level + 3);
//   for (int i = 0; i < level; i++) std::cout << " ";
//   std::cout << x->node_key << std::endl;
//   printTree(x->left, level + 3);
// }

}  // namespace s21