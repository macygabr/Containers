#ifndef CPP2_S21_CONTAINERS_3_SRC_S21_MAP_BINARYTREE_H
#define CPP2_S21_CONTAINERS_3_SRC_S21_MAP_BINARYTREE_H
namespace s21 {
template <typename Key, typename T>
class BinaryTree {
 public:
  class Node;
  class Iterator;

 public:  // change to protected
  Node* root;

 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<const key_type, mapped_type>;
  using iterator = Iterator;

 public:
  BinaryTree();

 public:
  BinaryTree& operator=(const BinaryTree& other);

 public:
  std::pair<iterator, bool> insert(const value_type val);
  std::pair<iterator, bool> insert(const Key& key, const T& obj = T());
  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj);

 public:             // Iterators
  iterator begin();  // returns an iterator to the beginning
  iterator end();    // returns an iterator to the end

 protected:
  std::pair<iterator, bool> insert_recursive(Node* x, value_type val,
                                             bool* check, bool permission);
  Node* rotate_Left(Node* x);
  Node* rotate_Right(Node* x);
  iterator Nurlanization(Node* x);
  int get_height(Node* node);
  int get_balance_factor(Node* node);

 public:
  T& at(const Key& key);
  T& operator[](const Key& key);

 public:
  class Node {
   public:
    Node* left;
    Node* right;
    Node* parent;
    int balanceFactor = 0;
    T node_val;
    Key node_key;

   public:
    Node()
        : node_val(),
          node_key(),
          left(nullptr),
          right(nullptr),
          parent(nullptr) {}

    Node(value_type val)
        : node_val(),
          node_key(),
          left(nullptr),
          right(nullptr),
          parent(nullptr) {
      node_key = Key(val.first);
      node_val = T(val.second);
      // node_key = value_type(val);
    }
  };

class Iterator {
   public:
    Iterator();
    Iterator(Node* node);
    iterator& operator++();
    iterator operator++(int);
    // iterator& operator--();
    // iterator operator--(int);
    // reference operator*();
    // bool operator==(const iterator& it);
    bool operator!=(const iterator& it);

   public:
    Node* node;
  };
};
};  // namespace s21
#include "BinaryTree.inc"
#endif