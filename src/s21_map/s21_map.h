#ifndef CPP2_S21_CONTAINERS_3_SRC_S21_MAP_S21_MAP_H
#define CPP2_S21_CONTAINERS_3_SRC_S21_MAP_S21_MAP_H

#include "../BinaryTree/BinaryTree.h"

namespace s21 {
template <typename Key, typename T>
class map : public BinaryTree<Key, T, pair<const Key, T>> {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using iterator = typename BinaryTree<Key, T, pair<const Key, T>>::Iterator;
  using const_iterator =
      typename BinaryTree<Key, T, pair<const Key, T>>::Const_Iterator;

 public:
  map();  // Конструктор по умолчанию
  map(std::initializer_list<value_type> const &items);
  map(const map &m) : BinaryTree<Key, T, value_type>(m){};  // copy constructor
  map(map &&m)
      : BinaryTree<Key, T, value_type>(std::move(m)){};  // move constructor
  ~map() = default;
  map &operator=(map &&m);  // assignment operator overload for moving object
  map &operator=(
      const map &m);  // assignment operator overload for copying object

 public:  // Element access
  T &operator[](const Key &key);
  T &at(const Key &key);
  pair<iterator, bool> insert_or_assign(const Key &key, const T &obj);

 protected:  // support
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
};

};  // namespace s21

#include "s21_map.inc"
#endif