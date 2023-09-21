#ifndef CPP1_S21_CONTAINERS_2_SRC_S21_MAP_S21_NODE_H
#define CPP1_S21_CONTAINERS_2_SRC_S21_MAP_S21_NODE_H

#include <cmath>
#include <iostream>

#include "s21_map.h"
using namespace std;

namespace s21 {
template <typename Key, typename T>
class Node {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;

 public:
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
  Node* iterator = nullptr;
  int balanceFactor = 0;
  T value;
  Key key;

 public:
  Node() {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    value = 0;
    key = 0;
  }

  Node(value_type val) {
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    key = key_type(val.first);
    value = mapped_type(val.second);
  }
};
};  // namespace s21
#endif