#ifndef CPP2_S21_CONTAINERS_3_SRC_S21_SET_S21_SET_H
#define CPP2_S21_CONTAINERS_3_SRC_S21_SET_S21_SET_H

#include "../BinaryTree/BinaryTree.h"

namespace s21 {
template <typename Key>
class set : public BinaryTree<Key, Key, Key> {
 public:
  class MapIterator;

 public:
  using key_type = Key;

 public:
  set();  // Конструктор по умолчанию
};

};  // namespace s21

#include "s21_set.inc"
#endif