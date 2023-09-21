#ifndef CPP1_S21_MATRIXPLUS_3_SRC_S21_MAP_ITERATOR_H
#define CPP1_S21_MATRIXPLUS_3_SRC_S21_MAP_ITERATOR_H

#include <cmath>
#include <iostream>

#include "s21_node.h"

namespace s21 {
template <typename Key, typename T>

class MapIterator {
 private:
  using iterator = map<Key, T>*;

 public:
  MapIterator& operator++() { return *this; }
};
};  // namespace s21

#include "s21_map.inc"
#endif