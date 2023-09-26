#ifndef CPP2_S21_CONTAINERS_3_SRC_S21_SET_S21_SET_H
#define CPP2_S21_CONTAINERS_3_SRC_S21_SET_S21_SET_H

#include "../BinaryTree/BinaryTree.h"

namespace s21 {
template <typename Key>
class set : public BinaryTree<Key, Key> {
 public:
  class SetIterator;

 public:
  using key_type = Key;

 public:
  void first();
  set();  // Конструктор по умолчанию
  void printTree(typename BinaryTree<Key, Key>::Node* x, int level = 0);
};

};  // namespace s21

#include "s21_set.inc"
#endif