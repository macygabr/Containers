#ifndef CPP2_S21_CONTAINERS_3_SRC_S21_MULTISET_S21_SET_H
#define CPP2_S21_CONTAINERS_3_SRC_S21_MULTISET_S21_SET_H

#include "../BinaryTree/BinaryTree.h"

namespace s21 {
template <typename Key>
class multiset : public BinaryTree<Key, Key, Key> {
 public:
  using key_type = Key;
  using setped_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;
  using const_iterator = typename BinaryTree<Key, Key, Key>::Const_Iterator;
  using iterator = typename BinaryTree<Key, Key, Key>::Iterator;

 public:
  multiset();  // Конструктор по умолчанию
  multiset(std::initializer_list<value_type> const &items);
  multiset(const multiset &m)
      : BinaryTree<Key, Key, Key>(m){};  // copy constructor
  multiset(multiset &&m)
      : BinaryTree<Key, Key, Key>(std::move(m)){};  // move constructor
  ~multiset() = default;
  multiset &operator=(
      multiset &&m);  // assignment operator overload for moving object
  multiset &operator=(
      const multiset &m);  // assignment operator overload for copying object

 public:  // Lookup
  iterator find(const Key &key);
  iterator insert(const Key &key);
  // template <class... Args>
  // std::vector<std::pair<iterator, bool>> insert_many(Args &&...args);

 protected:  // support
  virtual Key get_key(value_type val) override {
    BinaryTree<Key, Key, Key>::get_key(val);
    return Key(val);
  }
  virtual Key get_val(value_type val) override {
    BinaryTree<Key, Key, Key>::get_val(val);
    return Key(val);
  }

  virtual bool set_val(typename BinaryTree<Key, Key, Key>::Node *fir,
                       value_type sec) override {
    BinaryTree<Key, Key, Key>::set_val(fir, sec);
    fir->node_key = sec;
    return true;
  }
  virtual bool is_multiset() override {
    BinaryTree<Key, Key, Key>::is_multiset();
    return true;
  }

  iterator search(const Key &key);
};

};  // namespace s21

#include "s21_multiset.inc"
#endif