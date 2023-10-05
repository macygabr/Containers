#ifndef CPP1_S21_CONTAINERS_3_SRC_S21_MAP_S21_MAP_H
#define CPP1_S21_CONTAINERS_3_SRC_S21_MAP_S21_MAP_H

#include "../BinaryTree/BinaryTree.h"

namespace s21 {
template <typename Key, typename T>
class map : public BinaryTree<Key, T, pair<const Key, T>> {
 public:
  class MapIterator;

 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const Key, T>;

 public:
 public:
  map();  // Конструктор по умолчанию
          //   map(std::initializer_list<value_type> const& items);
          //   map(const map& m);       // copy constructor
          //   map(map&& m);            // move constructor
          //   ~map();                  // destructor
          // map operator=(map&& m);  // assignment operator overload for moving
          // map &operator=(const map &other);
  //   object map move(map&& m);       // assignment operator overload for
  //   moving object

 public:
  T &operator[](const Key &key);
  // T &operator[](Key &&key);
  T &at(const Key &key);
  const T &at(const Key &key) const;

 public:  // support
  virtual Key get_key(value_type val) override {
    BinaryTree<Key, T, value_type>::get_key(val);
    return Key(val.first);
  }
  virtual T get_val(value_type val) override {
    BinaryTree<Key, T, value_type>::get_val(val);
    return T(val.second);
  }

  virtual bool set_val(typename BinaryTree<Key, T, value_type>::Node *fir,
                       value_type sec) override {
    BinaryTree<Key, T, value_type>::set_val(fir, sec);
    fir->node_key.second = sec.second;
    return true;
  }

  void printTree(typename BinaryTree<Key, T, value_type>::Node *root,
                 int level = 0);
  void SimpleprintTree(typename BinaryTree<Key, T, value_type>::Node *root,
                       int level = 0);
  T &search(bool add, const Key &key);
};

};  // namespace s21

#include "s21_map.inc"
#endif