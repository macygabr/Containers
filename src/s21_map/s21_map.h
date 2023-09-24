#ifndef CPP1_S21_CONTAINERS_3_SRC_S21_MAP_S21_MAP_H
#define CPP1_S21_CONTAINERS_3_SRC_S21_MAP_S21_MAP_H

#include "../BinaryTree/BinaryTree.h"

namespace s21 {
template <typename Key, typename T>
class map : public BinaryTree<Key, T, std::pair<const Key, T>> {
 public:
  class MapIterator;

 public:
  void printTree(typename Node *x, int level = 0);

 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = MapIterator;
  using const_iterator = const MapIterator;
  using size_type = std::size_t;

  // Node<Key, T>* node;
  // Node<Key, T>* root;

 public:
  map();  // Конструктор по умолчанию
  //   map(std::initializer_list<value_type> const& items);
  //   map(const map& m);       // copy constructor
  //   map(map&& m);            // move constructor
  //   ~map();                  // destructor
  // map operator=(map&& m);  // assignment operator overload for moving
  map &operator=(const map &other);
  //   object map move(map&& m);       // assignment operator overload for
  //   moving object

  //  public:
  //   T& at(const Key& key);
  T &operator[](const Key &key);

  //  public:             // Iterators
  //   iterator begin();  // returns an iterator to the beginning
  //   iterator end();    // returns an iterator to the end

  //  public:  // Capacity
  //   bool empty();
  //   size_type size();
  //   size_type max_size();

  //  public:  // Modifiers
  //   void clear();
  // std::pair<iterator, bool> insert(const value_type val);
  // pair<iterator, bool> insert(const Key& key, const T& obj);
  //   std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);
  //   void erase(iterator pos);
  //   void swap(map& other);
  //   void merge(map& other);

  //  public:  // support
  //   std::pair<iterator, bool> insert_recursive(Node<Key, T>* x, value_type
  //   val,bool* check, bool permission); Node<Key, T>* rotate_Left(Node<Key,
  //   T>* x); Node<Key, T>* rotate_Right(Node<Key, T>* x); Node<Key, T>*
  //   Nurlanization(Node<Key, T>* x); int get_height(Node<Key, T>* node); int
  //   get_balance_factor(Node<Key, T>* node); void printTree(const Node<Key,
  //   T>* root, int level = 0);

  class MapIterator : public BinaryTree<Key, T, value_type>::Iterator {
   public:
    friend class map;
    MapIterator() : BinaryTree<Key, T, value_type>::Iterator(){};
    MapIterator(typename BinaryTree<Key, T, value_type>::Node *node)
        : BinaryTree<Key, T, value_type>::Iterator(node){};
  };
};

};  // namespace s21

#include "s21_map.inc"
#endif