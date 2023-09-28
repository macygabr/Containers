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
  using reference = value_type &;
  using const_reference = const value_type &;
  // using iterator = MapIterator;
  using const_iterator = const MapIterator;
  using size_type = std::size_t;

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
  //   T& at(const Key& key);
  T &operator[](const Key &key);

 public:  // Iterators
          //   iterator begin();  // returns an iterator to the beginning
          //   iterator end();    // returns an iterator to the end
 public:  // Capacity
          // bool empty();
          // size_type size();
          // size_type max_size();
 public:  // Modifiers
          //   void clear();
          // void erase(iterator pos);
          // void swap(map &other);
          // void merge(map &other);
 public:  // support
  // virtual typename BinaryTree<Key, T, Value>::Iterator
  // get_iterator(std::pair<iterator, bool> val) override {
  //   BinaryTree<Key, T, Value>::get_iterator(val);
  //   return val.first;
  // }
  virtual Key get_key(value_type val) override {
    BinaryTree<Key, T, value_type>::get_key(val);
    return Key(val.first);
  }
  virtual T get_val(value_type val) override {
    BinaryTree<Key, T, value_type>::get_val(val);
    return T(val.second);
  }
  // virtual bool set_key(typename BinaryTree<Key, T, Value>::Node *fir,
  //                      value_type sec) override {
  //   BinaryTree<Key, T, Value>::set_key(fir, sec);
  //   fir->node_key.first = sec.first;
  //   return true;
  // }
  virtual bool set_val(typename BinaryTree<Key, T, value_type>::Node *fir,
                       value_type sec) override {
    BinaryTree<Key, T, value_type>::set_val(fir, sec);
    fir->node_key.second = sec.second;
    return true;
  }

  void printTree(typename BinaryTree<Key, T, value_type>::Node *root,
                 int level = 0);

  // class MapIterator : public BinaryTree<Key, T, value_type>::Iterator {
  //  public:
  //   MapIterator() : BinaryTree<Key, T, value_type>::Iterator(){};
  //   // MapIterator(typename BinaryTree<Key, T, Value>::Node *node) :
  //   // BinaryTree<Key, T>::Iterator(node){};
  // };
};

};  // namespace s21

#include "s21_map.inc"
#endif