#ifndef CPP1_S21_CONTAINERS_3_SRC_S21_MAP_S21_NODE_H
#define CPP1_S21_CONTAINERS_3_SRC_S21_MAP_S21_NODE_H

#include <cmath>
#include <iostream>

#include "s21_map.h"

namespace s21 {
template <typename Key, typename T>
class Node {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using iterator = Node<Key, T>*;

 public:
  Node* left;
  Node* right;
  Node* parent;
  int balanceFactor = 0;
  T value;
  Key key;

 public:
  Node() : value(), key(), left(nullptr), right(nullptr), parent(nullptr) {}

  Node(value_type val)
      : value(), key(), left(nullptr), right(nullptr), parent(nullptr) {
    key = Key(val.first);
    value = T(val.second);
  }

  // iterator operator!=(){
  //   std::cout<<"OK"<<std::endl;
  // }
};
};  // namespace s21
#endif