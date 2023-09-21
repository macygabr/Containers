#ifndef CPP1_S21_MATRIXPLUS_1_SRC_S21_MAP_H
#define CPP1_S21_MATRIXPLUS_1_SRC_S21_MAP_H

#include <cmath>
#include <iostream>

#include "s21_node.h"

namespace s21 {
template <typename Key, typename T>
class map {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using Iterator = Node<Key, T>*;

  Node<Key, T>* node;
  Node<Key, T>* root;

 public:
  std::pair<Iterator, bool> insert(const value_type val);
  std::pair<Iterator, bool> insert(const Key& key, const T& obj);
  std::pair<Iterator, bool> insert_or_assign(const Key& key, const T& obj);

 public:
  map();  // Конструктор по умолчанию
  // map(std::initializer_list<value_type> const &items);
  // map(const map &m)	//copy constructor
  // map(map &&m)	//move constructor
  ~map();  // destructor
  // operator=(map &&m)	//assignment operator overload for moving object

 public:             // Iterators
  Iterator begin();  // returns an iterator to the beginning
  Iterator end();    // returns an iterator to the end
 public:
  T& operator[](const Key& key);

 public:  // Capacity
          // bool empty();
          // size_type size();
          // size_type max_size();
 public:  // support
  std::pair<Iterator, bool> insert_recursive(Node<Key, T>* x, value_type val,
                                             bool check, bool permission);
  Node<Key, T>* rotate_Left(Node<Key, T>* x);
  Node<Key, T>* rotate_Right(Node<Key, T>* x);
  Node<Key, T>* Nurlanization(Node<Key, T>* x);
  int get_height(Node<Key, T>* node);
  int get_balance_factor(Node<Key, T>* node);
  void printTree(const Node<Key, T>* root, int level = 0);
};
};  // namespace s21

#include "s21_map.inc"
#endif